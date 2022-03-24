#include <iostream>
#include <deque>

using namespace std;
int main()
{
    int n;
    deque<pair<int, int>> balloon;
    pair<int, int> paper;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> paper.first;
        paper.second = i + 1;
        balloon.push_back(paper);
    }

    paper = balloon.front();
    balloon.pop_front();
    cout << paper.second << " ";

    while(!balloon.empty())
    {
        if(paper.first > 0)
        {
            for(int i = 0; i < paper.first - 1; i++)
            {
                balloon.push_back(balloon.front());
                balloon.pop_front();
            }
        }
        else
        {
            for(int i = 0; i < abs(paper.first); i++)
            {
                balloon.push_front(balloon.back());
                balloon.pop_back();
            }
        }
        paper = balloon.front();
        balloon.pop_front();
        cout << paper.second << " ";
    }

    return 0;

}