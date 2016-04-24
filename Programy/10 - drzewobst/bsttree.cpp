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
void bstRemoveNode(BSTNode* proot);
BSTNode* bstFindAndRemove(BSTNode* proot, int val);
void bstRemoveNodeCormen(BSTNode* &proot, int val);
void insertRecursive(BSTNode* &proot, int key);
int bstSumConstMemory(BSTNode* proot);
int bstSumRecursive(BSTNode* proot);

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
    proot=add(proot, 6);
    proot=add(proot, 5);
    proot=add(proot, 3);
    proot=add(proot, 4);
    proot=add(proot, 1);

    inOrder(proot);
    ptr=proot->left->right;
    cout<<endl<<ptr->key<<endl;
    inOrder(proot);
    //proot=bstFindAndRemove(proot, 2);
    bstRemoveNodeCormen(proot, 10);
    cout<<endl;
    inOrder(proot);

    cout<<endl;
    ptr=NULL;
    insertRecursive(ptr, 10);
    insertRecursive(ptr, 15);
    insertRecursive(ptr, 16);
    insertRecursive(ptr, 14);
    insertRecursive(ptr, 13);
    insertRecursive(ptr, 5);
    insertRecursive(ptr, 6);
    inOrder(ptr);
    cout<<endl<<bstSumConstMemory(proot)<<" Recursive: "<<bstSumRecursive(proot);
    cout<<endl<<bstSumConstMemory(ptr)<<" Recursive: "<<bstSumRecursive(ptr);

}


//Insert node to tree
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

void insertRec(BSTNode* proot, BSTNode* parent, int key){
    if(proot==NULL){
        BSTNode* ptr=new BSTNode;
        ptr->left=ptr->right=NULL;
        ptr->key=key;
        if(parent->key>key) parent->left=ptr;
                else parent->right=ptr;
        ptr->parent=parent;
        return;
    }
    if(proot->key>key)insertRec(proot->left, proot, key);
        else insertRec(proot->right, proot, key);
}

void insertRecursive(BSTNode* &proot, int key){
    if(!proot){
        proot=new BSTNode;
        proot->key=key;
        proot->parent=proot->left=proot->right=NULL;
        return;
    }
    if(proot->key>key) insertRec(proot->left, proot, key);
        else insertRec(proot->right, proot, key);
}


//Find node
BSTNode* bstFind(BSTNode* proot, int val){
    while(proot && proot->key!=val)
    if(proot->key>val)proot=proot->left;
        else proot=proot->right;
    return proot;
}
//Walk inOder
void inOrder(BSTNode* proot){
    if(proot){
        inOrder(proot->left);
        cout<<proot->key<<" ";
        inOrder(proot->right);
    }
}

//Znajdz min
BSTNode* bstMin(BSTNode* proot){
    if(!proot) return NULL;
    while(proot->left){
        proot=proot->left;
    }
    return proot;
}

//Find max
BSTNode* bstMax(BSTNode* proot){
    if(!proot) return NULL;
    while(proot->right){
        proot=proot->right;
    }
    return proot;
}

//Find ancestor
BSTNode* bstAncestor(BSTNode* proot){
    if(proot->left) return bstMax(proot->left);
    while(proot->parent && proot->parent->left==proot){
        proot=proot->parent;
    }
    return proot->parent;
}

//Find successor
BSTNode* bstSuccessor(BSTNode* proot){
    if(proot->right) return bstMin(proot->right);
    while(proot->parent && proot->parent->right==proot){
        proot=proot->parent;
    }
    return proot->parent;
}

//Remove node including root
//Inlude guard
BSTNode* bstFindAndRemove(BSTNode* proot, int val){
    BSTNode* ptr=bstFind(proot, val);
    if(!ptr)return proot;
    if(ptr==proot){
        BSTNode* guard=new BSTNode;
        guard->left=proot;
        guard->right=guard->parent=NULL;
        ptr->parent=guard;
        bstRemoveNode(ptr);
        proot=guard->left;
        proot->parent=NULL;
        delete guard;
    }
        else bstRemoveNode(ptr);
    return proot;
}

//Remove node, do not remove root!
void bstRemoveNode(BSTNode* proot){
    BSTNode* ptr;
    if(!proot->left && ! proot->right) ptr=NULL;
        else{
        if(!proot->left) ptr=proot->right;
        if(!proot->right) ptr=proot->left;
        if(proot->left && proot->right){
            ptr=bstSuccessor(proot);
            if(ptr->parent->left==ptr) ptr->parent->left=ptr->right;
                else ptr->parent->right=ptr->right;
            ptr->left=proot->left;
            ptr->right=proot->right;
            }
    }
    if(ptr) ptr->parent=proot->parent;
    if(proot->parent->left==proot)proot->parent->left=ptr;
        else proot->parent->right=ptr;
    delete proot;
}

//Remove node, support removing root
//Cormen algorithm
void bstRemoveNodeCormen(BSTNode* &proot, int val){
    BSTNode* node,* x,* y;
    node=bstFind(proot, val);
    if(!node) return;

    if(!node->left || ! node->right) y=node;
        else y=bstSuccessor(node);
    if(y->left) x=y->left;
        else x=y->right;
    if(x) x->parent=y->parent;
    if(!y->parent) proot=x;
    else{
        if(y->parent->left==y) y->parent->left=x;
            else y->parent->right=x;
    }
    if(y!=node){
        if(!node->parent) {
            y->parent=NULL;
            proot=y;
        }else
        {
            if(node->parent->left==node) node->parent->left=y;
                else node->parent->right=y;
        }
        y->left=node->left;
        y->right=node->right;
    }
    delete node;
}


/*
5. Struct Node{
	node* left,* right;
	int value;
	}
Zsumowac wartosci drzewa bez uzycia dodatkowej pamieci(bez rekurencji)
Algorytm:
Mamy drzewo:  ojciec P
                wezel A
    dzieci  X           Y
1. Krok przychodzmy z P idziemy do X
    wezel       A
    dzieci  Y       P
2. Krok przychodzimy z X idziemy do Y
    wezel       A
    dzieci  P       X
3. Krok przychodzimy z Y wracamy do P
    wezel       A
    dzieci X        Y
4, MAGIC!
Nalezy podzielic wynik przez trzy poniewaz kazy wezel jest 3 razy zliczany
*/
int bstSumConstMemory(BSTNode* proot){
    BSTNode* node;
    BSTNode* parent=NULL;
    BSTNode* next=proot;
    int count=0;
    int countRoot=0;
    while(countRoot<3){
        node=next;
        if(node==proot) countRoot++;
        if(node){
            count+=node->key;
            next=node->left;
            node->left=node->right;
            node->right=parent;
            parent=node;
        }
        else{
            next=parent;
            parent=NULL;
        }
    }
    return count/3;
}

int bstSumRecursive(BSTNode* proot){
    if(proot) return bstSumRecursive(proot->left) + proot->key + bstSumRecursive(proot->right);
    return 0;
}
