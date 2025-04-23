#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 조합을 만드는 함수
void dfs(string& order, string comb, int depth, int start, int targetLen, map<string, int>& counter) {
    if (depth == targetLen) {
        counter[comb]++;
        return;
    }
    for (int i = start; i < order.size(); ++i) {
        dfs(order, comb + order[i], depth + 1, i + 1, targetLen, counter);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int len : course) {
        map<string, int> counter;

        // 모든 주문에 대해 길이 len 조합 생성
        for (string& order : orders) {
            sort(order.begin(), order.end()); // 사전순 정렬

            if (order.size() < len) continue;

            dfs(order, "", 0, 0, len, counter);
        }

        // 가장 많이 등장한 조합 찾기 (단, 2번 이상 등장한 것만)
        int maxCount = 0;
        for (auto& it : counter) {
            if (it.second >= 2)
                maxCount = max(maxCount, it.second);
        }

        for (auto& it : counter) {
            if (it.second == maxCount && maxCount >= 2) {
                answer.push_back(it.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}
