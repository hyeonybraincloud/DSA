#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer;
    vector<string> strNumbers;
    
    // 1. 숫자를 문자열로 변환
    for (int num : numbers)
        strNumbers.push_back(to_string(num));
    
    // 2. 정렬(XY > YX 기준으로 정렬)
    sort(strNumbers.begin(), strNumbers.end(),
        [](const string& a, const string& b) {
            return a + b > b + a;
        }
    );
    
    // 3. 결과 문자열 생성
    for (const string& num : strNumbers)
        answer += num;
    
    // 4. 가장 큰 수가 "0"으로 시작하면 "0" 반환
    return answer[0] == '0'? "0" : answer;
}