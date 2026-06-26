# Inventory Management System (BST)

![Badge](https://img.shields.io/badge/Language-C++-blue?style=flat-square) ![Badge](https://img.shields.io/badge/DataStructure-BinarySearchTree-green?style=flat-square) ![Badge](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)

---

## 📋 Table of Contents

- [Overview](#overview)
- [Architecture](#architecture)
- [Data Structures](#data-structures)
- [Core Features](#core-features)
- [System Design](#system-design)
- [Operations & Complexity](#operations--complexity)
- [Compilation & Execution](#compilation--execution)
- [Usage Example](#usage-example)
- [Technical Specifications](#technical-specifications)

---

## 🎯 Overview

The **Inventory Management System** is a robust C++ application that leverages a **Binary Search Tree (BST)** data structure to efficiently manage product inventory. The system supports dynamic product insertion, deletion, searching, and sorted viewing of all inventory items.

### Key Highlights
- ✅ **Self-balancing Storage**: Products organized by ID using BST
- ✅ **Fast Operations**: O(log n) average complexity for search, insert, delete
- ✅ **Memory Safe**: Automatic cleanup with destructors
- ✅ **User-Friendly**: Interactive CLI interface with input validation

---

## 🏗️ Architecture

### System Component Diagram

```
┌─────────────────────────────────────────────────────────┐
│                  USER INTERFACE                         │
│              (Interactive Menu System)                  │
└────────────────────┬────────────────────────────────────┘
                     │
        ┌────────────┴────────────┐
        │                         │
        ▼                         ▼
┌──────────────────┐      ┌──────────────────┐
│  Main Menu Loop  │◄────►│  Input Validator │
└────────────┬─────┘      └──────────────────┘
             │
        ┌────┴────┬────────┬────────┬────────┐
        │          │        │        │        │
        ▼          ▼        ▼        ▼        ▼
      ADD       SEARCH   DELETE   DISPLAY   EXIT
        │          │        │        │        │
        └────────┬─────────┴────────┴──────┘
                 │
                 ▼
        ┌────────────────────────┐
        │  InventoryBST Class    │
        │  ─────────────────────  │
        │  Root: Product*        │
        └────────────┬───────────┘
                     │
                     ▼
        ┌────────────────────────┐
        │  Binary Search Tree    │
        │  (Product Nodes)       │
        └────────────────────────┘
```

### Data Flow Diagram

```
User Input
    │
    ▼
┌─────────────────┐
│ Menu Selection  │
└────────┬────────┘
         │
    ┌────┴──────┬──────────┬──────────┬──────────┐
    │            │          │          │          │
    ▼            ▼          ▼          ▼          ▼
  ADD        SEARCH     DELETE    DISPLAY      EXIT
    │            │          │          │          │
    └────────────┴──────────┴──────────┘          │
                 │                                 │
                 ▼                                 │
        ┌────────────────────┐                    │
        │  BST Operations    │                    │
        │  (Insert/Search    │                    │
        │   Delete/Traverse) │                    │
        └────────┬───────────┘                    │
                 │                                 │
                 ▼                                 ▼
          Display Results         ┌──────────────────┐
                                  │ Program Exit &   │
                                  │ Memory Cleanup   │
                                  └──────────────────┘
```

---

## 📊 Data Structures

### Product Node Structure

```
┌──────────────────────────────────────────────┐
│             Product Node                      │
├──────────────────────────────────────────────┤
│  int id              (Product Unique ID)      │
│  string name         (Product Name)           │
│  int quantity        (Stock Count)            │
│  double price        (Unit Price)             │
│  Product* left       (Left Child Pointer)     │
│  Product* right      (Right Child Pointer)    │
└──────────────────────────────────────────────┘
```

### Binary Search Tree Layout Example

```
Sample Inventory Tree Structure:

                    ┌─────────┐
                    │  105    │  (Laptop)
                    └────┬────┘
                         │
            ┌────────────┴────────────┐
            │                         │
        ┌───▼────┐              ┌────▼───┐
        │  102   │              │  108   │
        │ Mouse  │              │Keyboard│
        └────┘───┘              └────────┘
            │
            └─ (potential left/right children)
```

### Insertion Order Flow

```
INSERT: ID=105 ──────────────────┐
                                 │
                    ┌────────────▼────────────┐
                    │  Root = NULL?          │
                    │  YES ─► Create Root    │
                    └─────────────────────────┘
                                 │
INSERT: ID=102 ──────────────────┤
                    ┌────────────▼────────────┐
                    │  102 < 105?            │
                    │  YES ─► Go Left        │
                    └─────────────────────────┘
                                 │
INSERT: ID=108 ──────────────────┤
                    ┌────────────▼────────────┐
                    │  108 > 105?            │
                    │  YES ─► Go Right       │
                    └─────────────────────────┘
```

---

## 🎛️ Core Features

### 1️⃣ Add Product
- **Purpose**: Insert a new product into the inventory
- **Input**: Product ID, Name, Quantity, Price
- **Processing**: Recursive insertion maintaining BST property
- **Output**: Success/Duplicate confirmation

### 2️⃣ Search Product
- **Purpose**: Locate a product by its ID
- **Input**: Product ID
- **Processing**: BST search algorithm
- **Output**: Product details or "Not Found" message

### 3️⃣ Delete Product
- **Purpose**: Remove a product from inventory
- **Input**: Product ID
- **Processing**: BST deletion with node replacement
- **Output**: Success/Not Found confirmation

### 4️⃣ Display Inventory
- **Purpose**: View all products in sorted order (by ID)
- **Input**: None
- **Processing**: In-order traversal of BST
- **Output**: Formatted table with all products

### 5️⃣ Exit
- **Purpose**: Gracefully terminate program
- **Processing**: Automatic memory cleanup via destructor
- **Output**: Exit message

---

## 🔧 System Design

### Class Hierarchy

```
┌─────────────────────────────────────┐
│      InventoryBST (Main Class)      │
├─────────────────────────────────────┤
│  PRIVATE MEMBERS:                   │
│  ├─ Product* root                   │
│  └─ Helper Methods (Recursive):     │
│     ├─ insertRec()                  │
│     ├─ searchRec()                  │
│     ├─ deleteRec()                  │
│     ├─ minValueNode()               │
│     ├─ inorderRec()                 │
│     └─ destroyTree()                │
├─────────────────────────────────────┤
│  PUBLIC METHODS:                    │
│  ├─ insertProduct()                 │
│  ├─ searchProduct()                 │
│  ├─ deleteProduct()                 │
│  ├─ displayInventory()              │
│  └─ Constructors/Destructors        │
└─────────────────────────────────────┘
           ▲
           │ contains/manages
           │
┌─────────────────────────────────────┐
│      Product (Data Structure)        │
├─────────────────────────────────────┤
│  DATA MEMBERS:                      │
│  ├─ int id                          │
│  ├─ string name                     │
│  ├─ int quantity                    │
│  ├─ double price                    │
│  ├─ Product* left                   │
│  └─ Product* right                  │
├─────────────────────────────────────┤
│  CONSTRUCTOR:                       │
│  └─ Product(id, name, qty, price)   │
└─────────────────────────────────────┘
```

### Operation Flowcharts

#### Insert Operation
```
START: insertProduct(id, name, qty, price)
    │
    ▼
Call insertRec(root, id, ...)
    │
    ▼
Is node NULL? ───YES──► Create new Product
    │                        │
    NO                        ▼
    │                  Return to parent
    ▼
Is id < node->id? ───YES──► Recurse LEFT
    │
    NO
    ▼
Is id > node->id? ───YES──► Recurse RIGHT
    │
    NO
    ▼
Duplicate ID ─────► Print Error & Return
    │
    ▼
END: Print "Product added successfully"
```

#### Delete Operation
```
START: deleteProduct(id)
    │
    ▼
Search for node with id
    │
    ├─ NOT FOUND ──► Print Error & END
    │
    └─ FOUND
        │
        ▼
    Is Node a LEAF? ───YES──► Delete & Return NULL
        │
        NO
        ▼
    Has ONE Child? ───YES──► Replace with child
        │
        NO
        ▼
    Has TWO Children
        │
        ▼
    Find IN-ORDER SUCCESSOR
        │
        ▼
    Copy Successor Data to Node
        │
        ▼
    Delete Successor Node
        │
        ▼
    END: Print "Product deleted successfully"
```

---

## ⏱️ Operations & Complexity

### Time Complexity Analysis

| Operation | Best Case | Average Case | Worst Case | Notes |
|-----------|-----------|--------------|------------|-------|
| Insert | O(log n) | O(log n) | O(n) | Balanced vs Skewed tree |
| Search | O(log n) | O(log n) | O(n) | Binary search property |
| Delete | O(log n) | O(log n) | O(n) | May require restructuring |
| Display | O(n) | O(n) | O(n) | Full traversal required |

### Space Complexity Analysis

| Component | Complexity | Notes |
|-----------|-----------|-------|
| Tree Storage | O(n) | n nodes in tree |
| Recursion Stack | O(log n) | Average tree height |
| Worst Case Stack | O(n) | Skewed tree height |

---

## 💾 Memory Management

```
┌──────────────────────────────────────┐
│      Memory Allocation Pattern        │
├──────────────────────────────────────┤
│                                      │
│  insertProduct()                     │
│      │                               │
│      └─► new Product() ◄─────────┐   │
│              │                   │   │
│              ▼                   │   │
│          Heap Memory          3 nodes │
│          Allocated            Total  │
│                                      │
│  deleteProduct(id)                   │
│      │                               │
│      └─► delete node ◄────────────┐  │
│              │                    │  │
│              ▼                    │  │
│          Heap Memory        Freed │  │
│          Deallocated            │  │
│                                  │  │
│  Destructor ~InventoryBST()     │  │
│      │                          │  │
│      └─► destroyTree()          │  │
│          (Post-order traversal) │  │
│              │                  │  │
│              └────► Free ALL ────┘  │
│                                      │
└──────────────────────────────────────┘
```

---

## 🖥️ Compilation & Execution

### Prerequisites
- C++ Compiler (g++ recommended)
- C++17 or later standard support

### Compilation

```bash
# Standard compilation
g++ -std=c++17 -Wall -Wextra -pedantic InventorySystem.cpp -o InventorySystem

# With debug symbols
g++ -std=c++17 -g -Wall -Wextra -pedantic InventorySystem.cpp -o InventorySystem

# With optimization
g++ -std=c++17 -O2 -Wall -Wextra -pedantic InventorySystem.cpp -o InventorySystem
```

### Execution

```bash
# Run the compiled executable
./InventorySystem

# Or using the VS Code task (if configured)
Ctrl+Shift+B  # Build
Ctrl+Shift+C  # Run
```

---

## 📝 Usage Example

### Sample Interactive Session

```
=== INVENTORY MANAGEMENT SYSTEM (BST) ===
 1. Add New Product
 2. Search for Product
 3. Delete Product
 4. View All Inventory (Sorted by ID)
 5. Exit
Enter your choice: 1

Enter Product ID (Integer): 105
Enter Product Name: Laptop
Enter Quantity: 12
Enter Price: $999.99
 [+] Product added successfully.

Enter your choice: 4

=====================================================
ID        Name                Quantity    Price
-----------------------------------------------------
102       Wireless Mouse              50    $25.50
105       Laptop                      12    $999.99
108       Mechanical Keyboard         30    $85.00
=====================================================

Enter your choice: 2
Enter Product ID to search: 105

 --- Product Found ---
 ID: 105
 Name: Laptop
 Quantity: 12
 Price: $999.99

Enter your choice: 5
Exiting system. Cleaning up memory...
```

---

## 📋 Technical Specifications

### Input Validation

```
┌─────────────────────────────────┐
│    INPUT VALIDATION FLOW         │
├─────────────────────────────────┤
│                                 │
│  User Input ────► cin.fail()?   │
│                      │          │
│                 YES──┴──NO       │
│                      │          │
│                      ▼          │
│                Clear Buffer     │
│                Ignore Input     │
│                Print Error      │
│                Retry            │
│                      │          │
│                      └─────────►│
│                                 │
│  Valid Input ─────► Process    │
│                                 │
└─────────────────────────────────┘
```

### Error Handling

| Error | Message | Action |
|-------|---------|--------|
| Duplicate ID | `Product ID already exists` | Reject insertion |
| Not Found | `Product not found` | Return nullptr |
| Invalid Input | `Invalid input. Please enter a number` | Clear buffer & retry |
| Empty Inventory | `Inventory is currently empty` | Display info message |

---

## 🎓 Learning Outcomes

By studying this codebase, you'll understand:

1. **Binary Search Tree Implementation** - Self-balanced data structure
2. **Recursive Algorithms** - Insert, Search, Delete, Traverse operations
3. **Memory Management** - Dynamic allocation and deallocation in C++
4. **OOP Principles** - Encapsulation, Data abstraction, Method organization
5. **User Interface** - Interactive menu-driven application design
6. **Error Handling** - Input validation and edge case management
7. **Software Design** - Well-structured, maintainable code patterns

---

## 🚀 Future Enhancements

Potential improvements for the system:

- [ ] **Persistence**: Save/Load inventory from file (JSON/CSV)
- [ ] **Balancing**: Implement AVL Tree or Red-Black Tree for O(log n) guarantee
- [ ] **Advanced Search**: Filter by name, price range, or quantity
- [ ] **Reporting**: Generate inventory reports and statistics
- [ ] **GUI**: Graphical interface using Qt or wxWidgets
- [ ] **Database**: Integration with SQLite or PostgreSQL
- [ ] **Multi-threading**: Concurrent operations with thread safety
- [ ] **Analytics**: Track sales, trends, and stock movements

---

## 📄 File Structure

```
InventorySystem/
├── InventorySystem.cpp       (Main source file)
├── InventorySystem           (Compiled executable)
└── README.md                 (This documentation)
```

---

## 🔍 Code Quality Metrics

- **Lines of Code**: ~250
- **Functions**: 12 (6 private helpers + 6 public methods)
- **Cyclomatic Complexity**: Low-Medium (suitable for learning)
- **Documentation**: Fully commented sections
- **Standards Compliance**: C++17

---

## 📖 References

### BST Theory
- Average insertion/search/deletion: O(log n)
- Worst case: O(n) (skewed tree)
- In-order traversal produces sorted sequence

### C++ Concepts Used
- Pointers and dynamic memory
- Recursion
- Object-oriented programming
- Standard I/O with formatting

---

## 📞 Support

For issues, improvements, or questions:
- Review the inline code comments
- Check the flowcharts for operation logic
- Verify input format matches expectations
- Ensure compilation flags include `-std=c++17`

---

## 📜 License

This project is provided as-is for educational purposes.

---

**Last Updated**: 2026-06-27 | **Version**: 1.0
