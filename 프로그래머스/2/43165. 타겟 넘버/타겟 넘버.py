def solution(numbers, target):
    answer = [0]  # 리스트는 내부에서 수정 가능

    def dfs(index, current_sum):
        if index == len(numbers):
            if current_sum == target:
                answer[0] += 1
            return
        dfs(index + 1, current_sum + numbers[index])
        dfs(index + 1, current_sum - numbers[index])
    
    dfs(0, 0)
    return answer[0]
