#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;
    int adj[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    if(t == 1) {
        int degin[n + 1] = {0};
        int degout[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(adj[i][j]) {
                    degin[j]++;
                    degout[i]++;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        cout << n << '\n';
        vector<vector<int>> adj_list(n + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(adj[i][j]) {
                    adj_list[i].push_back(j);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << adj_list[i].size() << ' ';
            for(auto u : adj_list[i]) {
                cout << u << ' ';
            }
            cout << '\n';
        }
    }
}