#include <iostream>

using namespace std;

int cube(int num);
int main(){
    
int p=cube(2);
cout<<p<<endl;


return 0;

}

int cube(int num){
    int k = num*num*num;
    return k;
}