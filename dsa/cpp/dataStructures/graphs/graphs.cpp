#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>

using namespace std;

class graph {
    // direction: undirected^, directed
    // weight: unweighted^, weighted

    // representation: adjacency list^, adjacency matrix
    // adjacency list: map^, linkedlist

    // modify: add^, remove^
    // traversal: breadth-first^, depth-first^

    // search: breadth-first, depth-first, dijkstra


    // create map: key=vertices, value=vector of adjacent vertices
    map<string, vector<string>> adjList;
    public:
        // create adjacency list with map
        void createMap() {
            adjList["A"] = {"B", "C", "F"};
            adjList["B"] = {"A", "D", "E"};
            adjList["C"] = {"A", "D", "E"};
            adjList["D"] = {"B", "C", "F"};
            adjList["E"] = {"B", "C", "F"};
            adjList["F"] = {"A", "D", "E"};
        }
        
        // print all edges
        void printEdges() {
            cout << "Edges for each vertex" << endl;
            for (auto & v : adjList) {
                cout << "\nEdges for " << v.first << ": ";
                for (auto e : v.second) {
                    cout << " | " << v.first << "-" << e << " | ";
                }
            }
        }

        // add edge
        void addEdge(string start, string dest) {
            // add start and dest nodes to graph if necessary
            if (adjList.find(start) == adjList.end()) {
                adjList.insert({start, {}});
            }
            if (adjList.find(dest) == adjList.end()) {
                adjList.insert({dest, {}});
            }

            // if edge not in graph, add it to graph
            if (find(adjList[start].begin(), adjList[start].end(), dest) == adjList[start].end()) {
                adjList[start].push_back(dest);
            }
            if (find(adjList[dest].begin(), adjList[dest].end(), start) == adjList[dest].end())
            {
                adjList[dest].push_back(start);
            }
        }

        // remove edge
        void removeEdge(string start, string dest) {
            // remove edge from graph if available
            if(
                // if both nodes are available
                adjList.find(start) != adjList.end()
                && adjList.find(dest) != adjList.end()
            ) {
                // remove edge if available
                adjList[start].erase(remove(adjList[start].begin(), adjList[start].end(), dest), adjList[start].end());
                
                adjList[dest].erase(remove(adjList[dest].begin(), adjList[dest].end(), start), adjList[dest].end());
            }
        }

