#ifndef BTREE_H
#define BTREE_H

class BTreeNode
{
private:
    int* keys;
    int minimumDegree;
    BTreeNode** children;
    int keyCount;
    bool leaf;

public:
    BTreeNode(int degree, bool isLeaf);

    void traverse();
    void insertNonFull(int key);
    void splitChild(int index, BTreeNode* child);

    friend class BTree;
};

class BTree
{
private:
    BTreeNode* root;
    int minimumDegree;

public:
    BTree(int degree);

    void traverse();
    void insert(int key);
};

#endif
