#include <iostream>
#include <cstring>
using namespace std;

int n;
int adj[101][101];
bool visited[101];

void dfs(int u) {
    visited[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

void dfs_undir(int u) {
    visited[u] = 1;
    for(int v = 1; v <= n; v++) {
        if((adj[u][v] || adj[v][u]) && !visited[v]) {
            dfs_undir(v);
        }
    }
}

bool strong_connectivity() {
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for(int v = 1; v <= n; v++) {
            if(!visited[v]) return 0;
        }
    }
    return 1;
}

bool weak_connectivity() {
    memset(visited, 0, sizeof(visited));
    dfs_undir(1);
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) return 0;
    }
    return 1;
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
    if(strong_connectivity())
        cout << 1;
    else if(weak_connectivity())
        cout << 2;
    else
        cout << 0;
}