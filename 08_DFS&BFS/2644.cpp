#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, p1, p2, m;
    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    vector<int> graph[101];
    int dist[101];
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(p1);
    dist[p1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[p2] << "\n";

    return 0;
}