#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0, max_h = 0;
    
    for (auto& size : sizes) {
        int w = size[0];
        int h = size[1];
        
        // 가로 길이를 항상 큰 값으로 정렬
        if (w < h) swap(w, h);
        
        // 최대 가로, 최대 세로 길이 갱신
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }
    
    return max_w * max_h;
}