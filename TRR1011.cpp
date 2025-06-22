#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges_list;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges_list.push_back({{u, v}, w});
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(auto edge : edges_list) {
            int u = edge.first.first;
            int v = edge.first.second;
            deg[u]++;
            deg[v]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        cout << n << '\n';
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 10000));
        for(auto edge : edges_list) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            a[u][v] = a[v][u] = w;
            a[u][u] = a[v][v] = 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}