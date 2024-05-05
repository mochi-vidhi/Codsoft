#include<iostream>
#include<stdlib.h>
using namespace std;
void addition(float num1,float num2){
    float add = num1 + num2;
    cout<<"Num1:"<<num1<<" Num2:"<<num2<<" Addition:"<<add<<endl;
}
void substraction(float num1,float num2){
    float sub = num1 - num2;
    cout<<"Num1:"<<num1<<" Num2:"<<num2<<" Substraction:"<<sub<<endl;
}
void Multiplication(float num1,float num2){
    float multi = num1 * num2;
    cout<<"Num1:"<<num1<<" Num2:"<<num2<<" Multiplication:"<<multi<<endl;
}
void division(float num1,float num2){
    float div = num1 / num2;
    cout<<"Num1:"<<num1<<" Num2:"<<num2<<" Division:"<<div<<endl;
}
int main(){
    int ch;
    float num1,num2;
    do{
        cout<<"1.Addition"<<endl;
        cout<<"2.Substraction"<<endl;
        cout<<"3.Multiplication"<<endl;
        cout<<"4.Division"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter Your choice to perform operations:";
        cin>>ch;
        switch(ch){
            case 1:
                    cout<<"Enter Two values to perform operations:";
                    cin>>num1>>num2;
                    addition(num1,num2);
                    break;
            case 2:
                    cout<<"Enter Two values to perform operations:";
                    cin>>num1>>num2;
                    substraction(num1,num2);
                    break;
            case 3:
                    cout<<"Enter Two values to perform operations:";
                    cin>>num1>>num2;
                    Multiplication(num1,num2);
                    break;
            case 4:
                    cout<<"Enter Two values to perform operations:";
                    cin>>num1>>num2;
                    division(num1,num2);
                    break;
            case 5:
                     exit(0);
            default:
                     cout<<"Invalid Choice:"<<endl;
        }
    }while(ch!=5);
  return 0;
}