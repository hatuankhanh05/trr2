#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int adj[101][101];
bool f[101];

void dfs(int u) {
    f[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[u][i] && !f[i]) {
            dfs(i);
        }
    }
}

void dfs2(int u, int del_v) {
    f[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(u == del_v || i == del_v) continue;
        if(adj[u][i] && !f[i]) {
            dfs2(i, del_v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    int origin_conn = 0;
    for(int i = 1; i <= n; i++) {
        if(!f[i]) {
            origin_conn++;
            dfs(i);
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        memset(f, 0, sizeof(f));
        for(int j = 1; j <= n; j++) {
            if(!f[j] && j != i) {
                cnt++;
                dfs2(j, i);
            }
        }
        if(cnt > origin_conn) {
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    if(!res.empty()) for(auto u : res) cout << u << ' ';
}