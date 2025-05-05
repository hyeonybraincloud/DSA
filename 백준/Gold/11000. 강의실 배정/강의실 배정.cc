#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> lectures(N);
    for (int idx = 0; idx < N; idx++)
        cin >> lectures[idx].first >> lectures[idx].second;
    
    sort(lectures.begin(), lectures.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int idx = 0; idx < N; idx++) {
        int start = lectures[idx].first;
        int end = lectures[idx].second;
        
        if (!pq.empty() && pq.top() <= start)
            pq.pop();

        pq.push(end);
    }
    
    cout << pq.size() << endl;
        
    return 0;
}