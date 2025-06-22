#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, u;
int adj[101][101];
int x[101];
bool f[101];
vector<vector<int>> res;

void rec() {
    vector<int> arr(x + 1, x + n + 2);
    // reverse(arr.begin(), arr.end());
    res.push_back(arr);
}

void hamilton(int k) {
    for(int v = 1; v <= n; v++) {
        if(adj[v][x[k - 1]]) {
            if(k == n + 1) {
                if(v == x[1]) x[k] = v, rec();
            }
            else {
                if(!f[v]) {
                    x[k] = v;
                    f[v] = 1;
                    hamilton(k + 1);
                    f[v] = 0;
                }
            }
        }
    }
}

void listHamilton() {
    x[1] = u;
    f[u] = 1;
    hamilton(2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> n >> u;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    listHamilton();
    cout << res.size() << '\n';
    for(auto arr : res) {
        for(auto v : arr) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}