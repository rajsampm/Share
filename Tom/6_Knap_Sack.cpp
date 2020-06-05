//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>
using namespace std;

/* Sack
//Capacity : 50

objects :  A    B    C
Wt      :  10   20   30
Value   :  60   100  120
*/

//
// dp [i] [j]   denotes :
// considering the first i elements
// and a sack of capacity  j
//
// dp[2][20] = 100;
//
// objects :  0    1     2
// Wt      :  10   20   30
// Value   :  60   100  120
//

/*

// objects :  0    1     2
// Wt      :  1    2    3
// Value   :  1    3    2

capacity : 5

     0    1    2   3    4    5    -- capacity
0    0    0    0   0    0    0
1    0    1    1   1    1    1
2    0    1    3   4    4    4
3    0    1    3   5    5    5


*/

int wt[100];
int val[100];
int n;
int capacity;

void knapSack(){
  int dp[n+1][capacity+1];

  for(int i = 0 ; i <= n;i++){
    //number_of_elements_ to choose from = i
    for(int j = 0 ; j <= capacity;j++){
      //j denotes the capacity of Sack
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }else{
        int current_element = i-1;
        int weight_of_current_element = wt[current_element];
        int value_of_current_element = val[current_element];

        if(weight_of_current_element <= j){
          //value_of_sack_if_current_element_is_taken =  vst;
          int vst = value_of_current_element + dp[i-1][j-weight_of_current_element];
          int vsnott = dp[i-1][j];

          dp[i][j] = max(vst,vsnott);
        }else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  cout<<"Maximum value of sack is  : "<<dp[n][capacity]<<endl;
}

int main(){
    cout<<"Enter the capacity of the knapsack : ";
    cin>>capacity;

    cout<<"Enter the number of the objects : ";
    cin>>n;

    cout<<"Enter objects in the following format : \n Weigh  Value\n";
    for(int i = 0; i < n;i++){
        cin>>wt[i];
        cin>>val[i];
    }
    knapSack();

    return 0;
}
