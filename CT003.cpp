#include <bits/stdc++.h>
using namespace std;

int adj[100][100];          
int numVertices, startVertex, mode;
int visited[100], stackDFS[10000], eulerPath[10000];
int visitedCount = 0;  

void dfs(int u) {
    visited[u] = 1;
    visitedCount++;
    for (int v = 1; v <= numVertices; ++v) {
        if ((adj[u][v] == 1 || adj[v][u] == 1) && visited[v] == 0) {
            dfs(v);
        }
    }
}

int checkEuler(int adj[100][100], int numVertices) {
    visitedCount = 0;
    memset(visited, 0, sizeof(visited));
    dfs(1); 

    if (visitedCount < numVertices) return 0;
    int inMore = 0, outMore = 0;
    for (int v = 1; v <= numVertices; v++) {
        int inDeg = 0, outDeg = 0;
        for (int i = 1; i <= numVertices; i++) {
            if (adj[i][v] == 1) inDeg++;
            if (adj[v][i] == 1) outDeg++;
        }

        if (inDeg != outDeg) {
            if (abs(inDeg - outDeg) > 1) return 0;
            if (inDeg - outDeg == 1) {
                if (inMore > 0) return 0;
                inMore = v;
            } else if (outDeg - inDeg == 1) {
                if (outMore > 0) return 0;
                outMore = v;
            } else return 0;
        }
    }

    if (inMore == 0 && outMore == 0) return 1;  
    else {
        startVertex = outMore;
        return 2;
    }
}

void findEulerCycle(int adj[100][100], int numVertices, int start) {
    stack<int> st;
    vector<int> path;
    st.push(start);

    while (!st.empty()) {
        int current = st.top();
        bool found = false;
        for (int next = 1; next <= numVertices; ++next) {
            if (adj[current][next] == 1) {
                st.push(next);
                adj[current][next] = 0;
                found = true;
                break;
            }
        }
        if (!found) {
            path.push_back(current);
            st.pop();
        }
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> mode;
    if (mode == 1) {
        cin >> numVertices;
    } else {
        cin >> numVertices >> startVertex;
    }

    for (int i = 1; i <= numVertices; i++) {
        int count, neighbor;
        cin >> count;
        for (int j = 0; j < count; j++) {
            cin >> neighbor;
            adj[i][neighbor] = 1;
        }
    }

    if (mode == 1) {
        int result = checkEuler(adj, numVertices);
        cout << result << endl;
    } else {
        findEulerCycle(adj, numVertices, startVertex);
    }

    return 0;
}