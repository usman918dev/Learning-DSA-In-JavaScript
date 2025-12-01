#include <iostream>
using namespace std;

class Leaf
{
public:
    Leaf(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    void setLeft(Leaf *left)
    {
        this->left = left;
    }

    void setRight(Leaf *right)
    {
        this->right = right;
    }

    Leaf *getLeft()
    {
        return left;
    }

    Leaf *getRight()
    {
        return right;
    }

    int getData()
    {
        return data;
    }

private:
    int data;
    Leaf *left;
    Leaf *right;
};

class Tree
{
public:
    Tree()
    {
        root = NULL;
    }

    // Set root
    void setRoot(int data)
    {
        root = new Leaf(data);
    }

    // Add left child of root
    void addLeft(int data)
    {
        if (root == NULL)
        {
            cout << "Root not found!\n";
            return;
        }

        Leaf *newLeaf = new Leaf(data);
        root->setLeft(newLeaf);
    }

    // Add right child of root
    void addRight(int data)
    {
        if (root == NULL)
        {
            cout << "Root not found!\n";
            return;
        }

        Leaf *newLeaf = new Leaf(data);
        root->setRight(newLeaf);
    }

    // Display tree (basic)
    void display()
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        cout << "Root: " << root->getData() << endl;

        if (root->getLeft() != NULL)
            cout << "Left Child: " << root->getLeft()->getData() << endl;

        if (root->getRight() != NULL)
            cout << "Right Child: " << root->getRight()->getData() << endl;
    }

private:
    Leaf *root;
};

int main()
{
    Tree tree;

    tree.setRoot(10);   // root
    tree.addLeft(5);    // left child
    tree.addRight(15);  // right child

    tree.display();

    
    return 0;
}
  