#!/usr/bin/env python

import freetype
import sys

if __name__ == "__main__":
    if (len(sys.argv) == 4):
        # Getting the command arguments
        font_path = sys.argv[1]
        character_size = int(sys.argv[2])
        code_path = sys.argv[3]

        # Loading the font
        font_face = freetype.Face(font_path)

        # Set character size
        font_face.set_pixel_sizes(0,character_size)

        # Iterate over the ASCII characters we need (from "!" to "~")
        for character_number in xrange(33,127):
            # Get the character as a string from the ASCII number
            character_str = chr(character_number)

            # Load the character
            font_face.load_char(character_str,freetype.FT_LOAD_RENDER|freetype.FT_LOAD_TARGET_MONO)

            # 

            pass
    else:
        print "usage : font2code [font file] [character size] [code file]"
