#include <string>
#include <vector>

using namespace std;

void dfs(int node, int n, vector<vector<int>>& computers, vector<bool>& visited) {
    visited[node] = true;
    
    for (int i = 0; i < n; i++) {
        if (computers[node][i] && !visited[i])
            dfs(i, n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, computers, visited);
            answer++;
        }
    }
    
    return answer;
}