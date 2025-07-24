import sys
sys.setrecursionlimit(10**7)

# 방향 벡터 상, 하, 좌, 우
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

# DFS로 연결 요소(빙산 덩어리) 탐색
def dfs(x, y, iceberg_map, visited, n, m):
    visited[x][y] = True
    for dir in range(4):
        nx, ny = x + dx[dir], y + dy[dir]
        if 0 <= nx < n and 0 <= ny < m:
            if iceberg_map[nx][ny] > 0 and not visited[nx][ny]:
                dfs(nx, ny, iceberg_map, visited, n, m)

# 빙산 덩어리 개수 세기
def countIcebergs(iceberg_map, n, m):
    visited = [[False] * m for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(m):
            if iceberg_map[i][j] > 0 and not visited[i][j]:
                dfs(i, j, iceberg_map, visited, n, m)
                count += 1
    return count

# 빙산 녹이기
def melt(iceberg_map, n, m):
    temp = [row[:] for row in iceberg_map]
    for i in range(n):
        for j in range(m):
            if iceberg_map[i][j] > 0:
                sea = 0
                for dir in range(4):
                    nx, ny = i + dx[dir], j + dy[dir]
                    if 0 <= nx < n and 0 <= ny < m and iceberg_map[nx][ny] == 0:
                        sea += 1
                temp[i][j] = max(0, iceberg_map[i][j] - sea)
    return temp

# 메인 함수
def main():
    n, m = map(int, input().split())
    iceberg_map = [list(map(int, input().split())) for _ in range(n)]
    year = 0

    while True:
        cnt = countIcebergs(iceberg_map, n, m)
        if cnt == 0:
            print(0)
            return
        if cnt >= 2:
            print(year)
            return
        iceberg_map = melt(iceberg_map, n, m)
        year += 1

if __name__ == "__main__":
    main()
