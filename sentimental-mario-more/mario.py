# TODO


# Prompt user for height

while True:
    n = int(input("Height: "))
    if n >= 1 and n <= 8:
        break

for i in range(n):
    print(" " * (n-i-1), end="")
    print("#" * (i+1), end="")
    print("  ", end="")
    print("#" * (i+1), end="")
    print()
