#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node {
int val;
node *next;
};
double *genArr(int size) {
double* A = new double[size];
for (int i = 0; i < size; ++i)
A[i] = rand()%1000;
return A;
}
void printArr(double* arr, int size){
for (int i = 0; i < size; ++i) {
cout << arr[i] << " ";
}
cout << endl;
}
void bucketSort(double A[], int n, int k) { // A zawiera liczby od [0,1) wylosowane zgodnie z rozkladem jednostajnym
node *B[k];
int idx = 0;
double max = 0;
for (int j = 0; j < n; ++j)
if (max < A[j])
max = A[j];
double scl = max / k; //rozmiar pierwszego kubelka to (0,scl)
for (int i = 0; i < n; ++i) {
node*p = new node;
node*q;
p->val = A[i];
idx = A[i]/scl;
q = B[idx];
if (q != NULL)
q = p;
else {
while (q->next !=NULL){
q = q->next;
}
q->next = p;
}
}
for (int i = 0; i < k; ++i) {
//sortowanie kubelkow
//przeniesienie do tablicy wyjsciowej
}
}
int main() {
int s;
cout << "Podaj rozmiar tablicy" << endl;
cin >> s;
cout << "Rozmiar tablicy: " << s << endl;
//int* arr = genArr(s);
double arr[] = {18,198,294,120,153};
printArr(arr,s);
bucketSort(arr,s,5);
printArr(arr,s);
return 0;
}
