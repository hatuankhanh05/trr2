#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int adj[101][101];
bool vst[101];

void dfs(int u, vector<int> &a) {
    vst[u] = 1;
    a.push_back(u);
    for(int v = 1; v <= n; v++) {
        if(adj[u][v] && !vst[v]) {
            dfs(v, a);
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
    vector<vector<int>> res;
    for(int i = 1; i <= n; i++) {
        if(!vst[i]) {
            vector<int> a;
            dfs(i, a);
            if(!a.empty()) {
                res.push_back(a);
            }
        }
    }
    for(auto &a : res) {
        sort(a.begin(), a.end());
    }
    cout << res.size() << '\n';
    for(auto a : res) {
        for(auto it : a) {
            cout << it << ' ';
        }
        cout << '\n';
    }
}