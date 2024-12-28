#ifndef CLASS       /* preventing duplicate class file */
#define CLASS 

#include <iostream>
#include <cstdio>
#include <fstream>

class Admin;                        /*          Information Admin               */
class Flowers;                     /*           Information ( Flowers )            */
class FlowersProductlist;         /*            ADT Flowers ( Admin )         */ 

class Users;                      /*           Information Users             */
class FlowersCarts;             /*             Users Buying ( Flowers )*/

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
    double flower_price() 
    {
        return m_flower_price;
    }
    int flower_id()
    {
        return m_flower_id;
    }
    int flower_quantity()
    {
        return m_flower_quantity;
    }
    bool flower_status()
    {
        return m_flower_status;
    }
    std::string flower_name()
    {
        return m_flower_name;
    }
    bool update_flower_status(bool new_status)
    {
        this->m_flower_status = new_status;
        return true;
    }
    friend class FlowersProductlist;
};
class FlowersProductlist /* for admin */
{
private:
    Flowers *head{nullptr};
    Flowers *tail{nullptr};
    int m_size{};

public:
    FlowersProductlist() = default;
    ~FlowersProductlist()
    {
        Flowers *current = head;
        while (current != nullptr)
        {
            Flowers *next = current->m_flower_next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        m_size = 0;
    }
    void add_product(bool flowers_status, int flowers_id, int flowers_quantity, double flowers_price, std::string flowers_name)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = new Flowers{flowers_status, flowers_id, flowers_quantity, flowers_price, flowers_name};
            tail = head;
            ++m_size;
        }
        else
        {
            head = new Flowers{flowers_status, flowers_id, flowers_quantity, flowers_price, flowers_name, head};
            ++m_size;
        }
    }
    void Display_product()
    {
        Flowers *current = head; 
        while (current != nullptr)
        {
            std::cout << "Flowers_status   : " << current->m_flower_status << "\n";
            std::cout << "Flowers_id       : " << current->m_flower_id << "\n";
            std::cout << "Flowers_quantity : " << current->m_flower_quantity << "\n";
            std::cout << "Flowers_price    : " << current->m_flower_price << "\n";
            std::cout << "Flowers_name     : " << current->m_flower_name << "\n";
            std::cout << "\n\n -------------------------------------------------------- \n\n";

            current = current->m_flower_next; 
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
        if (tail == nullptr)
        {
            return false; 
        }
        if (head == tail)
        {
            delete tail; 
            head = tail = nullptr;
            --m_size;
            return true;
        }

        Flowers *current = head;
        while (current->m_flower_next != tail)
        {
            current = current->m_flower_next;
        }

        delete tail;
        tail = current;
        tail->m_flower_next = nullptr;
        --m_size;
        return true;
    }

    int get_size()
    {
        return m_size;
    }
    bool delete_by_id(int flower_id)
    {
        if (head == nullptr)
        {
            std::cout << "The product list is empty.\n";
            return false;
        }

        if (head->m_flower_id == flower_id)
        {
            return delete_first_product();
        }

        Flowers *current = head;
        Flowers *previous = nullptr;

        while (current != nullptr && current->m_flower_id != flower_id)
        {
            previous = current;
            current = current->m_flower_next;
        }

        if (current == nullptr)
        {
            std::cout << "Flower with ID " << flower_id << " not found in the list.\n";
            return false;
        }

        previous->m_flower_next = current->m_flower_next;

        if (current == tail)
        {
            tail = previous;
        }

        delete current;
        --m_size;

        std::cout << "Flower with ID " << flower_id << " deleted successfully.\n";
        return true;
    }
    void search_id(int id , Flowers* checkid)
    {
        Flowers* current = head;
        for(current; current != nullptr;)
        {
            if(current->m_flower_id == id)
            {
                checkid->m_flower_id       = current->m_flower_id;
                checkid->m_flower_name     = current->m_flower_name;
                checkid->m_flower_price    = current->m_flower_price;
                checkid->m_flower_status   = current->m_flower_status;
                checkid->m_flower_quantity = current->m_flower_quantity;    
            }
            current = current -> m_flower_next;
        }
    }

    friend class Admin;
};
class FlowersCarts
{
private:
    bool m_flower_status{}; 
    int m_flower_id{};
    double m_flower_price{};
    std::string m_flower_name{};
    int m_flowers_quantity_cart{}; 
    FlowersCarts *m_flower_next{nullptr};

public:
    FlowersCarts() = default;
    FlowersCarts(bool flower_status , int flower_id , double flower_price , std::string flower_name , int flower_quantity_cart , FlowersCarts* flower_next = nullptr)
    : m_flower_status{flower_status} , m_flower_id{flower_id} , m_flower_price{flower_price} , m_flower_name{flower_name} , m_flowers_quantity_cart{flower_quantity_cart} , m_flower_next{flower_next}{}
    
