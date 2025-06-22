#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int adj[101][101], e[101];
bool f[101];
vector<vector<int>> res;

int count_len2path(int u, int v) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(adj[u][i] && adj[i][v]) {
            count++;
        }
    }
    return count;
}

void dfs(int u, int end) {
    if(u == end) {
        vector<int> a;
        for(u; u != -1; u = e[u]) {
            a.push_back(u);
        }
        reverse(a.begin(), a.end());
        res.push_back(a);
        return;
    }
    f[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(adj[u][v] && !f[v]) {
            e[v] = u;
            dfs(v, end);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t;
    cin >> t;
    int u, v;
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    e[u] = -1;
    dfs(u, v);
    if(t == 1) {
        cout << count_len2path(u, v);
    } else {
        if(res.empty()) cout << 0;
        else {
            auto arr = res[0];
            for(auto u : arr) {
                cout << u << ' ';
            }
        }
    }
}