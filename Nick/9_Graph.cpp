//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;
//
// 1. Adjecency matrix
//
// mat
//      0    1    2     3
// 0    T    T    F     F
// 1    T    T    T     T
// 2    F    T    T     T
// 3    F    T    T     T
//
//
// check if there is a link between 2 and 3 :
//   check if mat[2][3] == true;
//
// int n;
// take input n as the number of nodes
//
// create a matrix of n * n
// int mat[n][n] make all elements an the matrix as false
//
// int k which is the number of links in total graph
// k = 4;
//
// 0  1
// 1  2
// 2  3
// 3  1
//
// x  y
// mat[x][y] = true;
// mat[y][x] = true;
//
// 2 method adjacency list:
//
// vector<int> adj[4];
//
// adj[0] - 1
// adj[1] - 3 , 2, 1
// adj[2] - 1 , 3
// adj[3] - 1, 2
//
// k
//
// x y
//
// adj[x].push_back(y);
// adj[y].push_back(x);

int main(){
  cout<<"enter the number of nodes : ";
  int n;cin>>n;

  vector<int> adj[n];

  cout<<"Please enter the number of links : ";
  int k;
  cin>>k;

  for(int i = 0 ; i < k;i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  /*
  0 - 1 2 3
  1 - 0 4 5
  2 - 0 4
  3 - 0 5
  4 - 1 2
  5 - 1 3

  */
  return 0;
}
