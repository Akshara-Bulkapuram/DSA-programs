#include <iostream>

using namespace std;

class Book{
    public:
      int pages;
      string title;
      string Author;
    Book(){
        title="notitle";
        Author="no author";
        pages=0;
    }
    Book(string atitle,string aAuthor,int apages){
        title=atitle;
        Author=aAuthor;
        pages=apages;
      }
    void give_Autho_info(){
      cout<<Author;

    }

};

int main(){
    Book book1("Harry Potter","J.K.Rowling",700);
    cout<<book1.Author<<endl;
    Book book2;
    cout<<book2.Author;
    book1.give_Autho_info();



    return 0;


}
