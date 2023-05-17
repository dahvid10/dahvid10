def dijkstra(graph, start):
    """
    Find the shortest path from a given start node to all other nodes in the graph using Dijkstra's algorithm.
    """
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    heap = [(0, start)]
    while heap:
        (dist, current_node) = heapq.heappop(heap)
        if dist > distances[current_node]:
            continue
        for neighbor, weight in graph[current_node].items():
            distance = dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(heap, (distance, neighbor))
    return distances

