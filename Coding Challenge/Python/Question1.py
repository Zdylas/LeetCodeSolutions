def solution(n):
    # Write solution here
    if n % 2 != 0:
        return "SELL"
    if n % 4 == 0:
        return "BUY"
        
    return "PASS"


def main():
    n = int(input())
    print(solution(n))


if __name__ == "__main__":
    main()
