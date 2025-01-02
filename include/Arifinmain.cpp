#include <iostream>
#include <fstream>
#include <cstdio>
#include "Arifinclass1.cpp"

#define Alive 1
#define nearly_Death 0


using namespace std;

int main()
{
    FILE *flowerread;
    FlowersProductlist flower;

    flowerread = fopen("flower.txt", "r");
    if (flowerread == NULL)
    {
        std::cout << "Error opening file" << "\n";
    }
    else
    {
        char f_name[100]; // Temporary char array for fscanf
        int f_id;
        int f_status;
        int f_quantity;
        double f_price;

        // Read the data from the file
        while (fscanf(flowerread, "%s %d %d %d %lf", f_name, &f_id, &f_status, &f_quantity, &f_price) != EOF)
        {
            flower.add_product(static_cast<bool>(f_status), f_id, f_quantity, f_price, f_name);
        }        
    }
    int admin_choice; 
    int user_choice;
    int choice;
    int flower_buy_id{};
    int remove_id{};
    while (true)
    {
        std::cout << "\t\t\t\t\t\tStart Program" << std::endl;
        std::cout << "\t\t\t\t\t======= Administrator =======" << std::endl;
        std::cout << "\t\t\t\t\t|| 1.Admin                 ||" << std::endl;
        std::cout << "\t\t\t\t\t|| 2.User                  ||" << std::endl;
        std::cout << "\t\t\t\t\t|| 3.Exit                  ||" << std::endl;
        std::cout << "\t\t\t\t\t=============================" << std::endl;
        std::cout << "Who are you?: ";
        std::cin >> choice;

        switch(choice)
        {
            Administrator:
            case 1:
                cout << "\t\t\t\t\t=========== Admin ===========" << endl;
                cout << "\t\t\t\t\t|| 1.Add product           ||" << endl;
                cout << "\t\t\t\t\t|| 2.History               ||" << endl;
                cout << "\t\t\t\t\t|| 3.Delete product        ||" << endl;
                cout << "\t\t\t\t\t|| 4.Check is flower dead  ||" << endl;
                cout << "\t\t\t\t\t|| 5.Display product       ||" << endl;
                cout << "\t\t\t\t\t|| 6.Save                  ||" << endl;
                cout << "\t\t\t\t\t|| 7.Exit                  ||" << endl;
                cout << "\t\t\t\t\t=============================" << endl;
                cout << "Choose: ";
                cin >> admin_choice;
                switch(admin_choice)
                {
                    case 1:
                        std::cout << "case1";
                        break;
                    case 2:
                        std::cout << "case2";
                        break;
                    case 3:
                        std::cout << "case3";
                        break;
                    case 4:
                        std::cout << "case4";
                        break;
                    case 5:
                        std::cout << "case5";
                        break;
                    case 6:
                        std::cout << "case6";
                        break;
                    case 7:
                        std::cout << "case7";
                        break;
                    default:
                        cout << "Invalid choice!!";
                        goto Administrator;
                        break;
                }
            break;
            User:
            case 2:
                std::cout << "\n";
                std::cout << "Users Name : ";
                std::string users_name{};
                std::cin >> users_name;

                std::cout << "\n";

                std::cout << "Uses Id : ";
                int users_id{};
                std::cin >> users_id;

                Users users1{users_id , users_name};

                std::cout << "\n";

                std::cout << "Welcome : " << users1.user_name() << "\n";
                std::cout << "Id      : " << users1.users_id()  << "\n"; 

                Users:
                cout << "\t\t\t\t\t=========== User ============" << endl;
                cout << "\t\t\t\t\t|| 1.Buy                   ||" << endl;
                cout << "\t\t\t\t\t|| 2.remove                ||" << endl;
                cout << "\t\t\t\t\t|| 3.Promotion             ||" << endl;
                cout << "\t\t\t\t\t|| 4.Receipt               ||" << endl;
                cout << "\t\t\t\t\t|| 5.Exit                  ||" << endl;
                cout << "\t\t\t\t\t=============================" << endl;
                cout << "Choose: ";
                cin >> user_choice;
                switch (user_choice)
                {
                    case 1:
                        std::cout << "\n";
                        flower.Calculate_product_for_promotion();
                        flower.Display_product_for_users();
                        std::cout << "Enter Flowers Id You Want To Buy : ";
                        std::cin >> flower_buy_id;
                        if(flower_buy_id == 1)
                        {
                            Flowers flowersale;
                            flower.search_id(1 , &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status() , flowersale.flower_id() , flowersale.flower_price() , flowersale.flower_name() , quantity);
                            goto Users;
                        }
                        else if(flower_buy_id == 2)
                        {
                            Flowers flowersale;
                            flower.search_id(2, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 3)
                        {
                            Flowers flowersale;
                            flower.search_id(3, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 4)
                        {
                            Flowers flowersale;
                            flower.search_id(4, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 5)
                        {
                            Flowers flowersale;
                            flower.search_id(5, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 6)
                        {
                            Flowers flowersale;
                            flower.search_id(6, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 7)
                        {
                            Flowers flowersale;
                            flower.search_id(7, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 8)
                        {
                            Flowers flowersale;
                            flower.search_id(2, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        else if (flower_buy_id == 9)
                        {
                            Flowers flowersale;
                            flower.search_id(9, &flowersale);
                            std::cout << "How many : ";
                            int quantity{};
                            std::cin >> quantity;
                            users1.addtocart(flowersale.flower_status(), flowersale.flower_id(), flowersale.flower_price(), flowersale.flower_name(), quantity);
                            goto Users;
                        }
                        break;
                    case 2:
                        users1.display_carts();
                        std::cout << "Remove Items from \n";
                        std::cout << "(1) Item_Shown_On_First_Cart \n";
                        std::cout << "(2) Item_Shown_On_Last_Cart \n";
                        std::cout << "(3) Remove By ID \n";
                        std::cout << "Enter Yours Choice : ";
                        std::cin >> remove_id;
                        if(remove_id == 1)
                        {
                            users1.delete_first_cart();
                            std::cout << "\n-------------Item Remove----------- \n";
                            users1.display_carts();
                            goto Users;
                        }
                        else if(remove_id == 2)
                        {
                            users1.delete_last_cart();
                            std::cout << "\n-------------Item Remove----------- \n";
                            users1.display_carts();
                            goto Users;
                        }
                        else if(remove_id == 3)
                        {
                            std::cout << "Enter Flowers Id you want to remove : ";
                            int flower_id{};
                            std::cin >> flower_id;
                            users1.delete_flower_by_id(flower_id);
                            std::cout << "\n-------------Item Remove----------- \n";
                            users1.display_carts();
                            goto Users;
                        }
                        break;
                    case 3:
                        flower.Display_product_for_nearly_death();
                        goto Users;
                        break;
                    case 4:
                        users1.display_carts();
                        break;
                    case 5:
                        std::cout << "Goodbye!!";
                        return 1;
                        break;
                    default:
                        std::cout << "Invalid choice!!";
                        goto User;
                        break;
                }
        }
    }

        return 0;
    }