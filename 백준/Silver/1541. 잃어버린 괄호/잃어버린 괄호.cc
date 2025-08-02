#include <iostream>
#include <string>
#include <vector>

using namespace std;

// '+'로 구분된 숫자들을 합산하는 헬퍼 함수 (람다 대신 일반 함수)
int sumPlus(const string &t) {
    int sum = 0, num = 0;
    for (char c : t) {
        if (c == '+') {
            sum += num;
            num = 0;
        } else {
            num = num * 10 + (c - '0');
        }
    }
    sum += num;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // '-'를 기준으로 문자열을 나눕니다.
    vector<string> parts;
    size_t prev = 0, pos;
    while ((pos = s.find('-', prev)) != string::npos) {
        parts.push_back(s.substr(prev, pos - prev));
        prev = pos + 1;
    }
    parts.push_back(s.substr(prev));

    // 첫 번째 부분만 더하고, 이후 부분들은 모두 뺍니다.
    int result = sumPlus(parts[0]);
    for (size_t i = 1; i < parts.size(); ++i) {
        result -= sumPlus(parts[i]);
    }

    cout << result << "\n";
    return 0;
}
