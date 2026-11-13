//Завдання 2. Обчислення значення виразу у зворотній польській нотації
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string v) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    // Вхідні дані для варіанта 18 (Таблиця 2)
    vector<string> tokens = {"6", "4", "2", "+", "-", "9", "9", "+", "+"};
    
    stack<int> valStack;
    stack<TreeNode*> treeStack;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Обчислення значення
            int b = valStack.top(); valStack.pop();
            int a = valStack.top(); valStack.pop();
            
            if (token == "+") valStack.push(a + b);
            else if (token == "-") valStack.push(a - b);
            else if (token == "*") valStack.push(a * b);
            else if (token == "/") valStack.push(a / b);

            // Побудова вузла дерева
            TreeNode* rightNode = treeStack.top(); treeStack.pop();
            TreeNode* leftNode = treeStack.top(); treeStack.pop();
            TreeNode* opNode = new TreeNode(token);
            opNode->left = leftNode;
            opNode->right = rightNode;
            treeStack.push(opNode);
        } else {
            valStack.push(stoi(token));
            treeStack.push(new TreeNode(token));
        }
    }

    cout << "RPN Expression: 6 4 2 + - 9 9 + +" << endl;
    cout << "Calculated Result: " << valStack.top() << endl;
    cout << "Root of the expression tree: " << treeStack.top()->val << endl;

    return 0;
}
