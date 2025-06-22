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
            deg[edge.first]++;
            deg[edge.second]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        cout << n << '\n';
        int mat[n + 1][n + 1] = {0};
        for(auto edge : edges_list) {
            int i = edge.first, j = edge.second;
            mat[i][j] = mat[j][i] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}