#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> adj[N + 1], Path; 
bool visited[N + 1];         
int trace[N + 1];            
int n, m, S, T;              

void dfs(int u) {
    visited[u] = true; 
    for (auto v : adj[u]) {
        if (!visited[v]) {  
            trace[v] = u;   
            dfs(v);         
        }
    }
}

void find_path(int t) {
    int x = t;
    while (x != -1) {
        Path.push_back(x); 
        x = trace[x];      
    }
    reverse(Path.begin(), Path.end()); 
    for (int v : Path) {
        cout << v << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> S >> T;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    memset(visited, false, sizeof(visited));
    memset(trace, -1, sizeof(trace)); 
    dfs(S);

    if (!visited[T]) { 
        cout << "-1\n";
    } else {
        find_path(T); // In đường đi từ S đến T
    }

    return 0;
}
