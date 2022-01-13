import os
import sys
import errno
import pathlib
import imghdr
import time
import numpy as np
from PIL import Image, ImageSequence
from numpy.__config__ import show
from numpy.core.fromnumeric import size
from numpy.lib.type_check import imag
from subdir import retSubdirpaths
from imagelib import *

def replacepixels2(pixelRGBAlist,deltashift):
    """This is 5-8x faster\n
    8 images per second completed vs 1 img per second in replacepixels
    """
    makeinputoutput()
    pic=0
    total=0
    inputpaths=retSubdirpaths(0)
    total = len(inputpaths)
    
    replacements=[]
    for pix in pixelRGBAlist:
        p=verifycolormath(pix,deltashift,'RGBA')
        replacements.append(p)
    pixlist=np.array(pixelRGBAlist,np.uint8)
    replace=np.array(replacements,np.uint8)
    start=time.perf_counter()
    for ip in inputpaths:
        op=ip.replace("input","output")
        #print(ip,op)
        if not (os.path.splitext(ip)[1]==".png"):
            continue
        img= Image.open(ip)
        if img.mode =='P':
            continue
        img_arr = np.array(img,np.uint8)
        # print(img_arr.shape)
        #print(img_arr.dtype)
        for i in range(len(pixlist)): #indexed
            # print("replace ",i,replace[i])
            # print("pixlist ",i,pixlist[i])
            img_arr[...]=np.where(img_arr[:] == pixlist[i],replace[i],img_arr[:]) #in each row where its element matches pixlist[i], replace said element with replace[i]
        nimg=Image.fromarray(img_arr)
        nimg.save(op)
        pic+=1
        sys.stdout.write('\r'+str(pic)+' of '+str(total)+' done')
        # time.sleep(0.001)
        sys.stdout.flush()
    elapsed=time.perf_counter()-start
    print("\nDone in ",elapsed,"s")
    
def makeinputoutput():
    cwd=os.path.dirname(os.path.abspath(__file__))
    if not os.path.isdir(cwd+'/input'):
        print('The input directory is not present. Creating a new one..')
        os.mkdir(cwd+'/input')
    if not os.path.isdir(cwd+'/output'):
        print('The output directory is not present. Creating a new one..')
        os.mkdir(cwd+'/output')

def replacepixels(pixelRGBAlist,deltashift):
    """
    manipulates the images inside input folder, then saves to output folder\n
    very slow, 1 second per image due to O(n^4) complexity\n
    1.5+hr / 5000 img
    """
    pictures=0
    makeinputoutput()
    inputpaths=retSubdirpaths(0)
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


def main(): #numpy uses y,x not x,y
    pixellist= [[255,0,0,255],[0,0,0,255]]
    delta=[80,80,80]
    replacepixels2(pixellist,delta)


# Driver code
if __name__ == "__main__":
    main()