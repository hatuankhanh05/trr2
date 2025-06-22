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
        int degin[n + 1] = {0};
        int degout[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i][j]) {
                    degout[i]++;
                    degin[j]++;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << degin[i] << ' ' << degout[i] << '\n';
        }
    } else {
        vector<pair<int, int>> edges_list;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i][j]) {
                    edges_list.push_back({i, j});
                }
            }
        }
        cout << n << ' ' << edges_list.size() << '\n';
        for(auto edge : edges_list) {
            cout << edge.first << ' ' << edge.second << '\n';
        }
    }
}