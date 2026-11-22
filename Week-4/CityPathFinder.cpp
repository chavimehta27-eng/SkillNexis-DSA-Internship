#include <bits/stdc++.h>
using namespace std;
class CityPathFinder
{
    int n;
    vector<string> cities;
    vector<vector<pair<int, int>>> graph;
public:
    CityPathFinder()
    {
        n = 6;
        cities = {"Delhi", "Jaipur", "Jodhpur",
                  "Udaipur", "Ajmer", "Mumbai"};
        graph.resize(n);
        
        addEdge(0, 1, 280);  // Delhi - Jaipur
        addEdge(0, 4, 400);  // Delhi - Ajmer
        addEdge(1, 2, 350);  // Jaipur - Jodhpur
        addEdge(1, 4, 135);  // Jaipur - Ajmer
        addEdge(2, 3, 250);  // Jodhpur - Udaipur
        addEdge(3, 4, 270);  // Udaipur - Ajmer
        addEdge(3, 5, 700);  // Udaipur - Mumbai
        addEdge(4, 5, 650);  // Ajmer - Mumbai
    }

    void addEdge(int u, int v, int distance)
    {
        graph[u].push_back({v, distance});
        graph[v].push_back({u, distance});
    }

    void displayCities()
    {
        cout << "\nAvailable Cities:\n";

        for(int i = 0; i < n; i++)
        {
            cout << i + 1 << ". " << cities[i] << endl;
        }
    }

    void findShortestPath(int source, int destination)
    {
        const int INF = 1e9;

        vector<int> dist(n, INF);
        vector<int> parent(n, -1);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});
        while(!pq.empty())
        {
            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(currentDistance > dist[u])
                continue;
            for(auto edge : graph[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if(dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[destination] == INF)
        {
            cout << "\nNo route found!\n";
            return;
        }

        vector<int> path;

        int current = destination;

        while(current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        cout << "\nShortest Route:\n";

        for(int i = 0; i < path.size(); i++)
        {
            cout << cities[path[i]];

            if(i != path.size() - 1)
                cout << " -> ";
        }

        cout << "\nTotal Distance: "
             << dist[destination] << " km\n";
    }
};

int main()
{
    CityPathFinder obj;

    int source, destination;

    cout << "===== CITY PATH FINDER =====\n";

    obj.displayCities();

    cout << "\nEnter starting city number: ";
    cin >> source;

    cout << "Enter destination city number: ";
    cin >> destination;

    if(source < 1 || source > 6 ||
       destination < 1 || destination > 6)
    {
        cout << "\nInvalid city number!\n";
        return 0;
    }

    if(source == destination)
    {
        cout << "\nStarting city and destination are same.\n";
        return 0;
    }

    obj.findShortestPath(source - 1, destination - 1);
    return 0;
}
