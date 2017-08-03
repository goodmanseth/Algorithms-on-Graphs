#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

// returns true if cycle
bool explore(vector<vector<int>> &adj, vector<bool> &visited, int i,
                vector<bool> &stackFrame) {
    
    if (visited[i] == false) {
        visited[i] = true;
        stackFrame[i] = true;
        
        vector<int>::iterator j;    // *(j+x) = adj[i][x]
        for (j=adj[i].begin(); j!=adj[i].end(); ++j) {
            // if not visited and explore() returns true, then return true
            if (!visited[*j] && explore(adj,visited,*j,stackFrame)) return true;
            // if "j" is in the stack frame already then return true
            else if (stackFrame[*j]) return true;
        }
        
        /*
        vector<int>::size_type j;
        for (j=0;j!=adj[i].size();j++) {
            if (!visited[adj[i][j]] && explore(adj,visited,adj[i][j],stackFrame)) return true;
            else if (stackFrame[adj[i][j]]) return true;
        }
        */
    }
    stackFrame[i] = false;
    return false;
}

// essentially DFS
int acyclic(vector<vector<int> > &adj) {
    vector<bool> visited(adj.size());
    vector<bool> stackFrame(adj.size());
    for (vector<vector<int>>::size_type i=0; i!=adj.size(); i++) {
        if (explore(adj,visited,i, stackFrame)) return 1;
    }
    return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
