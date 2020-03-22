inp = input("Введите строку: ")
if inp[len(inp)-1]=='.' :
    string = inp[0:len(inp)-1]
    print("Длина строки: ", len(string))
    words = string.split()
    print("Количество слов: ", len(words))
    maxL = 0
    minL = len(string)
    for word in words :
        if len(word) > maxL :
            maxL = len(word)
        elif len(word) < minL :
            minL = len(word)
    print("Максимальная длина слова: ", maxL)
    print("Минимальная длина слова: ", minL)
    string = string.replace('*', '')
    str2 = ""
    for sym in string :
        str2 += sym*2
    print("Строка после форматирования: ", str2)
else :
    print("Некорректная строка")
