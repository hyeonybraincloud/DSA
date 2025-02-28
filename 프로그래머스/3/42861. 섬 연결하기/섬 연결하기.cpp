#include <vector>
#include <algorithm>

using namespace std;

// 유니온-파인드를 위한 부모 배열
vector<int> parent;

// 부모 노드를 찾는 함수 (Find)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축(Path Compression)
}

// 두 노드를 합치는 함수 (Union)
void unionNodes(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) parent[rootB] = rootA; // 루트 노드를 통합
}

int solution(int n, vector<vector<int>> costs) {
    // 비용 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2]; // 비용을 기준으로 정렬
    });

    // 부모 배열 초기화 (자기 자신을 부모로 설정)
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int totalCost = 0;
    int edgesUsed = 0;

    // 가장 적은 비용부터 간선을 추가 (Kruskal 알고리즘)
    for (const auto& edge : costs) {
        int islandA = edge[0];
        int islandB = edge[1];
        int cost = edge[2];

        if (find(islandA) != find(islandB)) { // 사이클이 발생하지 않도록
            unionNodes(islandA, islandB);
            totalCost += cost;
            edgesUsed++;

            // 최소 신장 트리는 (n-1)개의 간선을 사용하면 완성됨
            if (edgesUsed == n - 1) break;
        }
    }

    return totalCost;
}
