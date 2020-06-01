
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620
#include<bits/stdc++.h>

using namespace std;

//Topics coveres in this file :
// memorisation (dynamic Programming)

int array_of_fibinacci[100];

// array index  :  1    2    3  4   5   6    7
// array values :  0    1    1  2  -1   -1  -1

int count1 = 0;
//Old fib funtion without memorization
int fib(int n){
  count1 = count1 +1;
  if(n == 1){
    return 0;
  }
  else if(n == 2){
    return 1;
  }
  else{
    return fib(n-1)+fib(n-1);
  }
}

int count2 = 0;
int fibonacci(int n){
  count2 = count2 +1;
  //4
  if(array_of_fibinacci[n] == -1){
    array_of_fibinacci[n] = fibonacci(n-1)+fibonacci(n-2);
    return array_of_fibinacci[n];
  }
  else{
    return array_of_fibinacci[n];
  }
}

int main(){
  for(int i = 0 ;i < 100;i++){
    array_of_fibinacci[i] = -1;
  }
  array_of_fibinacci[1] = 0;
  array_of_fibinacci[2] = 1;

  cout<<"Enter a number : ";
  int n;
  cin>>n;
  //cout<<"Factorial of "<<n<<" is : "<<factorial(n)<<endl;
  cout<<"Fibonacci with memorisaion "<<n<<" is : "<<fibonacci(n)
      <<" took "<<count2<<" steps."<<endl;
  cout<<"Fibonacci without memorisaion "<<n<<" is : "<<fib(n)
          <<" took "<<count1<<" steps."<<endl;

  return 0;
}

//Time complexity charts
//Ranked from highest complexity (ie more time to compute) to lowest
//  2 ^ n
//  n ^ 2
//   n
//   log(n)
//   1
