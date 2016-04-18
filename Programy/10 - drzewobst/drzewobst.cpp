#include<iostream>
using namespace std;

struct BSTNode{
    int key;
    BSTNode* parent,* left,* right;
};

BSTNode* add(BSTNode* proot, int key);
void inOrder(BSTNode* proot);
BSTNode* bstMin(BSTNode* proot);
BSTNode* bstMax(BSTNode* proot);
BSTNode* bstAncestor(BSTNode* proot);
BSTNode* bstSuccessor(BSTNode* proot);

int main()
{
    BSTNode* proot=NULL;
    BSTNode* ptr;
    proot=add(proot, 10);
    proot=add(proot, 14);
    proot=add(proot, 13);
    proot=add(proot, 12);
    proot=add(proot, 11);
    proot=add(proot, 2);
    proot=add(proot, 3);
    inOrder(proot);
    ptr=proot->left->right;
    cout<<endl<<ptr->key<<endl;
    //ptr=bstAncestor(ptr);
    ptr=bstSuccessor(ptr);
    if(ptr)cout<<endl<<ptr->key;

}

//DOdawanie BST
BSTNode* add(BSTNode* proot, int key){
    BSTNode* ptr = new BSTNode;
    ptr->key=key;
    ptr->left=ptr->right=ptr->parent=NULL;
    if(proot==NULL) return ptr;
    BSTNode* parent,* root;
    root=parent=proot;
    while(proot!=NULL){
        parent=proot;
        if(proot->key>key) proot=proot->left;
            else proot=proot->right;
    }
    if(parent->key>key)parent->left=ptr;
    else parent->right=ptr;
    ptr->parent=parent;
    return root;
}

//WYpisz inOrder
void inOrder(BSTNode* proot){
    if(proot){
        inOrder(proot->left);
        cout<<proot->key<<" ";
        inOrder(proot->right);
    }
}

//Znajdz minimum
BSTNode* bstMin(BSTNode* proot){
    if(!proot) return NULL;
    while(proot->left){
        proot=proot->left;
    }
    return proot;
}

//znajdz maksimum
BSTNode* bstMax(BSTNode* proot){
    if(!proot) return NULL;
    while(proot->right){
        proot=proot->right;
    }
    return proot;
}

//znajdz poprzednika
BSTNode* bstAncestor(BSTNode* proot){
    if(proot->left) return bstMax(proot->left);
    while(proot->parent && proot->parent->left==proot){
        proot=proot->parent;
    }
    if(!proot->parent) return NULL;
    return bstMax(proot->parent->left);
}

//znajdz nastepnika
BSTNode* bstSuccessor(BSTNode* proot){
    if(proot->right) return bstMin(proot->right);
    while(proot->parent && proot->right==proot){
        proot=proot->parent;
    }
    if(!proot->parent) return NULL;
    return bstMin(proot->parent->right);
}
