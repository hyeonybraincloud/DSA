#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool finished = false;

void dfs(string current, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& path, int depth) {
    if (depth == tickets.size()) {
        answer = path;
        finished = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == current) {
            used[i] = true;
            path.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, used, path, depth + 1);
            if (finished) return; // 정답 찾았으면 바로 return
            used[i] = false;
            path.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); // 알파벳 순서 우선 탐색을 위해 미리 정렬

    vector<bool> used(tickets.size(), false);
    vector<string> path;
    path.push_back("ICN"); // 시작 공항

    dfs("ICN", tickets, used, path, 0);

    return answer;
}
