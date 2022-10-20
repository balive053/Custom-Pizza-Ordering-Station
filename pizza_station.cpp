// compiled with g++ --version 12.1.0
#include <iostream>
#include <string>
#include "pizza_station.hpp"
using namespace std;

void Pizza::main_menu() {

    // reset all variables and counters
    if (pizza_counter != 0) {
        cout << "pizza_counter" << pizza_counter << endl;
        // Variables to create a custom pizza
        base = 0, sauce = 0, cheese = 0, tomato = 0, pepper = 0, olives = 0;
        // Custom meat choices
        bacon = 0, pepperoni = 0, chicken = 0, salami = 0;
        // Counters
        topping_counter = 0;
        meat_counter = 0;
        // Previous pizza price
        finished_pizza_price = 0;
        temp_price = 0;
    }
    cout << "meat_counter" << meat_counter << "topping_counter" << topping_counter << "bacon"
    << bacon << "cheese" << cheese << "temp_price" << temp_price << "finished_pizza_price" << finished_pizza_price
    << "chekcout_price" << chekcout_price << endl;

    // Value for main choice in main menu
    int choice;

    cout << "1 - Order a custom pizza\n"
         << "2 - See set pizza menu\n";
    
    // Get and verify cin choice
    choice = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);

    switch(choice) {
        case 1:
            pizza_maker();
            break;
        case 2:
            pizza_menu();
            break;
    }
}

void Pizza::pizza_maker() {
    // Prompt user for input on base, sauce, and cheese
    base = base_selector();
    sauce = sauce_selector();
    cheese, tomato, pepper, olives = toppings_selector();

    cout << "base " << base << " sauce " << sauce << " cheese " << cheese << " tomato " << tomato 
         << " pepper " << pepper << " olives " << olives << " topping_counter " << topping_counter
         << " pepperoni " << pepperoni << "chicken" << chicken << "bacon" << bacon << "salami" << salami;
}

int Pizza::base_selector() {

    int base_type;
    temp_price = base_price;
    cout << "Please select the kind of pizza base would you like?\n"
        << "1 - Thin base\n" 
        << "2 - Regular\n"
        << "3 - Thick base\n"
        << "4 - Back to main menu\n"
        << "5 - Quit\n";

    // Verify valid option for base was chosen
    base_type = verifier("Error. Please enter a valid number (1-5)\n", 1, 5);
    
    // handle cin base_type choice
    switch (base_type) {
        case 1: case 2: case 3:
            return base_type;
            break;
        case 4:
            main_menu();
            return 0;
            break;
        default:
            return 0;
            break;
    }
}

int Pizza::sauce_selector() {
    int sauce_type;
    cout << "Please select your preferred sauce?\n"
        << "1 - Classic tomato\n" 
        << "2 - BBQ\n"
        << "3 - Hot Sauce\n"
        << "4 - Back to main menu\n"
        << "5 - Quit\n";

    // Verify valid option for base was chosen
    sauce_type = verifier("Error. Please enter a valid number (1-5)\n", 1, 5);
    
    // handle cin sauce_type choice
    switch (sauce_type) {
        case 1: case 2: case 3:
            return sauce_type;
            break;
        case 4:
            main_menu();
            return 0;
            break;
        default:
            return 0;
            break;
    }
}

int Pizza::toppings_selector() {
    cout << "You may select upto 3 portions of any topping free\n"
        << "and additional toppings for $0.45 each!\n" 
        << "Select which toppings you would like you add:\n" 
        << "1 - Extra Cheese\n"
        << "2 - Tomato\n" 
        << "3 - Pepper\n"
        << "4 - Olives\n" 
        << "5 - Enough toppings, on to the meat!" << endl;
    int choice; 
    // Get and verify cin choice
    choice = verifier("Error. Please enter a valid number (1-5)\n", 1, 5);

    switch (choice) {
        // topping cheese
        case 1:
            topping_cheese();
            break;
        // topping tomato
        case 2:
            // remove previous choice if exists
            if (tomato_clicker == 1 || tomato_clicker == 2) {
                topping_counter -= tomato_clicker;
            }
            tomato = topper_adder();
            // set clicker count to current choice for toppings count
            tomato_clicker = tomato;
            toppings_selector();
            break;
        // topping pepper
        case 3:
            // remove previous choice if exists
            if (pepper_clicker == 1 || pepper_clicker == 2) {
                topping_counter -= pepper_clicker;
            }
            pepper = topper_adder();
            // set clicker count to current choice for toppings count
            pepper_clicker = pepper;
            toppings_selector();
            break;
        // topping olives
        case 4:
            // remove previous choice if exists
            if (olives_clicker == 1 || olives_clicker == 2) {
                topping_counter -= olives_clicker;
            }
            olives = topper_adder();
            olives_clicker = olives;
            toppings_selector();
            break;
        // topping meat 
        case 5:
            toppings_meat();
            break;
    }
    return 0;
}

