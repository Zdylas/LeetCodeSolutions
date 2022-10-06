
def solution(N,M,P):
    current_biggest = P[0]
    biggest_difference = 0
    for num in P:
        if current_biggest > num:
            biggest_difference = max(biggest_difference, current_biggest+num)
            if (biggest_difference > M):
                return 0
        else:
            current_biggest = num
    return 1


def main():
  N,M=map(int,input().split())
  P=list(map(int,input().split()))
  print(solution(N,M,P))
  

if __name__ == '__main__':
  main()
