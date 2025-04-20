#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int dp[41][121][121];

int dfs(int index, int a_trace, int b_trace, const vector<vector<int>>& info, int n, int m)
{
    if (a_trace >= n || b_trace >= m) return INF;
    if (index == info.size()) return a_trace;
    
    int& ret = dp[index][a_trace][b_trace];
    if (ret != -1) return ret;
    
    int a_add = info[index][0];
    int b_add = info[index][1];
    
    int choose_A = dfs(index+1, a_trace+a_add, b_trace, info, n, m);
    int choose_B = dfs(index+1, a_trace, b_trace+b_add, info, n, m);
    
    return ret = min(choose_A, choose_B);
}

int solution(vector<vector<int>> info, int n, int m) {
    memset(dp, -1, sizeof(dp));
    int result = dfs(0, 0, 0, info, n, m);
    
    return (result >= INF ? -1 : result);
}