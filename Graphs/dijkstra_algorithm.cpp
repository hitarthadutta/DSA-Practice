#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

void dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Distance to " << i << " is " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);

    graph[0].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({3, 1});
    graph[3].push_back({4, 5});
    graph[4].push_back({0, 8});

    dijkstra(graph, 0);
}