    int flower_id()
    {
        return m_flower_id;
    }
    int flower_quantity_cart()
    {
        return m_flowers_quantity_cart;
    }
    bool flower_status()
    {
        return m_flower_status;
    }
    std::string flower_name()
    {
        return m_flower_name;
    }
    bool update_flower_status(bool new_status)
    {
        m_flower_status = new_status;
        return true;
    }

    friend class Users;
};
class Users
{
private:
    int m_id{};
    int m_product_quantity{};
    std::string m_name{};
    FlowersCarts *m_users_cart_head{};
    FlowersCarts *m_users_cart_tail{};

public:
    Users() = default;
    Users(int id, std::string name)
        : m_id{id}, m_name{name}
    {
    }
    void addtocart(bool flower_status, int flower_id, double flower_price, std::string flower_name, int flowers_quantity_cart)
    {
        FlowersCarts *new_cart = new FlowersCarts{flower_status, flower_id, flower_price, flower_name, flowers_quantity_cart, nullptr};
        if (m_users_cart_head == nullptr)
        {
            m_users_cart_head = new_cart;
            m_users_cart_tail = new_cart;
        }
        else
        {
            m_users_cart_tail->m_flower_next = new_cart;
            m_users_cart_tail = new_cart;
        }
    }

    ~Users()
    {
        FlowersCarts *current = m_users_cart_head;
        while (current != nullptr)
        {
            FlowersCarts *next = current->m_flower_next;
            delete current;
            current = next;
        }
        m_users_cart_head = m_users_cart_tail = nullptr;
    }

    void display_carts()
    {
        if (m_users_cart_head == nullptr)
        {
            std::cout << "\n\nCart is empty.\n\n";
            return;
        }

        FlowersCarts *current = m_users_cart_head;
        while (current != nullptr)
        {
            std::cout << "Flowers name     : " << current->m_flower_name << "\n";
            std::cout << "Flowers id       : " << current->m_flower_id << "\n";
            std::cout << "Flowers status   : " << (current->m_flower_status ? "Alive" : "Dead") << "\n";
            std::cout << "Flowers quantity : " << current->m_flowers_quantity_cart << "\n";
            std::cout << "Flowers price    : " << current->m_flower_price << "\n";
            std::cout << "\n\n-----------------------\n\n";
            current = current->m_flower_next;
        }
    }

    void delete_first_cart()
    {
        if (m_users_cart_head == nullptr)
        {
            std::cout << "\n\nYour cart is empty.\n\n";
            return;
        }
        FlowersCarts *temp = m_users_cart_head;
        m_users_cart_head = m_users_cart_head->m_flower_next;
        if (m_users_cart_head == nullptr) 
            m_users_cart_tail = nullptr;
        delete temp;
    }

    void delete_last_cart()
    {
        if (m_users_cart_head == nullptr)
        {
            std::cout << "\n\nYour cart is empty.\n\n";
            return;
        }
        if (m_users_cart_head == m_users_cart_tail) 
        {
            delete m_users_cart_head;
            m_users_cart_head = m_users_cart_tail = nullptr;
            return;
        }
        FlowersCarts *current = m_users_cart_head;
        while (current->m_flower_next != m_users_cart_tail)
        {
            current = current->m_flower_next;
        }
        delete m_users_cart_tail;
        current->m_flower_next = nullptr;
        m_users_cart_tail = current;
    }
    void delete_flower_by_id(int flower_id)
    {
        if (m_users_cart_head == nullptr) // Empty cart case
        {
            std::cout << "\n\nYour cart is empty.\n\n";
            return;
        }

        if (m_users_cart_head->m_flower_id == flower_id)
        {
            FlowersCarts *temp = m_users_cart_head;
            m_users_cart_head = m_users_cart_head->m_flower_next;
            if (m_users_cart_head == nullptr)
            {
                m_users_cart_tail = nullptr;
            }
            delete temp;
            std::cout << "Flower with ID " << flower_id << " deleted.\n";
            return;
        }


        FlowersCarts *current = m_users_cart_head;
        while (current->m_flower_next != nullptr && current->m_flower_next->m_flower_id != flower_id)
        {
            current = current->m_flower_next;
        }

        if (current->m_flower_next == nullptr) 
        {
            std::cout << "Flower with ID " << flower_id << " not found in the cart.\n";
            return;
        }

        FlowersCarts *temp = current->m_flower_next;
        current->m_flower_next = current->m_flower_next->m_flower_next;

        if (temp == m_users_cart_tail) 
        {
            m_users_cart_tail = current;
        }

        delete temp;
        std::cout << "Flower with ID " << flower_id << " deleted.\n";
    }

    int users_id()
    {
        return m_id;
    }
    std::string user_name()
    {
        return m_name;
    }
    void users_update_name(std::string new_name)
    {
        this -> m_name = new_name;
    } 
};

#endif