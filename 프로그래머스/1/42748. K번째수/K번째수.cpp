#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(const auto& command : commands) {
        vector<int> tmp;
        
        for (int i = command[0] - 1; i < command[1]; i++) {
            tmp.push_back(array[i]);
        }
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[command[2] - 1]);
    }
    
    return answer;
}