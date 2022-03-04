#include<iostream>
#include<stack>
#include<string>
/* 
L   : 커서를 왼쪽으로 한칸 이동 (커서가 문장의 맨 앞이면 무시됨)
D   : 커서를 오른쪽으로 한칸 이동 (커서가 문장의 맨 뒤이면 무시됨)
B   : 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
P $ : $라는 문자를 커서 왼쪽에 추가함

첫번째줄 문자열
두번째줄 명령어 개수
셋째줄부터 입력할 명령어가 순서대로 주어짐

편집기에 입력되어있는 문자열 출력
*/

using namespace std;
void L(stack<char>& left_clone, stack<char>& right_clone);
void D(stack<char>& left_clone, stack<char>& right_clone);
void B(stack<char>& left_clone, stack<char>& right_clone);
void P(stack<char>& left_clone, stack<char>& right_clone, char plus);

int main()
{
    stack<char> left;
    stack<char> right;

    string arg;
    int command_n;
    char command;
    char p_word;

    cin >> arg;

    for(int i = 0; i < arg.length(); i++)
    {
        left.push(arg.at(i));
    }

    cin >> command_n;

    for(int i = 0; i < command_n; i++)
    {
        cin >> command;

        switch (command)
        {
        case 'L':
            L(left, right);
            break;
        case 'D':
            D(left, right);
            break;
        case 'B':
            B(left, right);
            break;
        case 'P':
            cin>>p_word;
            P(left, right, p_word);
            break;
        }
    }

    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    return 0;
}

void L(stack<char>& left_clone, stack<char>& right_clone)
{
    if(!left_clone.empty())
    {
        right_clone.push(left_clone.top());
        left_clone.pop();
    }
    return;
}

void D(stack<char>& left_clone, stack<char>& right_clone)
{
    if(!right_clone.empty())
    {
        left_clone.push(right_clone.top());
        right_clone.pop();
    }
    return;
}

void B(stack<char>& left_clone, stack<char>& right_clone)
{
    if(!left_clone.empty())
    {
        left_clone.pop();
    }
    return;
}

void P(stack<char>& left_clone, stack<char>& right_clone, char plus)
{
    left_clone.push(plus);
    return;
}