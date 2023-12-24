// ConsoleApplication38.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int data{};
    TreeNode* left{};
    TreeNode* right{};
    TreeNode(int data) : data(data) {};
};
struct BinaryTree
{
    TreeNode* root{};
    BinaryTree(int root_value) : root(new TreeNode(root_value))
    {

    }
    void insert(int val)
    {
        if (!root)
            root = new TreeNode(val);
        return _insert(root, val);

    }
    void _insert(TreeNode* root, int val)
    {
        if (val < root->data)
        {
            if (!root->left)
                root->left = new TreeNode(val);
            else
                _insert(root->left, val);
        }
        else if (val > root->data)
        {
            if (!root->right)
                root->right = new TreeNode(val);
            else
                _insert(root->right, val);
        }
    }
    bool _search(TreeNode* root, int val)
    {
        if (!root)
            return false;
        if (root->data == val)
            return true;
        if (val < root->data)
            return _search(root->left, val);
        if (val > root->data)
            return _search(root->right, val);

    }
    bool search(int val)
    {
        if (!root)
            return false;
        return _search(root, val);
    }
    void print_inorder()
    {
        return _print_inorder(root);
    }
    void _print_inorder(TreeNode* root)
    {
        if (!root)
            return;
        _print_inorder(root->left);
        cout << root->data << " ";
        _print_inorder(root->right);
    }
   
};

class solution
{
    public:
        TreeNode* bst(vector<int>& v)
        {
            return _bst(v, 0, (int)v.size() - 1);
        }
        TreeNode* _bst(vector<int>& v, int s, int e)
        {
            if (s > e)
                return nullptr;
            int m = (s + e) / 2;
            TreeNode* root = new TreeNode(v[m]);
            root->left = _bst(v, s, m - 1);
            root->right = _bst(v, m + 1, e);
            return root;
        }
};
int main()
{
    BinaryTree tree(10);
    tree.insert(5);
    tree.insert(15);
    tree.print_inorder();
    cout << endl;
    cout << tree.search(10);
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
  
    cout << endl;
    cout << solution().bst(v)->data;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
