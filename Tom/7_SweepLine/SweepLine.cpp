//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


/*
You are given N vertical lines(parallel to Y axis) and M line segments
where each line segment is in the format (x1,y1) and (x2,y2)
i.e. it starts from (x1,y1)and ends on (x2,y2), we have to find
the total number of intersections of the line segments with the vertical lines.

Input format : First line contains two integers N and M
followed by N integers which are the X co-ordinates of the vertical lines,
which are followed by M lines each having 4 integers x1,y1,x2,y2.

Output the number of intersection points.
*/
// -10^6 to 10^6
#include<bits/stdc++.h>

using namespace std;




// pref  index    :   0      1     2  3  ..  10^6 .......  2*(10^6)
// corresponds to :  -10^6


// ind :     -5   -4   -3  -2  -1   0  1  2  3  4  5  6
// pref :     1    0    1   0   0   0  0  1  1  0  0  0
// after:     1    1    2   2   2   2  2  3  4  4   4  4
int main(){
    int size = 2000000 +2;
    int pref[size];

    for(int i = 0 ;i < size;i++){
      pref[i] = 0;
    }

    int n,m;
    cout<<"Enter the number of Vertical lines : ";cin>>n;
    cout<<"Enter the number of line segments  : ";cin>>m;

    for(int i = 0 ; i < n;i++){
      int x;cin>>x;
      x += pow(10,6);
      pref[x] = 1;
    }

    for(int i = 1 ; i < size;i++){
      pref[i] = pref[i-1] + pref[i];
    }

    //Number of intersections
    int ans = 0;
    for(int i = 0 ; i < m;i++){
      int x1,x2,y1,y2;
      cin>>x1>>y1>>x2>>y2;

      x1 += pow(10,6);
      x2 += pow(10,6);
      if(x1 > x2){
        swap(x1,x2);
      }
      //UPDATE
      if(x1 == x2){
        //No need to process

      }else{
        int number_of_occurences_till_right = pref[x2-1];
        int number_of_occurences_till_left = pref[x1];
        ans += number_of_occurences_till_right - number_of_occurences_till_left;
      }
    }

    cout<<"total intersections are : "<<ans<<endl;

    return 0;
}
