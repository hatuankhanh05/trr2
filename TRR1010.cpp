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
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(a[i][j] && a[i][j] != 10000) {
                    deg[i]++;
                    deg[j]++;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        vector<pair<pair<int, int>, int>> edges_list;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(a[i][j] && a[i][j] != 10000) {
                    edges_list.push_back({{i, j}, a[i][j]});
                }
            }
        }
        cout << n << " " << edges_list.size() << "\n";
        for(auto edge : edges_list) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            cout << u << " " << v << " " << w << '\n';
        }
    }
}