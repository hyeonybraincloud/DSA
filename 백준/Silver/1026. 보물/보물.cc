#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    
    for (int idx = 0; idx < N; idx++)
        cin >> A[idx];
    sort(A.begin(), A.end());
    
    for (int idx = 0; idx < N; idx++)
        cin >> B[idx];
    
    int sum = 0;
    for (int idx = 0; idx < N; idx++) {
        auto it = max_element(B.begin(), B.end());
        int index = distance(B.begin(), it);
        
        sum += (A[idx] * B[index]);
        
        B[index] = -1;
    }
    
    cout << sum << endl;
    
    return 0;
}