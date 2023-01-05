#include <iostream>
#include <math.h>

using namespace std;
int main()
{

    int chanel, brokenButtonNum;
    bool brokenButton[10];
    cin >> chanel >> brokenButtonNum;

    for(int i = 0; i < 10; i++)
    {
        brokenButton[i] = false;
    }

    for(int i = 0; i < brokenButtonNum; i++)
    {
        int temp;
        cin >> temp;
        brokenButton[temp] = true;
    }

    //+,-로만 가는 경우
    int currentChanel = 100;
    int plus_minusOnly = abs(chanel - currentChanel);

    //최대한 가까운 채널로 이동 후 가는 경우
    //int chanelNum = log10(chanel);
    int minNum = 200000000;
    int gap = 200000000;
    string chanelToStr = to_string(chanel);
    string chagedChanel = "";
    for(int i = 0; i < 1000000; i++)
    {
        bool isContinue = false;
        string check = to_string(i);
        
        for(int j = 0; j < check.size(); j++)
        {
            if(brokenButton[check[j] - '0'])
            {
                isContinue = true;
                
                break;
            } 
        }        
        //cout << i << ": " << isContinue<<"\n";
        if(isContinue){continue;}

        if(gap > abs(chanel - i))
        {
            gap = abs(chanel - i);
            minNum = i;
        }
    }

    int count = to_string(minNum).size() + abs(chanel - minNum);
    //cout << minNum<< "   "<<count << " " << plus_minusOnly;
    int result = min(count, plus_minusOnly);

    //cout << count <<"    " <<plus_minusOnly << "  "<<result;
    cout << result;
}