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
    vector<pair<pair<int, int>, int>> edges_list;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges_list.push_back({{u, v}, w});
    }
    if(t == 1) {
        int degin[n + 1] = {0};
        int degout[n + 1] = {0};
        for(auto edge : edges_list) {
            int u = edge.first.first;
            int v = edge.first.second;
            degin[v]++;
            degout[u]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 10000));
        for(auto edge : edges_list) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            mat[u][v] = w;
            mat[u][u] = mat[v][v] = 0;
        }
        cout << n << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}