#include <iostream>
#include <queue>

using namespace std;

struct RBTNode{
    int key;
    bool color=true;; //red is true, black is false
    RBTNode* parent,* left,* right;
};

void rbInsert(RBTNode* &proot, int key);
void print(RBTNode* node);
RBTNode* bstInsert(RBTNode* &proot, int key);

int main(){
    RBTNode* proot;
    proot=NULL;
    int array[]={11,2,14,1,7,5,8,15};
    for(int i=0;i<8;i++) bstInsert(proot,array[i]);
    proot->color=proot->right->color=proot->left->left->color=proot->left->right->color=false;
    print(proot);
    rbInsert(proot,4);
    print(proot);
}


void leftRotate(RBTNode* &proot, RBTNode* x){
    RBTNode* y=x->right;
    x->right=y->left;
    if(y->left){
        y->left->parent=x;
    }
    y->parent=x->parent;
    if(!x->parent){
        proot=y;
    }else{
        if(x==x->parent->left){
            x->parent->left=y;
        }else{
            x->parent->right=y;
        }
    }
    y->left=x;
    x->parent=y;
}

void rightRotate(RBTNode* &proot, RBTNode* y){
    RBTNode* x=y->left;
    y->left=x->right;
    if(x->right){
        x->right->parent=y;
    }
    x->parent=y->parent;
    if(!x->parent){
        proot=x;
    }else{
        if(y==y->parent->left){
            y->parent->left=x;
        }else{
            y->parent->right=x;
        }
    }
    x->right=y;
    y->parent=x;
}

//Insert node to tree
RBTNode* bstInsert(RBTNode* &proot, int key){
    RBTNode* ptr = new RBTNode;
    ptr->key=key;
    ptr->left=ptr->right=ptr->parent=NULL;
    if(proot==NULL) {
        proot=ptr;
        return ptr;
    }
    RBTNode* parent,* tmp;
    tmp=parent=proot;
    while(tmp!=NULL){
        parent=tmp;
        if(tmp->key>key) tmp=tmp->left;
            else tmp=tmp->right;
    }
    if(parent->key>key)parent->left=ptr;
        else parent->right=ptr;
    ptr->parent=parent;
    return ptr;
}

void rbInsert(RBTNode* &proot, int key){
    RBTNode* x=bstInsert(proot, key);
    x->color=true;
    RBTNode* y;
    while(x!=proot && x->parent->color==true){
        if(x->parent==x->parent->parent->left){
        /*
            Case A:
            Dla przypadku gdy wezel:
            rodzic jest lewym synem rodzica rodzica
        */
        /*
            Case 1:
            Wezel, rodzic, i stryj - czewony
            przekolorwoac drzewo
        */
            y=x->parent->parent->right;
            if(y->color==true){
                x->parent->color=false;
                y->color=false;
                x->parent->parent->color=true;
                x=x->parent->parent;
            }else{
        /*
            Case 2:
            Wezel, rodzic - czerwone
            stryj - czarny
            lewa rotacja
        */
                if(x==x->parent->right){
                    x=x->parent;
                    leftRotate(proot, x);
                }
                x->parent->color=false;
                x->parent->parent->color=true;
                rightRotate(proot, x->parent->parent);
            }
        }else{
            /*
                Case B:
                Dla przypadku gdy wezel:
                rodzic jest prawym synem rodzica rodzica
            */
            //code to do sth
            cout<<"ERR - not implemented";
        }
        print(proot);
    }

}

void print(RBTNode* node){
    cout<<"#------PRINT TREE"<<endl;
    int counter=1;
    int tmpCounter;
    RBTNode* ptr;
    queue<RBTNode*> listOfNodes;
    listOfNodes.push(node);
    while(counter>0){
        tmpCounter=0;
        while(counter>0){
            ptr=listOfNodes.front();
            listOfNodes.pop();
            if(ptr->left){
                listOfNodes.push(ptr->left);
                tmpCounter++;
            }
            if(ptr->right){
                listOfNodes.push(ptr->right);
                tmpCounter++;
            }
            cout<<ptr->key<<" ";
            counter--;
        }
        counter=tmpCounter;
        cout<<endl;
    }
    cout<<"#------PRINT TREE"<<endl;

}
