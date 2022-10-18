#include <vector>

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
    // menus
    void main_menu();
    void pizza_menu();
    void additional_menu();
    void checkout();
    // base pizza options
    void pizza_maker();
    int base_selector();
    int sauce_selector();  
    // toppings 
    int toppings_selector();
    void topping_cheese();
    int topper_adder();
    void toppings_meat();
    void extra_meat();
    // input verification
    int verifier(std::string message, int min, int max);
    void finalizer(int tomato, int pepper, int olives);
    };


