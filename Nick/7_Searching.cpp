
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;
//
//             m-1  m   m+1
// 1 2 3 4 5 6 7    8   9   10 11 12 13 14 15

int binarySearch(int arr[],int left, int right, int toFind){
  int mid = (left+right)/2;

  if(left == right){
    if(arr[left] == toFind){
      return left;
    }else{
      return -1;
    }
  }
  if(left > right){
    return -1;
  }
  if(arr[mid] == toFind){
    return mid;
  }

  if(toFind < arr[mid]){
    binarySearch(arr,left , mid-1, toFind);
  }else{
    binarySearch(arr,mid+1,right, toFind);
  }

}

int main(){

  int arr[10];

  arr[0] = 19;
  arr[1] = 21;
  arr[2] = 14;
  arr[3] = 9;
  arr[4] = 1;
  arr[5] = 3;
  arr[6] = 100;
  arr[7] = 333;
  arr[8] = 444;
  arr[9] = 72;

  // cout<<"Enter element to search : ";
  // int n;cin>>n;
  // bool found = false;
  //
  // for(int i = 0 ; i< 10;i++){
  //   if(arr[i] == n){
  //     cout<<"FOUND : "<<n<<" at index : "<<i<<endl;
  //     found = true;
  //   }
  // }
  //
  // if( found == false){
  //   cout<<"Element not found !"<<endl;
  // }

  sort(arr,arr+10);
  for(int i = 0 ;i < 10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Enter element to search : ";
  int n;cin>>n;

  int ind = binarySearch(arr,0,9,n);

  if(ind == -1){
    cout<<"Not found !!"<<endl;
  }else{
    cout<<"FOUND : "<<n<<" at index : "<<ind<<endl;
  }


  return 0;
}
