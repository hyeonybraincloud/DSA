#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dictionary; // 모든 가능한 단어를 저장할 벡터
string vowels = "AEIOU";   // 사용할 모음들

// DFS를 이용하여 가능한 단어를 생성하는 함수
void generateWords(string current) {
    if (current.length() > 5) return; // 최대 길이 5까지 제한
    dictionary.push_back(current);    // 현재 단어를 저장

    for (char vowel : vowels) {       // 다음 글자 추가
        generateWords(current + vowel);
    }
}

int solution(string word) {
    generateWords(""); // 빈 문자열부터 시작해서 모든 경우의 수를 탐색
    sort(dictionary.begin(), dictionary.end()); // 사전 순 정렬

    // 해당 단어가 몇 번째인지 찾기
    return find(dictionary.begin(), dictionary.end(), word) - dictionary.begin();
}
