import sys
sys.setrecursionlimit(10000)

def dfs(v, graph, visited):
    visited[v] = True
    for nxt in graph[v]:
        if not visited[nxt]:
            dfs(nxt, graph, visited)


def main():
    input = sys.stdin.readline
    n = int(input().strip())           # 컴퓨터 수
    m = int(input().strip())           # 연결 쌍 수
    graph = {i: [] for i in range(1, n+1)}
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    # 방문 순서를 위한 정렬(필수는 아님)
    for k in graph:
        graph[k].sort()

    visited = [False] * (n+1)
    dfs(1, graph, visited)

    # 1번 컴퓨터를 제외한 감염된 컴퓨터 수
    infected = sum(1 for i in range(2, n+1) if visited[i])
    print(infected)

if __name__ == '__main__':
    main()
