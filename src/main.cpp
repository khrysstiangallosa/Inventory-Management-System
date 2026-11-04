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
int ValidateInput(); // handles bad inputs

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

choice = ValidateInput();

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
    choice = ValidateInput();

    if (choice == 1) product1();
    else if (choice == 2) product2();
    else if (choice == 3) break;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout<< "Invalid option. Please try again." << endl;
        choice = ValidateInput();
    }
}
}

void product1(){
    int choice;
    cout<< "Displaying details for Product 1..." << endl;
    cout<< "0. Return to Products menu" << endl;
    choice = ValidateInput();

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
    choice = ValidateInput();

     if (choice == 0) {
            return;
        }
        else {
            cout<< "Invalid option. Please try again." << endl;
        }
}

void addProduct(){
   // int choice;
    cout<< "Adding product..." << endl;
    // Code to add product goes here
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
int ValidateInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            return input;
        }
    }
}