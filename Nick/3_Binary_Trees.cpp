
//Contact - gauravak007@gmail.com
//github  - www.github.com/gaurav1620

#include<bits/stdc++.h>

using namespace std;

//Topics covered in this file :
// 1. Creating Binary Trees
//
// 2. Inorder Traversal (Left , Root , Right)
//
// 3. Preorder Traversal (Root , Left , Right)
//
// 4. Postorder Traversal (Left ,  Right, root)
//
// 5. Level order Traversal
//
// 6. Print Any Given Level
//
// 7. Maximum depth
//

struct node{
    int data;
    struct node * left;
    struct node * right;

    node(int val){
      this -> data = val;
      left = right = NULL;
    }

};


void inorder(node* temp){
  if(temp == NULL){
    return ;
  }

  else{

    inorder(temp->left);

    cout<< temp->data <<" ";

    inorder(temp->right);
  }
}

void preorder(node* temp){
  if(temp == NULL){
    return ;
  }
  else{

    cout<< temp->data <<" ";

    preorder(temp->left);

    preorder(temp->right);
  }
}



void postorder(node* temp){
  if(temp == NULL){
    return ;
  }
  else{
    postorder(temp->left);
    postorder(temp->right);

    cout<< temp->data <<" ";
  }
}


void levelOrder(node* root){
  node* var = root;
  queue<node* > myq;

  myq.push(var);

  while(myq.size() > 0){
    var = myq.front();
    cout<< var-> data<<" ";
    myq.pop();

    if(var -> left != NULL){
      myq.push(var->left);
    }
    if(var-> right != NULL){
      myq.push(var->right);
    }
  }

}

void printGivenLevel(node * root, int level){
  if(level == 1){
    cout<<root->data<<" ";
  }else{

    if(root->left != NULL){

      node* leftChild = root->left;

      printGivenLevel(leftChild, level-1);
    }

    if(root->right != NULL){

      node* rightChild = root->right;

      printGivenLevel(rightChild, level-1);
    }
  }
}
int main(){

  node* root = new node(5);
  node* node1 = new node(7);
  node* node2 = new node(13);

  node* node3 = new node(2);
  node* node4 = new node(10);

  node* node5 = new node(17);
  node* node6 = new node(21);

  node* node7 = new node(9);
  node* node8 = new node(8);
  node* node9 = new node(6);

  root->left = node1;
  root->right = node2;

  node1->left = node3;
  node1->right = node4;

  node3->left = node5;
  node3->right = node6;
  node2->left = node7;
  node2->right = node8;
  node7->right = node9;

  // cout<<"Preorder travelsal : ";
  // preorder(root);
  // cout<<endl;

  // cout<<"Level order travelsal : ";
  // levelOrder(root);
  // cout<<endl;

  cout<<"Level 1 : ";
  printGivenLevel(root,1);
  cout<<endl;
  cout<<"Level 2 : ";
  printGivenLevel(root,2);
  cout<<endl;
  cout<<"Level 3 : ";
  printGivenLevel(root,3);
  cout<<endl;
  cout<<"Level4  : ";
  printGivenLevel(root,4);
  cout<<endl;

  return 0;
}

/*


 3. Preorder Traversal (Root , Left , Right)

 5  7   13

          5
          |
__________|__________
|                   |
7                   13





2  7   10  5  13


3. Preorder Traversal (Root , Left , Right)

5  (7  2   10 )  (13)


                    5
                    |
          __________|__________
          |                    |
          7                     13
    ______|______
    |            |
    2            10



output : 5  7  2 10
 stack :

5 , 7 , 13,  2, 10 , 9, 8

queue : 5

step 1 :
we will remove first and add its children to myQueue
queue : 7 , 13
print : 5

step 2 :
we will remove first and add its children to myQueue
queue : 13, 2 , 10
print : 5 , 7

step 3 :
we will remove first and add its children to myQueue
queue : 2 , 10 , 9 ,8
print : 5 , 7, 13

step 4 :
we will remove first and add its children to myQueue
queue :  10 , 9 ,8
print : 5 , 7, 13, 2

step 5 :
we will remove first and add its children to myQueue
queue :   9 ,8
print : 5 , 7, 13, 2, 10


step 6 :
we will remove first and add its children to myQueue
queue : 8
print : 5 , 7, 13, 2, 10 , 9


step 7 :
we will remove first and add its children to myQueue
queue :
print : 5 , 7, 13, 2, 10 , 9 , 8

                    5
                    |
          __________|__________
          |                   |
          7                   13
    ______|______       ______|_______
    |            |      |             |
    2            10     9             8



   inorderTraversal(v){

     inorderTraversal(v->left);

     print its own data ;

     inorderTraversal(v->right);
   }

   17   2    21    7     10        5       9   6   13    8


  inorder travelsal of 7   ---  17   2    21    7     10

  inorder travelsal of 13  --  9   6   13    8


  direct inorder traversal - 17   2   21  7  10  5  9  6  13  8


  3. Preorder Traversal (Root , Left , Right)

  5  (    7 (2  17   21)  (10)   )   (13 (9 6) (8))

  5   7   2  17  21  10  13   9  6  8


printLevl(root , 3)

PrintLevel(node 7 , 2)
PrintLevel(node 13 , 2)

PrintLevel(node 2 , 1)
PrintLevel(node 10 , 1)
PrintLevel(node 9 , 1)
PrintLevel(node 8 , 1)


                    5
                    |
          __________|__________
          |                   |
          7                   13
    ______|______       ______|_______
    |            |      |             |
    2            10     9             8
____|___                |____
|       |                    |
17     21                    6





*/
