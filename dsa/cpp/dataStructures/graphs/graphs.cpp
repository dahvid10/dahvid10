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
            cout << endl << endl;
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
        void bft(string start) {
            // initialize queue and visited vector with start node
            // traverse graph while queue is not empty (until all nodes visited)
                // get next node in queue
                // add neighbors of current node to visited vector and queue if they have not been visited
            cout << "Breadth First Traversal" << endl;
            queue<string> q;
            vector<string> visited;
            q.push(start);
            visited.push_back(start);
            
            while (q.empty() != true) {
                string cur = q.front();
                q.pop();
                cout << cur << " ";
                for (string neighbor : adjList[cur]) {
                    if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.push_back(neighbor);
                    }
                }
            }
            cout << endl << endl;
        }

        // dft
        vector<string> dft_helper(string start, vector<string> visited, stack<string> s)
        {
            if (s.empty() != true) {
                string cur = s.top();
                
                if(find(visited.begin(), visited.end(), cur) == visited.end()) {
                    visited.push_back(cur);
                }

                for (auto neighbor : adjList[cur]) {
                    if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                        s.push(neighbor);
                        visited = dft_helper(neighbor, visited, s);
                    }
                }

                s.pop();
            }
            return visited;
        }

        void dft(string start) {
            // initialize stack (with start node) and visited vector (empty)
            // use helper fn for recursive traversal
                // if stack not empty
                    // get current node from stack
                    // if current node hasn't been visited add it to visited vector
                    // if neighbors haven't been visited
                        // add neighbors of current node to stack 
                        // update visited vector with recursive call
                    // pop stack
                // return visited vector
            // update visited vector with call to helper fn
            cout << "Depth First Traversal" << endl;

            stack<string> s;
            s.push(start);
            vector<string> visited;
            
            visited = dft_helper(start, visited, s);

            for (string node : visited) {
                cout << node << " ";
            }

            cout << endl << endl;
        }

        void bfs(string start, string dest) {
            // alert if dest node not in graph
            // if start is dest
                // add start to path
                // found = true
                // return
            // create queue and visited vector
            // while node not found
                // get cur node from queue
                // if neighbor is dest
                    // set found as true
                    // return
                // for all neighbors of cur node
                    // if neighbor not visited
                        // add node to queue and visited vector

            cout << "Breadth-first search from " << start << " to " << dest << endl;

            if (adjList.find(dest) == adjList.end()) {
                printf("%s not in graph!", dest);
                return;
            }

            queue<string> q;
            q.push(start);
            vector<string> visited = {start};
            vector <string> path;
            bool found = false;

            if (start == dest)
            {
                path.push_back(start);
                found = true;
                cout << start << endl;
                return;
            }

            while(found != true) {
                string cur = q.front();
                q.pop();
                cout << cur << " ";
                path.push_back(cur);
                if (cur == dest) {
                    found = true;
                    return;
                }
                for (string neighbor : adjList[cur]) {
                    if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                        visited.push_back(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        
        vector<string> dfs_helper(string start, string dest, bool found, vector<string> visited, stack<string> s) {
            // return visited vector if dest node is found
            // if stack not empty
                // get cur node
                // if cur node hasn't been visited
                    // add cur node to visited
                // if cur node = dest
                    // set found = true
                    // return visited
                // for all neighbors of cur node
                    // if neighbor not been visited
                        // add neighbor to stack
                        // update visited = recursive call to helper fn with neighbor as start
                // remove last node from stack
            // return visited vector
            if (found == true) {
                return visited;
            }

            if (s.empty() == false) {
                string cur = s.top();
                if (find(visited.begin(), visited.end(), cur) == visited.end()) {
                    visited.push_back(cur);
                }
                if (cur == dest) {
                    found = true;
                    return visited;
                }
                for (string neighbor : adjList[cur]) {
                    if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                        s.push(neighbor);
                        visited = dfs_helper(neighbor, dest, found, visited, s);
                    }
                }
                s.pop();
            }

            return visited;
        }

        void dfs(string start, string dest) {
            // initialize stack and visited vector (with start node)
            // initialize found = false
            // if start == dest
                // add node to path
                // found = true
            // set visited = initial call to helper fn

            cout << "\n\nDepth-first search from " << start << " to " << dest << endl; 

            stack<string> s; 
            s.push(start);
            vector<string> visited;
            bool found = false;
            if (start == dest) {
                visited.push_back(start);
                found = true;
            }

            visited = dfs_helper(start, dest, found, visited, s);

            for (string vertex : visited) {
                cout << vertex << " ";
            }
        }

        tuple<map<string, int>, map<string,string>> dijkstra_unweighted(string start) {
            cout << "\n\nDijkstra algorithm - unweighted\n";
            map<string, int> known_dist_map; 
            map<string, string> prev_node_map;
            map<string, bool> visited_map;
            vector<string> unvisited_vect;

            for (auto node : adjList) {
                known_dist_map[node.first] = numeric_limits<int>::max();
                prev_node_map[node.first] = "";
                visited_map[node.first] = false;
                unvisited_vect.push_back(node.first);
            }

            known_dist_map[start] = 0;

            while (unvisited_vect.empty() != true) {
                int dist = numeric_limits<int>::max();
                string cur;
                for (auto node : adjList) {
                    if ((known_dist_map[node.first] < dist) && (visited_map[node.first] == false)) {
                        cur = node.first;
                        dist = known_dist_map[cur];
                    }
                }

                map<string, int> calc_dist_map;
                int cur_dist = known_dist_map[cur] + 1;
                for (auto neighbor : adjList[cur]) {
                    calc_dist_map[neighbor] = cur_dist;
                    if(calc_dist_map[neighbor] < known_dist_map[neighbor]) {
                        known_dist_map[neighbor] = calc_dist_map[neighbor];
                        prev_node_map[neighbor] = cur;
                    }
                }

                visited_map[cur] = true;
                unvisited_vect.erase(remove(unvisited_vect.begin(), unvisited_vect.end(), cur), unvisited_vect.end());
            }

            cout << "\nDijkstra Distances and Previous Nodes\n";
            for (auto node : known_dist_map) {
                cout << node.first << ": " << node.second << "\t" << prev_node_map[node.first] << endl;
            }
            
            return {known_dist_map, prev_node_map};
        }
};

int main() {
    graph g;
    g.createMap();
    g.printEdges();
    g.bft("A");
    g.dft("A");
    g.printEdges();
    // g.addEdge("A","Z");
    // g.printEdges();
    // g.removeEdge("A", "Z");
    // g.printEdges();
    g.bfs("A", "D");
    g.dfs("A", "D");
    map<string, int> kdm;
    map<string,string> pnm;
    tie(kdm, pnm) = g.dijkstra_unweighted("A");

    return 0;
}