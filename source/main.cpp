#include <iostream>
#include <fstream>
using namespace std;
class Flowers;
class Users{
};
<<<<<<< HEAD
class Cart{};
=======
class Cart;
>>>>>>> 9d2369d4688e85d3fff1e4d517f549b51a325ece

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
<<<<<<< HEAD
    }
    void deleteAt(int Data){
    }   
=======
    }   
    

>>>>>>> 9d2369d4688e85d3fff1e4d517f549b51a325ece
};



int main()
{
    int admin_choice, user_choice;
    int n;
    while(true){
    cout << "\t\t\t\t\t\tStart Program" << endl;
    cout << "\t\t\t\t\t======= Administrator =======" << endl;
    cout << "\t\t\t\t\t|| 1.Admin                 ||" << endl;
    cout << "\t\t\t\t\t|| 2.User                  ||" << endl;
    cout << "\t\t\t\t\t|| 3.Exit                  ||" << endl;
    cout << "\t\t\t\t\t=============================" << endl;
    cout << "Who are you?" << endl;
    cin >> n;
    switch(n){
        case 1: 
            cout << "\t\t\t\t\t=========== Admin ===========" << endl;
            cout << "\t\t\t\t\t|| 1.Add product           ||" << endl;
            cout << "\t\t\t\t\t|| 2.History               ||" << endl;
            cout << "\t\t\t\t\t|| 3.Check is flower dead  ||" << endl;
            cout << "\t\t\t\t\t|| 4.Display product       ||" << endl;
            cout << "\t\t\t\t\t|| 5.Exit                  ||" << endl;
            cout << "\t\t\t\t\t=============================" << endl;
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
            cout << "\t\t\t\t\t=========== User ============" << endl;
            cout << "\t\t\t\t\t|| 1.Buy                   ||" << endl;
            cout << "\t\t\t\t\t|| 2.remove                ||" << endl;
            cout << "\t\t\t\t\t|| 3.Promotion             ||" << endl;
            cout << "\t\t\t\t\t|| 4.Receipt               ||" << endl;
            cout << "\t\t\t\t\t|| 5.Exit                  ||" << endl;
            cout << "\t\t\t\t\t=============================" << endl;
            cout << "Choose: " << endl;
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
        case 3: 
            return 1;
        default :
            cout << "Invalid choice!!";
            return 1;
        }
        
    }
    return 0;
}