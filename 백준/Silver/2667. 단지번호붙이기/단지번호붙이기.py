from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    # Direction vectors: up, down, left, right
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    visited = [[False] * m for _ in range(n)]
    complexes = []

    for i in range(n):
        for j in range(m):
            if maps[i][j] == 1 and not visited[i][j]:
                # BFS to explore this complex
                q = deque()
                q.append((i, j))
                visited[i][j] = True
                count = 1
                while q:
                    x, y = q.popleft()
                    for k in range(4):
                        nx = x + dx[k]
                        ny = y + dy[k]
                        if 0 <= nx < n and 0 <= ny < m:
                            if maps[nx][ny] == 1 and not visited[nx][ny]:
                                visited[nx][ny] = True
                                q.append((nx, ny))
                                count += 1
                complexes.append(count)

    complexes.sort()
    # Return number of complexes and list of their sizes
    return [len(complexes)] + complexes


def main():
    n = int(input().strip())
    maps = [list(map(int, input().strip())) for _ in range(n)]
    result = solution(maps)
    # Print the results
    print(result[0])
    for size in result[1:]:
        print(size)


if __name__ == "__main__":
    main()