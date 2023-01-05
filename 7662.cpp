//이중 우선순위 큐
//명령어를 주면 최대값이나 최소값을 삭제, 마지막에 최대값과 최소값을 줌
//우선순위 큐, 트리를 사용한 집합과 맵
//멀티셋을 사용시도

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