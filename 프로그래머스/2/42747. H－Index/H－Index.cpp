#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int h = 0;
    
    sort(citations.begin(), citations.end(),
    [](int a, int b) {
        return a > b;
    });
        
    for (int i = 0 ; i < citations.size(); i++) {
        if (citations[i] >= i+1)
            h = i+1;
        else
            break;
    }
    
    return h;
}