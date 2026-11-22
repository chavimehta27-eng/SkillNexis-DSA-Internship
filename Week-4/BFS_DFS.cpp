#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    int V;
    vector<int> adj[100];
public:
    Graph(int v){
        V = v;
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start){
        bool visited[100] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal: ";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i];

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
    }

    void DFSUtil(int node, bool visited[]){
        visited[node] = true;
        cout << node << " ";

        for(int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);
            }
        }
    }

    void DFS(int start){
        bool visited[100] = {false};

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.BFS(0);
    g.DFS(0);
    return 0;
}
