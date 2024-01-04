import math
INF = math.inf

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
    return

# single path

# BFS (A-G)
# fn: visit all nodes breadth-first
def bfs_traversal(graph, start):
    # create queue and visited lists
    queue = [start]
    visited = [start]
    # while queue is not empty
    while queue:
        # pop queue to get current node
        cur = queue.pop(0)
        print(cur)
        graph[cur].sort()
        # add neighbors of current node to visited and queue lists if they have not been visited
        for neighbor in graph[cur]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.append(neighbor)
    return visited

def scratch_bfs_traversal():
    # bfs = bfs_traversal(graph, 'A')
    # print(bfs)
    # bfs = bfs_traversal(directed_graph, 'A')
    # print(bfs)
    return

# fn: find target node using BFS
def bfs_find(graph, start, target):
    # initialize queue and path lists
    queue = [start]
    path = []
    # while queue not empty
    while queue:
        # pop to get current node
        cur = queue.pop(0)
        print(cur)
        graph[cur].sort()
        path.append(cur)
        # return visited path if current node is target node
        if cur == target:
            return path
        # add neighbors of current node to queue if they have not been visited
        for neighbor in graph[cur]:
            if neighbor not in path:
                queue.append(neighbor)
    return path

def scratch_bfs_find():
    # bfs = bfs_find(graph, 'A', 'F')
    # print(bfs)
    # bfs = bfs_find(directed_graph, 'A', 'F')
    # print(bfs)
    return

def dfs_pseudocode():
    # DFS (A-G)

    # s1: 
    #     add start node to stack
    #     next c1

    # c1:
    #     stack has nodes
    #     0: return visited list
    #     1: s2

    # s2:
    #     get current node from stack
    #     add current node to visited list
    #     next: c2

    # c2:
    #     current node has unvisited neighbors
    #     0: c1
    #     1: s3

    # s3:
    #     add one of current node's unvisited neighbors to stack
    #     next: s4

    # s4:
    #     add current node to stack and visited list
    #     next: c2
    return

# fn: visit all nodes depth-first
def dfs_traversal(graph, start):
    # initialize stack and visited lists
    stack, visited = [start], []
    # helper fn: recursively traverse
    def dfs_helper(graph, start, visited, stack):
        # if stack not empty
        if stack:
            cur = stack[-1]
            if cur not in visited:
                visited += [cur]
            for neighbor in graph[cur]:
                if neighbor not in visited:
                    stack += [neighbor]
                    visited = dfs_helper(graph, neighbor, visited, stack)
            stack.pop()
        return visited
    return dfs_helper(graph, start, visited, stack)

def scratch_dfs_traversal():
    # dfs = dfs_traversal(graph, 'A')
    # print(dfs)
    # dfs = dfs_traversal(directed_graph, 'A')
    # print(dfs)
    
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }

    # stack = [A]
    # visited = []
    # ------------------
    # cur = A
    # stack = [A, C]
    # visited = [A]
    # ------------------
    # cur = C
    # stack = [A, C, D]
    # visited = [A, C]
    # ------------------
    # cur = D
    # stack = [A, C, D, E]
    # visited = [A, C, D]
    # ------------------
    # cur = E
    # stack = [A, C, D, E, G]
    # visited = [A, C, D, E]
    # ------------------
    # cur = G
    # stack = [A, C, D, E, G, F]
    # visited = [A, C, D, E, G]
    # ------------------
    # cur = F
    # stack = [A, C, D, E, G, F, B]
    # visited = [A, C, D, E, G, F]
    # ------------------
    # cur = B
    # stack = [A, C, D, E, G, F]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = F
    # stack = [A, C, D, E, G]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = G
    # stack = [A, C, D, E]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = E
    # stack = [A, C, D]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = D
    # stack = [A, C]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = C
    # stack = [A]
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    # cur = A
    # stack = []
    # visited = [A, C, D, E, G, F, B]
    # ------------------
    return

# fn: find target node with DFS
def dfs_find(graph, start, target):
    # initialize stack and visited lists
    stack, visited = [start], []
    # helper fn: traverse graph w/ DFS
    def dfs_helper(graph, target, stack, visited):
        # set current node
        cur = stack[-1]
        # add current node to visited list
        if cur not in visited:
            visited += [cur]
        # if current node is target node return visited list
        if (cur == target):
            return visited
        # check neighbors of current node for next unvisited node
        for neighbor in graph[cur]:
            if target in visited:
                break
            if (neighbor not in visited):
                stack += [neighbor]
                visited = dfs_helper(graph, target, stack, visited)
        stack.pop()
        # return visited list
        return visited
    return dfs_helper(graph, target, stack, visited)

