#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
void winner(){
cout<<"You Are The Lucky Winner ! congratulation..";
}
int main(){
    srand(time(NULL));
    
        int x=rand() %100000;

        int num;
        cout<<"Enter A Number :";
        cin>>num;
        if(num==x) {winner();}
        else{
        while(num!=x){
            
            if(num>x){
                cout<<"Enter More Smaller Number :";
                cin>>num;
                 if(num==x) {winner();
                 break;}
            }
           
           else if(num<x) {
            cout<<"Enter More Biggar Number :";
                cin>>num;
                 if(num==x) {winner();
                 break;}
           }
           else {winner();
           break;}
        }}
    
}