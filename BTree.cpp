#include <iostream>
#include "BTree.h"
using namespace std;

// Constructor for BTreeNode
BTreeNode::BTreeNode(int degree, bool isLeaf)
{
    minimumDegree = degree;
    leaf = isLeaf;

    keys = new int[2 * minimumDegree - 1];
    children = new BTreeNode*[2 * minimumDegree];

    keyCount = 0;
}

// Traverses and prints the B-Tree in sorted order
void BTreeNode::traverse()
{
    int i;

    for (i = 0; i < keyCount; i++)
    {
        if (!leaf)
        {
            children[i]->traverse();
        }

        cout << keys[i] << " ";
    }

    if (!leaf)
    {
        children[i]->traverse();
    }
}

// Inserts a key into a node that is not full
void BTreeNode::insertNonFull(int key)
{
    int i = keyCount - 1;

    if (leaf)
    {
        // Move larger keys one position forward
        while (i >= 0 && keys[i] > key)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = key;
        keyCount++;
    }
    else
    {
        // Find the child that should receive the key
        while (i >= 0 && keys[i] > key)
        {
            i--;
        }

        i++;

        // If the child is full, split it
        if (children[i]->keyCount == 2 * minimumDegree - 1)
        {
            splitChild(i, children[i]);

            if (keys[i] < key)
            {
                i++;
            }
        }

        children[i]->insertNonFull(key);
    }
}

// Splits a full child node
void BTreeNode::splitChild(int index, BTreeNode* child)
{
    BTreeNode* newNode = new BTreeNode(child->minimumDegree, child->leaf);

    newNode->keyCount = minimumDegree - 1;

    // Copy the last keys from child into new node
    for (int j = 0; j < minimumDegree - 1; j++)
    {
        newNode->keys[j] = child->keys[j + minimumDegree];
    }

    // Copy child pointers if child is not a leaf
    if (!child->leaf)
    {
        for (int j = 0; j < minimumDegree; j++)
        {
            newNode->children[j] = child->children[j + minimumDegree];
        }
    }

    child->keyCount = minimumDegree - 1;

    // Shift children of current node to make room
    for (int j = keyCount; j >= index + 1; j--)
    {
        children[j + 1] = children[j];
    }

    children[index + 1] = newNode;

    // Shift keys of current node to make room
    for (int j = keyCount - 1; j >= index; j--)
    {
        keys[j + 1] = keys[j];
    }

    keys[index] = child->keys[minimumDegree - 1];
    keyCount++;
}

// Constructor for BTree
BTree::BTree(int degree)
{
    root = nullptr;
    minimumDegree = degree;
}

// Traverses the whole B-Tree
void BTree::traverse()
{
    if (root != nullptr)
    {
        root->traverse();
    }
    else
    {
        cout << "The B-Tree is empty.";
    }
}

// Inserts a key into the B-Tree
void BTree::insert(int key)
{
    if (root == nullptr)
    {
        root = new BTreeNode(minimumDegree, true);
        root->keys[0] = key;
        root->keyCount = 1;
    }
    else
    {
        if (root->keyCount == 2 * minimumDegree - 1)
        {
            BTreeNode* newRoot = new BTreeNode(minimumDegree, false);

            newRoot->children[0] = root;
            newRoot->splitChild(0, root);

            int i = 0;

            if (newRoot->keys[0] < key)
            {
                i++;
            }

            newRoot->children[i]->insertNonFull(key);

            root = newRoot;
        }
        else
        {
            root->insertNonFull(key);
        }
    }
}
