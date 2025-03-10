#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a, b;   // a: 노란색 격자 총 가로 길이, b: 노란색 격자 총 세로 길이
    
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0 && (2 * (i + yellow/i) + 4 == brown)) {
            a = i;
            b = yellow / i;
            break;
        }
    }
    
    if (a < b) swap(a, b);
            
    answer.push_back(a+2);
    answer.push_back(b+2);
    
    return answer;
}