opened = open("in.txt", "r")
text = opened.read()
print(text)
opened.close()

txtIn = open('in.txt','r')
a = list(txtIn.read().replace('.','').replace(',','').replace('!','').replace('?','').split())

list1=[]
list2=[]

wrdtofind = str(input("\nВведите слово которое нужно проверить: "))
for word in a:
    if word == wrdtofind:
        list1.append(word)

lengthstring = len(list1)

print("Число повторений слова: ", lengthstring)

txtOut = open('out.txt','w')
txtOut.write("Число повторений слова ")
txtOut.write(wrdtofind)
txtOut.write(" : ")
txtOut.write(str(lengthstring))
txtOut.close()
txtIn.close()
