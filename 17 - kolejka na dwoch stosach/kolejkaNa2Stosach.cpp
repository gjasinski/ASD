//4. Zaimplementowac kolejkę na dwóch stosach przy uzyciu push, pop;

#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

struct queue{
    node* stackMaster,* stackSlave;
};

void queueInit(queue &q);
int queuePop(queue &q);
void queuePush(queue &q, int val);

int main()
{
    queue q;
    queueInit(q);
    queuePush(q, 10);
    queuePush(q, 5);
    queuePush(q, 6);
    queuePush(q, 7);
    queuePush(q, 20);
    cout<<queuePop(q)<<" ";
    cout<<queuePop(q)<<" ";
    queuePush(q,66);
    queuePush(q,88);
    for(int i=0;i<6;i++) cout<<queuePop(q)<<" ";

}

//initialize stack
node* stackInit(node* ptr){
    ptr=new node();
    ptr->next=NULL;
    return ptr;
}

//Return true if stack is empty
bool stackIsEmpty(node* ptr){
    if(ptr->next==NULL) return true;
    else return false;
}

void stackAdd(node* &peak, int val){
    node* ptr;
    ptr = new node;
    ptr->next=peak;
    ptr->val=val;
    peak=ptr;
}

void queueInit(queue &q){
    q.stackMaster=stackInit(q.stackMaster);
    q.stackSlave=stackInit(q.stackSlave);
}

int queuePop(queue &q){
    if(stackIsEmpty(q.stackMaster)){
        cout<<"Queue is empty";
        return 0;
    }
    int ret=q.stackMaster->val;
    node* ptr = q.stackMaster;
    q.stackMaster = q.stackMaster->next;
    delete ptr;
    return ret;
}

void queuePush(queue &q, int val){
    node* ptr;
    while(!stackIsEmpty(q.stackMaster)){
        ptr=q.stackMaster;
        q.stackMaster=q.stackMaster->next;
        ptr->next=q.stackSlave;
        q.stackSlave=ptr;
    }
    ptr = new node;
    ptr->next=q.stackMaster;
    ptr->val=val;
    q.stackMaster=ptr;
    while(!stackIsEmpty(q.stackSlave)){
        ptr=q.stackSlave;
        q.stackSlave=q.stackSlave->next;
        ptr->next=q.stackMaster;
        q.stackMaster=ptr;
    }
}
