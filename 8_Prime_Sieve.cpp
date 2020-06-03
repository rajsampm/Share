
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

//Prime nos

// 10 : 1 , 10 , 2, 5
//
// 7 : 1, 7
//
// primes : 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43
//
//|1|  2  3  |4|  5  |6|  7   |8|  |9|  |10|  11  |12|  13  |14|  |15|  |16|  17  |18|  19  |20| |21| |22|  23  |24|  |25|
//
// x * x : Z
// Z is not a primes

int  isPrime[110];


int main(){

    for(int i = 0; i < 110;i++){
      isPrime[i] = -1;
    }

    //Prime sieve

    isPrime[1] = 1;

    for(int i = 2; i < 110;i++){

      if(isPrime[i] == -1){
        for(int j = i*i;j < 110; j = j+i){
          isPrime[j] = i;
        }
      }
    }

    cout<<"Primes : \n";
    for(int i = 1 ;i < 110;i++){
      if(isPrime[i] != -1){
        cout<<"Is not prime : "<<i<<" factor is : "<<isPrime[i]<<endl;
      }else{
        cout<<"Is  a  prime : "<<i<<endl;
      }
    }
    cout<<endl;

    return 0;
}