// Topping selectors //
void Pizza::topping_cheese() {
    if (cheese == 0) {
        cout << "All pizzas come with a standard cheddar cheese toping.\n"
             << "To add extra cheese, please select the type you would like:\n";
    }
    else {
        cout << "You have already selected extra cheese topping.\n"
             << "To change your selection, please select from the options below:\n";
    }
    cout << "1 - Double the cheddar!\n"
         << "2 - Blue cheese chunks\n"
         << "3 - Brie cheese chunks\n"
         << "4 - Back" << endl;
    
    // Get and verify cin choice plus add to topping count
    cheese = verifier("Error. Please enter a valid number (1-4)\n", 1, 4);
    // Count topping and handle cases with change of choice to aviod double charging
    if (cheese == 0) {
        topping_counter += 1;
    }
    cout << "\nOne topping portion has been added to your pizza!\n" 
         << "In total you have now added " << topping_counter << " portions.\n" << endl;
    
    // Return to toppings menu 
    toppings_selector();
}

int Pizza::topper_adder() {
    cout << "Would you like a single or double serving?:" << endl;
    cout << "1 - Single portion\n"
         << "2 - Make that a double portion! (2 portions of toppings)\n"
         << "3 - Yuck, my bad, no thanks!\n"
         << "4 - Back" << endl;
    int feedback;
    // Get and verify cin choice plus add to topping count
    feedback = verifier("Error. Please enter a valid number (1-4)\n", 1, 4);
    
    switch(feedback) {
        case 1: 
            // Adjust topping count
            cout << "\nOne topping portion has been added to your pizza!\n" 
                 << "In total you have now added " << topping_counter << " portions.\n" << endl;
            topping_counter += 1;
            return feedback;
            break;
        case 2:
            // Adjust topping count
            cout << "\nTwo topping portions have been added to your pizza!\n" 
                 << "In total you have now added " << topping_counter << " portions.\n" << endl;
            topping_counter += 2;
            return feedback;
            break;
        case 3: 
            return 0;
            break;
        case 4:
            // return to topping options
            toppings_selector();
            break;
        default:
            break;
    }
    return 0;
}

void Pizza::toppings_meat() {

    if (salami == 0 && pepperoni == 0 && chicken == 0 && bacon == 0) {
        cout << "All pizzas come with a free meat topping of your choice!\n"; 
    }
    int choice;
    cout << "Please choose from the options below\n"
         << "1 - Salami\n"
         << "2 - Pepperoni\n"
         << "3 - Chicken\n"
         << "4 - Bacon\n" 
         << "5 - No meat for me thanks!" << endl;
    if ((salami + pepperoni + chicken + bacon) > 0) {
        cout << "6 - I'm good with my current choices\n"
             << "7 - Back to toppings menu" << endl;
             // Verify valid option for base was chosen
            choice = verifier("Error. Please enter a valid number (1-7)\n", 1, 7);
    }
    else {
        cout << "6 - Back to toppings menu" << endl;
        // Verify valid option for base was chosen
        choice = verifier("Error. Please enter a valid number (1-6)\n", 1, 6);
    }

    switch (choice) {
        case 1:
            salami += 1;
            extra_meat();
            break;
        case 2:
            pepperoni += 1;
            extra_meat();
            break;
        case 3:
            chicken += 1;
            extra_meat();
            break;
        case 4:
            bacon += 1;
            extra_meat();
            break;
        case 5:
            // move to next section
            finalizer(tomato, pepper, olives);
            break;
        case 6:
            if ((salami+pepperoni+chicken+bacon) > 0) {
                finalizer(tomato, pepper, olives);
            }
            else {
                // back to previous menu
                toppings_selector();
            }
            break;
        case 7:
            // back to previous menu
            toppings_selector();
            break;
    }
}

