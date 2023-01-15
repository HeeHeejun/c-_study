// (��2) ���� �� �����ϴ� �κ� ����
// ���� a�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���
// �̺�Ž���̿�

#include <iostream>
#include <vector>

using namespace std;
vector<int> LCS;
void findLongestSubsequence(int n);

int main()
{
    int n; 
    cin >> n;
    findLongestSubsequence(n);    
}

void findLongestSubsequence(int n)
{
    int first;
    cin >> first;
    LCS.push_back(first);
    for(int i = 1; i < n; i++)
    {
        int current;
        cin >> current;

        if(current > LCS[LCS.size()-1]) LCS.push_back(current);
        else
        {
            auto it = lower_bound(LCS.begin(), LCS.end(), current);
            *it = current;
        }
    }

    cout <<LCS.size();
}