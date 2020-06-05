//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

//Must watch Video on KMP - https://www.youtube.com/watch?v=V5-7GzOfADQ
//Article - https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

#include<bits/stdc++.h>
using namespace std;

/*
 *
LPS / PI - Longest prefix that is also a suffix

Example 1 :
            A   A   A   A
  lps       0   1   2   3

Example 2:
            A   B   C   D
            0   0   0   0

Example 3:
            A   A   A   C   A   A   A   A   A   C
            0   1   2   0   1   2   3   3   3   4

Example 4:
            A   A   A   B   A   A   A
            0   1   2   0   1   2   3

*/

// ind  0  1  2  3  4  5  6  7  8  9  10  11   12
// A =  A  B  C  D  E  A  B  C  D  A  A    B   C
// B =           D  E  A

 //
 //   ind  0  1  2  3  4  5  6  7  8  9  10
 //   S =  A  B  C  D  E  F   A  B  C  E  A  A  B  C
 // pat =                     A  B  C  E
// runtime is : len(A) * len(B);

void naiveSearch(string s,string pat){
  if(pat.length() > s.length()){
    cout<<"Pattern not found !\n";
    return;
  }


  for(int i = 0; i < s.length() - pat.length();i++){
    bool found = true;
    for(int j = 0;j < pat.length();j++){
      if(s[i+j] != pat[j]){
        found = false;
        break;
      }
    }
    if(found == true){
      cout<<"The pattern was found at index : "<<i<<endl;
      return ;
    }
  }
  cout<<"Pattern not found !\n";
  return;
}

//KMP

//    ind  0  1  2  3  4  5  6  7  8  9  10
//    S =  A  A  A  A  A  A  A  A  A  A   B
//   pat=  A  A  A  B
//
//
//   S =  A  A  B  A   A  C  A  A  D A  A
// pat =        A  A  D  A
//
// pa

//runtime : O(len(a));

// void computeLPS(string pat,array){
//
// }
//
// KMP(s,pat){
//   computes the LPS array
//
//   LPS array to find the matching patern;
//
// }

int main(){

    string s,pat;
    cout<<"Enter string : ";
    cin>>s;
    cout<<"Enter pattern to search : ";
    cin>>pat;

    naiveSearch(s,pat);
    return 0;
}
