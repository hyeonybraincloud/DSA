#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hash_map;
    
    for (const auto& item : clothes)
        hash_map[item[1]]++;
    
    for (const auto& pair : hash_map)
        answer *= (pair.second + 1);
    
    return answer - 1;
}