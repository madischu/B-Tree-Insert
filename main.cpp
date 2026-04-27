#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
    int degree;
    int totalValues;
    int value;

    cout << "Enter the minimum degree of the B-Tree: ";
    cin >> degree;

    while (degree < 2)
    {
        cout << "Minimum degree must be at least 2. Enter again: ";
        cin >> degree;
    }

    BTree tree(degree);

    cout << "Enter the number of values to insert: ";
    cin >> totalValues;

    for (int i = 1; i <= totalValues; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;

        tree.insert(value);
    }

    cout << "\nB-Tree traversal after insertion: ";
    tree.traverse();

    cout << endl;

    return 0;
}
