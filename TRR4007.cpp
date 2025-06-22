#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 1001;

struct edge {
    int u, v, w;
};

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

int n, m;
vector<edge> edges;
int par[maxn];

int find(int u) {
    if(u == par[u]) return par[u];
    return par[u] = find(par[u]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        return 0;
    }
    par[v] = u;
    return 1;
}

void kruskal() {
    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }
    vector<edge> spanningTree;
    int totalWeight = 0;
    for(auto e : edges) {
        auto [u, v, w] = e;
        if(join(u, v)) {
            spanningTree.push_back(e);
            totalWeight += w;
        }
        if(spanningTree.size() == n - 1) {
            break;
        }
    }
    if(spanningTree.size() == n - 1) {
        cout << totalWeight << endl;
        for(auto e : spanningTree) {
            auto [u, v, w] = e;
            cout << u << ' ' << v << ' ' << w << endl;
        }
    } else {
        cout << 0 << endl;
    }
}

int main() {
    IO_boost

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    stable_sort(edges.begin(), edges.end(), cmp);
    kruskal();
}