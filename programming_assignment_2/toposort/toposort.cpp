#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<int> &order, int x) {
    visited[x] = true;
    
    // normal dfs, we just add the postvisit index to order afterwards
    vector<int>::iterator i;
    for (i=adj[x].begin(); i!=adj[x].end(); ++i) {
        if (!visited[*i]) dfs(adj,visited,order,*i);
    }
    order.push_back(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
    vector<bool> visited(adj.size(), 0);
    vector<int> order;
    vector<vector<int>>::size_type i;
    for (i=0; i!=adj.size(); ++i) {
        if (visited[i] == false) dfs(adj,visited,order,i);
    }
    // reverse postvisit order
    std::reverse(order.begin(),order.end());
    return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
