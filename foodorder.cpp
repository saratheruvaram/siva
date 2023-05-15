Sure, here's a basic implementation of a food ordering app in C++:

```
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a food item
struct FoodItem {
    string name;
    double price;
};

// Define a struct to represent an order
struct Order {
    vector<FoodItem> items;
    double total;
};

// Define a function to display the menu
void displayMenu() {
    cout << "Welcome to our food ordering app!" << endl;
    cout << "Here's our menu:" << endl;
    cout << "1. Burger - $5.99" << endl;
    cout << "2. Pizza - $8.99" << endl;
    cout << "3. Salad - $4.99" << endl;
    cout << "4. Fries - $2.99" << endl;
    cout << "5. Drink - $1.99" << endl;
}

// Define a function to get the user's choice
int getUserChoice() {
    int choice;
    cout << "Please enter your choice (1-5): ";
    cin >> choice;
    return choice;
}

// Define a function to add an item to the order
void addItemToOrder(Order& order, FoodItem item) {
    order.items.push_back(item);
    order.total += item.price;
}

// Define a function to display the order
void displayOrder(Order order) {
    cout << "Your order:" << endl;
    for (int i = 0; i < order.items.size(); i++) {
        cout << order.items[i].name << " - $" << order.items[i].price << endl;
    }
    cout << "Total: $" << order.total << endl;
}

int main() {
    // Initialize the menu
    vector<FoodItem> menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.99},
        {"Fries", 2.99},
        {"Drink", 1.99}
    };

    // Initialize the order
    Order order = {
        vector<FoodItem>(),
        0.0
    };

    // Display the menu
    displayMenu();

    // Get the user's choice and add the item to the order
    int choice = getUserChoice();
    while (choice >= 1 && choice <= 5) {
        addItemToOrder(order, menu[choice - 1]);
        choice = getUserChoice();
    }

    // Display the order
    displayOrder(order);

    return 0;
}
```

This code defines two structs: `FoodItem` to represent a food item with a name and price, and `Order` to represent an order with a vector of `FoodItem`s and a total price. It also defines several functions to display the menu, get the user's choice, add an item to the order, and display the order.

In `main()`, the code initializes the menu and order, displays the menu, gets the user's choice, and adds the selected item to the order until the user enters an invalid choice. Finally, it displays the order.
