//DP 기법
//스티커를 사용할 때 최대의 점수를 구하기

#include <iostream>

using namespace std;

int maxScoreSticker(int stickerAmount)
{
    int matrix[2][stickerAmount];
    int preUp = -1, preDown = -1, nowUp = -1, nowDown = -1;
   
    for(int i = 0; i < 2; i++)
    {
        
        for(int j = 0; j < stickerAmount; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < stickerAmount; i++)
    {
        if(preUp == -1 && preDown == -1)
        {
            preUp = matrix[0][i];
            preDown = matrix[1][i];
            continue;    
        }
        else if(nowUp == -1 && nowDown == -1)
        {
            nowUp = matrix[0][i] + preDown;
            nowDown = matrix[1][i] + preUp;
            continue;
        }

        int nextUp = max(matrix[0][i] + preDown, matrix[0][i] + nowDown);
        int nextDown = max(matrix[1][i] + preUp, matrix[1][i] + nowUp);

        preUp = nowUp;
        preDown = nowDown;
        nowUp = nextUp;
        nowDown = nextDown;
    }

    return max(max(nowUp, nowDown), max(preUp, preDown));
}

int main()
{
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++)
    {
        int stickerAmount;
        cin >> stickerAmount;
        cout << maxScoreSticker(stickerAmount) << "\n";
    }
}