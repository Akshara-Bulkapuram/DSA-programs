#include <iostream>

using namespace std;



int main(){
    int secretnumber=7;
    int guess;
    int count=0;
    while(secretnumber!=guess){
        cout<<"enter guess ";
        cin>>guess;
        count++;
        if(count>=5){
            cout<<"You lose";
            break;
        }
    }
    cout<<"You win";
    return 0;

}
