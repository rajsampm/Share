//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;



vector<int> adj[100];
bool vis[100];

void BFS(int start){
  queue<int> q;
  q.push(start);
  vis[start] = true;

  while(q.size() > 0){
    int x = q.front();
    q.pop();

    cout<<x<<" ";
    for(int i = 0;i < adj[x].size();i++){
      int currentElement = adj[x][i];
      if(vis[currentElement] == false){
        q.push(currentElement);
        vis[currentElement] = true;
      }
    }
  }
}


int main(){
  cout<<"enter the number of nodes : ";
  int n;cin>>n;

  for(int i = 0 ; i < n;i++){
    vis[i] = false;
    adj[i].clear();
  }

  cout<<"Please enter the number of links : ";
  int k;
  cin>>k;

  for(int i = 0 ; i < k;i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout<<"Please enter a starting node : ";
  int start;cin>>start;
  BFS(start);

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
