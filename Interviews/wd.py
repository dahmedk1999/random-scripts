import time
# palindrome
def ispalindrome(input:str):
    strToList=list(input)
    size= len(input)
    pointerL=0
    pointerR=size-1
    while(pointerL<pointerR):
        if(strToList[pointerR]==' '): # alternatively I could sanitize the string, but this is faster
            pointerR-=1
        if(strToList[pointerL]==' '):
            pointerL+=1
        if(strToList[pointerL]==strToList[pointerR]):
            # print(strToList[pointerL])
            # print(strToList[pointerR])
            pointerR-=1
            pointerL+=1
        else:
            return False
    return True


# fibonacci
def fibonacci(input:int):
    if(input<=3):
        return 1
    return fibonacci(input-1)+fibonacci(input-2)

def fibonacciFast(input:int):
    fib=[0,1]
    index=1
    while(input>2):
        fib.append(fib[index]+fib[index-1])
        index+=1
        input-=1 # if you forget this line, your PC will max out RAM and freeze until you forceshutdown    
    print(fib)


# vowel rep -
def vowel(input:str):
    out=input.replace(('a'),'-',-1)
    out=out.replace(('e'),'-',-1)
    out=out.replace(('i'),'-',-1)
    out=out.replace(('o'),'-',-1)
    out=out.replace(('u'),'-',-1)
    out=out.replace(('A'),'-',-1)
    out=out.replace(('E'),'-',-1)
    out=out.replace(('O'),'-',-1)
    out=out.replace(('I'),'-',-1)
    out=out.replace(('U'),'-',-1)

    print(out)
def vowel2(input:str):
    for char in input:
        if char in "aeiouAEIOU":
            input=input.replace(char,'-',-1)
    print(input)


# dictionary
# a dictionary with keys of tuple (1,2,3) and (4,5,6) mapped to values 10 and 20
def createDictionary():
    dict={(1,2,3):10,(4,5,6):20}
    print(dict.get((1,2,3)))
    print(dict[(1,2,3)])
    dict2={(x,x+1,x+2):10*x for x in range(0,5,2)}
    for x in dict2:
        print(x)
    print(dict2.items()) # values
    print(sorted(dict2)) # keys


def main():
    string="never odd or even"
    print(ispalindrome(string))
    st1=time.time()
    print(fibonacci(35))
    et1=time.time()-st1
    print(et1)
    print(fibonacciFast(35))
    st=time.time()
    vowel("""Thisjjjk tool was created because we wanted random text for our web designs. When we show a design to a client we want to have some text that doesn't mean anything in particular just to indicate that "here is where the text will be". So why shouldn't we just copy-paste a single sentence and get a block of text ? Have a look at the following examples:This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text.This is a single sentence repeated a few times.Is post each that just leaf no. He connection interested so we an sympathize advantages. To said is it shed want do. Occasional middletons everything so to. Have spot part for his quit may. Enable it is square my an regard. Often merit stuff first oh up hills as he.And this is some text from our generator.As you can easily notice the second block of text looks more realistic. This way when you show a design to a client you can have a result that resembles the final product. However you can also use this text when you need meaningless text in the background of a design for a poster, t-shirt or whatever else you please.Why not use lorem ipsum ?Lorem ipsum is the most common form of "Greeking". However more and more people are sick and tired of using the same sample text over and over again. Also lorem ipsum is in latin and it may not always be the best choice. We tried to have text generated in some of the most widely used languages but if you are in desperate need of random text in your own language, send us an email and we'll add it here.aaaaanierocbcpeAEIOUruygbxlpodthsppeeirufeekluuaahhhaeuioextrawordstobloatthestringsoitsnotallzerosecondruntimeContented get distrusts certainty nay are frankness concealed ham. On unaffected resolution on considered of. No thought me husband or colonel forming effects. End sitting shewing who saw besidesLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. son musical adapted. Contrasted interested eat alteration pianoforte sympathize was. He families believed if no elegance interest surprise an. It abode wrong miles an so delay plate. She relation own put outlived may disposed""")
    et=time.time()-st
    print(et)
    st=time.time()
    vowel2("""Thisjjjh tool was created because we wanted random text for our web designs. When we show a design to a client we want to have some text that doesn't mean anything in particular just to indicate that "here is where the text will be". So why shouldn't we just copy-paste a single sentence and get a block of text ? Have a look at the following examples:This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text. This is some dummy text.This is a single sentence repeated a few times.Is post each that just leaf no. He connection interested so we an sympathize advantages. To said is it shed want do. Occasional middletons everything so to. Have spot part for his quit may. Enable it is square my an regard. Often merit stuff first oh up hills as he.And this is some text from our generator.As you can easily notice the second block of text looks more realistic. This way when you show a design to a client you can have a result that resembles the final product. However you can also use this text when you need meaningless text in the background of a design for a poster, t-shirt or whatever else you please.Why not use lorem ipsum ?Lorem ipsum is the most common form of "Greeking". However more and more people are sick and tired of using the same sample text over and over again. Also lorem ipsum is in latin and it may not always be the best choice. We tried to have text generated in some of the most widely used languages but if you are in desperate need of random text in your own language, send us an email and we'll add it here.aaaaanierocbcpeAEIOUruygbxlpodthsppeeirufeekluuaahhhaeuioextrawordstobloatthestringsoitsnotallzerosecondruntimeContented get distrusts certainty nay are frankness concealed ham. On unaffected resolution on considered of. No thought me husband or colonel forming effects. End sitting shewing who saw besidesLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. son musical adapted. Contrasted interested eat alteration pianoforte sympathize was. He families believed if no elegance interest surprise an. It abode wrong miles an so delay plate. She relation own put outlived may disposed""")
    et=time.time()-st
    print(et)
if __name__ == "__main__":
    main()


