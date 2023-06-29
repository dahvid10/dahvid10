# create adjacency lists
graph = {
    'A': ['C', 'B', 'D'],
    'B': ['E', 'A', 'F'],
    'C': ['D', 'E', 'A'],
    'D': ['C', 'A', 'E', 'F'],
    'E': ['C', 'D', 'G', 'B'],
    'F': ['D', 'G', 'B'],
    'G': ['F', 'E']
}

directed_graph = {
    'A': ['B'],
    'B': ['D', 'F'],
    'C': ['E', 'A'],
    'D': ['C'],
    'E': ['G'],
    'F': [],
    'G': ['F', 'D']
}

weighted_graph = {
    'A': [('C', 2), ('B', 3), ('D', 6)],
    'B': [('E', 10), ('A', 3), ('F', 4)],
    'C': [('D', 1), ('E', 7), ('A', 2)],
    'D': [('C', 1), ('A', 6), ('E', 11), ('F', 5)],
    'E': [('C', 7), ('D', 11), ('G', 9), ('B', 10)],
    'F': [('D', 5), ('G', 8), ('B', 4)],
    'G': [('F', 8), ('E', 9)]
}

# sort adjacency lists alphabetically


def sort_graph(graph):
    for key in graph.keys():
        graph[key].sort()
    return graph

# REPS
# BFS
def scratch_bfs():
    # pseudocode
    # start with graph, start, target, queue, path, visited_dict
    # set start node in queue, path, and visited in dict
    # set all other nodes as unvisited
    # if target node not in graph, return None
    # repeat while queue is not empty
    # get current node from queue
    # add current node to path
    # if current node is target node
    # return path
    # visit each neighbor of the current node
    # if neighbor is not visited
    # set neighbor as visited
    # add neighbor to queue
    # return None

    def bfs_find(graph, start, target):
        queue, path, visited_dict = [start], [], {}
        for node in graph.keys():
            visited_dict[node] = False
        visited_dict[start] = True
        if target not in graph.keys():
            return None
        while queue:
            cur = queue.pop(0)
            path.append(cur)
            if cur == target:
                return path
            for neighbor in graph[cur]:
                if not visited_dict[neighbor]:
                    visited_dict[neighbor] = True
                    queue.append(neighbor)
        return None

    print(bfs_find(graph, 'A', 'D'))
    return


# DFS
def scratch_dfs():
    # pseudocode
    # start with graph, start node, target node, stack, path, visited_dict
    # set start node in stack and visited in dict
    # set all other nodes as unvisited
    # use helper fn for recursive calls
    # get current node from stack
    # add current node to path
    # if current node is target node return path
    # visit all neighbors of current node
    # if neighbor has not been visited
    # add neighbor to stack
    # set neighbor as visited
    # set path as recursive call to helper fn with neighbor as start node
    # if target visited
    # return path
    # return path
    # return initial call to helper fn

    def dfs_find(graph, start, target):
        stack, path, visited_dict = [start], [], {}
        for node in graph.keys():
            visited_dict[node] = False
        visited_dict[start] = True

        def dfs_helper(graph, start, target, stack, path, visited_dict):
            cur = stack.pop()
            path.append(cur)
            if cur == target:
                return path
            for neighbor in graph[cur]:
                if not visited_dict[neighbor]:
                    stack.append(neighbor)
                    visited_dict[neighbor] = True
                    path = dfs_helper(graph, neighbor, target,
                                      stack, path, visited_dict)
                if visited_dict[target]:
                    return path
            return path
        return dfs_helper(graph, start, target, stack, path, visited_dict)

    # print(dfs_find(graph, 'A', 'F'))
    return


# ALL PATHS
def scratch_all_paths():
    # pseudocode
    # start with graph, start node, target node, path list, paths list, visited dict
    # set all nodes as unvisited in dict
    # use helper fn
    # add start node to path
    # set start node as visited
    # if start node is target node
    # add path to paths
    # else
    # visit each neighbor of start node
    # if neighbor not visited
    # set paths as output of recursive call to helper fn with neighbor as start node
    # remove start node from path
    # set start node as unvisited
    # return paths
    # return initial call to helper fn

    def all_paths(graph, start, target):
        path, paths, visited_dict = [], [], {}
        for node in graph.keys():
            visited_dict[node] = False

        def all_paths_helper(graph, start, target, path, paths, visited_dict):
            path.append(start)
            visited_dict[start] = True
            if start == target:
                paths.append(path.copy())
            else:
                for neighbor in graph[start]:
                    if not visited_dict[neighbor]:
                        paths = all_paths_helper(
                            graph, neighbor, target, path, paths, visited_dict)
            path.pop()
            visited_dict[start] = False
            return paths
        return all_paths_helper(graph, start, target, path, paths, visited_dict)
    print(all_paths(graph, 'A', 'G'))
    return


