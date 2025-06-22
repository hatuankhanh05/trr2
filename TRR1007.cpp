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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int u;
            cin >> u;
            adj[i].push_back(u);
        }
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            deg[i] = adj[i].size();
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        cout << n << '\n';
        int a[n + 1][n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(auto u : adj[i]) {
                a[i][u] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}