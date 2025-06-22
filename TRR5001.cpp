#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 1e2 + 1;

int n, s, t;
int c[maxn][maxn];
int par[maxn], d[maxn];
bool vst[maxn];

void dijkstra() {
    for(int v = 1; v <= n; v++) {
        d[v] = c[s][v];
        par[v] = s;
    }
    d[s] = 0;
    par[s] = 0;
    vst[s] = 1;
    while(1) {
        int u = 0, minn = 1e4;
        for(int v = 1; v <= n; v++) {
            if(d[v] < minn && !vst[v]) {
                u = v;
                minn = d[v];
            }
        }
        if(!u) {
            break;
        }
        vst[u] = 1;
        for(int v = 1; v <= n; v++) {
            if(!vst[v] && d[v] > d[u] + c[u][v]) {
                par[v] = u;
                d[v] = d[u] + c[u][v];
            }
        }
    }
    if(d[t] != 1e4) {
        cout << d[t] << endl;
        vector<int> path;
        for(int u = t; u != 0; u = par[u]) {
            path.push_back(u);
        }
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    } else {
        cout << 0;
    }
}

int main() {
    IO_boost

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    dijkstra();
}