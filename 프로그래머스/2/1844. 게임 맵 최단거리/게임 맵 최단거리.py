from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    # BFS를 위한 큐
    q = deque()
    q.append((0, 0))

    # 거리 기록 배열 (초기값: -1)
    distance = [[-1] * m for _ in range(n)]
    distance[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위 내 & 방문하지 않았고 & 길이 열려있을 경우
            if 0 <= nx < n and 0 <= ny < m:
                if distance[nx][ny] == -1 and maps[nx][ny] == 1:
                    distance[nx][ny] = distance[x][y] + 1
                    q.append((nx, ny))

    return distance[n - 1][m - 1]
