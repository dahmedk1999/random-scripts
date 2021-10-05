import os
import errno
import pathlib
def retSubdirpaths(verbose):
    """copies the folder structure inside /input folder to /output folder, and returns list of paths for all items inside input folder"""
    root=os.path.dirname(os.path.abspath(__file__))

    inputpath = root+'/input/'
    outputpath = root+'/output/'
    fileinpaths=[]
    fileoutpaths=[]
    for dirpath, dirnames, filenames in os.walk(inputpath):
        structure = os.path.join(outputpath, dirpath[len(inputpath):])
        if not os.path.isdir(structure):
            os.mkdir(structure)
        else:
            if verbose==1:
                print("Directory {} already exists".format(structure))
        for img in filenames:
            fileoutpaths.append(os.path.normpath(os.path.join(structure,img))) 
            fileinpaths.append(os.path.normpath(os.path.join(structure,img).replace('output','input')))
    # for path in fileinpaths:
        # print(path)
    # for path in fileoutpaths:
        # print(path)

    return fileinpaths