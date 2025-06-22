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
        int degin[n + 1] = {0};
        int degout[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            degout[i] += adj_list[i].size();
            for(auto u : adj_list[i]) {
                degin[u]++;
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        vector<pair<int, int>> edges_list;
        for(int i = 1; i <= n; i++) {
            for(auto u : adj_list[i]) {
                edges_list.push_back({i, u});
            }
        }
        cout << n << ' ' << edges_list.size() << '\n';
        for(auto edge : edges_list) {
            cout << edge.first << ' ' << edge.second << '\n';
        }
    }
}