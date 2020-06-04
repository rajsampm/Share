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

void DFS(int n){
  vis[n] = true;
  cout<<n<<" ";

  for(int i = 0 ; i < adj[n].size();i++){
    int currentElement = adj[n][i];
    if(vis[currentElement] == false){
      DFS(currentElement);
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
    

    DFS(0);

    return 0;
}
