def dijkstra(graph, start):
  """
  Dijkstra's algorithm for finding the shortest paths from a single source node to all other nodes in a graph.

  Args:
    graph: A graph represented as a dictionary of dictionaries. The keys of the outer dictionary are the nodes in the graph, and the values are dictionaries that map to the neighbors of each node. The values in these inner dictionaries are the weights of the edges between the nodes.
    start: The node to start the search from.

  Returns:
    A dictionary that maps from each node to its shortest distance from the start node.
  """

  # Initialize the distance table.
  distances = {}
  for node in graph:
    distances[node] = float("inf")
  distances[start] = 0

  # Initialize the set of unvisited nodes.
  unvisited = set(graph.keys())

  # While there are still unvisited nodes:
  while unvisited:

    # Find the node with the shortest distance in the unvisited set.
    current_node = min(unvisited, key=lambda node: distances[node])

    # Remove the current node from the unvisited set.
    unvisited.remove(current_node)

    # Update the distances to all of the neighbors of the current node.
    for neighbor in graph[current_node]:
      new_distance = distances[current_node] + graph[current_node][neighbor]
      if new_distance < distances[neighbor]:
        distances[neighbor] = new_distance

  # Return the distance table.
  return distances