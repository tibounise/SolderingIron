#!/usr/bin/ruby

require 'optparse'
require 'tmpdir'
require 'shellwords'

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
font_size = 0

code_file = File.open(options[:codefile],'w')

code_file.write('#include <avr/pgmspace.h>'+"\n\n")
code_file.write("static const uint8_t font_#{font_name}[#{font_size}] PROGMEM = {\n")

byte_width = (options[:chrsize].split("x").first.to_i + 7)/8

# Generate a temporary directory
Dir.mktmpdir { |tmp_dir|
  # Iterate over every ascii character
  for ascii_character_number in 33..126
    # Convert from number to string
    ascii_character = ascii_character_number.chr

    # Converting the glyph to an image
    font_to_image = puts("convert -resize #{options[:chrsize]}\\! -font #{options[:font]} -pointsize #{options[:pointsize]} -monochrome label:'#{ascii_character.gsub(/[']/,'\\\'')}' #{tmp_dir}/#{ascii_character_number}.png")
    
    # Code indentation
    code_file.write('    ')

    # Line return
    code_file.write("\n")
  end
}

code_file.write('};')
code_file.close