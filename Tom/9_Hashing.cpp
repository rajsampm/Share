
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

//array : 3 5  7  ....(1000).. .    23   45   79  19  10  3  19

// array : 6  9  2   10  3  5   7  13 , 12 , 8 : size 10 : range(min to max) : 2  to 13
// Hash table
//Selected number is 7;

//array : 1   2   4   ....   (5000)  ... 10 34  , 53

/*
O (1) - const time
O (n) -
O(n^2) -

comp from best to worst
o(1)
o(log(n))
o(n)
o(n^2)
o(2^n)



array of size n : n/2

n   +  n-1  + n-2  +  n-3  .. (n) ..  2  1

n * (n+1)/2
n*n

1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10  = 55


(10 * (11))/2 = (110)/2 = 55

*/

/*
eg : 6 % 7 = 6
eg : 9 % 7 = 2
eg : 2 % 7 = 2
eg : 10 % 7 = 3
eg : 5 % 7 = 5
eg : 13 % 7 = 5
eg : 12 % 7 = 4

0
1
2  -  9 , 2
3  - 10
4  - 12
5  - 5, 13
6  -  6


//array : 3 5  7  ....(1000).. .65    23   45   79  19  10  3  19
range 3 - 100
number 50

eg 65 % 50 15

SIZE 1000
FIND 100 numbers

65 % 50  - 15

0 - A  B
1 - G  H  K
2 - J W T
3  - R  T  M
4  - E  P  M
5  - R Q
.
.
15   65, d ,
.
.
50 - R

prev example we had 100 querries and the array size was 1000
time complexity   -  q * n;  // n is length of array
                  - 100 * 1000
                  100000

hashtable :          q * 3
                    100 * 3
                    300


*/
int main(){

    // cout<<" 7%3  "<< 7 % 3<<endl;
    // cout<<" 13%7  "<< 13 % 7<<endl;
    // cout<<" 18%4  "<< 18 % 4<<endl;
    //
    // cout<<" 16  %  4  "<< 16 % 4<<endl;

    int arr[10];
    arr[0] = 6;
    arr[1] = 13;
    arr[2] = 16;
    arr[3] = 1;
    arr[4] = 18;
    arr[5] = 23;
    arr[6] = 68;
    arr[7] = 88;
    arr[8] = 610;
    arr[9] = 93;

    int selected_number = 6;
    vector<int> hashtable [6] ;


    cout<<"ARRAY : ";
    for(int i = 0 ; i < 10;i++){
        cout<<arr[i]<<" ";
        int mod = arr[i]%selected_number;
        hashtable[mod].push_back(arr[i]);
    }
    cout<<endl;

    cout<<"HASH TABLE : \n";

    for(int i = 0 ; i < 6;i++){
      cout<<"Index : "<<i<<"  : ";

      for(int j = 0;j < hashtable[i].size();j++){
        cout<<hashtable[i][j]<<" ";
      }

      cout<<endl;
    }

    cout<<"Enter element to find : ";
    int x;cin>>x;
    int xmod = x % selected_number;

    bool found = false;

    for(int i = 0;i < hashtable[xmod].size();i++){
          if(x == hashtable[xmod][i]){
            found = true;
          }
    }
    if(found == true){
      cout<<"  Found !!\n";
    }
    else{
      cout<<" NOT Found !!\n";
    }

    return 0;
}
