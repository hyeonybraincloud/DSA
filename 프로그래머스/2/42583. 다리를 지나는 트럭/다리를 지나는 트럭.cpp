#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;          // 다리 위 트럭을 관리하는 큐
    int time = 0;               // 총 소요 시간
    int total_weight = 0;       // 현재 다리 위 트럭들의 총 무게
    
    for (int i = 0 ; i < bridge_length; i++)
        bridge.push(0);         // 초기 다리는 비어 있음
    
    int index = 0;              // 다음에 다리에 올라갈 트럭의 인덱스
    while (index < truck_weights.size() || total_weight > 0) {
        time++;
        
        // 다리에서 트럭이 나옴(맨 앞 요소 제거)
        total_weight -= bridge.front();
        bridge.pop();
        
        // 새로운 트럭을 다리에 올릴 수 있는지 확인
        if (index < truck_weights.size() && total_weight + truck_weights[index] <= weight) {
            bridge.push(truck_weights[index]);
            total_weight += truck_weights[index];
            index++;
        }
        else
            bridge.push(0);
    }
    
    return time;
}