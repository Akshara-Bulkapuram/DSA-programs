#include <iostream>

using namespace std;

int main(){

    bool isMale=true;
    bool isTall=true;

    if(isMale || isTall){
        cout<<"you are a dude";
    }
    else if(isMale&& !isTall) {
        cout<<"you are a girl";
    }
    else if(5>2){
        cout<<"5 is more than 2";
    }

return 0;

}

