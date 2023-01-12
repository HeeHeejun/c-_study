//(��2) Ʈ���� ��ȸ
// inorder, postorder�� �־��� ��, Ʈ���� preorder�� ���
// ���� ����

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
    { //������ Ʈ���� ����
        cout << root << " ";
        preOrder(inBegin, leftInLast, postBegin, lefePostLast);//����Ʈ������
    } 
    else if(leftInLast == inBegin)
    { //���� Ʈ���� ����
        cout << root << " ";
        preOrder(rightInBegin, inEnd, lefePostLast, rightPostLast);//������Ʈ������
    }
    else
    {
        cout << root << " ";
        preOrder(inBegin, leftInLast, postBegin, lefePostLast);//����Ʈ������
        preOrder(rightInBegin, inEnd, lefePostLast, rightPostLast);//������Ʈ������
    }
}