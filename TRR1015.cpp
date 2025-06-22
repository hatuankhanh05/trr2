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
    vector<pair<int, int>> edges_list;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges_list.push_back({u, v});
    }
    if(t == 1) {
        int degin[n + 1] = {0};
        int degout[n + 1] = {0};
        for(auto edge : edges_list) {
            degout[edge.first]++;
            degin[edge.second]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        int adj[n + 1][n + 1];
        memset(adj, 0, sizeof(adj));
        for(auto edge : edges_list) {
            adj[edge.first][edge.second] = 1;
        }
        cout << n << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << adj[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}