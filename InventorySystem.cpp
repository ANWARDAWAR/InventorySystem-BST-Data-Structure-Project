    #include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// 1. Data Structure: Node Definition
// ==========================================
struct Product {
    int id;
    string name;
    int quantity;
    double price;
    Product* left;
    Product* right;

    Product(int pid, string pname, int pqty, double pprice) {
        id = pid;
        name = pname;
        quantity = pqty;
        price = pprice;
        left = nullptr;
        right = nullptr;
    }
};

// ==========================================
// 2. Class Definition: Binary Search Tree
// ==========================================
class InventoryBST {
private:
    Product* root;

    // Helper functions for recursion
    Product* insertRec(Product* node, int id, string name, int quantity, double price) {
        if (node == nullptr) {
            return new Product(id, name, quantity, price);
        }
        if (id < node->id) {
            node->left = insertRec(node->left, id, name, quantity, price);
        } else if (id > node->id) {
            node->right = insertRec(node->right, id, name, quantity, price);
        } else {
            cout << " [!] Product ID " << id << " already exists." << endl;
        }
        return node;
    }

    Product* searchRec(Product* node, int id) {
        if (node == nullptr || node->id == id) {
            return node;
        }
        if (node->id < id) {
            return searchRec(node->right, id);
        }
        return searchRec(node->left, id);
    }

    Product* minValueNode(Product* node) {
        Product* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Product* deleteRec(Product* node, int id) {
        if (node == nullptr) return node;

        if (id < node->id) {
            node->left = deleteRec(node->left, id);
        } else if (id > node->id) {
            node->right = deleteRec(node->right, id);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Product* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Product* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get inorder successor
            Product* temp = minValueNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->quantity = temp->quantity;
            node->price = temp->price;
            node->right = deleteRec(node->right, temp->id);
        }
        return node;
    }

    void inorderRec(Product* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << left << setw(10) << node->id 
                 << setw(20) << node->name 
                 << setw(15) << node->quantity 
                 << "$" << fixed << setprecision(2) << node->price << endl;
            inorderRec(node->right);
        }
    }

    void destroyTree(Product* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    InventoryBST() {
        root = nullptr;
    }

    ~InventoryBST() {
        destroyTree(root);
    }

    // Public Wrapper Methods
    void insertProduct(int id, string name, int quantity, double price) {
        root = insertRec(root, id, name, quantity, price);
        cout << " [+] Product added successfully." << endl;
    }

    void searchProduct(int id) {
        Product* result = searchRec(root, id);
        if (result != nullptr) {
            cout << "\n --- Product Found --- " << endl;
            cout << " ID: " << result->id << "\n Name: " << result->name 
                 << "\n Quantity: " << result->quantity << "\n Price: $" << result->price << endl;
        } else {
            cout << " [!] Product with ID " << id << " not found." << endl;
        }
    }

    void deleteProduct(int id) {
        Product* target = searchRec(root, id);
        if (target != nullptr) {
            root = deleteRec(root, id);
            cout << " [-] Product deleted successfully." << endl;
        } else {
             cout << " [!] Cannot delete: Product ID " << id << " not found." << endl;
        }
    }

    void displayInventory() {
        if (root == nullptr) {
            cout << " [i] Inventory is currently empty." << endl;
            return;
        }
        cout << "\n=====================================================" << endl;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Quantity" << "Price" << endl;
        cout << "-----------------------------------------------------" << endl;
        inorderRec(root);
        cout << "=====================================================\n" << endl;
    }
};

// ==========================================
// 3. Main Interface
// ==========================================
void displayMenu() {
    cout << "\n=== INVENTORY MANAGEMENT SYSTEM (BST) ===" << endl;
    cout << " 1. Add New Product" << endl;
    cout << " 2. Search for Product" << endl;
    cout << " 3. Delete Product" << endl;
    cout << " 4. View All Inventory (Sorted by ID)" << endl;
    cout << " 5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    InventoryBST inventory;
    int choice;

    // Populating with some dummy data for demonstration
    inventory.insertProduct(105, "Laptop", 12, 999.99);
    inventory.insertProduct(102, "Wireless Mouse", 50, 25.50);
    inventory.insertProduct(108, "Mechanical Keyboard", 30, 85.00);

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << " [!] Invalid input. Please enter a number." << endl;
            continue;
        }

        int id, qty;
        string name;
        double price;

        switch (choice) {
            case 1:
                cout << "Enter Product ID (Integer): ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: $";
                cin >> price;
                inventory.insertProduct(id, name, qty, price);
                break;
            case 2:
                cout << "Enter Product ID to search: ";
                cin >> id;
                inventory.searchProduct(id);
                break;
            case 3:
                cout << "Enter Product ID to delete: ";
                cin >> id;
                inventory.deleteProduct(id);
                break;
            case 4:
                inventory.displayInventory();
                break;
            case 5:
                cout << "Exiting system. Cleaning up memory..." << endl;
                break;
            default:
                cout << " [!] Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}