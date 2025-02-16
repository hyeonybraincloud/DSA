#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    
    // 아래에서부터 위로 DP를 수행하여 최대 합을 계산
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    
    // 최상단에 최댓값이 저장됨
    return triangle[0][0];
}
