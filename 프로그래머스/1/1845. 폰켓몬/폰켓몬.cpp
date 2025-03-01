#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> unique_pokemon(nums.begin(), nums.end()); // 포켓몬 종류를 Hash Set에 저장
    int max_types = unique_pokemon.size(); // 포켓몬의 고유한 종류 개수
    int max_picks = nums.size() / 2; // 선택할 수 있는 포켓몬 개수 (N/2)
    
    return min(max_types, max_picks); // 최대한 많은 종류를 선택하는 경우
}
