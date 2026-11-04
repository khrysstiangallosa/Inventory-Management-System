#include <iostream>
#include <limits>
using namespace std;

//forward declaration of functions
void viewProducts();
void addProduct();
void updateProduct();
void deleteProduct();
void viewInventory();
void product1();
void product2();
int validateInput(); // handles bad inputs

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
    int choice;
    while(true){
    cout<< "1. Product 1" << endl;
    cout<< "2. Product 2" << endl;
    cout<< "3. Return to main menu" << endl;
    cout<< "Choice: ";
    choice = validateInput();

    if (choice == 1) product1();
    else if (choice == 2) product2();
    else if (choice == 3) break;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout<< "Invalid option. Please try again." << endl;
        choice = validateInput();
    }
}
}

void product1(){
    int choice;
    cout<< "Displaying details for Product 1..." << endl;
    cout<< "0. Return to Products menu" << endl;
    choice = validateInput();

        if (choice == 0) {
            return;
        }
        else {
            cout<< "Invalid option. Please try again." << endl;
        }
}

void product2(){
    int choice;
    cout<< "Displaying details for Product 2..." << endl;
    cout<< "0. Return to Products menu" << endl;
    choice = validateInput();

     if (choice == 0) {
            return;
        }
        else {
            cout<< "Invalid option. Please try again." << endl;
        }
}

struct Product {
    string name;
    int quantity;
    double price;
};

void addProduct(){
    Product newProduct;

    cout<< "What product would you like to add? (Press Enter to continue)"<< endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
    
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer

    cout<< "Product added successfully!" << endl;
    cout<< "Product Name: " << newProduct.name << endl;
    cout<< "Product Quantity: " << newProduct.quantity << endl;
    cout<< "Product Price: " << newProduct.price << endl;
}

void updateProduct(){
   // int choice;
    cout<< "Updating product..." << endl;
    // Code to update product goes here
}

void deleteProduct(){
    //int choice;
    cout<< "Deleting product..." << endl;
    // Code to delete product goes here
}

void viewInventory(){
    //int choice;
    cout<< "Viewing inventory..." << endl;
    // Code to view inventory goes here
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