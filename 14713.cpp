#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    int n;
    string one_talk;
    bool is_same = false;
    
    cin >> n;
    cin.ignore();   
    queue<string> split_talk[n+1];

    for(int i = 0; i < n + 1; i++)
    {
        getline(cin, one_talk);
        istringstream split_temp(one_talk);
        while(split_temp >> one_talk)
        {
            split_talk[i].push(one_talk);
        }
    }

    while(!split_talk[n].empty())
    {
        one_talk = split_talk[n].front();
        split_talk[n].pop();

        for(int i = 0; i < n; i++)
        {
            if(one_talk == split_talk[i].front())
            {
                split_talk[i].pop();
                is_same = true;
                break;
            }
        }
        
        if(!is_same)
        {
            cout << "Impossible";
            return 0;
        }
        is_same = false;
    }

    for(int i = 0; i < n; i++)
    {
        if(!split_talk[i].empty())
        {
            cout << "Impossible";
            return 0;
        }
    }

    cout << "Possible";
    return 0;
}