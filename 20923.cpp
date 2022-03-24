#include <iostream>
#include <deque>

using namespace std;
int main()
{   
    deque<int> dodo, suyeon, groundDodo, groundSuyeon;
    int n, m, inputCard;

    cin >> n >> m;

    //덱에 카드 입력받기
    for(int i = 0; i < n; i++)
    {
        cin >> inputCard;
        dodo.push_back(inputCard);

        cin >> inputCard;
        suyeon.push_back(inputCard);
    }

    //게임을 진행, 한사람이 카드를 낼때마다 m은 줄어듬
    while(true)
    {
        //카드를 그라운드에 깔기, 도도 먼저
        groundDodo.push_front(dodo.back());
        dodo.pop_back();
        m--;
        
        //만약 도도의 카드가 없다면 수연이 승리하고 종료
        if(dodo.empty())
        {
            cout << "su";
            return 0;
        }
        
        //수연의 1판의 게임 승리 조건
        if(!groundDodo.empty() && !groundSuyeon.empty() && (groundDodo.front() + groundSuyeon.front() == 5))
        {
            while(!groundDodo.empty())
            {
                suyeon.push_front(groundDodo.back());
                groundDodo.pop_back();
            }
            while(!groundSuyeon.empty())
            {
                suyeon.push_front(groundSuyeon.back());
                groundSuyeon.pop_back();
            }
        }
        //도도의 1판의 게임 승리 조건
        else if( (!groundDodo.empty() && groundDodo.front() == 5) || (!groundSuyeon.empty() && groundSuyeon.front() == 5 ))
        {
            while(!groundSuyeon.empty())
            {
                dodo.push_front(groundSuyeon.back());
                groundSuyeon.pop_back();
            }
            while(!groundDodo.empty())
            {
                dodo.push_front(groundDodo.back());
                groundDodo.pop_back();
            }
        }

        if(m == 0) { break; }

        //카드를 깔기, 그 다음 차례 수연
        groundSuyeon.push_front(suyeon.back());
        suyeon.pop_back();
        m--;

        //만약 수연의 카드가 없다면 도도이 승리하고 종료
        if(suyeon.empty())
        {
            cout << "do";
            return 0;
        }

        //수연의 1판의 게임 승리 조건
        if(!groundDodo.empty() && !groundSuyeon.empty() && (groundDodo.front() + groundSuyeon.front() == 5))
        {
            while(!groundDodo.empty())
            {
                suyeon.push_front(groundDodo.back());
                groundDodo.pop_back();
            }
            while(!groundSuyeon.empty())
            {
                suyeon.push_front(groundSuyeon.back());
                groundSuyeon.pop_back();
            }
        }
        //도도의 1판의 게임 승리 조건
        else if((!groundDodo.empty() && groundDodo.front() == 5) || (!groundSuyeon.empty() && groundSuyeon.front() == 5 ))
        {
            while(!groundSuyeon.empty())
            {
                dodo.push_front(groundSuyeon.back());
                groundSuyeon.pop_back();
            }
            while(!groundDodo.empty())
            {
                dodo.push_front(groundDodo.back());
                groundDodo.pop_back();
            }
        }
        
        if(m == 0) { break; }
    }

    //게임이 끝난 후, 카드 수를 비교
    if(dodo.size() > suyeon.size()) { cout << "do"; }
    else if(dodo.size() == suyeon.size()) { cout << "dosu"; }
    else { cout << "su"; }

    return 0;

}