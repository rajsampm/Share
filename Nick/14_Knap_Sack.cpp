//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

//Aritcle - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//Video - https://www.youtube.com/watch?v=8LusJS5-AGo

#include<bits/stdc++.h>

using namespace std;
//
// we have a sack and the weight capacity of sack is given
//
// capacity : 5
//
// objects :  0    1     2

//            A    B    C
// weight  :  1    2     3
// value   :  1    3      2
//
//
//     0    1    2   3   4   5             -- current weight
// 0   0    0    0   0   0    0
// 1   0    1    1   1   1   1             -- best value of knapsack
// 2   0    1    3   4   4   4
// 3   0    1    3   4   4   5
//
// i = 2
// j = 2
//
// if B is taken = 3 + 0 = 3;
// if B not taken = dp[i-1][2] = 1;

int capacity;
int wt[100];
int val[100];
int n;

int knapsack(){
  int i,j;


  int dp[n+1][capacity+1];
  // capacity = 100
              // cap 10
              // cap if we take d becomes 5
              // dp[3][5];
              // wt  2   1  3   5
  // obj      :   A   B  C   D   E   F
  //
  //dp[3][10];

  //dp[i][j] corresponds to the maximum value
  // of knapsack we can get if we consider first
  // i elements and have a knapsack of j capacity
  for(int i = 0 ; i <= n;i++){

    for(int j = 0 ; j <= capacity;j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else if(wt[i-1] <= j){
        int current_elements_value = val[i-1];
        int current_elements_weight = wt[i-1];

        int value_if_taken =  current_elements_value + dp[i-1][j - current_elements_weight];
        int value_if_not_taken = dp[i-1][j];

        dp[i][j]  = max(value_if_taken, value_if_not_taken);

      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp[n][capacity];
}
int main(){

    cout<<"Enter the capacity of sack : ";
    cin>>capacity;

    cout<<"Enter the number of objects : ";
    cin>>n;

    cout<<"Please enter "<<n<<" values of format : \n Weight , value\n";

    for(int i = 0 ; i < n;i++){
      cin>>wt[i]>>val[i];
    }

    cout<<knapsack()<<endl;
    return 0;
}
