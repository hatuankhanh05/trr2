#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int u;
            cin >> u;
            adj_list[i].push_back(u);
        }
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(auto u : adj_list[i]) {
                deg[u]++;
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        vector<pair<int, int>> edges_list;
        for(int i = 1; i <= n; i++) {
            for(auto u : adj_list[i]) {
                if(u > i) {
                    edges_list.push_back({i, u});
                }
            }
        }
        int m = edges_list.size();
        int mat[n + 1][m + 1];
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < m; i++) {
            auto edge = edges_list[i];
            mat[edge.first][i + 1] = 1;
            mat[edge.second][i + 1] = 1;
        }
        cout << n << ' ' << m << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}