#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> seq(K);
    for (int i = 0; i < K; i++)
        cin >> seq[i];
    
    unordered_set<int> plugged;
    int result = 0;
    
    for (int i = 0; i < K; i++) {
        int current = seq[i];
        
        // already plugged
        if (plugged.count(current))
            continue;
        
        if (plugged.size() < N) {
            plugged.insert(current);
            continue;
        }
        
        int farthestIndex = -1;
        int deviceToRemove = -1;
        
        for (int device : plugged) {
            int nextUse = -1;
            
            for (int j = i + 1; j < K; j++) {
                if (seq[j] == device) {
                    nextUse = j;
                    break;
                }
            }
            
            if (nextUse == -1) {
                deviceToRemove = device;
                break;
            }
            
            if (nextUse > farthestIndex) {
                farthestIndex = nextUse;
                deviceToRemove = device;
            }
        }
        
        plugged.erase(deviceToRemove);
        plugged.insert(current);
        result++;
    }
    
    cout << result << endl;
    
    return 0;
}