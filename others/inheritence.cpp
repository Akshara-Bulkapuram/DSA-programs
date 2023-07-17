#include <iostream>

using namespace std;

class chef{
    public:
    void makechicken(){
        cout<<"the chef makes chicken meatballs"<<endl;
    }
    void makesalad(){
        cout<<"the chef makes a egg salad"<<endl;
    }
    void makesoup(){
        cout<<"the chef makes tomato soup"<<endl;
    }
    void makespecialdish(){
        cout<<"the chef makes ramen"<<endl; 
    }
    };
class Italianchef :  public chef{
    public:
    void makepasta(){
        cout<<"Italian chef makes sphageetti"<<endl;
    }
    void makespecialdish(){
        cout<<"Italian chef makes ravioli pasta"<<endl;
    }
};
int main(){
    chef mike;
    Italianchef john;
    mike.makechicken();
    john.makechicken();

    mike.makespecialdish();
    john.makespecialdish();
    //overwrites base class function 
    

    return 0;


}
