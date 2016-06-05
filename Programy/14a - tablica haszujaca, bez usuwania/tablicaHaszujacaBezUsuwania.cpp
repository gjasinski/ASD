/*
3, Implementacja funkcji hashujacej:
	struct Data{
		char* first_name;
		char* last_name;
		int age;
	}
4. Implementacja tablicy hashujacej z liniowym rozwiazywaniem konfliktow
	a) wyszukiwanie
	b) wstawianie
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

//Funkcja hashujaca z zmienna waga
int hashMultiplier1(Data* data){
    int val, sum, multiplier;
    val=sum=0;
    multiplier=1;
    for(int i=0; data->first_name[i]!=0; i++){
        sum+=data->first_name[i]*multiplier;
        multiplier++;
    }
    for(int i=0; data->last_name[i]!=0; i++){
        sum+=data->last_name[i]*multiplier;
        multiplier++;
    }
    sum+=data->age*multiplier;
    return sum;
}

//Funkcja hashujaca z stala waga
int hashConstMultiplier(Data* data){
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

void hashFunctionTest(){
    Data* ptr1,* ptr2,* ptr3;
    ptr1=new Data();
    ptr2=new Data();
    ptr3=new Data();
    ptr1->first_name="stefan";
    ptr2->first_name="Nowak";
    ptr3->first_name="Adamaaaaaaaaaaaaaaa";
    ptr1->last_name="Nowak";
    ptr2->last_name="stefan";
    ptr3->last_name="szybki";
    ptr1->age=23;
    ptr1->age=32;
    ptr1->age=11;


    cout<<hashConstMultiplier(ptr1)<<endl;
    cout<<hashConstMultiplier(ptr2)<<endl;
    cout<<hashConstMultiplier(ptr3)<<endl;


    cout<<hashMultiplier1(ptr1)<<endl;
    cout<<hashMultiplier1(ptr2)<<endl;
    cout<<hashMultiplier1(ptr3)<<endl;
}



//Dodawanie elementu do tablicy
//argumenty tablica hashujaca, dane, rozmiar tablicy
void insert(Data* A[], Data* data, int size){
    int counter=0;
    int start=(int)abs(hashConstMultiplier(data))%size;
    if(A[start]==NULL){
        A[start]=data;
        cout<<"A: "<<start<<endl;
        return;
    }
    int position=start+1;
    while(position!=start){
        if(A[position]==NULL){
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
Data* find(Data* A, Data* data, int size){
    int start=(int)abs(hashConstMultiplier(data))%size;
    if(!A[start]) return NULL;
    if(eq(A[start], data)) return A[start];
    cout<<start;
    for(int i=start+1; A[i]!=NULL && i!=start; i++){
        cout<<" "<<i;
        i=i%size;
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

void hashTableTest(int size){
    Data* table[size];
    for(int i=0;i<size;i++)table[i]=NULL;
    Data* p1,* p2,* p3,* p4;
    p1=makeData("Stefan", "Nowak", 19);
    p2=makeData("Nowak"," Stefan", 91);
    p3=makeData("Adam", "VZVZVVZVVZZV", 10);
    p4=makeData("TEstowo", "AAAAAAAAAABBBBBBBBBBBCEDASFDASFASF", 150);
    insert(table, p1, size);
    insert(table, p2, size);
    insert(table, p3, size);
    insert(table, p4, size);

    Data* test;
    test=makeData("Stefan", "Nowak", 19);
    test=find(table, test, size);
    if(test){
     cout<<test->first_name<<" "<<test->last_name<<" "<<test->age;
    }
}
