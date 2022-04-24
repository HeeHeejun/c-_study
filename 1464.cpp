#include <iostream>
#include <deque>
#include <string>

using namespace std;
int main()
{
    string input;
    deque<char> sortInput;
    
    cin >> input;
    for(auto letter : input)
    {
        if(letter <= sortInput.front())
        {
            sortInput.push_front(letter);          
        }
        else
        {
            sortInput.push_back(letter);
        }
    }

    for(auto letter : sortInput)
    {
        cout << letter;
    }

    return 0;
}

/* 처음 생각 했던 코드
using namespace std;
int main()
{
    string input;
    deque<char> flip, temp;
    bool isIncrease = false, isDecrease = false;
    int point = 1;
    cin >> input;

    for(char letter : input)
    {
        flip.push_back(letter);
    }

    temp.push_back(flip.front());
    flip.pop_front();

    while(!flip.empty())
    {
        if(temp.back() > flip.front())
        {
            temp.push_back(flip.front());
            flip.pop_front();
            point++;
            isDecrease = true;
            break;
        }
        else if(temp.back() < flip.front())
        {
            temp.push_back(flip.front());
            flip.pop_front();
            point++;
            isIncrease = true;
            break;
        }
        else
        {
            temp.push_back(flip.front());
            flip.pop_front();
            point++;
        }
    }
    
    while(!(point == input.size()))
    {
        if(isIncrease)
        {
            if(temp.back() > flip.front())
            {
                while(!temp.empty())
                {
                    flip.push_front(temp.front());
                    temp.pop_front();

                }
                isIncrease = false;
                isDecrease = true;
            }
            else
            {
                while (!temp.empty())
                {
                    flip.push_front(temp.back());
                    temp.pop_back();
                }
            }
            point++;
        }      
        else if(isDecrease)
        {
            if(temp.back() < flip.front())
            {
                while(!temp.empty())
                {
                    flip.push_front(temp.front());
                    temp.pop_front();
                }
                isIncrease = true;
                isDecrease = false;
            }
            else
            {
                while (!temp.empty())
                {
                    flip.push_front(temp.back());
                    temp.pop_back();
                }
            }
            point++;
        }
        for(int i = 0; i < point; i++)
        {
            temp.push_back(flip.front());
            flip.pop_front();
                                
        }
    }

    if(isIncrease)
    {
        while(!temp.empty())
        {
            cout << temp.front();
            temp.pop_front();
        }
    }
    else
    {
        while(!temp.empty())
        {
            cout << temp.back();
            temp.pop_back();
        }
    }
    return 0;
}
*/