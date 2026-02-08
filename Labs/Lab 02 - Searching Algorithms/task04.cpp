/*Product Lookup for Imtiaz Super Market*/

#include<iostream>
#include<string>
using namespace std;

struct product{
    string name;
    string section;
    float price;
};

// function to search products by name
void searchByName(product products[], int size, string targetName){
    bool found = false;
    
    for(int i = 0; i < size; i++){
        if(products[i].name == targetName){
            cout << "\nProduct Found!\n"
            << "Name: " << products[i].name << endl
            << "Section: " << products[i].section << endl
            << "Price: Rs. " << products[i].price << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "\nProduct named (" << targetName << ") not found." << endl;
    }
}

// function to search products by price
void searchByPrice(product products[], int size, float targetPrice){
    bool found = false;
    
    for(int i = 0; i < size; i++){
        if(products[i].price == targetPrice){
            cout << "\nProduct Found!\n"
            << "Name: " << products[i].name << endl
            << "Section: " << products[i].section << endl
            << "Price: Rs. " << products[i].price << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "\nProduct with price (" << targetPrice << ") not found." << endl;
    }
}

int main(){
    product products[15] = {
        {"Tissue Roll", "HouseholdSection", 50.00},
        {"Soap", "PersonalCareToiletriesSection", 60.00},
        {"Toothpaste", "ToiletriesSection", 85.00},
        {"Bread", "BakerySection", 90.00},
        {"Sugar", "GrocerySection", 95.25},
        {"Milk", "DairySection", 120.50},
        {"Hand Sanitizer", "PersonalCareToiletriesSection", 150.00},
        {"Rice", "GrocerySection", 150.00},
        {"Eggs", "DairyPerishablesSection", 180.00},
        {"Tea", "GrocerySection", 200.00},
        {"Cooking Oil", "GroceryHouseholdSection", 230.00},
        {"Face Wash", "CosmeticsPersonalCare", 275.50},
        {"Cheese", "DairySection", 320.00},
        {"Shampoo", "PersonalCareToiletriesSection", 350.75},
        {"Washing Powder", "HouseholdCleaningSupplies", 400.00}
    };

    cout << "\n***Welcome to Imtiaz Super Market***" << endl << endl;

    int choice = 0;
    do{
        cout << "\n1. Search products by name." << endl;
        cout << "2. Search products by price." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        // search by name
        if(choice == 1){
            string targetName;
            cout << "\nEnter the name of product to find: ";
            getline(cin, targetName);
            searchByName(products, 15, targetName);
        }
        
        // search by price
        else if(choice == 2){
            float targetPrice = 0.0;
            cout << "\nEnter the price of product to find: ";
            cin >> targetPrice;
            searchByPrice(products, 15, targetPrice);
        }

        else if(choice == 3){
            cout << "\nThank you for shopping :)" << endl;
        }
        
        else{
            cout << "\nInvalid choice!" << endl;
        }

    }while(choice != 3);

}