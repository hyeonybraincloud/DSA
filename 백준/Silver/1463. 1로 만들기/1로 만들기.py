def make_one(n):
    # 0으로 모두 초기화했으니 dp[1]=0 은 따로 지정할 필요 없음
    dp = [0] * (n + 1)

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