#!/usr/bin/ruby

require 'optparse'
require 'tmpdir'
require 'shellwords'
require 'chunky_png'

# Parsing arguments
options = {}
OptionParser.new do |opts|
  opts.banner = "Usage : font2code.rb [options]"

  opts.on(:REQUIRED,'-f','--font','Font name') do |v|
    options[:font] = v
  end
  opts.on(:REQUIRED,'-s','--size','Character size') do |v|
    options[:chrsize] = v
  end
  opts.on(:REQUIRED,'-c','--code-output','Code output') do |v|
    options[:codefile] = v
  end
  opts.on(:REQUIRED,'-p','--point-size','Point size') do |v|
    options[:pointsize] = v
  end
end.parse(ARGV)

font_name = File.basename(options[:font],File.extname(options[:font]))

code_file = File.open(options[:codefile],'w')

code_file.write('#include <avr/pgmspace.h>'+"\n\n")
code_file.write("static const uint8_t font_#{font_name}[] PROGMEM = {\n")

byte_width = (options[:chrsize].split("x").first.to_i + 7)/8

# Generate a temporary directory
Dir.mktmpdir { |tmp_dir|
  # Iterate over every ascii character
  for ascii_character_number in 33..126
    # Convert from number to string
    ascii_character = ascii_character_number.chr

    # We don't need that character, so let's replace it with a more usefull one
    if (ascii_character == '`')
      ascii_character = "°"
    end

    # Fix our problems
    if (ascii_character == '\$')
      ascii_character_fixed = '\\$'
    elsif (ascii_character == '\\')
      ascii_character_fixed = '\\\\\\\\' # Hell yeah
    elsif (ascii_character == '"')
      ascii_character_fixed = '\\"'
    elsif (ascii_character == '@')
      ascii_character_fixed = '\\@'
    else
      ascii_character_fixed = ascii_character
    end
      

    # Image path
    image_url = "#{tmp_dir}/#{ascii_character_number}.png"

    # Converting the glyph to an image
    system("convert -resize #{options[:chrsize]}\\! -font #{options[:font]} -pointsize #{options[:pointsize]} -monochrome label:\"#{ascii_character_fixed}\" #{image_url}")

    # Converting the image to C code
    c_code = `java img2code #{image_url}`
    
    # Writing that into the C file
    code_file.write('    '+c_code[0..-2]+", // #{ascii_character_number}\n")
  end
}

# Let's close the file, shall we ?
code_file.write('};')
code_file.close