# Dijkstra's unweighted
def scratch_dijkstra_unweighted():
    # pseudocode
    # start with dicts for distances, previous nodes, visited condition, and list for unvisited nodes
    # set all distances as inf
    # set all previous nodes as None
    # set all nodes as unvisited in dict and list
    # set distance from start node to start node as 0
    # repeat until all nodes are visited
    # get closest unvisited node
    # set distance variable, dist, as inf
    # visit all nodes in graph
    # if node is unvisited and has a distance less than dist
    # set current node variable, cur, as current node
    # set dist as current node's distance
    # set cur as visited
    # remove cur from unvisited list
    # visit each neighbor of cur
    # set new distance variable, new_dist, as dist + 1
    # if neighbor's distance is more than new_dist
    # set neighbor's distance as new_dist
    # set neighbor's previous node as current node
    # return dicts for distances and previous nodes

    def dijkstra_unweighted(graph, start):
        dist_dict, prev_dict, visited_dict, unvisited_list = {}, {}, {}, []
        import math
        inf = math.inf
        for node in graph.keys():
            dist_dict[node] = inf
            prev_dict[node] = None
            visited_dict[node] = False
            unvisited_list.append(node)
        dist_dict[start] = 0
        while unvisited_list:
            dist = inf
            for node in graph.keys():
                if (not visited_dict[node]) and (dist_dict[node] < dist):
                    cur = node
                    dist = dist_dict[node]
            visited_dict[cur] = True
            unvisited_list.remove(cur)
            for neighbor in graph[cur]:
                new_dist = dist + 1
                if dist_dict[neighbor] > new_dist:
                    dist_dict[neighbor] = new_dist
                    prev_dict[neighbor] = cur
        return [dist_dict, prev_dict]

    print(dijkstra_unweighted(graph, 'A'))
    return


# Dijkstra's weighted
def scratch_dijkstra_weighted():
    # pseudocode
    # start with dicts for distances, previuos nodes, visited condition, and list of unvisited nodes
    # set all distances as inf
    # set all previous nodes as None
    # set all nodes as unvisited in dict and list
    # set distance of start node as 0
    # repeat until all nodes are visited
    # set distance variable, dist, as inf
    # get closest, unvisited node: cur
    # visit all unvisited nodes
    # if node's distance is less than dist
    # set dist as node's distance
    # set current node as node
    # set current node as visited in dict and list
    # update distances and previous nodes of current node's neighbors
    # visit each neighbor of current node
    # set new distance variable, new_dist, as dist + neighbor's distance to current node
    # if neighbor's distance from start node is more than new_dist
    # update neighbor's distance
    # update neighbor's previous node
    # return dicts for distances and previous nodes

    def dijkstra_weighted(graph, start):
        dist_dict, prev_dict, visited_dict, unvisited_list = {}, {}, {}, []
        import math
        inf = math.inf
        for node in graph.keys():
            dist_dict[node] = inf
            prev_dict[node] = None
            visited_dict[node] = False
            unvisited_list.append(node)
        dist_dict[start] = 0
        while unvisited_list:
            dist = inf
            for node in unvisited_list:
                if dist_dict[node] < dist:
                    dist = dist_dict[node]
                    cur = node
            visited_dict[cur] = True
            unvisited_list.remove(cur)
            for neighbor in graph[cur]:
                neighbor_node = neighbor[0]
                neighbor_dist = neighbor[1]
                new_dist = dist + neighbor_dist
                if dist_dict[neighbor_node] > new_dist:
                    dist_dict[neighbor_node] = new_dist
                    prev_dict[neighbor_node] = cur
        return [dist_dict, prev_dict]

    print(dijkstra_weighted(weighted_graph, 'A'))
    return
