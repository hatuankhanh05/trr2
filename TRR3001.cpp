#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int t, n, u, a[105][105], deg[105];
set<int> adj[105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

bool lien_thong()
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt == 1;
}

int isEuler()
{
    if (!lien_thong())
        return 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2)
            cnt++;
    }
    if (!cnt)
        return 1;
    else if (cnt == 2)
        return 2;
    else
        return 0;
}

void Euler(int u)
{
    stack<int> st;
    vector<int> EC;
    st.push(u);

    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for (int x : EC)
        cout << x << ' ';
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> t >> n;
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 1) {
                    adj[i].insert(j);
                    deg[i]++;
                }
            }
        }
        cout << isEuler() << endl;
    } else {
        cin >> u;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 1) {
                    adj[i].insert(j);
                    deg[i]++;
                }
            }
        }
        Euler(u);
    }
}