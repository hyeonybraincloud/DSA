#include <iostream>

using namespace std;

int main() {
    int H, W, N, M;
    
    cin >> H >> W >> N >> M;
    
    int rowCount = (H + N) / (N + 1);
    int colCount = (W + M) / (M + 1);

    cout << rowCount * colCount << endl;
}