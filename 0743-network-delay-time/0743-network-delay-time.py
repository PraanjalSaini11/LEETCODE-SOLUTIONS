import heapq
from collections import defaultdict
from typing import List

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        g = defaultdict(list)
        for u, v, w in times:
            g[u].append((v, w))

        dist = {}
        pq = [(0, k)]
        while pq:
            d, u = heapq.heappop(pq)
            if u in dist:                 # already finalized with a shorter time
                continue
            dist[u] = d
            for v, w in g[u]:
                if v not in dist:
                    heapq.heappush(pq, (d + w, v))

        return max(dist.values()) if len(dist) == n else -1