#include <iostream>
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
    vector<pair<int, int>> edges_list;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges_list.push_back({u, v});
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(auto edge : edges_list) {
            int u = edge.first;
            int v = edge.second;
            deg[u]++;
            deg[v]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        int a[n + 1][m + 1] = {0};
        for(int i = 0; i < m; i++) {
            auto edge = edges_list[i];
            int u = edge.first;
            int v = edge.second;
            a[u][i + 1] = a[v][i + 1] = 1;
        }
        cout << n << ' ' << m << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}