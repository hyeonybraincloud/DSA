#include <vector>
#include <climits>
using namespace std;

vector<int> minTime;

void dfs(int current, int time, int K, const vector<vector<int>>& road) {
    if (time > K || time >= minTime[current]) return;

    minTime[current] = time;

    for (const auto& r : road) {
        int a = r[0], b = r[1], cost = r[2];
        if (a == current) {
            dfs(b, time + cost, K, road);
        } else if (b == current) {
            dfs(a, time + cost, K, road);
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    minTime.assign(N + 1, INT_MAX); // 1번 마을부터 시작하므로 N+1

    dfs(1, 0, K, road); // 1번 마을에서 시작

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (minTime[i] <= K) ++answer;
    }
    return answer;
}
