#include <iostream>

using namespace std;

struct BSTNode{
    int key;
    BSTNode* left,* right;
    int sum;
};

BSTNode* add(BSTNode* proot, int key);
void inOrder(BSTNode* proot);
BSTNode* bstFindNElement(BSTNode* proot, int n);
int bstCountElementsBefore(BSTNode* proot, int val);

int main(){
    BSTNode* proot=NULL;
    BSTNode* ptr;
    proot=add(proot, 10);
    proot=add(proot, 14);
    proot=add(proot, 13);
    proot=add(proot, 12);
    //proot=add(proot, 11);
    proot=add(proot, 2);
    proot=add(proot, 6);
    proot=add(proot, 5);
    proot=add(proot, 3);
    proot=add(proot, 4);
    proot=add(proot, 1);
    proot=add(proot, 8);
    proot=add(proot, 7);
    proot=add(proot, 9);

    inOrder(proot);
    ptr=bstFindNElement(proot, 11);
    if(ptr) cout<<endl<<ptr->key;
    cout<<endl<<bstCountElementsBefore(proot, 9);
    return 0;
}

//Insert node to tree
BSTNode* add(BSTNode* proot, int key){
    BSTNode* ptr = new BSTNode;
    ptr->key=key;
    ptr->left=ptr->right=NULL;
    ptr->sum=1;
    if(proot==NULL) return ptr;
    BSTNode* parent,* root;
    root=parent=proot;
    while(proot!=NULL){
        parent=proot;
        proot->sum++;
        if(proot->key>key) proot=proot->left;
            else proot=proot->right;
    }
    if(parent->key>key)parent->left=ptr;
        else parent->right=ptr;
    return root;
}

//Walk inOder
void inOrder(BSTNode* proot){
    if(proot){
        inOrder(proot->left);
        cout<<proot->key<<" "<<proot->sum<<endl;
        inOrder(proot->right);
    }
}

//zwraca n-ty element drzewa
BSTNode* bstFindNElement(BSTNode* proot, int n){
    if(!proot) return NULL;
    int lsum;
    if(!proot->left) lsum=0;
        else lsum=proot->left->sum;
    if (lsum+1==n) return proot;
    if(lsum>=n) return bstFindNElement(proot->left, n);
            else return bstFindNElement(proot->right, n-lsum-1);
}

//zwraca ilosc elementow mniejszych od daneog wezla
//mozna tez isc od node w strone korzenia w przypadku
//gdy struktura bedzie miala wskaznik na rodzica
//1. Jezeli jest node jest lewym synem dodjemy 1
//2. jezeli node jest prawym synem dodajemy sum z
//z lewego syna +1 idziemy do korzenia
int bstCountElementsBefore(BSTNode* proot, int val){
    int sum=0;
    if(!proot) return -1;
    while(proot->key!=val){
        if(proot->key>val)  proot=proot->left;
            else {
            if(proot->left)sum+=proot->left->sum;
            sum++;
            proot=proot->right;
        }
        if(!proot) return -1;
    }
    if(proot->left) sum+=proot->left->sum;
    return sum;
}