def scratch_dfs_find():
    # dfs = dfs_find(graph, 'A', 'G')
    # print(dfs)
    # dfs = dfs_find(directed_graph, 'A', 'G')
    # print(dfs)

    # graph = {
    #         'A': ['C', 'B', 'D'],
    #         'B': ['E', 'A', 'F'],
    #         'C': ['D', 'E', 'A'],
    #         'D': ['C', 'A', 'E', 'F'],
    #         'E': ['C', 'D', 'G', 'B'],
    #         'F': ['D', 'G', 'B'],
    #         'G': ['F', 'E']
    #     }

    # target = 'G'
    # stack = ['A']
    # visited = []
    # ---------------
    # target = 'G'
    # cur = 'A'
    # stack = ['A', 'C']
    # visited = ['A']
    # ------------------------
    # target = 'G'
    # cur = 'C'
    # stack = ['A', 'C', 'D']
    # visited = ['A', 'C']
    # ------------------------
    # target = 'G'
    # cur = 'D'
    # stack = ['A', 'C', 'D', 'E']
    # visited = ['A', 'C', 'D']
    # ------------------------
    # target = 'G'
    # cur = 'E'
    # stack = ['A', 'C', 'D', 'E', 'G']
    # visited = ['A', 'C', 'D', 'E']
    # ------------------------
    # target = 'G'
    # cur = 'G'
    # stack = ['A', 'C', 'D', 'E', 'G']
    # visited = ['A', 'C', 'D', 'E', 'G']
    # ------------------------
    return

# fn: find all paths from start node to end node
def pseudocode_all_paths():
    # s1:
    #     add start node to path
    #     next: c1
    # c1:
    #     start node is end node
    #     0: c2
    #     1: return path
    # c2:
    #     graph doesn't have start node as key or key has empty array
    #     0: s2
    #     1: return empty array
    # s2:
    #     check all neighbors of start node for unvisited node
    #     next c3
    # c3:
    #     neighbor not in path
    #     0: s2, until all neighbors exhausted, then s3
    #     1: s1 with neighbor as start node, then add all new paths to newpaths array
    return

def all_paths(graph, start, end, path=[], paths=[]):
    visited, paths = {}, []
    for key in graph.keys():
        visited[key] = False
    # fn: helper fn
    def all_paths_helper(graph, start, end, path, visited, paths):
        visited[start] = True
        path += [start]

        if start == end:
            paths += [path.copy()]
        else:
            for neighbor in graph[start]:
                if visited[neighbor] == False:
                    paths = all_paths_helper(graph, neighbor, end, path, visited, paths)
        path.pop()
        visited[start] = False
        return paths
    return all_paths_helper(graph, start, end, path, visited, paths)

def scratch_all_paths():
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'A'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': False,
    #   'D': False,
    #   'E': False,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A']
    # paths = []
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'C'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': False,
    #   'E': False,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C']
    # paths = []
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'D'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': False,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C', 'D']
    # paths = []
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'E'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'E']
    # paths = []
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'G'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': False,
    #   'G': True
    # }
    # path = ['A', 'C', 'D', 'E', 'G']
    # paths = [['A', 'C', 'D', 'E', 'G'], ]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'B'
    # visited = {
    #   'A': True,
    #   'B': True,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'E', 'B']
    # paths = [['A', 'C', 'D', 'E', 'G'], ]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'F'
    # visited = {
    #   'A': True,
    #   'B': True,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': True,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'E', 'B', 'F']
    # paths = [['A', 'C', 'D', 'E', 'G'], ]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'G'
    # visited = {
    #   'A': True,
    #   'B': True,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': True,
    #   'G': True
    # }
    # path = ['A', 'C', 'D', 'E', 'B', 'F', 'G']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G']]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'F'
    # visited = {
    #   'A': True,
    #   'B': True,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': True,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'E', 'B', 'F']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G']]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'B'
    # visited = {
    #   'A': True,
    #   'B': True,
    #   'C': True,
    #   'D': True,
    #   'E': True,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'E', 'B']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G']]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'D'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': False,
    #   'F': False,
    #   'G': False
    # }
    # path = ['A', 'C', 'D']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G']]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'F'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': False,
    #   'F': True,
    #   'G': False
    # }
    # path = ['A', 'C', 'D', 'F']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G']]
    # --------------------
    # graph = {
    #     'A': ['C', 'B', 'D'],
    #     'B': ['E', 'A', 'F'],
    #     'C': ['D', 'E', 'A'],
    #     'D': ['C', 'A', 'E', 'F'],
    #     'E': ['C', 'D', 'G', 'B'],
    #     'F': ['D', 'G', 'B'],
    #     'G': ['F', 'E']
    # }
    # --------------------
    # start = 'G'
    # visited = {
    #   'A': True,
    #   'B': False,
    #   'C': True,
    #   'D': True,
    #   'E': False,
    #   'F': True,
    #   'G': True
    # }
    # path = ['A', 'C', 'D', 'F', 'G']
    # paths = [['A', 'C', 'D', 'E', 'G'], ['A', 'C', 'D', 'E', 'B', 'F', 'G'], ['A', 'C', 'D', 'F', 'G']]
    # --------------------
    

    return

