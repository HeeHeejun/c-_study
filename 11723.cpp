//(��5) ����
//������ �ڷᱸ���� ���� �Լ��� ���� �� �� �ְ� ����
//��Ʈ ����ŷ �̿�

#include <iostream>

unsigned int set = 0;
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int operation;
    cin >> operation;
    while (operation--)
    {
        string operand;
        cin >> operand;
        if(operand == "all") 
        {
            set = set | 4294967295;
            continue;
        }
        else if(operand == "empty"){set = set & 0; continue;}

        int option;
        cin >> option;

        if(operand == "add") {int temp = 1 << (option - 1) ; set = set | temp;} 
        else if(operand == "remove")
        {
            int temp = ~(1 << (option - 1));
            set = set & temp;
        }
        else if(operand == "check") {cout << ((set << (32 - option)) >> 31)  << "\n";}
        else
        {   
            if(((set << (32 - option)) >> 31))
            {
                int temp = ~(1 << (option-1));
                set = set & temp;
            }
            else 
            {
                int temp = 1 << (option-1);
                set = set|temp;
            }
        }
        
    }
}