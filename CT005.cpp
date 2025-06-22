#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, u;
vector<vector<int>> paths;
int adj[101][101];
bool vst[101];
int x[102];

void record() {
    vector<int> path(x + 1, x + n + 2);
    paths.push_back(path);
}

void hamilton(int i) {
    for(int v = 1; v <= n; v++) {
        if(adj[x[i - 1]][v]) {
            if(i == n + 1) {
                if(v == x[1]) {
                    x[i] = v;
                    record();
                }
            } else {
                if(!vst[v]) {
                    x[i] = v;
                    vst[v] = 1;
                    hamilton(i + 1);
                    vst[v] = 0;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> n >> m >> u;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    x[1] = u;
    vst[u] = 1;
    hamilton(2);
    if(paths.empty())
        cout << 0;
    else {
        cout << paths.size() << '\n';
        for(auto path : paths) {
            for(auto it : path) {
                cout << it << ' ';
            }
            cout << '\n';
        }
    }
}