#include <iostream>
#include <vector>
using namespace std;

int n, u, sum, res = 1e9;
int c[200][200];
int x[200];
bool f[200];
vector<int> resx;

void rec() {
    x[n + 1] = x[1];
    if(sum + c[x[n]][x[n + 1]] < res) {
        res = sum + c[x[n]][x[n + 1]];
        vector<int> tmp(x + 1, x + n + 2);
        resx = tmp;
    }
}

void hamilton(int k) {
    for(int v = 1; v <= n; v++) {
        if(c[x[k - 1]][v] && c[x[k - 1]][v] != 10000) {
            if(k == n + 1) {
                if(v == x[1]) {
                    rec();
                }
            } else {
                if(!f[v]) {
                    x[k] = v;
                    f[v] = 1;
                    sum += c[x[k - 1]][v];
                    hamilton(k + 1);
                    f[v] = 0;
                    sum -= c[x[k - 1]][v];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> u;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }    
    x[1] = u;
    f[u] = 1;
    hamilton(2);
    if(res != 1e9) {
        cout << res << '\n';
        for(auto it : resx) {
            cout << it << ' ';
        }
    } else {
        cout << 0;
    }
}