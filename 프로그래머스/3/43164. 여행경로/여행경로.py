from collections import deque

def solution(tickets):
    # dict를 사용해 그래프 구성: 출발지 -> [도착지1, 도착지2, ...]
    graph = {}
    for frm, to in tickets:
        if frm in graph:
            graph[frm].append(to)
        else:
            graph[frm] = [to]
    # 알파벳 순으로 작은 경로부터 탐색하기 위해 역순 정렬
    for frm in graph:
        graph[frm].sort(reverse=True)

    route = []  # 최종 경로를 담을 리스트

    def dfs(airport):
        # 현재 공항에서 출발 가능한 모든 티켓 사용
        # graph에 키가 없으면 get으로 빈 리스트를 리턴(
        while graph.get(airport):
            next_dest = graph[airport].pop()
            dfs(next_dest)
        # 더 이상 사용 가능한 티켓이 없으면 방문 기록에 추가
        route.append(airport)

    # ICN에서 출발
    dfs('ICN')
    # 역추적 방식이므로 뒤집어서 반환
    return route[::-1]