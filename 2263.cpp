//(골2) 트리의 순회
// inorder, postorder가 주어질 때, 트리의 preorder를 출력
// 분할 정복

#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder, postorder;

void preOrder(vector<int>::iterator inBegin, vector<int>::iterator inEnd, vector<int>::iterator postBegin, vector<int>::iterator postEnd);

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        inorder.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        postorder.push_back(temp);
    }

    preOrder(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

void preOrder(vector<int>::iterator inBegin, vector<int>::iterator inEnd, vector<int>::iterator postBegin, vector<int>::iterator postEnd)
{
    int root = *(postEnd - 1);
    auto leftInLast = inBegin;
    auto lefePostLast = postBegin;
    for(; (*leftInLast) != root; leftInLast++, lefePostLast++){}
    auto rightInBegin = leftInLast;
    auto rightPostLast = lefePostLast;
    for(; (*rightPostLast) != root; rightPostLast++){}
    rightInBegin++;

    if(root == *(inEnd - 1) && leftInLast == inBegin) cout << root << " ";
    else if(root == *(inEnd - 1))
    { //오른쪽 트리가 없음
        cout << root << " ";
        preOrder(inBegin, leftInLast, postBegin, lefePostLast);//왼쪽트리조사
    } 
    else if(leftInLast == inBegin)
    { //왼쪽 트리가 없음
        cout << root << " ";
        preOrder(rightInBegin, inEnd, lefePostLast, rightPostLast);//오른쪽트리조사
    }
    else
    {
        cout << root << " ";
        preOrder(inBegin, leftInLast, postBegin, lefePostLast);//왼쪽트리조사
        preOrder(rightInBegin, inEnd, lefePostLast, rightPostLast);//오른쪽트리조사
    }
}