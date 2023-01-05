//���� �켱���� ť
//��ɾ �ָ� �ִ밪�̳� �ּҰ��� ����, �������� �ִ밪�� �ּҰ��� ��
//�켱���� ť, Ʈ���� ����� ���հ� ��
//��Ƽ���� ���õ�

#include <iostream>
#include <set>

using namespace std;
void dual_priority_queue();
int main()
{
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){ dual_priority_queue(); }
}

void dual_priority_queue()
{
    multiset<int> ms;
    int operation;
    cin >> operation;

    while (operation--)
    {
        char operand;
        int option;
        cin >> operand >> option;

        if(operand == 'I') { ms.insert(option); }
        else
        {
            if(option == 1)
            {
                auto it = ms.end();
                if(it == ms.begin()) continue;
                ms.erase(--it);
            }
            else
            {
                auto it = ms.begin();
                if(it == ms.end()) continue;
                ms.erase(it);
            }
        }
    }
    auto it = ms.begin();
    if(it == ms.end()) {cout << "EMPTY"<< "\n"; return;}

    int min = *(it);
    it = ms.end();
    it--; 
    int max = *(it);
       
    cout <<max << " " << min << "\n";
    return;
}