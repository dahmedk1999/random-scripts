import os
import sys
import errno
import pathlib
import imghdr
import time
import numpy as np
from PIL import Image, ImageSequence

def verifycolormath(input,delta,mode):
    """Pass in a list of RGB pixels tuples [(R,G,B,A),(R,G,B,A),...] and list of delta RGB [R,G,B]\n
    #@return list with proper RGB/RGBA values<=255"""
    temp=[input[0]+delta[0],input[1]+delta[1],input[2]+delta[2],input[3]]
    #print(temp)
    if input[0]+delta[0] >= 255:
        temp[0]=255
    if input[1]+delta[1] >= 255:
        temp[1]=255
    if input[2]+delta[2] >= 255:
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

def reshape_img(img: Image):
    img_data = np.array(img.getdata()).reshape(img.size[1], img.size[0], 4)
    difference_found = False
    for i in range(img.size[0]):
        for j in range(img.size[1]):
            get_pixel = img.getpixel((i, j))
            data = img_data[j, i]

            if any(get_pixel != data):
                difference_found = True
                msg = 'Difference in pixel {pixel}: img.getpixel={getpixel}, ' \
                      'img_data={data}'.format(pixel=(i, j), getpixel=get_pixel, data=data)
                print(msg)
    if not difference_found:
        msg = 'The two images are identical'
        print(msg)

def what_colors(img: Image):
    color_list = []
    for i in range(img.size[0]):
        for j in range(img.size[1]):
            get_pixel = img.getpixel((i, j))
            if get_pixel not in color_list:
                color_list.append(get_pixel)
    print(color_list)
    return color_list

def what_colors(arr: np.array,v):
    color_list= np.unique(arr.reshape(-1, arr.shape[2]), axis=0)
    if v==1:
        print(color_list)
    return color_list

def img_to_np(img: Image,v):
    """v=1 to print image details"""
    img_arr= np.array(img)
    if v==1:
        print('\nImage Resolution: ',img.size,'\nMode: ', img.mode,'\nType: ',img.format,'\nArray datatype: ',img_arr.dtype,'\nArray shape: ',img_arr.shape)
    return img_arr
