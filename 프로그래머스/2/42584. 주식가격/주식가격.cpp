#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> s;
    
    for (int i = 0 ; i < n; i++) {
        while (!s.empty() && prices[i] < prices[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx;
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        int idx = s.top();
        s.pop();
        answer[idx] = n - 1 - idx;
    }
    
    return answer;
}