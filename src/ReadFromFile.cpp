#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

struct FlowerDetails
{
    std::string flower_name;
    int quantity;
    double price;
    double subtotal;
};

struct Receipt
{
    std::string user_name;
    int user_id;
    std::vector<FlowerDetails> flowers;
    double total_cost;
    std::string payment_method;
};

void parse_receipts(const char *filename, std::vector<Receipt> &receipts)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        std::cerr << "Error: Unable to open file.\n";
        return;
    }

    char buffer[256];
    while (fscanf(file, " *** Receipt ***%*[^\n]\n") == 0)
    {
        Receipt receipt;

        // Read user name
        fscanf(file, " User Name: %[^\n]\n", buffer);
        receipt.user_name = buffer;

        // Read user ID
        fscanf(file, " User ID  : %d\n", &receipt.user_id);

        fscanf(file, " -------------------------------\n");
        fscanf(file, " Flower Name    Quantity  Price     Subtotal\n");
        fscanf(file, " -------------------------------\n");

        while (fscanf(file, " %s %d %lf %lf\n", buffer, &receipt.user_id, &receipt.total_cost, &receipt.total_cost) == 4)
        {
            FlowerDetails flower;
            flower.flower_name = buffer;
            flower.quantity = receipt.user_id;
            flower.price = receipt.total_cost;
            flower.subtotal = receipt.total_cost;
            receipt.flowers.push_back(flower);
        }

        fscanf(file, " Total Cost: %lf\n", &receipt.total_cost);

        fscanf(file, " *******************************\n");

        fscanf(file, " Payment Method: %[^\n]\n", buffer);
        receipt.payment_method = buffer;

        receipts.push_back(receipt);
    }

    fclose(file);
}

void display_receipts(const std::vector<Receipt> &receipts)
{
    for (const auto &receipt : receipts)
    {
        std::cout << "\n\n*** Receipt ***\n\n";
        std::cout << "User Name: " << receipt.user_name << "\n";
        std::cout << "User ID  : " << receipt.user_id << "\n";
        std::cout << "------------------------------------------------------------------------------------\n";
        std::cout << "Flower Name    \t\tQuantity  \t\tPrice     \t\tSubtotal\n";
        std::cout << "------------------------------------------------------------------------------------\n";
        for (const auto &flower : receipt.flowers)
        {
            std::cout << flower.flower_name << "              " <<  flower.quantity
                      << " \t\t        " << flower.price << "$" << "\t\t       " << flower.subtotal << "$" << "\n";
        }
        std::cout << "------------------------------------------------------------------------------------\n";
        std::cout << "Total Cost: " << "$" << receipt.total_cost << "\n";
        std::cout << "*******************************\n";
        std::cout << "\n\nPayment Method: " << receipt.payment_method << "\n\n";
    }
}
