//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;

/*

   INTERVAL TREE

   * Use case *
   We use Interval tree when we have a set of intervals
   and we need to make operations on these intervals like
   add a new interval or find if a given interval Xleft, Xright
   overlaps with any interval in the tree.

   * Implementaion Note*
   We can implement a  Binary Search Tree to
   maintain the intervals and with that we
   can do all the above operations in log(n) time.

   * Structure of a node *
   Every node will contain two integers (left) and (right)
   which correspond to the interval represented by the current
   node. Also each node will contain one more integer (high) which
   holds the max right  value of its generations.

   * Implementation *
   we will use the left varible as a key to make the BST.
*/

struct Interval{
  int low,high;
};
typedef struct Interval Interval;

struct Node{
  Interval *i;
  int m;
  Node *left,*right;
};
typedef struct Node Node;

Node * newNode(Interval i){
  Node * ret = new Node;
  ret->i = new Interval(i);
  ret->m = i.high;
  ret->left = ret->right = NULL;
  return ret;
}

//Funtion to insert Nodes in the TREE
Node* insert(Node *root,Interval i){
  if(root == NULL){
    Node * temp = newNode(i);
    return temp;
  }
  int lower_val_of_root = root->i->low;

  if(i.low < lower_val_of_root){
    root->left = insert(root->left,i);
  }
  else{
    root->right = insert(root->right,i);
  }

  if(root->m < i.high){
    root->m = i.high;
  }
  return root;
}

//A           _________________
//B        ___________

bool overlap(Interval a,Interval b){
  if(a.low <= b.high && b.low <= a.high){
    return true;
  }else{
    return false;
  }
}

Interval * searchOverlapping(Node * root, Interval passed_Interval){
  if(root == NULL ){
    return NULL;
  }else if(overlap(*(root->i), passed_Interval) == true){
    return root->i;
  }else if(root->left != NULL && root->left->m >= passed_Interval.low){
    return  searchOverlapping(root->left,passed_Interval);
  }else{
    return  searchOverlapping(root->right,passed_Interval);
  }
}

int main(){
    cout<<"Enter the number of Intervals you want ot enter : ";
    int n;cin>>n;
    Node *root = NULL;

    for(int i = 0 ; i < n;i++){
      cout<<"Enter "<<i+1<<" th interval : ";
      int a,b;cin>>a>>b;

      root = insert(root,{a,b});
    }

    cout<<"Enter Interval that you want to check if it overlaps : ";
    int a,b;cin>>a>>b;
    Interval * ret = searchOverlapping(root,{a,b});
    if(ret == NULL){
      cout<<"No overlapping intervals found !\n";
    }else{
      cout<<"Overlap found =  low : "<<ret->low<<" high : "<<ret->high<<endl;
    }
    return 0;
}

                    //         (10,15 , {25})
                    //     __________|
                    // (5,25 ,{25})
                    //
/*
Diagram :
//Interval : 3 to 7
//Interval : 30 to 33



                        (10,15 , {35})
                  ___________|___________
                  |                      |
            (5,25 ,{25})              (12,14 , {35})
        __________|_________                 |_________
        |                   |                          |
    (0,15 , {15})        (7,10 , {10})             (25,35, {35})

*/
