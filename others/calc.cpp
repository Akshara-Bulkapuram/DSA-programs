#include <iostream>

using namespace std;

int main(){
    // double num1;
    // double num2;

    // cout <<"Enter number 1 :";
    // cin>>num1;
    // cout <<"Enter number 2 :";
    // cin>>num2;
    // cout<< num1+num2;
    int num1,num2;
    char op; 
    cout<<"enter your first number ";
    cin>>num1;
    cout<<"enter second number ";
    cin>>num2;
    cout<<"enter operator ";
    cin>>op;
    int result;
    if(op=='+'){
        result=num1+num2;
    }
    else if(op=='-'){
        result=num1-num2;

    }
    else if(op=='*'){
        result=num1*num2;

    }
    else if(op=='/'){
        result=num1/num2;

    }
    cout<<"result is "<<result;

    return 0;


}
