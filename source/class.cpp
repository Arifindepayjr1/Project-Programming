#ifndef CLASS       /* preventing duplicate class file */
#define CLASS 


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class Admin;       /*          Information Admin               */
class Flowers;     /*          Information Flowers            */
class Users;       /*          Information Users             */
class Productlist; /*                      ADT              */

class Admin
{
private:
    const int m_admin_password{555};
    std::string m_admin_name{"Admin"};

public:
    Admin() = default;

    void admin_users_history();
    void admin_flowers_history();
    bool admin_vertify_password(int password);
    void admin_users_information(int user_id);    /*      searching for specific users     */
    void admin_flowrs_information(int flower_id); /*      searching for specific flowers   */
};

class Users
{
private:
    int m_id{};
    int m_product_quantity{};
    std::string m_name{};
    Users *m_users_next{nullptr};

public:
    Users() = default;
    Users(int id, int product_quantity, std::string name, Users *users_next = nullptr)
        : m_id{id}, m_product_quantity{product_quantity}, m_name{name}, m_users_next{users_next}
    {
    }

    int users_id();
    int users_product_quantity();
    std::string user_name();
    bool users_update_name(std::string new_name); /* true = successful , flase = un-successful */
};

class Flowers
{
private:
    bool m_flower_status{}; /* true = Alive , false = Death   */
    int m_flower_id{};
    int m_flower_quantity{};
    std::string m_flower_name{};
    Flowers *m_flower_next{nullptr};

public:
    Flowers() = default;
    Flowers(bool status, int flower_id, int flower_quantity, std::string flower_name, Flowers *flower_next = nullptr)
        : m_flower_status{status}, m_flower_id{flower_id}, m_flower_quantity{flower_quantity}, m_flower_name{flower_name}, m_flower_next{flower_next}
    {
    }

    int flower_id();
    int flower_quantity();
    bool flower_status();
    std::string flower_name();
};
struct Node {
    int id;
    Node* next;
    int data;
    Node(int value ,int ID){
        id = ID;
        data = value;
        next = NULL;
    }
    
};
class ProductList
{
<<<<<<< HEAD
 private:
    Node* head;
    int gen_ID(){
        int id = 1;
        Node* tmp = head;
        while(tmp){
            id = max(id,tmp->id+1);
            tmp = tmp->next;
        }
        return id;
    }
 public:
=======
 public:
    Users* head;
    Users* tail;
    int size;
>>>>>>> 777109a0763b8fc2ab994acb9eb0f299671dd5b6
    ProductList(){
        head = NULL;
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }else {
            return false;
        }
    }
<<<<<<< HEAD
    void insertAt(int id, int Newdata){
        Node* newNode = new Node(id,Newdata);
=======
    void add(int Newdata){
        Users* t = new Node;
        t->data = Newdata;
        t->next = head;
       head = t;
       if(isEmpty()){
        cout << "Can't add!!" << endl;
       }
       size++;
    }
    void deleteAt(int ID){
        if(isEmpty()){
            cout << "Nothing in file." << endl;
        }
>>>>>>> 777109a0763b8fc2ab994acb9eb0f299671dd5b6

        if( head == NULL){
            head = newNode;
        } else {
            Node* tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        cout << "Enter the ID: " << id << endl;
        cout << "Enter value : " << Newdata << endl;
    }
<<<<<<< HEAD
    void deleteAt(int id){
        if(isEmpty()){
            cout << "The product is empty." << endl;
            return;
        }
        if(head->id == id){
            Node* tmp = head;
            head = head->next;
            delete tmp;
            cout << " " << id << "deleted!" << endl;
            return;
        }
        Node* tmp = head;
        while (tmp->next && tmp->next->id != id){
            tmp = tmp->next;
        }
        if(tmp->next == NULL){
            cout << "ID " << id << "not found!" << endl;
            return;
        }
        Node* ToDelete = tmp->next;
        tmp->next = tmp->next->next;
        delete ToDelete;
        cout << "ID " << id << "deleted!" << endl;
    }
    void update(int id, int newData){
        Node* tmp = head ;
        while(tmp){
            if(tmp->id == id){
                tmp->data = newData;
                cout << "Product id[" << id << "] updated to " << newData << " " << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "ID [" << id << "] not found!" << endl;
    }
    // Done with add update and delete at any position by searching product id
    void saveTofile(string& filename){
        ofstream file(filename);
        if(!file.is_open()){
            cout << "File could not open!" << endl;
            return;
        }
        Node* tmp = head;
        while(tmp){
            file << tmp->id << "," << tmp->data << endl;
            tmp = tmp->next;
        }
        file.close();
        cout << "Data have been saved!" << endl;
    }
    
    void readFromFile(string& filename){
        ifstream file(filename);
        if(!file.is_open()){
            cout << "File could not open!" << endl;
            return;
        }
        string line;
        while(getline(file,line)){
            stringstream ss(line);
            string idstr, datastr;
            getline(ss,idstr, ",");
            getline(ss,datestr, ",");

            Node* newData = new Node(id,data);
            if(head == NULL){
                head = newData;
            }else {
                Node* tmp = head;
                while(tmp->next){
                    tmp = tmp->next;
                }
                tmp->next = newData;
        }
    }
    file.close();
    cout << "Data loaded." << endl;
    }
=======
};

>>>>>>> 777109a0763b8fc2ab994acb9eb0f299671dd5b6
#endif