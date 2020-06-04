
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

int mat[100][100];
int n;

int minDist(int dist[], bool vis[]){

  int best_distance = INT_MAX;
  int best_index;

  for(int i = 0;i < n;i++){
    if(vis[i] == false){
      if(dist[i] <= best_distance){
        best_distance = dist[i];
        best_index = i;
      }
    }
  }

  return best_index;
}

void dijkstras(int start){
  int dist[n];
  bool vis[n];

  //Initialise :
  for(int i = 0 ;i  < n;i++){
    dist[i] = INT_MAX;
    vis[i] = false;
  }

  // set the distance from the source to itself as zero
  dist[start] = 0;

  for(int i = 0;i < n - 1;i++){
    int u = minDist(dist,vis);
    vis[u] = true;

    for(int j = 0;j < n;j++){
      //Update j th element if its not visited
      if(vis[j] == false && mat[u][j] && dist[u] != INT_MAX && dist[u] + mat[u][j] < dist[j]){
        dist[j] = dist[u] + mat[u][j];
      }
    }
  }

  cout<<"Minimum distances from : "<<start<<endl;


  //Printing minimum distances :
  for(int i = 0 ; i < n;i++){
    cout<<"Index : "<<i<<" , dist : "<<dist[i]<<endl;
  }

}


int main(){
  cout<<"Enter number of nodes : ";
  cin>>n;
  int i,j;

  for(i = 0; i < n;i++){
    for(j = 0;j < n;j++){
      mat[i][j] = 0;
    }
  }

  cout << "Enter the number of links : ";
  int k;
  cin>>k;

  for(int i = 0 ; i < k;i++){
    cout<<"Enter link "<<i <<" : ";
    int a,b;cin>>a>>b;
    cout<<"Enter cost : ";
    int cost;cin>>cost;

    mat[a][b] = cost;
    mat[b][a] = cost;

  }

  int start;
  cout<<"Enter start point : ";
  cin>>start;
  dijkstras(start);
  return 0;
}
