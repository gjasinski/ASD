#include <iostream>
#include <climits>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct SLNode{
        int val;
        SLNode ** next;
};

struct SkipList{
    SLNode* first;
    int level;
};

void initializeSkipList(SkipList &sl, int maxLevel);
void insertNodeToSkipList(SkipList &sl, int key, int maxLevel);
SLNode* findElement(SkipList sl, int element, int maxLevel);
int findLevel(int maxLevel);
void removeElement(SkipList &sl, int element, int maxLevel);
void printSkipList(SkipList sl, int maxLevel);

int main(){
    srand(time(NULL));
    SkipList SL;
    int maxLevel=10;
    initializeSkipList(SL, maxLevel);
    printSkipList(SL, maxLevel);

    cout<<endl<<endl<<endl;


    SLNode* ptr=findElement(SL, 20, maxLevel);
    if(ptr) cout<<ptr->val<<endl; else cout<<"ERR"<<endl;
    insertNodeToSkipList(SL, 50, maxLevel);
    ptr=findElement(SL, 50, maxLevel);
    if(ptr) cout<<ptr->val<<endl; else cout<<"ERR"<<endl;
    removeElement(SL, 50, maxLevel);
    ptr=findElement(SL, 50, maxLevel);
    if(ptr) cout<<ptr->val<<endl; else cout<<"ERR"<<endl;
    printSkipList(SL, maxLevel);
}

int findLevel(int maxLevel){
    int modulo=pow(2,maxLevel)-1;
    int result=rand()%modulo+1;
    result=maxLevel-(int)(log(result)/log(2))-1;
    return result;
}

void insertNodeToSkipList(SkipList &sl, int key, int maxLevel){
    int level=findLevel(maxLevel);
    SLNode* newNode=new SLNode;
    newNode->val=key;
    newNode->next=new SLNode* [level];
    SLNode *ptr;
    for(int i=sl.level-1;i>=0;i--){
        ptr=sl.first;
        while(ptr->next[i]->val<key)
            ptr=ptr->next[i];
        if(i<level){
            newNode->next[i]=ptr->next[i];
            ptr->next[i]=newNode;
        }
    }
}

void initializeSkipList(SkipList &sl, int maxLevel){
    SLNode* first,* last;
    first= new SLNode;
    first->val=INT_MIN;
    first->next=new SLNode* [maxLevel];

    last= new SLNode;
    last->val=INT_MAX;
    last->next=new SLNode* [maxLevel];

    for(int i=maxLevel-1;i>=0;i--){
        first->next[i]=last;
        last->next[i]=NULL;
    }
    sl.first=first;
    sl.level=maxLevel;
}

SLNode* findElement(SkipList sl, int element, int maxLevel){
    SLNode* ptr;
    for(int i=maxLevel-1;i>=0;i--){
        ptr=sl.first->next[i];
        while(ptr->val<element)
            ptr=ptr->next[i];
        if(ptr->val==element) return ptr;
    }
    return NULL;
}

void removeElement(SkipList &sl, int element, int maxLevel){
    SLNode* ptr,* prev;
    for(int i=maxLevel-1;i>0;i--){
        prev=sl.first;
        ptr=sl.first->next[i];
        while(ptr->val<element)
            ptr=ptr->next[i];
        if(ptr->val==element)
            prev->next[i]=ptr->next[i];
    }
    prev=sl.first;
    ptr=sl.first->next[0];
    while(ptr->val<element)
        ptr=ptr->next[0];
    if(ptr->val==element)
        prev->next[0]=ptr->next[0];
    delete [] ptr->next;
    delete ptr;
}
void printSkipList(SkipList SL, int maxLevel){
    SLNode* ptr;
    for(int i=0;i<100;i++) insertNodeToSkipList(SL, rand()%100,maxLevel);
    for(int i=9;i>=0;i--){
    cout<<endl<<"#---------LEVEL "<<i<<"---------#"<<endl;
        ptr=SL.first->next[i];
        while(ptr->val<INT_MAX){
            cout<<ptr->val<<" ";
            ptr=ptr->next[i];
        }
    }
}
