#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash_map;
    
    for (const auto& number : phone_book)
        hash_map[number] = 1;
    
    for (const auto& number : phone_book) {
        string prefix = "";
        
        for (char ch : number) {
            prefix += ch;
            if (prefix != number && hash_map.find(prefix) != hash_map.end())
                return false;
        }
    }
    
    return true;
}