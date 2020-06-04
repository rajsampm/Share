
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620


#include<bits/stdc++.h>

using namespace std;

struct node{
  int data;
  struct node * left;
  struct node * right;

};
typedef  struct node node;

node* createNode(int passedData){
  node * newNode = new node;
  newNode->data = passedData;

  newNode->left = newNode->right = NULL;

  return newNode;
}

node* LCA(node* root,int person1 , int person2){

    if(root == NULL){
      return NULL;
    }

    if(root-> data == person1 || root->data == person2){
      return root;
    }

    if(root->left == NULL && root->right == NULL){
      return NULL;
    }

    node* leftCall = LCA(root->left,person1,person2);
    node* rightCall = LCA(root->right,person1,person2);

    //Denotes the one of the person is on left subtree
    // and other on right subtree, this shows us that
    // current element is the LCA
    if(leftCall != NULL && rightCall != NULL){
      return root;
    }

    if(leftCall != NULL){
      return leftCall;
    }
    if(rightCall != NULL){
      return rightCall;
    }

    return NULL;
}

bool find(node* root,int toFind){
  if(root == NULL){
    return false;
  }
  if(root->data == toFind){
    return true;
  }

  if(find(root->left,toFind) || find(root->right,toFind) ){
    return true;
  }else{
    return false;
  }
}
int main(){

  node *nodeA = createNode(1);

  node *nodeB1 = createNode(2);
  node *nodeB2 = createNode(3);

  node *nodeC1 = createNode(4);
  node *nodeC2 = createNode(5);
  node *nodeC3 = createNode(6);
  node *nodeC4 = createNode(7);

  node *nodeD1 = createNode(8);
  node *nodeD2 = createNode(9);
  node *nodeD3 = createNode(10);
  node *nodeD4 = createNode(11);
  node *nodeD5 = createNode(12);
  node *nodeD6 = createNode(13);
  node *nodeD7 = createNode(14);
  node *nodeD8 = createNode(15);

  nodeA->left = nodeB1;
  nodeA->right = nodeB2;

  nodeB1->left = nodeC1;
  nodeB1->right = nodeC2;

  nodeB2->left = nodeC3;
  nodeB2->right = nodeC4;


  nodeC1->left = nodeD1;
  nodeC1->right = nodeD2;

  nodeC2->left = nodeD3;
  nodeC2->right = nodeD4;

  nodeC3->left = nodeD5;
  nodeC3->right = nodeD6;

  nodeC4->left = nodeD7;
  nodeC4->right = nodeD8;

  cout<<"Enter two elements : ";
  int a,b;
  cin>>a>>b;

  node* lca = LCA(nodeA,a,b);

  bool g =find(nodeA,a);
  bool k =find(nodeA,b);

  if(lca == NULL || g == false || k == false){
    cout<<"One or both of the elements is not present in the tree !\n";
  }else{
    cout<<lca -> data<<endl;
  }



  return 0;
}
