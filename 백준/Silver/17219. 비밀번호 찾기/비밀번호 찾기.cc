#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> password_map;

    for (int i = 0; i < N; ++i) {
        string site, password;
        cin >> site >> password;
        password_map[site] = password;
    }

    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        cout << password_map[query] << '\n';
    }

    return 0;
}
