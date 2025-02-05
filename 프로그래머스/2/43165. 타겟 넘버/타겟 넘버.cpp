#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int target, int index, int current_sum) {
    // 모든 숫자를 다 사용했을 때
    if (index == numbers.size()) {
        return (current_sum == target) ? 1 : 0;
    }
    
    // 현재 숫자를 더하는 경우와 빼는 경우를 탐색
    return dfs(numbers, target, index + 1, current_sum + numbers[index]) + 
           dfs(numbers, target, index + 1, current_sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}
