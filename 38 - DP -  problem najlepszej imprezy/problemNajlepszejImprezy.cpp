/*
    Drzewiasta struktura pracownikow firmy, kazda osoba ma pewna przypisana wartosc
    Chcemy aby sumaryczna wartosc byla jak najwieksz, przy zalozeniu ze pracownicy
    rozniacy sie o 1 w hierarchi nie moga isc na ipreze(szef i jego beposredni powdwadni)
*/

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Employee{
    int fun;
    int f,g;
    Employee** employee;
    int employees;
};

int f(Employee* boss);
int g(Employee* boss);
void reset(Employee* boss);

int main(){
    Employee* boss = new Employee;
    boss->fun=7;
    Employee* tmp,* tmp2;
    tmp=new Employee;
    tmp2=new Employee;
    tmp->fun=3;
    tmp2->fun=5;
    boss->employees=2;
    boss->employee=new Employee*[2];
    boss->employee[0]=tmp;
    boss->employee[1]=tmp2;
    tmp=new Employee;
    tmp2=new Employee;
    tmp->fun=11;
    tmp2->fun=20;
    boss->employee[0]->employees=2;
    boss->employee[0]->employee=new Employee*[2];

    boss->employee[0]->employee[0]=tmp;
    boss->employee[0]->employee[1]=tmp2;
    tmp=new Employee;
    tmp2=new Employee;
    tmp->fun=1;
    tmp2->fun=2;
    boss->employee[1]->employees=2;
    boss->employee[1]->employee=new Employee*[2];
    boss->employee[1]->employee[0]=tmp;
    boss->employee[1]->employee[1]=tmp2;
    reset(boss);
    printf("%d", f(boss));
}


void reset(Employee* boss){
    boss->f=-1;
    boss->g=-1;
    for(int i=0;i<boss->employees;i++) reset(boss->employee[i]);
}

int f(Employee* boss){
    if(boss->f!=-1) return boss->f;
    int fr=boss->fun;
    for(int i=0;i<boss->employees;i++) fr+=g(boss->employee[i]);
    boss->f=max(g(boss), fr);
    return boss->f;
}

int g(Employee* boss){
    if(boss->g!=-1)return boss->g;
    boss->g=0;
    for(int i=0;i<boss->employees;i++) boss->g+=f(boss->employee[i]);
    return boss->g;
}

