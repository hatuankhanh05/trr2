#include <iostream>
#include <vector>
#include <algorithm>
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
    // sort(edges_list.begin(), edges_list.end());
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
        vector<vector<int>> adj(n + 1);
        for(auto edge : edges_list) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        for(int i = 1; i <= n; i++) {
            cout << adj[i].size() << ' ';
            for(auto it : adj[i]) {
                cout << it << ' ';
            }
            cout << '\n';
        }
    }
}