#include <iostream>
#include "pizza_station.hpp"
using namespace std;

// Robot Joe's pizza ordering station

int main() {
    // Welcome message
    cout << "\t\t\t*************************************************\n";
    cout << "\t\t\t*       Hello and welcome to Robot Joe's!       *\n";  
    cout << "\t\t\t*    Home of the best pizza's $5.29* can buy!   *\n";
    cout << "\t\t\t*************************************************\n";

    cout << "How can we help you today?" << endl;
    
    Pizza test_pizza;
    test_pizza.main_menu();
    test_pizza.checkout();
}


