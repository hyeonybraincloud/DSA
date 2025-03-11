#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int stamina;
    vector<int> order(dungeons.size());
    
    for (int i = 0; i < dungeons.size(); i++)
        order[i] = i;
    
    
    int max_count = 0;
    do {
        int max_tmp = 0;
        stamina = k;
        
        for (int i = 0 ; i < dungeons.size(); i++) {
            if (stamina < dungeons[order[i]][0])
                break;
            else {
                stamina -= dungeons[order[i]][1];
                max_tmp++;
            }
        }
        
        max_count = max(max_count, max_tmp);
    }while (next_permutation(order.begin(), order.end()));
        
    return max_count;
}