#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

void init() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

vector<lli> dijkstra(const vector<vector<pii>>& graph, lli start, lli n) {
    vector<lli> dist(n + 1, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    init();
    lli n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n + 1), revGraph(n + 1);
    for (lli i = 0; i < m; i++) {
        lli a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        revGraph[b].push_back({a, c});
    }

    // Compute shortest paths from city 1
    vector<lli> dist_from_start = dijkstra(graph, 1, n);

    // Compute shortest paths to city n
    vector<lli> dist_to_end = dijkstra(revGraph, n, n);

    // Find the minimum cost by considering the discount on each flight
    lli min_cost = LLONG_MAX;
    for (lli u = 1; u <= n; u++) {
        for (auto [v, c] : graph[u]) {
            if (dist_from_start[u] != LLONG_MAX && dist_to_end[v] != LLONG_MAX) {
                lli total_cost = dist_from_start[u] + (c / 2) + dist_to_end[v];
                min_cost = min(min_cost, total_cost);
            }
        }
    }

    cout << min_cost << '\n';
    return 0;
}