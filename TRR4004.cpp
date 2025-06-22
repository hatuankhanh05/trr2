#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 1e2 + 1;
const int inf = 1e4;

struct edge {
    int u, v, w;
};

int n, s;
int c[maxn][maxn];
bool vs[maxn];

void prim() {
    vector<edge> mst;
    int mtw = 0;
    vs[s] = 1;
    for(int i = 0; i < n - 1; i++) {
        int x = 0, y = 0, mw = inf;
        for(int u = 1; u <= n; u++) {
            if(vs[u]) {
                for(int v = 1; v <= n; v++) {
                    if(!vs[v] && c[u][v] && c[u][v] < mw) {
                        x = u;
                        y = v;
                        mw = c[u][v];
                    }
                }
            }
        }
        if(!x) {
            cout << 0;
            return;
        }
        mst.push_back({x, y, mw});
        mtw += mw;
        vs[y] = 1;
    }
    cout << mtw << endl;
    for(auto [u, v, w] : mst) {
        if(u > v) {
            swap(u, v);
        }
        cout << u << ' ' << v << ' ' << w << endl;
    }
}

int main() {
    IO_boost

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    prim();
}