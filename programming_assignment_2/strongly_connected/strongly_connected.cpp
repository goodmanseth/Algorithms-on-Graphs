#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// returns the reverse graph of its input
vector<vector<int>> reverseGraph(vector<vector<int>> adj) {
    vector<vector<int>> adjRev(adj.size(),vector<int>());
    vector<vector<int>>::size_type i;
    for(i=0; i!=adj.size();i++) {
        vector<int>::iterator j;
        for(j=adj[i].begin(); j!=adj[i].end(); ++j) {
           adjRev[*j].push_back(i);
        }
    }
    return adjRev;
}

// explore
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v, vector<int> &order) {
    visited[v] = true;
    vector<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); ++i) {
        if (!visited[*i]) dfs(adj,visited,*i,order);
    }
    order.push_back(v);
}

// function overloading (to not include order)
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v) {
    visited[v] = true;
    vector<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); ++i) {
        if (!visited[*i]) dfs(adj,visited,*i);
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int result = 0;
    vector<vector<int>> adjRev = reverseGraph(adj);
    vector<bool> visited(adj.size(),0);
    vector<int> order;
    
    // dfs on G-rev
    vector<vector<int>>::size_type i;
    for(i=0; i!=adjRev.size(); ++i) {
        if (!visited[i]) dfs(adjRev,visited,i,order);
    }
    
    // dfs on G in reverse postvisit order of G-rev
    std::reverse(order.begin(),order.end());
    std::fill(visited.begin(),visited.end(),0);
    vector<int>::size_type j;
    for(j=0; j!=order.size(); ++j) {
        if (!visited[j]) {
            dfs(adj,visited,j);
            result += 1;
        }
    }

    return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
