#ifndef CLASS /* preventing duplicate class file */
#define CLASS

#include <iostream>
#include <cstdio>
#include <fstream>
#include <iomanip>

class Admin;              /*          Information Admin               */
class Flowers;            /*           Information ( Flowers )            */
class FlowersProductlist; /*            ADT Flowers ( Admin )         */

class Users;        /*           Information Users             */
class FlowersCarts; /*             Users Buying ( Flowers )*/

class Admin
{
public:
    void admin_users_history()
    {
        const char *filename = "receipt.txt";
        std::vector<Receipt> receipts;
        parse_receipts(filename, receipts);
        display_receipts(receipts);
    }
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
    Flowers(bool status, int flower_id, int flower_quantity, double flowers_price, std::string flower_name, Flowers *flower_next = nullptr)
        : m_flower_status{status}, m_flower_id{flower_id}, m_flower_price{flowers_price}, m_flower_quantity{flower_quantity}, m_flower_name{flower_name}, m_flower_next{flower_next}
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
    void update_price_nearly_death()
    {
        this -> m_flower_price =  m_flower_price * 0.5;  
    }
    friend class FlowersProductlist;
    friend class Admin;
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
    void Display_product_for_nearly_death()
    {
        Flowers *current = head;
        while(current != nullptr)
        {
            if(current->m_flower_status == 0)
            {
                current->update_price_nearly_death();
                std::cout << "Flowers_name     : " << current->m_flower_name << "\n";
                std::cout << "Flowers_id       : " << current->m_flower_id << "\n";
                std::cout << "Flowers_price    : " << current->m_flower_price << "\n";
                std::cout << "\n\n -------------------------------------------------------- \n\n";
            }
            else;
            current = current->m_flower_next;
        }
    }
    void Calculate_product_for_promotion()
    {
        Flowers *current = head;
        while (current != nullptr)
        {
            if (current->m_flower_status == 0)
            {
                current->update_price_nearly_death();
            }
            else;
            current = current->m_flower_next;
        }
    }
    void Display_product_for_users()
    {
        Flowers *current = head;
        while (current != nullptr)
        {
            std::cout << "Flowers_name     : " << current->m_flower_name << "\n";
            std::cout << "Flowers_id       : " << current->m_flower_id << "\n";
            std::cout << "Flowers_price    : " << current->m_flower_price << "\n";
            std::cout << "\n\n -------------------------------------------------------- \n\n";

            current = current->m_flower_next;
        }
    }

    bool product_empty()
    {
        if (head == nullptr)
        {
            return true;
        }
    }
    bool delete_first_product()
    {
        if (head == nullptr)
        {
            return false;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        if (head != nullptr)
        {
            Flowers *current = head;
            current = current->m_flower_next;
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
    void search_id(int id, Flowers *checkid)
    {
        Flowers *current = head;
        for (current; current != nullptr;)
        {
            if (current->m_flower_id == id)
            {
                checkid->m_flower_id = current->m_flower_id;
                checkid->m_flower_name = current->m_flower_name;
                checkid->m_flower_price = current->m_flower_price;
                checkid->m_flower_status = current->m_flower_status;
                checkid->m_flower_quantity = current->m_flower_quantity;
            }
            current = current->m_flower_next;
        }
    }
    void write_to_file(const std::string &filename)
    {
        std::ofstream file(filename , std::ios::out);

        if (!file)
        {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        Flowers *current = head;
        while (current != nullptr)
        {
            file << current->m_flower_name << " "
                 << current->m_flower_id << " "
                 << current->m_flower_status << " "
                 << current->m_flower_quantity << " "
                 << current->m_flower_price << "\n";

            current = current->m_flower_next;
        }

        file.close();
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
    FlowersCarts(bool flower_status, int flower_id, double flower_price, std::string flower_name, int flower_quantity_cart, FlowersCarts *flower_next = nullptr)
        : m_flower_status{flower_status}, m_flower_id{flower_id}, m_flower_price{flower_price}, m_flower_name{flower_name}, m_flowers_quantity_cart{flower_quantity_cart}, m_flower_next{flower_next} {}

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
        this->m_name = new_name;
    }
    void set_product_quantity(int quantity)
    {
        this ->m_product_quantity = quantity;
    }
    void generate_receipt()
    {
        if (m_users_cart_head == nullptr)
        {
            std::cout << "\n\nCart is empty. No receipt to generate.\n\n";
            return;
        }

        std::ofstream receipt_file("receipt.txt" , std::ios::app);
        if (!receipt_file)
        {
            std::cerr << "Error: Unable to create receipt file.\n";
            return;
        }

        std::cout << "\n\n*** Receipt ***\n";
        receipt_file << "*** Receipt ***\n";

        std::cout << "User Name: " << m_name << "\n";
        receipt_file << "User Name: " << m_name << "\n";

        std::cout << "User ID  : " << m_id << "\n";
        receipt_file << "User ID  : " << m_id << "\n";

        std::cout << "-------------------------------\n";
        receipt_file << "-------------------------------\n";

        std::cout << std::left << std::setw(15) << "Flower Name"
                  << std::setw(10) << "Quantity"
                  << std::setw(10) << "Price"
                  << std::setw(10) << "Subtotal\n";
        receipt_file << std::left << std::setw(15) << "Flower Name"
                     << std::setw(10) << "Quantity"
                     << std::setw(10) << "Price"
                     << std::setw(10) << "Subtotal\n";

        std::cout << "-------------------------------\n";
        receipt_file << "-------------------------------\n";

        FlowersCarts *current = m_users_cart_head;
        double total_cost = 0;

        while (current != nullptr)
        {
            double subtotal = current->m_flower_price * current->m_flowers_quantity_cart;
            total_cost += subtotal;

            std::cout << std::left << std::setw(15) << current->m_flower_name
                      << std::setw(10) << current->m_flowers_quantity_cart
                      << std::setw(10) << "$" << current->m_flower_price
                      << std::setw(10) << "$" << subtotal << "\n";

            receipt_file << std::left << std::setw(15) << current->m_flower_name
                         << std::setw(10) << current->m_flowers_quantity_cart
                         << std::setw(10) << current->m_flower_price
                         << std::setw(10) << subtotal << "\n";

            current = current->m_flower_next;
        }

        std::cout << "-------------------------------\n";
        std::cout << "Total Cost: $" << total_cost << "\n";
        std::cout << "*******************************\n";

        receipt_file << "-------------------------------\n";
        receipt_file << "Total Cost: " << total_cost << "\n";
        receipt_file << "*******************************\n";

        int payment_choice;
        std::string payment_method;
        std::cout << "Choose a payment method:\n";
        std::cout << "1. Cash\n";
        std::cout << "2. Credit Card\n";
        std::cout << "Enter your choice: ";
        std::cin >> payment_choice;

        switch (payment_choice)
        {
        case 1:
            payment_method = "Cash";
            break;
        case 2:
            payment_method = "Credit Card";
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Cash.\n";
            payment_method = "Cash";
            break;
        }

        std::cout << "Payment Method: " << payment_method << "\n";
        receipt_file << "Payment Method: " << payment_method << "\n";

        receipt_file.close();
    }
};

#endif