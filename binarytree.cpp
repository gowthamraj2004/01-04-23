#include <iostream>
using namespace std;
struct node{ 
    int data;
    node* left;
    node* right;
    node(int data){
        this->data= data;
        this->left=NULL;
        this->right=NULL;
    }
};
class binarytree{
public:
node* root;
    binarytree(){
        root=NULL;
    }

void addnode(int data){
    node* newnode= new node(data);
    if(root == NULL){
        root = newnode;
    }
    else{
        node* focusnode=root;
        node* parent;

        while(true){
            parent = focusnode;
            if(data < focusnode->data){
                focusnode = focusnode->left;
                if(focusnode == NULL){
                    parent->left = newnode;
                    return;
                }
            }
            else{
                focusnode = focusnode->right;
                if(focusnode==NULL){
                    parent->right = newnode;
                    return;
                }
            }
        }
    }
}
void preordertraversal(node* focusnode){
    if(focusnode != NULL){
        cout<< focusnode->data<<" ";
        preordertraversal(focusnode->left);
        preordertraversal(focusnode->right);
    }
}
void inorder(node* focusnode){
    if(focusnode !=NULL){
        inorder(focusnode->left);
        cout<<focusnode->data<<" ";
        inorder(focusnode->right);
    }
}
void postorder(node* focusnode){
    if(focusnode !=NULL){
        postorder(focusnode->left);
        postorder(focusnode->right);
        cout<<focusnode->data<<" ";
    }
}
};
int main(){
    binarytree tree;
    tree.addnode(50);
    tree.addnode(5);
    tree.addnode(40);
    tree.addnode(45);
    tree.addnode(20);
    tree.addnode(25);
    tree.addnode(100);
    tree.preordertraversal(tree.root);
    cout<<"\n";
    tree.inorder(tree.root);
    cout<<"\n";
    tree.postorder(tree.root);
    cout<<"\n";
    return 0;
}