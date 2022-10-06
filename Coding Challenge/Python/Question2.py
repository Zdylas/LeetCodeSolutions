from collections import Counter


def solution(files):
    myCounter = Counter()
    total = 0
    spare = 0
    for char in files:
        myCounter[char] += 1
        if (myCounter[char] & 1):
            spare += 1
        else:
            total += 2
            spare -= 1
    if spare:
        return total + 1
    return total


def main():
    str = input()
    answer = solution(str)
    print(answer)


if __name__ == '__main__':
    main()
