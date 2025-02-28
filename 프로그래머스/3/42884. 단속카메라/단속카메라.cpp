#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 1. 차량의 진출 지점 기준으로 정렬
    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1]; // 진출 지점 기준 정렬
    });

    int cameras = 0;
    int last_camera = -30001; // 카메라가 설치된 마지막 위치 (초기값: 범위 밖)

    // 2. 그리디하게 카메라 배치
    for (const auto& route : routes) {
        int entry = route[0];
        int exit = route[1];

        // 현재 카메라로 해당 차량을 단속할 수 없으면 새로운 카메라 설치
        if (entry > last_camera) {
            cameras++;         // 새로운 카메라 설치
            last_camera = exit; // 해당 차량의 진출 지점에 카메라 설치
        }
    }

    return cameras;
}
