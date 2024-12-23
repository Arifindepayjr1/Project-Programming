#include <iostream>
#include <fstream>
#include <sstring>
using namespace std;
class Flowers;
class Users{
};
class Cart{};

struct Node {
    int data;
    Node *next;
};
class Linklist{
   
};   




int main(){


    int admin_choice, user_choice;
    int n;
    while(true){
        Aministrator:
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
                cout << "\t\t\t\t\t|| 3.Delete product        ||" << endl;
                cout << "\t\t\t\t\t|| 4.Check is flower dead  ||" << endl;
                cout << "\t\t\t\t\t|| 5.Display product       ||" << endl;
                cout << "\t\t\t\t\t|| 6.Exit                  ||" << endl;
                cout << "\t\t\t\t\t=============================" << endl;
                cout << "Choose: ";
                cin >> admin_choice;
                switch(admin_choice){
                    case 1:

                    case 2:

                    case 3:

                    case 4:

                    case 5:

                    case 6:
                        return 1;
                    default:
                        cout << "Invalid choice!!";
                        goto Aministrator;
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
                        goto Aministrator;

                }
            case 3: 
                return 1;
            default :
                cout << "Invalid choice!!";
                goto Aministrator;
            }
            
        }
    return 0;
}