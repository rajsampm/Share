
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;


//queue : A , B , C , D

int main(){

    queue<int> myQueue;

    myQueue.push(6);
    myQueue.push(8);
    myQueue.push(10);
    myQueue.push(1);

    cout<<"First element is : "<<myQueue.front()<<endl;
    cout<<"Size before popping : "<<myQueue.size()<<endl;
    myQueue.pop();
    cout<<"First element after popping is : "<<myQueue.front()<<endl;
    cout<<"Size after popping : "<<myQueue.size()<<endl;

    return 0;
}
