def main():
    n = int(input())
    prices = [0] + list(map(int, input().split()))
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        dp[i] = max(prices[j] + dp[i - j] for j in range(1, i + 1))

    print(dp[n])

if __name__ == "__main__":
    main()
