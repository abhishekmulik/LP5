%%writefile hpc-1.cpp
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define N 1000

vector<int> adj[N];
bool visited[N];
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
   
    while (!q.empty()){

      int u = q.front();
      q.pop();
      cout << u << " ";

     #pragma omp parallel for
     for (int i = 0; i < adj[u].size(); i++){

      int v = adj[u][i];
      if (!visited[v]){

         visited[v] = true;
         q.push(v);
     }
    }
  
  }
}


void dfs(int u){
	visited[u] = true;
	cout << u << " ";

    #pragma omp parallel for
    for (int i = 0; i < adj[u].size(); i++){

     int v = adj[u][i];
     if (!visited[v]){

     dfs(v);
   }
   }
}

int main() {

    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cout << "Enter the edges (x y): ";
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int start;
    cout << "Enter the starting vertex for traversal: ";
    cin >> start;

    cout << "BFS: ";
    memset(visited, false, sizeof(visited));
    bfs(start);

    cout << "DFS: ";
    memset(visited, false, sizeof(visited));
    dfs(start);
  

    return 0;
}

