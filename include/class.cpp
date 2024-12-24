#ifndef CLASS       /* preventing duplicate class file */
#define CLASS 
#include <iostream>

class Admin;                        /*          Information Admin               */
class Flowers;                     /*           Information Flowers            */
class Users;                      /*           Information Users             */
class FlowersProductlist;        /*            ADT Flowers              */ 
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
    double m_flower_price{};
    std::string m_flower_name{};
    Flowers *m_flower_next{nullptr};

public:
    Flowers() = default;
    Flowers(bool status, int flower_id, int flower_quantity, double flowers_prcice , std::string flower_name, Flowers *flower_next = nullptr)
        : m_flower_status{status}, m_flower_id{flower_id}, m_flower_price{flowers_prcice} , m_flower_quantity{flower_quantity}, m_flower_name{flower_name}, m_flower_next{flower_next}
    {
    }

    int flower_id();
    int flower_quantity();
    bool flower_status();
    std::string flower_name();
    bool update_flower_status(bool new_status);
    friend class FlowersProductlist;
};
class FlowersProductlist
{
private:
    Flowers *head{nullptr};
    Flowers *tail{nullptr};
    int size{};

public:
    FlowersProductlist() = default;
    ~FlowersProductlist()
    {
        Flowers *current = head;
        for (current; current != nullptr;)
        {
            head = head->m_flower_next;
            delete current;
            current = head;
        }
    }
    void add_product(bool flowers_status, int flowers_id, int flowers_quantity, double flowers_price, std::string flowers_name)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = new Flowers{flowers_status, flowers_id, flowers_quantity, flowers_price, flowers_name};
            tail = head;
            ++size;
        }
        else
        {
            head = new Flowers{flowers_status, flowers_id, flowers_quantity, flowers_price, flowers_name, head};
            ++size;
        }
    }
    void Display_product()
    {
        Flowers *current = head;
        for (current; current != nullptr;)
        {
            std::cout << "Flowers_status   : " << current->m_flower_status << "\n";
            std::cout << "Flowers_id       : " << current->m_flower_id << "\n";
            std::cout << "Flowers_quantity : " << current->m_flower_quantity << "\n";
            std::cout << "Flowers_price    : " << current->m_flower_price << "\n";
            std::cout << "Flowers_name     : " << current->m_flower_name << "\n";
            std::cout << "\n\n -------------------------------------------------------- \n\n";
            head = head->m_flower_next;
            current = head;
        }
    }
    bool product_empty()
    {
        if(head == nullptr)
        {
            return true;
        }
    }
    bool delete_first_product()
    {
        if(head == nullptr)
        {
            return false; 
        }
        if(head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        if(head != nullptr)
        {
            Flowers* current = head;
            current = current -> m_flower_next;
            delete head;
            head = current;  
            return true;
        }
    } 
    bool delete_last_product()
    {
        if(tail == nullptr)
        {
            return false;
        }
        if(head == tail)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        if(head -> m_flower_next == tail)
        {
            delete tail;
            tail = head;
            return true;
        }
        else 
        {
            Flowers* current = head;
            for(current; current != tail;){}
            delete tail;
            tail = current;
            return true;
        }
    }
};

#endif