#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 1e2 + 1;

int n, s, t;
int c[maxn][maxn];
int d[maxn], par[maxn];

void bellmanford() {
    for(int v = 1; v <= n; v++) {
        d[v] = c[s][v];
        par[v] = s;
    }
    d[s] = 0;
    par[s] = 0;
    int ok = 0;
    for(int i = 0; i < n - 1; i++) {
        ok = 1;
        for(int v = 1; v <= n; v++) {
            for(int u = 1; u <= n; u++) {
                if(d[v] > d[u] + c[u][v]) {
                    d[v] = d[u] + c[u][v];
                    par[v] = u;
                    ok = 0;
                }
            }
        }
        if(ok) {
            break;
        }
    }
    if(ok) {
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
    } else {
        cout << -1;
    }
}

int main() {
    IO_boost

    // freopen("BN.INP", "r", stdin);
    // freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    bellmanford();
    cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
}