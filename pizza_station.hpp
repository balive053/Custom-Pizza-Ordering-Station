// compiled with g++ --version 12.1.0
#include <vector>

/*
* A pizza station to automate the creation of customer pizzas through user input std::cin prompts
* and offer a set menu of pizzas as an alternative. Through various choices the pizzas are highly
* customizable and adjustable. 
* This is designed as an example pizzas station so has humour added to std::cout comments in places. 
* For a custom pizza:
* Users may select a custom base, sauce, toppings, and meat toppings. Upto 3 toppings and 1 meat 
* topping may be chosen as part of the base price. Addition are charged as per the selected rates.
* For a preset menu pizza: 
* A set menu is offered to choose from.
*/
class Pizza {
    // Variables to create a custom pizza
    int base = 0, sauce = 0, cheese = 0, tomato = 0, pepper = 0, olives = 0;
    // Custom meat choices
    int bacon = 0, pepperoni = 0, chicken = 0, salami = 0;
    // Counters
    int topping_counter = 0;
    int meat_counter = 0;
    int pizza_counter = 0;
    // Clickers to store amount of each topping added when activated
    int tomato_clicker;
    int pepper_clicker;
    int olives_clicker;
    // Pricing
    double temp_price = 0;
    double finished_pizza_price = 0;
    double chekcout_price = 0;
    // Pricing to account for free options before surcharge
    double topping_set_price = 0;
    double meat_set_price = 0;
    // Topping prices
    double const base_price = 5.29;
    double const topping_unit_price = 0.45;
    double const meat_topping_unit_price = 0.70;
    // Standard pizza counts
    int margarita = 0, meat_lovers = 0, vegetarian = 0, egalitarian = 0, olivetti = 0, italian = 0, dynamite = 0;

public:
    /// menu functions

    /*
    * Call to open main menu of the app
    * 
    * @param Void
    * @return Void - calls either pizza_maker() or pizza_menu() dependant on std::cin choice
    */
    void main_menu();
    
    /*
    * Opens order menu for preset pizzas, displays menu options, and prompts user for std::cin choice.
    * 
    * @param Void
    * @return Void - Adjusts price of order and calls makes call to additional_menu() or recursive 
    * call to itself based on std:cin user choice.
    */
    void pizza_menu();
    
    /*
    * Prompts user if they would like to make an additional pizza purchase.
    * 
    * @param Void
    * @return Void - Takes user to either main_menu() or checkout() based on choice.
    */
    void additional_menu();
    
    /*
    * Displays final order price and promts user if they would like to pick-up or have a delivery, 
    * then charges users card without their permission - Come on, it's just an app built for fun, 
    * how else would we end this??
    * 
    * @param Void
    * @return Void - Has no further function calls and is designed as potentially later adjustable 
    * end to program.
    */
    void checkout();
    
    
    /// base pizza options functions

    /*
    * Input prompts for making a custom pizza. 
    * Will request std::cin choice of base, sauce, and toppings and call relavant functions to manage.
    * 
    * @param Void
    * @return Void - calls base_selector(), sauce_selector(), and toppings_selector() to set 
    * variable values for base, sauce, cheese, tomato, pepper, and olives.
    */
    void pizza_maker();
    
    /*
    * Opens a menu prompt to select relevant base for pizza
    * 
    * @param Void
    * @return Void - sets cumstom pizza base type
    */
    int base_selector();
    
    /*
    * Opens a menu prompt to select relevant sauce for pizza
    * 
    * @param Void
    * @return Void - sets cumstom pizza sauce type
    */
    int sauce_selector();  
    
    
    /// toppings call functions

    /*
    * Input prompts for choosing desired custom pizza toppings. 
    * Will request std::cin to select relevant toppings for custom pizza and call relavant functions 
    * to manage for cheese, toppings, and meat toppings.
    * 
    * @param Void
    * @return Void - calls topping_cheese(), topper_adder(), toppings_meat() and recursive calls to 
    * itself to set variable values for cheese, toppings, and meat toppings selection.
    */
    int toppings_selector();
    
    /*
    * Input prompts for choosing desired custom pizza extra cheese topping from three choices. 
    *
    * @param Void
    * @return Void - adjusts variable and returns to toppings_selector() after choice has been made.
    */
    void topping_cheese();
    
    /*
    * Requests input as a toppings manager to set desired toppings (olives, tomato, pepper, cheese) 
    * and quantities of each requested.
    * 
    * @param Void
    * @return Void - adjusts topping variable count and recursive calls itself with an exit option. 
    */
    int topper_adder();
    
    /*
    * Requests input as a meat topping manager to set desired meat topping (bacon, salami, pepperoni, 
    * chicken) and quantities of each requested.
    * 
    * @param Void
    * @returns int - std::cin to adjusts meat topping variable count and calls toppings_selector() with 
    * an exit option. 
    */
    void toppings_meat();
    
    /*
    * Option menu to appear after meat topping is selected to manage quantity of meat - request if 
    * extra meat toppings are desired.
    * 
    * @param Void
    * @return Void - adjusts meat topping variable count and recursive calls itself or takes user to 
    * finalizer() depending on std::cin choices. 
    */
    void extra_meat();
    
    
    /// input verification
    
    /*
    * To verify std::cin input is both an integer and with value in expected range: max > x > min
    * 
    * Will prompt user with a provided error message if the input is not within the expected range or 
    * not an int and continue to prompt while condition is not met.
    * 
    * @param std::string message - error message to be displayed if std::cin value is invalid, 
    * @param int min - minimum allowable int value within range
    * @param int max - maximum allowable int value within range
    * 
    * @returns int - returns cin::std int if it is int and within expected range
    */
    
    int verifier(std::string message, int min, int max);
    
    /*
    * Finalizes the users custom pizza and dislays chosen options to get confirmation the pizza 
    * is as expected. Also calculates the price of the custom pizza based on topping selection.
    * 
    * @param int tomato - std::cin user choice of tomato
    * @param int pepper - std::cin user choice of pepper
    * @param int olives - std::cin user choice of olives
    * 
    * @return Void - Prompts user is choices are correct, provides option to adjust, go back to 
    * additional_menu(), toppings_selector() or otherwise pass if order is correct and complete. 
    */
    void finalizer(int tomato, int pepper, int olives);
    };


