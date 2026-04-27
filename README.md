# B-Tree-Insert

## Program Description
This C++ program implements a **B-Tree insert function**. A B-Tree is a self-balancing search tree that keeps data sorted and allows insertion, searching, and traversal. 

This program allows the user to enter integer values. Each value is inserted into a B-Tree. If a node becomes full, the program splits the node and continues inserting while maintinaing B-Tree rules.

The program outputs the B-Tree values using an in-order traversal. 

## Inputs
The user enters:
- the minimum degree of the B-Tree
- the number of values to insert
- the integer values to insert

## Outputs
The program displays:
- the values inserted into the B-Tree
- the B-Tree traversal after insertion

## Compile and Run Instructions
**Using g++**

*g++ main.cpp BTree.cpp -o btree*

*./btree*

## Design Documentation
**Detailed Psuedocode**
```
Start

Ask user for minimum degree t
Create an empty B-Tree with degree t

Ask user how many values will be inserted

For each value
    Ask user to enter an integer
    Insert integer into B-Tree

Insert function:
    If root is null
        Create root node
        Insert key into root
    Else if root is full
        Create new root
        Make old root child of new root
        Split old root
        Insert key into correct child
    Else
        Insert key into non-full root

Insert non-full function:
    If node is a leaf
        Insert key into correct sorted position
    Else
        Find correct child
        If child is full
            Split child
            Choose correct child after split
        Recursively insert key into child

Split child function:
    Create new node
    Move half of full child’s keys into new node
    Move middle key up into parent
    If child is not a leaf
        Move half of child’s children into new node

Print B-Tree traversal

End
```

## UML Class Diagram
<img width="394" height="268" alt="image" src="https://github.com/user-attachments/assets/13f5e464-c809-44ae-97cc-d62719b82a27" />
<img width="393" height="188" alt="image" src="https://github.com/user-attachments/assets/8db1e9c5-4158-40cb-a608-246aeb4beb12" />

## Use Case Diagram
<img width="583" height="679" alt="image" src="https://github.com/user-attachments/assets/d343ff9a-8977-47f2-8432-a7675ae4b5b0" />

## Program Execution Evidence
<img width="445" height="180" alt="image" src="https://github.com/user-attachments/assets/79b064d6-79d0-4a3a-bb29-6c91c564ec35" />
<img width="525" height="247" alt="image" src="https://github.com/user-attachments/assets/136ab2e6-8301-4fbf-99c4-0244b280e75e" />
<img width="602" height="289" alt="image" src="https://github.com/user-attachments/assets/4154ee61-4202-4255-873d-635131586fc7" />
