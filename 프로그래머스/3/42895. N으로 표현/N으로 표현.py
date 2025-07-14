def solution(N, number):
    # dp[i]: set of numbers expressible with i uses of N
    dp = [set() for _ in range(9)]
    # Pre-fill concatenations: N, NN, NNN, ...
    for i in range(1, 9):
        dp[i].add(int(str(N) * i))

    # Build DP
    for i in range(1, 9):
        # Check if target achievable by concatenation alone
        if number in dp[i]:
            return i
        # Combine smaller counts
        for j in range(1, i):
            for op1 in dp[j]:
                for op2 in dp[i - j]:
                    dp[i].add(op1 + op2)
                    dp[i].add(op1 - op2)
                    dp[i].add(op2 - op1)
                    dp[i].add(op1 * op2)
                    if op2 != 0:
                        dp[i].add(op1 // op2)
                    if op1 != 0:
                        dp[i].add(op2 // op1)
        # After combining, check if target achievable
        if number in dp[i]:
            return i
    return -1