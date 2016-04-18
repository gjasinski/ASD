/*
3, Implementacja funkcji hashujacej:
	struct Data{
		char* first_name;
		char* last_name;
		int age;
	}
4. Implementacja tablicy hashujacej z liniowym rozwiazywaniem konfliktow
	a) wyszukiwanie
	b) usuwanie
	c) dodawanie
*/

#include<iostream>
#include<cmath>

using namespace std;

struct Data{
    string first_name;
    string last_name;
    int age;
};

void hashTableTest(int size);

int main(){

    hashTableTest(100);
}



//Funkcja hashujaca z stala waga
int hash(Data* data){
    int sum=0;
    int multiplier=65599;
    for(int i=0; data->first_name[i]!=0; i++){
        sum=sum*multiplier+data->first_name[i];
    }
    for(int i=0; data->last_name[i]!=0; i++){
        sum=sum*multiplier+data->last_name[i];
    }
    sum=sum*multiplier+data->age;
    return sum;
}

//Dodawanie elementu do tablicy
//argumenty tablica hashujaca, dane, rozmiar tablicy
void insert(Data* A[], Data* data, int size){
    int counter=0;
    int start=(int)abs(hash(data))%size;
    if(A[start]==NULL || (int)A[start]==0){
        A[start]=data;
        cout<<"A: "<<start<<endl;
        return;
    }
    int position=start+1;
    while(position!=start){
        if(A[position]==NULL || (int)A[position]==0){
            A[position]=data;
            cout<<"B: "<<position<<endl;
            return;
        }
        position=(position+1)%size;
    }
}
//sprawdza czy podane dwa wskazniki sa takie same
bool eq(Data* a, Data* b){
    if(a->age!=b->age) return false;
    if(a->first_name!=b->first_name) return false;
    if(a->last_name!=b->last_name) return false;
    return true;
}

//znajduje dane w tablicy hashujacej
Data* find(Data* A[], Data* data, int size){
    int start=(int)abs(hash(data))%size;
    //gdy wskaznik jest rowny NULL i adres jego jest rozny od 0
    //zero specjalny znacznik ze element zostal usuniety
    if(A[start]==NULL && (int)A[start]!=0) return NULL;
    //Usuwam przypadek specjlny po usunieciu elementu
    if((int)A[start]!=0 && eq(A[start], data)) return A[start];
    //dzialaj gdy (wskaznik nie jest rowny null lub adres jest równy 0) i nie wrocilismy do poczatku
    for(int i=start+1; (A[i]!=NULL || (int)A[i]==0) && i!=start; i++){
        i=i%size;
        if(int(A[i])==0) continue;
        if(eq(A[i], data)) return A[i];
    }
    return NULL;
}

Data* makeData(string first_name, string last_name, int age){
    Data* a= new Data;
    a->age=age;
    a->first_name=first_name;
    a->last_name=last_name;
    return a;
}

struct DataDel{
    int i;
    Data* ptr;
};

DataDel findToDel(Data* A[], Data* data, int size){
    DataDel d;
    d.ptr=NULL;
    int start=(int)abs(hash(data))%size;
    if(A[start]==NULL && (int)A[start]!=0) return d;
    if((int)A[start]!=0 && eq(A[start], data)) {
            d.i=start;
            d.ptr=A[start];
            return d;
        };
    for(int i=start+1; (A[i]!=NULL || (int)A[i]==0) && i!=start; i++){
        i=i%size;
        if((int)A[i]==0) continue;
        if(eq(A[i], data)){
            d.i=i;
            d.ptr=A[i];
            return d;
        }
    }
    return d;
}

void remove(Data* A[], Data* data, int size){
    DataDel ptr=findToDel(A, data, size);
    if(!ptr.ptr){
        cout<<"Usuwanie - element nie istnieje"<<endl;
        return;
    }
    delete ptr.ptr;
    A[ptr.i]=0;
    cout<<"INFO: "<<ptr.i<<endl;
}

void hashTableTest(int size){
    Data* table[size];
    for(int i=0;i<size;i++)table[i]=NULL;
    Data* p1,* p2,* p3,* p4,* p1b,* p1c;
    p1=makeData("Stefan", "Nowak", 20);
    p2=makeData("Nowak"," Stefan", 91);
    p3=makeData("Adam", "VZVZVVZVVZZV", 10);
    p4=makeData("TEstowo", "AAAAAAAAAABBBBBBBBBBBCEDASFDASFASF", 150);
    p1b=makeData("Stefan", "Nowak", 19);
    p1c=makeData("Stefan", "Nowak", 20);
    insert(table, p1, size);
    insert(table, p2, size);
    insert(table, p3, size);
    insert(table, p4, size);
    insert(table, p1b, size);
    insert(table, p1c, size);

    Data* test;
    test=makeData("Stefan", "Nowak", 19);
    remove(table, test,size);
    test->age=20;
    remove(table, test, size);
    remove(table, test, size);
    test=find(table, test, size);
    if(test){
      cout<<test->first_name<<" "<<test->last_name<<" "<<test->age;
    }
}
