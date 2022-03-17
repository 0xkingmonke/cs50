# TODO

# get user input
while True:
    try:
        x = float(input("Change owed: "))
        if x > 0:
            break
    except ValueError:
        print("Not a valid number")

# iterate through each denomination and adjust the value accordingly
a = x * 100
b = a // 25
a = a - b * 25
c = a // 10
a = a - c * 10
d = a // 5
a = a - d * 5

e = int(a + b + c + d)

print(e)
