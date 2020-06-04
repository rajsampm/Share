//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>
using namespace std;

//Topics covered in this file : Recurtion
// 1. Factorial
// 2. Fibonacci
//
/*
5! = 5*4*3*2*1
3! = 3*2*1

5! = 5 * 4 * 3 * 2 * 1
4! = 4 * 3 * 2 * 1

n! = n* (n-1)!
*/

int factorial(int n){
  //n = 5
  if(n == 1){
    return 1;
  }else {
    return n*factorial(n-1);

    //return 4 * factorial(3);
  }
}

int factorial(int n){
  return n * factorial(n-1);
}

int fibonacci(int n){
  if(n == 1){
    return 0;
  }else if(n == 2){
    return 1;
  }else{
    //n > 2
    return fibonacci(n-1) + fibonacci(n-2);
  }
}


//Fibonacci
/*
fibonacci(n) = fibonacci(n-1) + fibonacci(n-1);
fibonacci(8) = fibonacci(7) + fibonacci(6);
indices : 1   2   3   4   5  6   7   8   9    10  11  12  13
values :  0   1   1   2   3   5  8   13  21   34  55
*/

int main(){
    cout<<"Enter a number : ";
    int n;
    cin>>n;
    //cout<<"Factorial of "<<n<<" is : "<<factorial(n)<<endl;
    cout<<"Fibonacci of "<<n<<" is : "<<fibonacci(n)<<endl;
    return 0;
}
