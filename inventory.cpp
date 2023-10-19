#include <iostream>
#include <string>
using namespace std;

// Sub-struct 1
struct Supplier {
    string name = "";
    int numItemsAvailable = 0;
};

// Sub-struct 2
struct Category {
    string name = "";
    bool isBranNew;
};

// Main struct
struct Inventory {
    int id = 0;
    string itemName = "";
    char itemSize = 's';
    bool isAvailable;
    double price = 0.0;
    Supplier supplierDetails; // Sub-struct 1
    Category categoryDetails; // Sub-struct 2
    string itemDescription[5]; // Array within struct
};

// Function to read a member of an Inventory struct
void setItem(Inventory& item) {
    cout << "Enter item code: ";
    cin >> item.id;
    cout << "Enter item name: ";
    cin >> item.itemName;
    cout << "Enter item size (Small, Medium, Large): ";
    cin >> item.itemSize;
    cout << "Is the item available? (1 for yes, 0 for no): ";
    cin >> item.isAvailable;
    cout << "Enter item price: $";
    cin >> item.price;
    cout << "Enter supplier name: ";
    cin >> item.supplierDetails.name;
    cout << "Enter number of items available: ";
    cin >> item.supplierDetails.numItemsAvailable;
    cout << "Enter category name: ";
    cin >> item.categoryDetails.name;
    cout << "Enter 3 item descriptions (separated by ENTER): " << endl << endl;
    for (int i = 0; i < 5; i++) {
        cin >> item.itemDescription[i];
    }
}

// Function to print a member of an Inventory struct
void printItem(Inventory item) {
    cout << "Item Code: " << item.id << endl;
    cout << "Item Name: " << item.itemName << endl;
    cout << "Item Size: " << item.itemSize << endl;
    cout << "Item Available?: " << item.isAvailable << endl;
    cout << "Item Price: " << item.price << " $ "<<endl;
    cout << "Supplier Name: " << item.supplierDetails.name << endl;
    cout << "Number of Items Available: " << item.supplierDetails.numItemsAvailable << endl;
    cout << "Category Name: " << item.categoryDetails.name << endl;
    cout << "Item Descriptions: " << endl << endl;
    for (int i = 0; i < 5; i++) {
        cout << item.itemDescription[i] << " ";
    }
    cout << endl;
}

// Recursive function to find a member (in this case, an item with a particular item number)
bool findItem(Inventory items[], int n, int id) {
    // Base case: if n is 0, the entire array has been searched and the item was not found
    if (n == 0) {
        return false;
    }
    // Recursive case: check the current item in the array, then search the rest of the array
    if (items[n - 1].id == id) {
        return true; // item was found
    }
    return findItem(items, n - 1, id); // search the rest of the array
}

// Function to input all members of an array of Inventory structs
void inputAllMembers(Inventory items[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter details for item(code_number) #" << i + 1 << ":" << endl;
        setItem(items[i]);
    }
}

// Function to print all members of an array of Inventory structs
void printAllMembers(Inventory items[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Details for item(code_number) #" << i + 1 << ":" << endl;
        printItem(items[i]);
    }
}

int main() {
    const int NUMBER_ITEMS = 5;
    Inventory items[NUMBER_ITEMS];

    inputAllMembers(items, NUMBER_ITEMS);
    cout << endl << "--- Item details ---" << endl;
    printAllMembers(items, NUMBER_ITEMS);

    int id = 0;
    cout << endl << "Enter item number to search: ";
    cin >> id;
    if (findItem(items,  NUMBER_ITEMS, id)) {
        cout << "Item found!" << endl;
    }
    else {
        cout << "Item not found." << endl;
    }

    return 0;
}
