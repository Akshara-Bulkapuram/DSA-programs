#include <iostream>

using namespace std;

class student{
    private:
    double grade;
    public:
    string name;
    string major;

    student( string sname,string smajor,double sgrade){
        name=sname;
        major=smajor;
        grade=sgrade;

    }
   void  get_grade(){
    cout<<"grade is "<<grade;
   }
};

int main(){
    
   student mike=student("mike","physics",9.6);

   mike.get_grade();
   //getters and setters are used for private classifiers
    return 0;


}
