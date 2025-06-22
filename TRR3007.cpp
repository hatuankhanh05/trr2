#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, u;
vector<vector<int>> adj_list(101);
vector<vector<int>> paths;
int x[102];
bool vst[101];

void record() {
    vector<int> path(x + 1, x + n + 2);
    paths.push_back(path);
}

void hamilton(int i) {
    for(auto v : adj_list[x[i - 1]]) {
        if(i == n + 1) {
            if(v == x[1]) {
                x[i] = v;
                record();
            }
        } else {
            if(!vst[v]) {
                vst[v] = 1;
                x[i] = v;
                hamilton(i + 1);
                vst[v] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> n >> u;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            int adj;
            cin >> adj;
            if(adj) {
                adj_list[i].push_back(j);
            }
        }
    x[1] = u;
    vst[u] = 1;
    hamilton(2);
    if(paths.empty())
        cout << 0;
    else {
        for(auto path : paths) {
            for(auto v : path) {
                cout << v << ' ';
            }
            cout << '\n';
        }
        cout << paths.size();
    }
}