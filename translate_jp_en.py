#pip install googletrans==4.0.0-rc1
from googletrans import Translator 
import sys
import string
import argparse
import time
import re
#from yandex.Translater import Translater
def tltest():
    translatorG = Translator()
    #translatorY = Translater()

    # f= open('jptext.txt', 'r', encoding='utf8')

    # if f.mode=='r':
    #     content=f.read()
    #     #print(content)
    #     #print('\n\n')

    # result = translator.translate(content,src='ja', dest='en')

    # with open('translate.txt', 'w') as f:
    #     f.write(result.text)
    string = 'Please paste/input jp text to translate'
    print(string)
    while (1):
        string = input()
        if(string=='x'):
            sys.exit('Done')
        else:
            result = translatorG.translate(string, src='ja',dest='en')
            print(result.text)
            
def checkregex(input):
    #^[a-zA-Z0-9_.:\-"\\\/! >@]*$   Ignore alphabets numbers, > - : \ _ !/ " newlines/spaces @ per line
    check = re.compile(r'^[a-zA-Z0-9_.:\-"\\\/! >@]*$')
    if check.match(input):
        return True
    else:
        return False

def translatefile():
    MTL = Translator()
    fin = open('strings.txt',encoding='utf-8')
    fout =open('stringout.txt','w',encoding='utf-8')
    for string in fin:
        if(MTL.detect(string).lang=='en'):
            fout.write(string)
        else:
            strtl=MTL.translate(string,src='ja',dest='en')
            fout.write(strtl.text)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i','--input',required=True,dest='input',help='Specify input filename',type=str)
    parser.add_argument('-o','--output',required=True,dest='output',help='Specify output filename',type=str)
    args=parser.parse_args()
    
    MTL = Translator()
    with open(args.input,encoding='utf-8') as read:
        for c,l in enumerate(read):
            pass
    print(c+1," lines total")
    fin = open(args.input,encoding='utf-8')
    fout =open(args.output,'w',encoding='utf-8')
    for s in fin:
        c-=1
        if(checkregex(s)):
            #print(s)
            fout.write(s)
            sys.stdout.write("\rRemaining: "+ str(c))
            time.sleep(0)
            sys.stdout.flush()
        else:
            strtl=MTL.translate(s,src='ja',dest='en')
            #print(strtl.text)
            fout.write(strtl.text)
            sys.stdout.write("\rRemaining: "+ str(c))
            time.sleep(0)
            sys.stdout.flush()

if __name__ == '__main__':
    main()