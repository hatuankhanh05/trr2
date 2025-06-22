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
    int mat[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    if(t == 1) {
        int deg[n + 1] = {0};
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(mat[i][j]) {
                    deg[i]++;
                    deg[j]++;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        vector<pair<int, int>> edges_list;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(mat[i][j]) {
                    edges_list.push_back({i, j});
                }
            }
        }
        int m = edges_list.size();
        int a[n + 1][m + 1] = {0};
        for(int i = 0; i < m; i++) {
            auto edge = edges_list[i];
            a[edge.first][i + 1] = 1;
            a[edge.second][i + 1] = 1;
        }
        cout << n << ' ' << m << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}