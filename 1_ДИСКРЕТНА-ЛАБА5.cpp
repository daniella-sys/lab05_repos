//Завдання 1. Побудова дерева виразу та виведення префіксної і постфіксної форм
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* left;
    Node* right;

    Node(string v) : val(v), left(nullptr), right(nullptr) {}
};

// Інфіксний обхід (ЛКП)
void printInfix(Node* root) {
    if (!root) return;
    if (root->left || root->right) cout << "(";
    printInfix(root->left);
    cout << root->val;
    printInfix(root->right);
    if (root->left || root->right) cout << ")";
}

// Префіксний обхід (КЛП)
void printPrefix(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Постфіксний обхід (ЛПК)
void printPostfix(Node* root) {
    if (!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->val << " ";
}

int main() {
    // Побудова дерева для виразу: (n - 3) - (m - n / 5)
    Node* root = new Node("-");

    // Ліве піддерево: (n - 3)
    root->left = new Node("-");
    root->left->left = new Node("n");
    root->left->right = new Node("3");

    // Праве піддерево: (m - n / 5)
    root->right = new Node("-");
    root->right->left = new Node("m");
    root->right->right = new Node("/");
    root->right->right->left = new Node("n");
    root->right->right->right = new Node("5");

    cout << "Infix:   ";
    printInfix(root);
    cout << "\nPrefix:  ";
    printPrefix(root);
    cout << "\nPostfix: ";
    printPostfix(root);
    cout << endl;

    return 0;
}
