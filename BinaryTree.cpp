#include <iostream>
#include <vector>
#include <math.h>
const int MIN = -pow(2, 31);
const int MAX = pow(2, 31) - 1;
std::vector<int> elements(0);

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

bool check_tree_in_range(const struct Node* root, int lo, int hi)
{
    if (root == NULL)
        return true;

    if (root->data < lo || root->data > hi)
        return false;

    return
        check_tree_in_range(root->left, lo, root->data) &&
        check_tree_in_range(root->right, root->data, hi);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<Node*> nodes(0);
    for (int i = 0; i < n; ++i) {
        Node *node = new Node(0);
        nodes.push_back(node);
    }

    for (int i = 0; i < n; ++i) {
        int k, l, r;
        std::cin >> k >> l >> r;
        nodes[i]->data = k;
        if (l == -1) {
            nodes[i]->left = NULL;
        }
        else {
            nodes[i]->left = nodes[l];
        }
        if (r == -1) {
            nodes[i]->right = NULL;
        }
        else {
            nodes[i]->right = nodes[r];
        }
    }

    bool is_correct = true;

    if (check_tree_in_range(nodes[0], MIN, MAX))
        std::cout << "CORRECT";
    else
        std::cout << "INCORRECT";

    return 0;
}
