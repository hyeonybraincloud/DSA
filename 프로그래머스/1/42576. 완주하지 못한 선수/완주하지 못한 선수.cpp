#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash_map;
    
    for (const string& p : participant)
        hash_map[p]++;
    
    for (const string& c : completion)
        hash_map[c]--;
    
    for (const auto& pair : hash_map) {
        if (pair.second > 0)
            return pair.first;
    }
}