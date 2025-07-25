import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

# 방향: 서, 북, 동, 남
dr = [0, -1, 0, 1]
dc = [-1, 0, 1, 0]

def dfs(r, c, id):
    """(r,c)에서 출발해 id번 방으로 표시하고, 방 크기(칸 수)를 재귀로 계산해 반환."""
    room_id[r][c] = id
    cnt = 1
    w = wall[r][c]
    for d in range(4):
        # 해당 방향에 벽이 있으면 건너뛴다
        if w & (1 << d):
            continue
        nr, nc = r + dr[d], c + dc[d]
        if 0 <= nr < N and 0 <= nc < M and room_id[nr][nc] == 0:
            cnt += dfs(nr, nc, id)
    return cnt

# 입력
M, N = map(int, input().split())
wall = [list(map(int, input().split())) for _ in range(N)]

# 방문 및 방 번호 기록
room_id = [[0]*M for _ in range(N)]
# 방 크기 저장 (1-based indexing 위해 앞에 더미 넣음)
room_size = [0]

# 1) 방 탐색: 모든 칸에 대해 아직 안 간 방이면 새 id로 dfs
id = 0
for i in range(N):
    for j in range(M):
        if room_id[i][j] == 0:
            id += 1
            room_size.append(dfs(i, j, id))

# 2) 방 개수, 가장 큰 방 크기
num_rooms = id
max_room = max(room_size)

# 3) 한 개 벽을 제거했을 때 얻을 수 있는 최대 방 크기
max_combined = 0
for i in range(N):
    for j in range(M):
        cur = room_id[i][j]
        w = wall[i][j]
        for d in range(4):
            # 해당 방향에 벽이 있을 때만
            if w & (1 << d):
                ni, nj = i + dr[d], j + dc[d]
                if 0 <= ni < N and 0 <= nj < M:
                    other = room_id[ni][nj]
                    if other != cur:
                        combined = room_size[cur] + room_size[other]
                        if combined > max_combined:
                            max_combined = combined

# 출력
print(num_rooms)
print(max_room)
print(max_combined)
