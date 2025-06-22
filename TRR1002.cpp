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
            for(int j = 1; j <= n; j++) {
                deg[i] += mat[i][j];
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << deg[i] << ' ';
        }
    } else {
        cout << n << '\n';
        vector<vector<int>> neighbors(n + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(mat[i][j]) {
                    neighbors[i].push_back(j);
                    neighbors[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << neighbors[i].size() << ' ';
            for(auto it : neighbors[i]) {
                cout << it << ' ';
            }
            cout << '\n';
        }
    }
}