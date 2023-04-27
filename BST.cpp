#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL){  //if tree is empty return null
        return;
    }
    traverseInOrder(root ->left);  //first traverse the left subtree
    printf("%d ",root ->key);     //then the root
    traverseInOrder(root ->right);    //and the right subtree
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    if (root==NULL){    //look if the tree is empty or not
        struct node *newNode = new node;    //creating a new node
        newNode->key = key;    //assigning the keyvalue to the node
        newNode->left= NULL;    //creating empty left and right subtrees for the node
        newNode->right= NULL;
        return newNode;
    }
    
    if ( key<=root->key){    //search for the relevent position for inserting
        root->left =insertNode(root->left,key);
    }else{
        root->right =insertNode(root->right,key);
    }
    return root;
}
//function to find the maximum of a tree
struct node* findMaximum(struct node* root){
    while(root->right != NULL) {  //if its the maximum it doesnt have a right sub tree
        root = root->right;}
            return root;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root==NULL){  //if tree is empty there is nothing to delete
        return root;
    }else if (key < root->key){  //if key to delete is less than the root go for the left sub tree
        root->left=deleteNode(root->left,key);
    }else if (key > root->key){  //if key to delete is greater than the root go for the right sub tree
        root->right =deleteNode(root->right,key);
    }else if (key == root->key){   //if key to delete is equal to the root check for the cases 
        if ((root->left==NULL)and(root->right==NULL)){
            delete root;   //case where root has no children
            root =NULL;
            
        }
        else if (root->right==NULL){     //cases where when there is only one child
            struct node *nodeToDelete=root;
            root = root ->left;
            delete nodeToDelete;
            
        }else if (root->left==NULL){
            struct node *nodeToDelete=root;
            root = root ->right;
            delete nodeToDelete;
            
        }else{   //case where when there are two children
            struct node *tempory = findMaximum(root->left);
            root->key=tempory->key;
            root->left=deleteNode(root->left,tempory->key);
            
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}