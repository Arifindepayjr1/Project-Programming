#include <iostream>
#include <fstream>
#include <cstdio>
#include "class.cpp"

#define Alive 1
#define Death 0

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

        fclose(flowerread);
        flower.Display_product();
    }

  return 0;
}