
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;


// Get left child of index i : 2*i +1
// Get right child of index i : 2*i +2
//
//         0  1  2   3   4   5  6   7 8 9 10 11 12 , 13, 14
// tree : [7, 8 ,9 , 10 ,11,12,13 , N, N, N, N, N N, ,N , N];
//
//              7
//           ___|___
//           8       9
//         __|__   __|__
//         10  11  12   13
//


//           0   1   2    3   4   5
// array :  [1 , 3 , 5,  7,  9 , 11]


   //         33
   //    13        20
   // 5     7    9    11

int getMid(int ss,int se){
  return ss + (se-ss)/2;
}


//  si -> segment tree index.
//  ss -> starting index of array  for index si
//  se -> ending index of array    for index si
//  qs -> index of querry start
//  qe -> index of querry end

int getSumUtil(int st[],int ss,int se,int qs,int qe,int si){

  // cout<<" ss : "<<ss;
  // cout<<" se : "<<se;
  // cout<<" qs : "<<qs;
  // cout<<" qe : "<<qe;
  // cout<<" si : "<<si;

  if(qs <= ss && qe >= se){
    return st[si];
  }else if(qs > se || qe < ss){
    return 0;
  }
  int mid = getMid(ss,se);
  int ans = getSumUtil(st,ss,mid,qs,qe, 2*si +1) +
            getSumUtil(st,mid+1,se,qs,qe,2*si+2);
  return ans;
}

void getSum(int st[],int n,int start,int end){
  if(start < 0 || start >= n || end<0 || end >= n || start > end){
    cout<<"Invalid Input !";
    return ;
  }
  int ans = getSumUtil(st,0,n-1,start,end,0);
  cout<<"Sum of elements from range : "<<start<<" to "<<end<<" are : "<<ans<<endl;
}


void updateValueUtil(int st[],int ss,int se,int i,int diff,int si){
  if(i < ss || i > se){
    return;
  }
  st[si] += diff;
  if(ss != se){
    int mid = getMid(ss,se);
    updateValueUtil(st,ss,mid,i,diff,2*si+1);
    updateValueUtil(st,mid+1,se,i,diff,2*si+2);
  }
}


void updateValue(int arr[],int st[],int n,int i,int new_value){
  if( i< 0 || i >= n){
    cout<<"Bad index passed !\n";
    return;
  }
  int diff = new_value - arr[i];
  arr[i] = new_value;
  updateValueUtil(st,0,n-1,i,diff,0);
}


int constructSTUtil(int arr[],int ss,int se,int st[],int  si){

  if(ss == se){
    st[si] = arr[ss];
    return arr[ss];
  }else{
    int mid =  getMid(ss,se);
    st[si] = constructSTUtil(arr,ss,mid,st,si*2 +1) +
                 constructSTUtil(arr,mid+1,se,st,si*2 +2);
    return st[si];
  }
}

int * constructST(int arr[],int n){
  int x = (int)(ceil(log2(n)));
  int max_size = 2*(int)pow(2,x)-1;

  int *st = new int[max_size];

                  //  L  R     ST_ind
  constructSTUtil(arr,0,n-1,st,  0);

  return st;
}
int main(){

  int n;
  cout<<"Enter the length of array : ";
  cin>>n;

  int arr[n];
  cout<<"Enter "<<n<<" elements : ";
  for(int i = 0 ; i < n;i++){
    cin>>arr[i];
  }

  int *st = constructST(arr,n);

  for(int i = 0 ;i < 2*n;i++)cout<<i<<" : "<<st[i]<<endl;

  cout<<"Querry format : \n";
  cout<<"1  X  Y  ==>  Get the sum of numbers from index X to Y\n";
  cout<<"2  I  U  ==>  Change Number at index I to U\n";

  cout<<"Enter number of querries : ";
  int q;cin>>q;
  for(int i = 0 ; i < q;i++){
    int a,b,c;cin>>a>>b>>c;
    if(a == 1){
        getSum(st,n,b,c);
    }else{
        int ind = b;
        int updated_Value = c;
        updateValue(arr,st,n,ind,updated_Value);
    }
  }

  return 0;
}
