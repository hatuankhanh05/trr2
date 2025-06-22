#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 1e2 + 1;

int n;
int c[maxn][maxn];
int d[maxn][maxn], par[maxn][maxn];

void floyd() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = c[i][j];
            par[i][j] = i;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                if(d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                    par[u][v] = par[k][v];
                }
            }
        }
    }
    int u = 0, v = 0, maxx = -1e9;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] != 1e4 && d[i][j] > maxx) {
                maxx = d[i][j];
                u = i;
                v = j;
            }
        }
    }
    if(!u) {
        cout << 0;
    } else {
        cout << u << ' ' << v << ' ' << maxx << endl;
        vector<int> path;
        path.push_back(v);
        for(int i = par[u][v]; i != par[u][i]; i = par[u][i]) {
            path.push_back(i);
        }
        path.push_back(u);
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    }
}

int main() {
    IO_boost

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    floyd();
}