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
            degin[edge.second]++;
            degout[edge.first]++;
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++) {
            auto edge = edges_list[i];
            a[edge.first][i + 1] = 1;
            a[edge.second][i + 1] = -1;
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