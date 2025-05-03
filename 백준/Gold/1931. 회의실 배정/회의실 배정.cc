#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의 정보를 저장할 구조체
struct Meeting {
    int start, end;
};

// 종료 시간 기준 오름차순 정렬
bool cmp(Meeting a, Meeting b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);

    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    // 종료 시간 기준으로 정렬
    sort(meetings.begin(), meetings.end(), cmp);

    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < N; ++i) {
        if (meetings[i].start >= last_end_time) {
            last_end_time = meetings[i].end;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
