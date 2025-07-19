import sys
from collections import deque

input = sys.stdin.readline

# Read N, M, V
N, M, V = map(int, input().split())

# Build adjacency list
graph = {i: [] for i in range(1, N+1)}
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# Sort neighbors for ascending visit order
for key in graph:
    graph[key].sort()

visited = [False] * (N + 1)

# DFS implementation
def dfs(v):
    visited[v] = True
    sys.stdout.write(str(v) + ' ')
    for nxt in graph[v]:
        if not visited[nxt]:
            dfs(nxt)

# BFS implementation
def bfs(start):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        sys.stdout.write(str(v) + ' ')
        for nxt in graph[v]:
            if not visited[nxt]:
                visited[nxt] = True
                queue.append(nxt)

# Run DFS, reset visited, then BFS
dfs(V)
print()
visited = [False] * (N + 1)
bfs(V)
