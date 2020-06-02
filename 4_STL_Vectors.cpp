
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

// STL
// Vectors

int main(){
  //Declaration
  vector<int> myVector;
  //Adding elements
  myVector.push_back(3);
  myVector.push_back(7);
  myVector.push_back(1);
  myVector.push_back(8);
  myVector.push_back(2);
  myVector.push_back(9);

  //indices  0  1  2
  //Vector : 3  7  1
  //Size
  int n = myVector.size();


  for(int i = 0 ;i < n;i++){
    cout<<myVector[i]<<" ";
  }
  cout<<endl;


  //Clear
  cout<<"Before clearing : ";
  cout<<myVector.size()<<endl;
  myVector.clear();
  cout<<"After clearing clearing : ";
  cout<<myVector.size()<<endl;


    return 0;
}
