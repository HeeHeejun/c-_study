//(실1) 트리 순회
// 트리가 주어질 때, preorder, inorder, postorder로 탐색한 결과를 출력
// 트리 탐색

#include <iostream>

using namespace std;
struct Node
{
    char charater;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node node[26];
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        node[i].charater = i + 'A';
        char root, left, right;
        cin >> root >> left >> right;
        if(left != '.') node[root - 'A'].left = &node[left - 'A'];
        if(right != '.') node[root - 'A'].right = &node[right - 'A'];
    }
    preorder(&node[0]);
    cout << "\n";
    inorder(&node[0]);
    cout << "\n";
    postorder(&node[0]);
}

void preorder(Node* root)
{
    cout << root->charater;
    if(root->left != nullptr) preorder(root->left);
    if(root->right != nullptr) preorder(root->right);
}

void inorder(Node* root)
{
    if(root->left != nullptr) inorder(root->left);
    cout << root->charater;
    if(root->right != nullptr) inorder(root->right);
}

void postorder(Node* root)
{
    if(root->left != nullptr) postorder(root->left);
    if(root->right != nullptr) postorder(root->right);
    cout << root->charater;
}