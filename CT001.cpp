#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, u;
int deg[101];
int adj[101][101];
bool f[101];

void dfs(int curr) {
    f[curr] = 1;
    for(int next = 1; next <= n; next++) {
        if(adj[curr][next] && !f[next]) {
            dfs(next);
        }
    }
}

int checkEuler() {
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!f[i]) return 0;
    }
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(deg[i] % 2 != 0) {
            count++;
        }
    }
    if(count == 0) return 1;
    else if(count <= 2) return 2;
    else return 0;
}

vector<int> eulerPath() {
    vector<int> path;
    stack<int> s;
    s.push(u);
    while(!s.empty()) {
        int top = s.top();
        int ok = 1;
        for(int v = 1; v <= n; v++) {
            if(adj[top][v]) {
                s.push(v);
                ok = 0;
                adj[top][v] = adj[v][top] = 0;
                break;
            }
        }
        if(ok) {
            path.push_back(top);
            s.pop();
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    if(t == 1) {
        cin >> n >> m;
    } else {
        cin >> n >> m >> u;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        adj[x][y] = adj[y][x] = 1;
    }
    if(t == 1) {
        cout << checkEuler();
    } else {
        vector<int> path = eulerPath();
        for(auto v : path) {
            cout << v << ' ';
        }
    }
}