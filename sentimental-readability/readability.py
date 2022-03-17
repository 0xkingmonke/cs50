# TODO

text = input("Text: ")

sentencecount = 0
charcount = 0
wordcount = 0

for char in text:
    if char == "!" or char == "?" or char == ".":
        # print (char)
        sentencecount += 1
# print(sentencecount)

for char in text:
    if char.isalpha() == True:
        # print (char)
        charcount += 1
# print(charcount)

for char in text:
    if char == " ":
        # print (char)
        wordcount += 1
wordcount += 1
# print(wordcount)

L = charcount * 100 / wordcount
S = sentencecount * 100 / wordcount

index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(int(index)))

