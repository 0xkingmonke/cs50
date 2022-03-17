from csv import reader, DictReader
from sys import argv, exit


def main():

    found = False
    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    database = argv[1]
    sequence = argv[2]

    dbv = []
    # TODO: Read DNA sequence file into a variable
    with open(database, "r") as file:
        dbreader = reader(file)
        for row in dbreader:
            # print (row)
            dbv.append(row)
        # print (dbv)

    with open(database, "r") as file:
        dbdictreader = DictReader(file)
        headers = dbdictreader.fieldnames
        # print(headers)

    with open(sequence, "r") as file:
        sequencetext = reader(file)
        for row in sequencetext:
            temp = row
        sequencetotest = temp[0]

    # print(sequencetotest)

    results = []
    x = 0

    for i in headers:
        # print(i)
        y = longest_match(sequencetotest, i)
        # print (y)
        results.append(y)
        # print(x)
        x += 1

    # print(results)

    del results[0]

    for i in range(len(results)):
        results[i] = str(results[i])
    # print(results)

    for i in range(1, len(dbv), 1):
        if dbv[i][1:] == results:
            print(dbv[i][0])
            found = True

    if found == False:
        print("No Match")

    return
    exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
exit(0)