        // bft
        void bft(string start)
        {
            // map to check visited nodes
            // path
            // queue
            // while q not empty
                // get node from queue
                // for all neighbors
                    // if not visited
                        // add to queue
                        // set as visited


            cout << "\n\nBreadth-first traversal from " << start << endl;

            map<string, bool> visited_map;
            for (auto node : adjList)
            {
                if (node.first == start)
                {
                    visited_map[node.first] = true;
                }
                else
                {
                    visited_map[node.first] = false;
                }
            }

            vector<string> path;
            queue<string> q;
            q.push(start);

            while (q.empty() == false)
            {
                string cur = q.front();
                q.pop();
                path.push_back(cur);
                for (auto neighbor : adjList[cur])
                {
                    if (visited_map[neighbor] == false)
                    {
                        visited_map[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            for (auto node : path) {
                cout << node << " ";
            }
        }

        // dft
        tuple<vector<string>, map<string, bool>> dft_helper(string start, map<string, bool> visited_map, stack<string> s, vector<string> path)
        {
            // add start node to path
            // if stack not empty
                // get top node
                // set as visited
                // for all neighbors
                    // if not visited
                        // add to stack
                        // recursive call with neighbor as start
            // pop stack
            // return path and visited map

            path.push_back(start);
            if (s.empty() == false) {
                string cur = s.top();
                visited_map[cur] = true;
                for (auto neighbor : adjList[cur]) {
                    if (visited_map[neighbor] == false) {
                        s.push(neighbor);
                        tie(path, visited_map) = dft_helper(neighbor, visited_map, s, path);
                    }
                }
            }
            s.pop();
            return {path, visited_map};
        }

        void dft(string start) {
            // map for visited nodes
            // vector for path
            // stack for traversal

            // verify start node in graph
            // add start to stack
            // set path and visited map to initial call of helper fn (begin dft)

            cout << "\n\nDepth-first traversal from " << start << endl;

            map<string, bool> visited_map;
            vector<string> path;
            stack<string> s;

            for (auto node : adjList) {
                visited_map[node.first] = false;
            }

            map<string, bool>::iterator visited_it;
            visited_it = visited_map.find(start);
            if (visited_it == visited_map.end()) {
                cout << "Start node, " << start << ", not in graph!" << endl;
                return;
            }

            s.push(start);

            tie(path, visited_map) = dft_helper(start, visited_map, s, path);

            for (auto node : path) {
                cout << node << " ";
            }
        }

        void bfs(string start, string dest) {
            // verify start and dest in graph
            
            // map for visited nodes
            // vector for path
            // bool for found
            // queue for traversal

            // add start to queue
            // set start as visited

            // if start == dest
                // found = true
                // add start to path

            // while queue not empty and dest not found
                // get node from queue
                // add node to path
                // if node == dest
                    // found = true
                    // break
                // for each neighbor of node
                    // if neighbor not visited
                        // set neighbor as visited
                        // add neighbor to queue

            // print nodes in path

            cout << "\n\nBreadth-first search from " << start << " to " << dest << endl;

            map<string, vector<string>>::iterator start_it;
            map<string, vector<string>>::iterator dest_it;

            start_it = adjList.find(start);
            dest_it = adjList.find(dest);
            if(start_it == adjList.end()) {
                cout << "Start node, " << start << ", not in graph!" << endl;
            } else if (dest_it == adjList.end()) {
                cout << "Destination node, " << dest << ", not in graph!" << endl;
            }

            map<string, bool> visited_map;
            vector<string> path;
            bool found = false;
            queue<string> q;

            for (auto node : adjList) {
                visited_map[node.first] = false;
            }
            visited_map[start] = true;
            q.push(start);

            if(start == dest) {
                path.push_back(start);
                found = true;
            }

            while ((q.empty() == false) && (found == false)) {
                string cur = q.front();
                q.pop();
                path.push_back(cur);

                if (cur == dest) {
                    found = true;
                    break;
                }

                for (auto neighbor : adjList[cur]) {
                    if (visited_map[neighbor] == false) {
                        visited_map[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            for (auto node : path) {
                cout << node << " ";
            }
        }

        
        tuple<vector<string>, map<string, bool>, bool> dfs_helper(string start, string dest, map<string, bool> visited_map, vector<string> path, stack<string> s, bool found) {

            // if stack not empty and dest not found
                // get top node
                // set top node as visited
                // add start to path
                // if start == dest
                    // set found as true
                    // return path, visited_map, and found
                // for neighbors of top node
                    // if neighbor not visited
                        // add neighbor to stack
                        // set path, visited map, and found to recursive call with neighbor as start
                    // if dest found
                        // stop searching neighbors
            // pop stack
            // return path, visited map, and found

            if ((s.empty() == false) && (found == false)) {
                string cur = s.top();
                visited_map[cur] = true;
                path.push_back(cur);
                if (start == dest) {
                    found = true;
                    return {path, visited_map, found};
                }
                for (auto neighbor : adjList[cur]) {
                    if (visited_map[neighbor] == false) {
                        s.push(neighbor);
                        tie(path, visited_map, found) = dfs_helper(neighbor, dest, visited_map, path, s, found);
                    }
                    if (found == true) {
                        break;
                    }
                }
            }
            s.pop();
            return {path, visited_map, found};
        }

        void dfs(string start, string dest) {
            // map for visited nodes
            // stack for traversal
            // vector for path 
            // bool for found
            
            // check if start and dest nodes are in graph
            // add start to stack
            // set path and visited map to initial call of helper fn (begin dfs)

            // print path

            cout << "\n\nDepth-first search from " << start << " to " << dest << endl;
            map<string, bool> visited_map;
            stack<string> s;
            vector<string> path;
            bool found = false;

            for (auto node : adjList) {
                visited_map[node.first] = false;
            }

            map<string, bool>::iterator start_it, dest_it;
            start_it = visited_map.find(start);
            dest_it = visited_map.find(dest);

            if (start_it == visited_map.end()) {
                cout << "Start node, " << start << ", not in graph!" << endl;
                return;
            } else if (dest_it == visited_map.end()) {
                cout << "Destination node, " << dest << ", not in graph!" << endl;
                return;
            }

            if (start == dest) {
                path.push_back(start);
            } else {
                s.push(start);
                tie(path, visited_map, found) = dfs_helper(start, dest, visited_map, path, s, found);
            }

            for (auto node : path) {
                cout << node << " ";
            }
        }

        tuple<map<string, int>, map<string, string>> dijkstra_unweighted(string start) {
            // verify start node in graph

            // map for known distances: all infinite except start node(=0)
            // map for previous nodes: all unknown (="")
            // map for visited nodes: all unvisited
            // vector for unvisited nodes: all nodes in graph

            // while unvisited nodes not empty
                // get closest unvisited node
                // visit its neighbors
                    // if new distance < known distance
                        // update neighbors' distance and previous node
                // set node as visited in map and vector
            
            // print distances and previous nodes for each node

            cout << "\n\nDijkstra Algorithm: distances and previous nodes from " << start << endl;

            map<string, vector<string>>::iterator start_it;
            start_it = adjList.find(start);
            map<string, int> known_dist_map;
            map<string, string> prev_nodes_map;
            map<string, bool> visited_map;
            vector<string> unvisited_vector;
            const int INF = numeric_limits<int>::max();

            if (start_it == adjList.end()) {
                cout << "Start node, " << start << ", not in graph!" << endl;
                return {known_dist_map, prev_nodes_map};
            }

            for (auto node : adjList) {
                known_dist_map[node.first] = INF;
                prev_nodes_map[node.first] = "";
                visited_map[node.first] = false;
                unvisited_vector.push_back(node.first);
            }

            known_dist_map[start] = 0;
            int dist = INF, cur_dist;
            string cur;
            while (unvisited_vector.empty() == false) {
                for (auto node : unvisited_vector) {
                    if ((visited_map[node] == false) && (known_dist_map[node] < dist)) {
                        cur = node;
                        cur_dist = known_dist_map[cur];
                    }
                }
                int new_dist = cur_dist + 1;
                for (auto neighbor : adjList[cur]) {
                    if (new_dist < known_dist_map[neighbor]) {
                        known_dist_map[neighbor] = new_dist;
                        prev_nodes_map[neighbor] = cur;
                    }
                }
                visited_map[cur] = true;
                unvisited_vector.erase(remove(unvisited_vector.begin(), unvisited_vector.end(), cur), unvisited_vector.end());
            }

            for (auto node : known_dist_map) {
                cout << node.first << ": " << known_dist_map[node.first] << "\t" << prev_nodes_map[node.first] << endl;
            }

            return {known_dist_map, prev_nodes_map};
        }

        void dijkstra_shortest_path(string start, string dest)
        {
            // verify start and dest nodes in graph
            // if start == dest
                // add start to path
                // add start to stack
            // get known distances and previous nodes from dijkstra algorithm
            // stack for traversal
            // set cur node as dest
            // set previous node as dest's previous node
            // while (cur != start)
                // add current node's previous node to stack
                // set current node as previous node
            // if (cur == start)
                // add cur to stack
            // while (stack not empty)
                // get top node and print it, then pop stack
            
            cout << "\n\nDijkstra's Shortest Path from " << start << " to " << dest << endl;
            map<string, vector<string>>::iterator start_it, dest_it;
            start_it = adjList.find(start);
            dest_it = adjList.find(dest);
            if (start_it == adjList.end()) {
                cout << "Start node, " << start << ", not in graph!" << endl;
                return;
            } else if (dest_it == adjList.end()) {
                cout << "Destination node, " << dest << ", not in graph!" << endl;
                return;
            }
            
            stack<string> s;
            if (start == dest)
            {
                cout << start << endl;
                return;
            }

            map<string, int> known_dist_map;
            map<string, string> prev_nodes_map;
            tie(known_dist_map, prev_nodes_map) = dijkstra_unweighted(start);

            string cur = dest;
            string prev = prev_nodes_map[cur];
            
            while (cur != start) {
                s.push(cur);
                cur = prev_nodes_map[cur];
            }
            if (cur == start) {
                s.push(cur);
            }
            while (s.empty() == false) {
                string top = s.top();
                cout << top << " ";
                s.pop();
            }
        }
};

int main() {
    graph g;
    g.createMap();
    g.printEdges();
    // g.addEdge("A","Z");
    // g.printEdges();
    // g.removeEdge("A", "Z");
    // g.printEdges();
    g.bft("A");
    g.dft("A");
    g.bfs("D", "C");
    g.dfs("D", "C");
    g.dijkstra_unweighted("A");
    g.dijkstra_shortest_path("D", "C");

    return 0;
}