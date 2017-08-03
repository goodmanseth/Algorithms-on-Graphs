#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

int reach(vector<vector<int> > &adj, int x, int y) {
    // for (vector<int>::size_type i = 0; i != adj[x].size(); i++) {
    //     if (adj[x][i] == y) return 1;
    // }
    // return 0;
    return ( std::find(adj[x].begin(), adj[x].end(), y) != adj[x].end() );
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) << std::endl;
}
