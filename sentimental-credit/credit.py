# TODO

def main():
    while True:
        try:
            ccnum = int(input("Number: "))
            if ccnum >= 0:
                break
        except ValueError:
            print("Thats not a number or thats a negative number")
            return 1

    ccdigits = len(str(ccnum))

    if ccdigits == 13 or 15 or 16:
        header = getheader(ccnum)
        if checksum(ccnum) == True:
            if header >= 50 and header <= 55:
                print("MASTERCARD\n")
            elif header >= 40 and header <= 49:
                print("VISA\n")
            elif header == 34 or 37:
                print("AMEX\n")
            else:
                print("INVALID\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


def checksum(num):

    digits = len(str(num))
    dblsum = 0
    singlesum = 0
    totalsum = 0

    for i in range(digits - 2, -1, -2):
        # print(i)
        x = int(str(num)[i])
        # print(x)
        if x >= 5 and x <= 9:
            dblsum += 1 + (2 * (x - 5))
        else:
            dblsum += 2 * x

    for j in range(digits - 1, -1, -2):
        # print(j)
        singlesum += int(str(num)[j])

    # print(singlesum)
    # print(dblsum)
    totalsum = singlesum + dblsum
    # print(totalsum)

    if totalsum % 10 == 0:
        return True
    else:
        return False


def getheader(num):
    return int(str(num)[0]+str(num)[1])


main()