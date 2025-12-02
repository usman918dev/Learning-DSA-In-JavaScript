#include <iostream>
using namespace std;

class Leaf {
public:
    Leaf(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    int getData() { return data; }
    Leaf* getLeft() { return left; }
    Leaf* getRight() { return right; }

    void setLeft(Leaf* node) { left = node; }
    void setRight(Leaf* node) { right = node; }

private:
    int data;
    Leaf* left;
    Leaf* right;
};

class Tree {
public:
    Tree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    void display() {
        if (!root) {
            cout << "Tree is empty\n";
            return;
        }
        cout << "BST in-order traversal: ";
        inOrder(root);
        cout << endl;
    }

private:
    Leaf* root;

    // Recursive insert
    Leaf* insertRec(Leaf* node, int data) {
        if (!node) {
            return new Leaf(data);
        }

        if (data < node->getData()) {
            node->setLeft(insertRec(node->getLeft(), data));
        } else if (data > node->getData()) {
            node->setRight(insertRec(node->getRight(), data));
        }
        // if equal, do nothing (no duplicates)
        return node;
    }

    void inOrder(Leaf* node) {
        if (!node) return;
        inOrder(node->getLeft());
        cout << node->getData() << " ";
        inOrder(node->getRight());
    }
};

int main() {
    Tree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.display(); // Output: 3 5 7 10 12 15 18

    return 0;
}
