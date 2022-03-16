# TODO


# Prompt user for height

while True:
    try:
        n = int(input("Height: "))
        if n >= 1 and n <= 8:
            break
    except ValueError:
        print("Thats not an integer")

for i in range(n):
    print(" " * (n-i-1), end="")
    print("#" * (i+1), end="")
    print()