# fn: shortest path (brute force)
def shortest_path():
    length = 9999999
    shortest_path = []
    paths = all_paths(graph, 'A', 'G')
    for path in paths:
        if len(path) < length:
            length = len(path)
            shortest_path = path
    print('The shortest path traverses', length, 'nodes:', shortest_path)
    return

# Dijkstra's algorithm (shortest path)
# https://www.youtube.com/watch?v=pVfj6mxhdMw

def pseudocode_dijkstra():
    # initialize distance of start node from start node as 0
    # let distance of all other vertices from start be infinity
    # repeat until all vertices visited
        # visit unvisited node with the smallest known distance from the start node
        # for the current node calculate distance of each neighbor from start node
        # if calculated distance of neighbor is less than known distance, update known distance
        # update previous node for each updated distance
        # set current node as visited
    return

def dijkstra_unweighted(graph, start):
    known_dist_dict = {} # initialize dict for known distances
    previous_dict = {} # initialize dict for previous nodes
    visited_dict = {} # intialize dict for visited nodes
    unvisited_list = [] # initialize list for unvisited nodes
    for node in graph.keys():
        known_dist_dict[node] = INF # set all node's distances as infinite
        previous_dict[node] = None # set all previous nodes as None
        visited_dict[node] = False # set all nodes as unvisited
        unvisited_list.append(node) # set all nodes as unvisited
    known_dist_dict[start] = 0 # set distance from start node to start node as 0
    # repeat until all nodes are visited
    while unvisited_list:
        # visit unvisited node with smallest known dist from start node
        dist = INF
        for node in graph.keys():
            if (known_dist_dict[node] < dist) and (visited_dict[node] == False):
                cur = node
                dist = known_dist_dict[node]
        # calculate distance of each neighbor from start node
        calc_dist_dict = {}
        cur_dist = known_dist_dict[cur] + 1
        for neighbor in graph[cur]:
            calc_dist_dict[neighbor] = cur_dist
            # update known distances if they are more than the calculated distances
            if calc_dist_dict[neighbor] < known_dist_dict[neighbor]:
                known_dist_dict[neighbor] = calc_dist_dict[neighbor]
                # update previous node for each updated distance
                previous_dict[neighbor] = cur
        # add current node to list of visited vertices
        visited_dict[cur] = True
        unvisited_list.remove(cur)
    return [known_dist_dict, previous_dict]

def scratch_dijkstra_unweighted():
    dist, previous = dijkstra_unweighted(graph, 'A')
    print(dist)
    print(previous)
    print('--------------------')
    dist, previous = dijkstra_unweighted(directed_graph, 'A')
    print(dist)
    print(previous)
    return

def dijkstra_weighted(weighted_graph, start):
    known_dist_dict = {} # initialize dict for known distances
    previous_dict = {} # initialize dict for previous nodes
    visited_dict = {} # intialize dict for visited nodes
    unvisited_list = [] # initialize list for unvisited nodes
    for node in weighted_graph.keys():
        known_dist_dict[node] = INF # set all node's distances as infinite
        previous_dict[node] = None # set all previous nodes as None
        visited_dict[node] = False # set all nodes as unvisited
        unvisited_list.append(node) # set all nodes as unvisited
    known_dist_dict[start] = 0 # set distance from start node to start node as 0
    # repeat
    cur = start # initalize current node as start node
    known_dist_dict[cur] = 0 # intialize current distance from start node as 0
    while unvisited_list:
    # def dijkstra_helper(graph, start, known_dist_dict, previous_dict, visited_dict, cur_dist):
        # visit unvisited node with smallest known dist from start node
        dist = INF
        for node in weighted_graph.keys():
            if (known_dist_dict[node] < dist) and (visited_dict[node] == False):
                cur = node
                dist = known_dist_dict[node]
        
        for neighbor in weighted_graph[cur]:
            # calculate distance of each neighbor from start node
            neighbor_node = neighbor[0]
            neighbor_distance = neighbor[1]
            new_dist = dist + neighbor_distance
            # update known distances if they are more than the calculated distances
            if new_dist < known_dist_dict[neighbor_node]:
                known_dist_dict[neighbor_node] = new_dist
                # update previous node for each updated distance
                previous_dict[neighbor_node] = cur
        # add current node to list of visited vertices
        visited_dict[cur] = True
        unvisited_list.remove(cur)
    return [known_dist_dict, previous_dict]

def scratch_dijkstra_weighted():
    print('------------------')
    dist, previous = dijkstra_weighted(weighted_graph, 'A')
    print(dist)
    print(previous)
    return
