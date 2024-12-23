#include <iostream>
#include <fstream>
using namespace std;
class Flowers;
class Users{
};
class Cart;

struct Node {
    int data;
    Node *next;
};
class Linklist{
    public:
    Node* head;
    Node* tail;
    int size;
    Linklist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    bool isEmpty(){
        if(size == 0){
            return true;
        }else {
            return false;
        }
    }
    void add(int Newdata){
        Node* t = new Node;
        t->data = Newdata;
        t->next = head;
       head = t;
       if(isEmpty()){
        cout << "Can't add!!" << endl;
       }
       size++;
    }   
    

};



int main()
{
    int admin_choice, user_choice;
    int n;
    while(true){
    cout << "\n\n";
    cout << "\n\n Start Program \n\n";
    cout << "\t\t\t======= Administrator =======";
    cout << "\t\t\t|| 1.Admin                 ||";
    cout << "\t\t\t|| 2.User                  ||";
    cout << "\t\t\t|| 3.Exit                  ||";
    cout << "\t\t\t=============================";
    cout << "Who are you?" << endl;
    cin >> n;
    switch(n){
        case 1: 
            cout << "\t\t\t=========== Admin ===========";
            cout << "\t\t\t|| 1.Add product           ||";
            cout << "\t\t\t|| 2.History               ||";
            cout << "\t\t\t|| 3.Check is flower dead  ||";
            cout << "\t\t\t|| 4.Display product       ||";
            cout << "\t\t\t|| 5.Exit                  ||";
            cout << "\t\t\t=============================";
            cout << "Choose: ";
            cin >> admin_choice;
            switch(admin_choice){
                case 1:

                case 2:

                case 3:

                case 4:

                case 5:
                    return 1;
                default:
                    cout << "Invalid choice!!";
            }

        case 2: 
            cout << "\t\t\t=========== User ===========";
            cout << "\t\t\t|| 1.Buy                   ||";
            cout << "\t\t\t|| 2.remove                ||";
            cout << "\t\t\t|| 3.Promotion             ||";
            cout << "\t\t\t|| 4.Receipt               ||";
            cout << "\t\t\t|| 5.Exit                  ||";
            cout << "\t\t\t=============================";
            cout << "Choose: ";
            cin >> user_choice;
            switch(user_choice){
                case 1:

                case 2:

                case 3:

                case 4:

                case 5:
                    return 1;
                default:
                    cout << "Invalid choice!!";

            }
        }
    }











    std::cout << "\n\n";

    return 0;
}