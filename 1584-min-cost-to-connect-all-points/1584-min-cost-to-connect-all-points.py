from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        dist = [float('inf')] * n         # cheapest cost to attach each point
        dist[0] = 0
        visited = [False] * n
        total = 0

        for _ in range(n):
            u = min((i for i in range(n) if not visited[i]), key=lambda i: dist[i])
            visited[u] = True
            total += dist[u]
            for v in range(n):
                if not visited[v]:
                    cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
                    dist[v] = min(dist[v], cost)
        return total