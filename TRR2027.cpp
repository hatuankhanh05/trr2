#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
int adj[101][101];
bool vst[101];

void dfs(int u, pair<int, int> rmv_edge) {
    vst[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(u == rmv_edge.first && v == rmv_edge.second)
            continue;
        if(v == rmv_edge.first && u == rmv_edge.second)
            continue;
        if(adj[u][v] && !vst[v]) {
            dfs(v, rmv_edge);
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
    int ori_connectedComp = 0;
    for(int i = 1; i <= n; i++) {
        if(!vst[i]) {
            ori_connectedComp++;
            dfs(i, {-1, -1});
        }
    }
    memset(vst, 0, sizeof(vst));
    vector<pair<int, int>> edges_list;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(adj[i][j]) {
                edges_list.push_back({i, j});
            }
        }
    }
    vector<pair<int ,int>> res;
    for(auto edge : edges_list) {
        memset(vst, 0, sizeof(vst));
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(!vst[i]) {
                count++;
                dfs(i, edge);
            }
        }
        if(count > ori_connectedComp) {
            res.push_back(edge);
        }
    }
    cout << res.size() << '\n';
    for(auto it : res) {
        cout << it.first << ' ' << it.second << '\n';
    }
}