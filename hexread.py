import os
import sys
import errno
import PIL import Image

"""
Usage in cmd: python hexread.py Test.bin\n
Reads for PNG headers in a binary file and dumps them, useful for extracting textures from game files\n
Compress using compression.py
"""

if len(sys.argv) !=1:
    print("Selecting file..."+sys.argv[1])
else:
    filename=input("Enter Filename or press ENTER to skip:")
    if filename == '':
        sys.exit("No Args or filename, exiting")
    else:
        sys.argv.append(filename)
        print("Selecting file..."+sys.argv[1])

with open(sys.argv[1], "rb") as binary_file:
    print("Opening file:"+sys.argv[1])
    binary_file.seek(0, 2)  # Seek the end
    num_bytes = binary_file.tell()  # Get the file size
    print('File size:'+str(num_bytes)+'B')
    count = 0
    print('Finding PNG signatures')
    for i in range(num_bytes):
        binary_file.seek(i)
        eight_bytes = binary_file.read(8)
        if eight_bytes == b"\x89\x50\x4e\x47\x0d\x0a\x1a\x0a":  # PNG signature
            count += 1
            print("Found PNG Signature #" + str(count) + " at " + str(i))

            # Next four bytes after signature is the IHDR with the length
            png_size_bytes = binary_file.read(4)
            png_size = int.from_bytes(png_size_bytes, byteorder='little', signed=False)

            # Go back to beginning of image file and extract full thing
            binary_file.seek(i)
            # Read the size of image plus the signature
            png_data = binary_file.read(png_size + 8)
            try:
                os.mkdir('pngs')
            except OSError as e:
                if e.errno != errno.EEXIST:
                    raise
            with open("pngs/" + str(i) + ".png", "wb") as outfile:
                outfile.write(png_data)
if count==0:
    print('No png signatures found?')