void Pizza::extra_meat() {

    cout << "Would you like to add extra meat for just $0.70?\n"
         << "1 - Give me more meat!\n"
         << "2 - I'm good, thanks. On to the checkout!\n";
    
    // Verify valid option for base was chosen
    int choice;
    choice = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);

    if (choice == 1) {
        // back to meat topping options
        toppings_meat();
    } 
    else {
        // move to next section
        finalizer(tomato, pepper, olives);
    }
}

int Pizza::verifier(string message, int min, int max) {

    int input_test;
        cin >> input_test;
        while (cin.fail() || (input_test < min || input_test > max)) {
            cout << message << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> input_test;
        }
    return input_test;
}

void Pizza::finalizer(int tomato, int pepper, int olives) {
    
    // Summarize choices on final custom pizza 
    cout << "Your final custom pizza has:\n" 
         << "Base:" << endl;
    // display pizza base
    switch (base) {
        case 1: 
            cout << "Thin base\n\n";
            break;
        case 2:
            cout << "Regular base\n\n";
            break;
        case 3: 
            cout << "Thick base\n\n";
            break;
        default:
            cout << "Error\n\n";
            break;
    }

    cout << "Sauce:" << endl;
    // display pizza sauce
    switch (base) {
        case 1: 
            cout << "Classic tomato\n\n";
            break;
        case 2:
            cout << "BBQ\n\n";
            break;
        case 3: 
            cout << "Hot Sauce\n\n";
            break;
        default:
            cout << "Error\n\n";
            break;
    }

    // display cheese topping
    cout << "Cheese:" << endl;
    switch (cheese) {
        case 1:
            cout << "Double cheddar" << endl;
            break;
        case 2:
            cout << "Standard + extra blue cheese : 1 portion\n" << endl;
            break;
        case 3:
            cout << "Standard + extra brie cheese : 1 portion\n" << endl;
            break;
        default:
            cout << "Standard\n" << endl;
            break;
    }

    // display toppings
    cout << "and toppings of:" << endl;
    std::vector<int> toppings = {tomato, pepper, olives};
    std::vector<string> toppings_names = {"tomato", "pepper", "olives"};
    for (int i = 0; i< toppings.size(); i++) {
        if (toppings[i] > 0) {
            cout << toppings_names[i] << ": " << toppings[i] << " portion(s)" << endl;
        }
    }  

    // display meat toppings
    std::vector<int> meat_list = {bacon, pepperoni, chicken, salami};
    std::vector<string> meat_names = {"bacon", "pepperoni", "chicken", "salami"};
    for (int i = 0; i< meat_list.size(); i++) {
        if (meat_list[i] > 0) {
            // add extra meat toppings to price
            meat_counter += meat_list[i];
            cout << meat_names[i] << ": " << meat_list[i] << " portion(s)" << endl;
        }
    }   

    // calculate price of toppings/extra cheese without charging for first 3
    if (topping_counter >=3 || (topping_counter >=2 && cheese > 0)) {
        // account for cheese with other toppings
        if (cheese > 0) {
            topping_counter +=1;
        }
        topping_set_price = (topping_counter-3) * topping_unit_price;
    }
    // calculate price of meat toppings without charging for first 1
    if (meat_counter >=1) {
        meat_set_price = (meat_counter-1) * meat_topping_unit_price;
    }

    // calculate and display price of current pizza
    finished_pizza_price += temp_price + meat_set_price + topping_set_price;
    cout << "Final pizza price : $" << finished_pizza_price << endl;
 
    // calculate and display price of total order
    chekcout_price += finished_pizza_price;
    cout << "Total order price : $" << chekcout_price << endl;

    cout << "Please confirm your pizza:\n" 
         << "1 - Looks good to me!\n"
         << "2 - Back to main menu\n";

    // Get and verify cin choice
    int choice = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);
    if (choice == 1) {
        pizza_counter += 1;
        cout << "Super!! Your custom pizza order has been saved." << endl;
        additional_menu();
    }
    if (choice == 2) {
        // remove total from order and go back to menu
        chekcout_price -= finished_pizza_price;
        toppings_selector();
    }
}

