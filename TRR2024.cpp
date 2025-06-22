#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int adj[101][101];
bool visited[101];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()) {
        int curr_v = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(adj[curr_v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

void bfs2(int u, int del_v) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()) {
        int curr_v = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(i == del_v) continue;
            if(adj[curr_v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");
    fin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }
    int origin_conn = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            origin_conn++;
            bfs(i);
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        int count = 0;
        memset(visited, 0, sizeof(visited));
        for(int j = 1; j <= n; j++) {
            if(i != j && !visited[j]) {
                count++;
                bfs2(j, i);
            }
        }
        if(count > origin_conn) res.push_back(i);
    }
    fout << res.size() << '\n';
    if(!res.empty()) for(auto u : res) fout << u << ' ';
}