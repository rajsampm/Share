//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

// using vector

// 0 - 1
// 1 - 0, 3, 2
// 2 - 1 , 3
// 3 - 1, 2

vector<int> adj[100];
bool vis[100];

void BFS(int n,int start){
  list<int> q;

  q.push_back(start);
  vis[start] = true;

  while(q.size() > 0){
    int x = q.front();
    q.pop_front();

    cout<<x<<" ";

    for(int i = 0 ; i < adj[x].size();i++){
      int currentElement = adj[x][i];

      if(vis[currentElement] == false){
        q.push_back(currentElement);
        vis[currentElement] = true;
      }
    }
  }
}

int main(){

    cout<<"Put the number of nodes : ";
    int n;
    cin>>n;

    for(int i = 0; i < n+1;i++){
      adj[i].clear();
      vis[i] = false;
    }

    cout<<"Please enter the number of links : ";
    int k;
    cin>>k;

    for(int i = 0 ; i< k;i++){
      int a, b;
      cin>>a>>b;

      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int start;
    cout<<" Enter start point : ";
    cin>>start;
    BFS(n,start);
    return 0;
}