void Pizza::additional_menu() {
    
    cout << "Would you like to add any further pizzas to your order?\n" 
         << "1 - Give me another pizza!!\n" 
         << "2 - That's enough pizza for today" << endl;
    
    // get and verify choice
    int choice;
    choice = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);

    if (choice == 1) {
        main_menu();
    }
    else {
        checkout();
    }
}

void Pizza::pizza_menu() {
    cout << "Please select an item from our menu below:\n"
         << "1 - Margarita - Double cheddar cheese and tomato\n"
         << "2 - Meat Lovers - Cheddar cheese, tomato, BBQ sauce, pepperoni, bacon, and salami\n"
         << "3 - Vegetarian - Cheddar cheese, olives, mushroom, tomato, and pepper\n"
         << "4 - Egalitarian - Blue cheese, brie cheese, tomato, oliver, and pepperoni\n"
         << "5 - Olivetti - Cheddar cheese, double olives, tomato, mushroom, and salami\n"
         << "6 - The Italian - Cheddar cheese, olives, tomato, pepperoni, and salami\n" 
         << "7 - Dynamite - Cheddar cheese, hot sauce, tomato, olives, bacon, salami" 
         << "8 - Back" << endl;

    // get and verify choice
    int choice;
    choice = verifier("Error. Please enter a valid number (1-8)\n", 1, 8);

    // confirm choice is correct
    cout << "You selected: " << choice << "\n"
         << "Please confirm your choice:\n"
         << "1 - Confirm\n"
         << "2 - Go back\n" << endl;
    int confirmation;
    confirmation = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);
    
    if (confirmation == 1) {
        switch (choice) {
            case 1:
                cout << "Great! One 'Margarita' has been added to your order" << endl;
                margarita += 1;
                break;
            case 2:
                cout << "Great! One 'Meat Lovers' has been added to your order" << endl;
                meat_lovers += 1;
                break;
            case 3:
                cout << "Great! One 'Vegetarian' has been added to your order" << endl;
                vegetarian += 1;
                break;
            case 4:
                cout << "Great! One 'Egalitarian' has been added to your order" << endl;
                egalitarian += 1;
                break;
            case 5:
                cout << "Great! One 'Olivetti' has been added to your order" << endl;
                olivetti += 1;
                break;
            case 6:
                cout << "Great! One 'The Italian' has been added to your order" << endl;
                italian += 1;
                break;
            case 7:
                cout << "Great! One 'Dynamite' has been added to your order" << endl;
                dynamite += 1;
                break;
        }
        // calculate and display price of total order
        chekcout_price += base_price;
        cout << "Total order price : $" << chekcout_price << endl;
        
        // Check if another order is needed or take to checkout
        additional_menu();
    }
    // if not confirmed, return to set menu
    else {
        pizza_menu();
    }
}

void Pizza::checkout() {
    cout << "Your total order price : $" << chekcout_price << endl
         << "Please wait while we charge your card and take your details without your permission!\n" 
         << ". . . .\n"
         << ". . . .\n" << endl;

    // Choose pickup or delivery
    cout << "How would you like to take your pizza?\n"
         << "1 - Pick-up\n"
         << "2 - Delivery" << endl;
    int choice;
    choice = verifier("Error. Please enter a valid number (1-2)\n", 1, 2);
    
    if (choice == 1) {
        cout << "Fantastic! Cause that's actually our only option... that would have been awkward...\n\n";
    }
    else {
        cout << "We don't actually do deliveries so I'm going to pretend you said 'pick-up' and go from there!..\n\n";
    }
    // Final wrap up statement
    cout << "Great! Your account has been charged, your details taken, and your order is on it's way!\n"
         << "Thank you for choosing Robot Joe's! We hope to see you again soon!" << endl;
}
