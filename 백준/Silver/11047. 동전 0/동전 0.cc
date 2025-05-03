#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> coins(N);
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    int count = 0;

    // 큰 동전부터 사용하기 위해 뒤에서부터 탐색
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0)
            break;
        
        if (coins[i] <= K) {
            count += K / coins[i];   // 해당 동전을 최대 몇 개 쓸 수 있는지
            K %= coins[i];           // 남은 금액
        }
    }

    cout << count << endl;
    
    return 0;
}