/*
Dany jest ciąg zbudowany z nawiasów '(' i ')'. Czy jest poprawny
 pod wzgledem matemtycznym ciag nawiasow.
 */

 #include<iostream>
 using namespace std;

 int main(){
    int count=0;
    string bracket;
    cin>>bracket;
    int length=bracket.length();
    bool error=false;
    for(int i=0;i<length&&!error;i++){
        if(bracket[i]=='(') count++;
        else{
            if(count==0) error=true;
            else count--;
        }
    }
    if(error || count>0) cout<<"niepoprawny ciag";
    else cout<<"Poprawny ciag";
}

