#include <iostream>
#include <limits>
#include <vector> // for storing products and testing vectors for learning purposes
#include <string>
using namespace std;

//forward declaration of functions
void viewProducts();
void addProduct();
void updateProduct();
void deleteProduct();
void viewInventory();
int validateInput(); // handles bad inputs

struct Product {
    string name;
    int quantity;
    double price;
};

vector<Product>& getInventory();

int main(){
// Menu Display
int choice;
bool mainMenu = true;
while (mainMenu){
cout<< "=================================" << endl;
cout<< "   Inventory Management System" << endl;
cout<< "=================================" << endl<< endl;
cout<< "1. View products" << endl;
cout<< "2. Add product" << endl;
cout<< "3. Update product" << endl;
cout<< "4. Delete product" << endl;
cout<< "5. View inventory" << endl;
cout<< "6. Exit" << endl<< endl;
cout<< "Select an option: "; 

choice = validateInput();

if (choice ==1) viewProducts();
else if (choice ==2) addProduct();
else if (choice ==3) updateProduct();
else if (choice ==4) deleteProduct();
else if (choice ==5) viewInventory();
else if (choice ==6) {
    cout<< "Exiting the program..." << endl;
    mainMenu = false;
}
else cout<< "Invalid option. Please try again." << endl;
}

    return 0;
}

void viewProducts(){
    if (getInventory().empty()) {
        cout << "No products available." << endl;
        cout << "Press 0 to return to the main menu." << endl;
        validateInput(); // Wait for user input to return to the main menu
    }
    else {
        cout << "Available products:" << endl;
        for (size_t i = 0; i < getInventory().size(); ++i) {
            cout << i + 1 << ". " << getInventory()[i].name << endl;
        }   
        cout << "Select a product to view details (or 0 to return): ";
        int choice = validateInput();
        if (choice >= 1 && choice <= static_cast<int>(getInventory().size())) {
            // Display details for the selected product
            cout << "Product Name: " << getInventory()[choice - 1].name << endl;
            cout << "Product Quantity: " << getInventory()[choice - 1].quantity << endl;
            cout << "Product Price: " << getInventory()[choice - 1].price << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        } else if (choice == 0) {
            return;
        } else {
            cout << "Invalid option. Please try again." << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        }
    }
}

vector<Product>& getInventory() {
    static vector<Product> inventory; // static to persist across function calls
    return inventory;
}


void addProduct(){
    Product newProduct;

    cout<< "What product would you like to add? (Press Enter to continue)"<< endl;
    
    cout<< "Enter product name: " << endl;
    getline(cin, newProduct.name);

    cout<< "Enter product quantity: ";
    while (true) {
        cin >> newProduct.quantity;
        if (cin.fail() || newProduct.quantity < 0) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a non-negative number for quantity: ";
        } 
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            break;
        }
    }

    cout<< "Enter product price: ";
    while (true) {
        cin >> newProduct.price;
        if (cin.fail() || newProduct.price < 0) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a non-negative number for price: ";
        } 
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            break;
        }
    }


    getInventory().push_back(newProduct);
    cout<< "Product added successfully!" << endl;
    cout<< "Product Name: " << newProduct.name << endl;
    cout<< "Product Quantity: " << newProduct.quantity << endl;
    cout<< "Product Price: " << newProduct.price << endl;
    cout << "Press 0 to return to the main menu." << endl;
    validateInput();
}

void updateProduct(){
  if (getInventory().empty()) {
        cout << "No products available." << endl;
        cout << "Press 0 to return to the main menu." << endl;
        validateInput(); // Wait for user input to return to the main menu
    }
    else {
        cout << "Available products:" << endl;
        for (size_t i = 0; i < getInventory().size(); ++i) {
            cout << i + 1 << ". " << getInventory()[i].name << endl;
        }
        int choice = validateInput();
        if (choice >= 1 && choice <= static_cast<int>(getInventory().size())) {
            Product& productToUpdate = getInventory()[choice - 1];
            cout << "Updating product: " << productToUpdate.name << endl;

            cout << "Enter new product name (or press Enter to keep current): ";
            string newName;
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, newName);
            if (!newName.empty()) {
                productToUpdate.name = newName;
            }

            cout << "Enter new product quantity (or -1 to keep current): ";
            int newQuantity;
            cin >> newQuantity;
            if (newQuantity >= 0) {
                productToUpdate.quantity = newQuantity;
            }

            cout << "Enter new product price (or -1 to keep current): ";
            double newPrice;
            cin >> newPrice;
            if (newPrice >= 0) {
                productToUpdate.price = newPrice;
            }

            cout << "Product updated successfully!" << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        } else {
            cout << "Invalid option. Please try again." << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        }   
    }
}

void deleteProduct(){
     if (getInventory().empty()) {
        cout << "No products available." << endl;
        cout << "Press 0 to return to the main menu." << endl;
        validateInput(); // Wait for user input to return to the main menu
    }
    else {
        cout << "Available products:" << endl;
        for (size_t i = 0; i < getInventory().size(); ++i) {
            cout << i + 1 << ". " << getInventory()[i].name << endl;
        }
        int choice = validateInput();
        if (choice >= 1 && choice <= static_cast<int>(getInventory().size())) {
            getInventory().erase(getInventory().begin() + choice - 1);
            cout << "Product deleted successfully!" << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        } else {
            cout << "Invalid option. Please try again." << endl;
            cout << "Press 0 to return to the main menu." << endl;
            validateInput(); // Wait for user input to return to the main menu
        }
    }
}

void viewInventory(){
   for (const Product& product : getInventory()) {
        cout << "Product Name: " << product.name << endl;
        cout << "Product Quantity: " << product.quantity << endl;
        cout << "Product Price: " << product.price << endl;
        cout << "-------------------------" << endl;
        cout << "Press 0 to return to the main menu." << endl;
        validateInput(); // Wait for user input to return to the main menu
    }
}

//reusable function to validate user input
int validateInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number: ";
        } 
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            return input;
        }
    }
}