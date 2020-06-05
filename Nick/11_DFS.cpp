//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;



vector<int> adj[100];
bool vis[100];

void DFS(int start){
  vis[start] = true;
  cout<<start<<" ";

  for(int i = 0 ; i < adj[start].size();i++){
    int currentElement = adj[start][i];
    if(vis[currentElement] == false){
      DFS(currentElement);
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
  DFS(start);

  return 0;
}
