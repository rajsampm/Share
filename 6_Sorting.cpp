
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;

/*
size = 5
unsorted array :  7, 4, 2, 10, 9

step 1         :  2, 4, 7, 10, 9
step 2         :  2, 4, 7, 10, 9

step 3         :  2, 4, 7, 10, 9
step 4         :  2, 4, 7, 9 , 10

sorted   array :  2, 4, 7 ,9 ,10
*/
//             X         Y
// memory :   2466      13934
//            3           10
// void myswap(int &x,int &y){
//   int temp = x;
//   x = y;
//   y = temp;
// }
//pass by value
//pass by reference
int main(){

    // int x = 3;
    // int y = 10;
    // myswap(x, y);

    int arr[10];

    cout<<"Enter 10 elements : ";

    for(int i = 0 ; i < 10;i++){
      cin>>arr[i];
    }

    //sorting on arrays
    //sort(arr,arr + 10);
    //basic syntax : sort(arr,arr + size);

    //SORTING ON VECTORS :
    // vector<int > v;
    // v.push_back(3);
    // v.push_back(6);
    // v.push_back(9);
    // v.push_back(10);
    //
    // sort(v.begin(), v.end());

    // arr[0];
    // 5433 +0
    // arr[10];
    // arr[2];
    // 5433 + 2;
    // memory loc :     5433   5434  5435 . ........................ 5442  5443
    //                  8      10    2     5 9 100 32 59 73          88
    int start;
    for(start = 0; start < 9;start++){

        cout<<"Step number : "<<start+1<<endl;

        int var ;
        int minInd = start;

        for(var = start;var < 10;var++){
          if( arr[var] < arr[minInd]){
            minInd = var;
          }
        }
        //swap(arr[start],arr[minInd]);
        cout<<"Found minimum element which is : "<<arr[minInd]<<" at index : "<<minInd<<endl;
        int temp = arr[start];
        arr[start] = arr[minInd];
        arr[minInd] = temp;
        cout<<"Array at this step is : ";
        for(int g = 0;g < 10;g++){
          cout<<arr[g]<<" ";
        }
        cout<<"\n\n";

    }
    cout<<"Sorted array : ";

    for(int i = 0;i < 10;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
8 10 2 5 9      100 32 59 73 88
2 5 8 9 10      32 59 73 88 100

 1  23 93 349 29 12 198 398 32 9 8 32 89 12 91

// geeksforgeeks.org
// merge sort geeks for geeks
7  9  2 10 4 13

2  7  9    4  10 13

2  4  7  9  10  13
*/
/*

Enter 10 elements : 8 10 2 5 9 100 32 59 73 88
Step number : 1
Found minimum element which is : 2 at index : 2
Array at this step is : 2 10 8 5 9 100 32 59 73 88

Step number : 2
Found minimum element which is : 5 at index : 3
Array at this step is : 2 5 8 10 9 100 32 59 73 88

Step number : 3
Found minimum element which is : 8 at index : 2
Array at this step is : 2 5 8 10 9 100 32 59 73 88

Step number : 4
Found minimum element which is : 9 at index : 4
Array at this step is : 2 5 8 9 10 100 32 59 73 88

Step number : 5
Found minimum element which is : 10 at index : 4
Array at this step is : 2 5 8 9 10 100 32 59 73 88

Step number : 6
Found minimum element which is : 32 at index : 6
Array at this step is : 2 5 8 9 10 32 100 59 73 88

Step number : 7
Found minimum element which is : 59 at index : 7
Array at this step is : 2 5 8 9 10 32 59 100 73 88

Step number : 8
Found minimum element which is : 73 at index : 8
Array at this step is : 2 5 8 9 10 32 59 73 100 88

Step number : 9
Found minimum element which is : 88 at index : 9
Array at this step is : 2 5 8 9 10 32 59 73 88 100

Sorted array : 2 5 8 9 10 32 59 73 88 100


*/
