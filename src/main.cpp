#include <iostream>
using namespace std;
int main(){
// Menu Display
int choice;
int back = 1;
cout<< "=================================" << endl;
cout<< "   Inventory Management System" << endl;
cout<< "=================================" << endl<< endl;
cout<< "1. View products" << endl;
cout<< "2. Add product" << endl;
cout<< "3. Update product" << endl;
cout<< "4. Delete product" << endl;
cout<< "5. View inventory" << endl;
cout<< "6. Exit" << endl<< endl;
cout<< "Select an option: "; cin>> choice;
if(choice == 1){
    cout<< "Product List: " << endl << endl;
    // Code to display products goes here
    cout<< "Press 0 to return to the main menu: "<<endl; cin>> back;
}
else if(choice == 2){
    cout<< "Add Product: " << endl;
    // Code to add product goes here
    cout<< "Press 0 to return to the main menu: "<<endl; cin>> back;
}
else if(choice == 3){
    cout<< "Update Product: " << endl;
    // Code to update product goes here
    cout<< "Press 0 to return to the main menu: "<<endl; cin>> back;
}
else if(choice == 4){
    cout<< "Delete Product: " << endl;
    // Code to delete product goes here
    cout<< "Press 0 to return to the main menu: "<<endl; cin>> back;
}
else if(choice == 5){
    cout<< "View Inventory: " << endl;
    // Code to view inventory goes here
    cout<< "Press 0 to return to the main menu: "<<endl; cin>> back;
}
else if(choice == 6){
    cout<< "Exiting..." << endl;
    // Code to exit goes here
}
else{
    cout<< "Invalid option. Please try again." << endl;
}
if (back == 0){
    main(); // Call main function again to return to the menu
}
    return 0;
}