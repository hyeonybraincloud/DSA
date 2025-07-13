def main():
    n = int(input())
    if n == 1:
        print(1)
        return
    # dp[i-2], dp[i-1] 을 두 변수로 관리
    prev2, prev1 = 1, 2  # dp[1]=1, dp[2]=2
    if n == 2:
        print(prev1)
        return
    for i in range(3, n+1):
        curr = (prev1 + prev2) % 10007
        prev2, prev1 = prev1, curr
    print(prev1)

if __name__ == "__main__":
    main()