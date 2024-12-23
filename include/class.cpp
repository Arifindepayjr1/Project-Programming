#ifndef CLASS       /* preventing duplicate class file */
#define CLASS 


#include <iostream>

using namespace std;

class Admin;            /*          Information Admin               */
class Flowers;          /*          Information Flowers            */
class Users;            /*          Information Users             */
class Productlist;      /*                      ADT              */

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
class ProductList
{
 public:
    Users* head;
    Users* tail;
    int size;
    ProductList(){
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

    }
};

#endif