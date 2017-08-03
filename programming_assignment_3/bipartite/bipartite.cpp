#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool bfs(vector<vector<int>> &adj, int source, vector<int> &color) {
    color[source] = 1;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        source = q.front();
        q.pop();
        vector<int>::iterator i;
        for (i=adj[source].begin(); i!=adj[source].end(); ++i) {
            if (color[*i] == -1) {
                color[*i] = 1 - color[source];
                q.push(*i);
            } else if (color[*i] == color[source]) return false;
        }
    }
    return true;
}

int bipartite(vector<vector<int> > &adj) {
    vector<int> color(adj.size(),-1);
    vector<vector<int>>::size_type i;
    for (i=0; i!=adj.size(); ++i) {
       if (color[i] == -1) {
            if (!bfs(adj, i, color)) return 0;
       }
    }
    return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
