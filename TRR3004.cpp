#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, u;
int adj[200][200];
int degin[200], degout[200];
bool f[200];

void dfs(int curr) {
    f[curr] = 1;
    for(int next = 1; next <= n; next++) {
        if((adj[curr][next] || adj[next][curr]) && !f[next]) {
            dfs(next);
        }
    }
}

int euler_check() {
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!f[i]) return 0;
    }
    bool found = 0;
    for(int i = 1; i <= n; i++) {
        if(degin[i] != degout[i]) {
            found = 1;
            break;
        }
    }
    if(!found) return 1;
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(abs(degin[i] - degout[i]) == 1) {
            count++;
        }
    }
    if(count <= 2) return 2;
    return 0;
}

vector<int> euler_path() {
    vector<int> path;
    stack<int> s;
    s.push(u);
    while(!s.empty()) {
        int top = s.top();
        bool ok = 1;
        for(int v = 1; v <= n; v++) {
            if(adj[top][v]) {
                adj[top][v] = 0;
                ok = 0;
                s.push(v);
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

    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t == 1) {
        cin >> n;
    } else {
        cin >> n >> u;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if(adj[i][j]) {
                degout[i]++;
                degin[j]++;
            }
        }
    }
    if(t == 1) {
        cout << euler_check();
    } else {
        vector<int> res = euler_path();
        for(auto it : res) {
            cout << it << ' ';
        }
    }
}