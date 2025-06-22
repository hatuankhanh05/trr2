#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int n, u;
int deg[101];
int adj[101][101];
bool vst[101];

void dfs(int curr) {
    vst[curr] = 1;
    for(int next = 1; next <= n; next++) {
        if(adj[curr][next] && !vst[next]) {
            dfs(next);
        }
    }
}

int eulerCheck() {
    memset(vst, 0, sizeof(vst));
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!vst[i]) {
            return 0;
        }
    }
    int deg[101];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            deg[i] += adj[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2 != 0) {
            count++;
        }
    }
    if(count == 0)
        return 1;
    else if(count <= 2)
        return 2;
    else
        return 0;
}

vector<int> eulerPath() {
    vector<int> path;
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int top = st.top();
        bool ok = 1;
        for(int i = 1; i <= n; i++) {
            if(adj[top][i]) {
                adj[top][i] = adj[i][top] = 0;
                st.push(i);
                ok = 0;
                break;
            }
        }
        if(ok) {
            st.pop();
            path.push_back(top);
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

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
        }
    }
    if(t == 1) {
        cout << eulerCheck();
    } else {
        vector<int> path;
        path = eulerPath();
        for(auto it : path) {
            cout << it << ' ';
        }
    }
}