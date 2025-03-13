#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());
    int mixCount = 0;

    while (minHeap.size() > 1 && minHeap.top() < K) {
        int first = minHeap.top(); 
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int newScoville = first + (second * 2);
        minHeap.push(newScoville);
        mixCount++;
    }

    return (minHeap.top() >= K) ? mixCount : -1;
}
