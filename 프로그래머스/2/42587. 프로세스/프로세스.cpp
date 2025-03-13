#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> processQueue;     // 프로세스 큐 (index, priority)
    priority_queue<int> priorityQueue;      // 우선순위 큐 (높은 우선순위부터 실행)
    
    for (int i = 0; i < priorities.size(); i++) {
        processQueue.push({i, priorities[i]});
        priorityQueue.push(priorities[i]);
    }
    
    int order = 0;      // 실행 순서
    
    while (!processQueue.empty()) {
        int idx = processQueue.front().first;
        int priority = processQueue.front().second;
        processQueue.pop();
        
        // 현재 프로세스가 현재 가장 높은 우선순위인지 확인
        if (priority == priorityQueue.top()) {
            priorityQueue.pop();
            order++;
            
            // 찾고자 하는 위치의 프로세스가 실행되었다면 반환
            if (idx == location)
                return order;
        }       
        else
            processQueue.push({idx, priority});
    }
    
    return -1;
}