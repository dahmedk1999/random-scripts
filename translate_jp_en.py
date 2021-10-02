#pip install googletrans==4.0.0-rc1
from googletrans import Translator 
#from yandex.Translater import Translater
translatorG = Translator()
#translatorY = Translater()

# f= open("jptext.txt", 'r', encoding='utf8')

# if f.mode=='r':
#     content=f.read()
#     #print(content)
#     #print("\n\n")

# result = translator.translate(content,src='ja', dest='en')

# with open('translate.txt', 'w') as f:
#     f.write(result.text)

string="""
こんにちは元気ですか
"""
result = translatorG.translate(string, src='ja',dest='en')
print(result.text)

