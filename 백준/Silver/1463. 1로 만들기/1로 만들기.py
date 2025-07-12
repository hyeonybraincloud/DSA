def make_one(n):
    # dp[i] = i를 1로 만드는 최소 연산 횟수
    dp = [0] * (n + 1)
    dp[1] = 0

    for i in range(2, n + 1):
        # 1 빼기
        dp[i] = dp[i - 1] + 1
        # 2로 나누기
        if i % 2 == 0:
            dp[i] = min(dp[i], dp[i // 2] + 1)
        # 3으로 나누기
        if i % 3 == 0:
            dp[i] = min(dp[i], dp[i // 3] + 1)

    return dp[n]

if __name__ == "__main__":
    N = int(input())
    print(make_one(N))