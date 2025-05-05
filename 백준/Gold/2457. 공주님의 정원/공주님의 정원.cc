#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower {
    int start, end;
};

int toInt(int month, int day) {
    return month * 100 + day;
}

// 람다 대신 비교 함수
bool compare(const Flower &a, const Flower &b) {
    if (a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

int main() {
    int N;
    cin >> N;

    vector<Flower> flowers;

    for (int i = 0; i < N; ++i) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        int start = toInt(sm, sd);
        int end = toInt(em, ed);
        if (end <= 301 || start >= 1201) continue; // 범위 밖은 제외
        flowers.push_back({start, end});
    }

    sort(flowers.begin(), flowers.end(), compare);  // ✅ 여기!

    int count = 0;
    int idx = 0;
    int current = 301;
    int max_end = 0;

    while (current < 1201) {
        bool found = false;
        while (idx < flowers.size() && flowers[idx].start <= current) {
            if (flowers[idx].end > max_end) {
                max_end = flowers[idx].end;
                found = true;
            }
            ++idx;
        }
        if (!found) {
            cout << 0 << '\n';
            return 0;
        }
        current = max_end;
        ++count;
    }

    cout << count << '\n';
    return 0;
}
