#include <bits/stdc++.h>

#define ll long long
#define IO_boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int maxn = 101;

int adj[maxn][maxn];
vector<pair<int, int>> span;
bool vst[maxn];
int n, s;

void dfs(int u, int prev) {
    vst[u] = 1;
    if(prev != -1) {
        span.push_back({prev, u});
    }
    for(int i = 1; i <= n; i++) {
        if(adj[u][i] && !vst[i]) {
            dfs(i, u);
        }
    }
}

void findDfsSpan() {
    dfs(s, -1);
    if(span.size() != n - 1) {
        cout << 0;
    } else {
        cout << span.size() << endl;
        for(auto e : span) {
            auto [u, v] = e;
            cout << u << ' ' << v << endl;
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vst[u] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(adj[curr][i] && !vst[i]) {
                vst[i] = 1;
                q.push(i);
                span.push_back({curr, i});
            }
        }
    }
}

void findBfsSpan() {
    bfs(s);
    if(span.size() != n - 1) {
        cout << 0;
    } else {
        cout << span.size() << endl;
        for(auto e : span) {
            auto [u, v] = e;
            cout << u << ' ' << v << endl;
        }
    }
}

int main() {
    IO_boost

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int t;
    cin >> t;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    switch(t) {
        case 1:
            findDfsSpan();
            break;
        case 2:
            findBfsSpan();
    }
}