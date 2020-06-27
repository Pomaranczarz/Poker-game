#include "Header.h"

int main()
{
    srand(time(0));
    char choice;
    Five_card* gra = new Five_card();
    do
    {
        gra->play();
        std::cout << "Do you want to continue?" << std::endl;
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
