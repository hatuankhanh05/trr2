#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj_list(1001);
bool f[1001] = {0};

void bfs(int u, vector<int> &arr) {
    queue<int> q;
    q.push(u);
    f[u] = 1;
    while(!q.empty()) {
        int curr_v = q.front();
        arr.push_back(curr_v);
        q.pop();
        for(auto v : adj_list[curr_v]) {
            if(!f[v]) {
                q.push(v);
                f[v] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int ok;
            cin >> ok;
            if(ok) {
                adj_list[i].push_back(j);
            }
        }
    }
    vector<vector<int>> res;
    for(int i = 1; i <= n; i++) {
        if(!f[i]) {
            vector<int> arr;
            bfs(i, arr);
            if(!arr.empty()) {
                sort(arr.begin(), arr.end());
                res.push_back(arr);
            }
        }
    }
    cout << res.size() << '\n';
    for(auto arr : res) {
        for(auto it : arr) {
            cout << it << ' ';
        }
        cout << '\n';
    }
}