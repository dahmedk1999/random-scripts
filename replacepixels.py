import os
import sys
import errno
import pathlib
import imghdr
import time
import numpy
from PIL import Image, ImageSequence
from subdir import retSubdirpaths
def verifycolormath(input,delta,mode):
    """#@brief Pass in a list of RGB pixels tuples [(R,G,B,A),(R,G,B,A),...] and list of delta RGB [R,G,B]\n
    #@return list with proper RGB/RGBA values<=255"""
    temp=[input[0]+delta[0],input[1]+delta[1],input[2]+delta[2],input[3]]
    #print(temp)
    for rgb in input:
        if rgb+delta[0] >= 255:
            temp[0]=255
        if rgb+delta[1] >= 255:
            temp[1]=255
        if rgb+delta[2] >= 255:
            temp[2]=255

    if mode=='RGBA':
        temp[3]=input[3]
        #print("Returning verified: {} {}".format(temp,mode))
        return temp
    elif mode=='RGB' or 'P':
        #print("Returning verified: {} {}".format(temp[:3],mode))
        return temp[:3]

def get_dur(PIL_Image_object):
    """ Returns the duration of provided .gif """
    PIL_Image_object.seek(0)
    frames = duration = 0
    while True:
        try:
            frames += 1
            duration += PIL_Image_object.info['duration']
            PIL_Image_object.seek(PIL_Image_object.tell() + 1)
        except EOFError:
            return duration

def replacepixels(pixelRGBAlist,deltashift):
    """Creates input/output folders\n
    manipulates the images inside input folder, then saves to output folder\n
    very slow, 1 second per image due to O(n^4) complexity\n
    """
    cwd=os.path.dirname(os.path.abspath(__file__))
    pictures=0
    if not os.path.isdir(cwd+'/input'):
        print('The input directory is not present. Creating a new one..')
        os.mkdir(cwd+'/input')
    if not os.path.isdir(cwd+'/output'):
        print('The output directory is not present. Creating a new one..')
        os.mkdir(cwd+'/output')
    inputpaths=retSubdirpaths()
    for inputfilepath in inputpaths:
        output_img_path = (inputfilepath.replace("input","output"))
        #print("output path is: {}".format(output_img_path))
        #print("input path is: {}".format(inputfilepath))
        #Open File
        with Image.open(inputfilepath) as im:
            pictures+=1
            filetype=im.format
            imagemode=im.mode
            #print("Loaded image{}".format(im))
            #Perform Operations
            pixelMap=im.load()
            img = Image.new( imagemode, im.size)
            pixelsNew = img.load()
            if imagemode=='RGBA':
                #print("RGBA image")
                for i in range(img.size[0]):
                    for j in range(img.size[1]):
                        for pixel in pixelRGBAlist:
                            if pixelMap[i,j] == tuple(pixel):
                                #print("Found a {} pixel at \t{},{}".format(pixel,i,j))
                                rgbapixel = verifycolormath(pixel,deltashift,imagemode)
                                newpixel = (rgbapixel[0],rgbapixel[1],rgbapixel[2],pixel[3])
                                pixelMap[i,j] = newpixel
                            pixelsNew[i,j] = pixelMap[i,j]      
            elif imagemode=='RGB':
                #print("RGB image")
                for i in range(img.size[0]):
                    for j in range(img.size[1]):
                        for pixel in pixelRGBAlist:
                            tempixel=pixel[:3]
                            #print(tuple(tempixel))
                            #print(tuple(pixelMap[i,j]))
                            if pixelMap[i,j] == tuple(tempixel):
                                rgbpixel = verifycolormath(pixel,deltashift,imagemode)
                                #print("Replacing {}\tpixel at ({},{}) with {}".format(pixelMap[i,j],i,j,rgbpixel))
                                newpixel = (rgbpixel[0],rgbpixel[1],rgbpixel[2])
                                pixelMap[i,j] = newpixel
                            pixelsNew[i,j] = pixelMap[i,j]            
            else: 
                #print("Unsupported image format!")
                continue;
            #Save File
            img.save(output_img_path, filetype)      
            sys.stdout.write('\r'+str(pictures)+'  done')
            time.sleep(0)
            sys.stdout.flush()
    print()

def main():
    pixellist= [[244,220,136,255],[255,244,143,255]]
    delta=[10,10,90]
    replacepixels(pixellist,delta)
# Driver code
if __name__ == "__main__":
    main()