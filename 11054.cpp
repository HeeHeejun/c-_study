//(��4) ���� �� ������� �κ� ����
// ������ �־����� ��, �����ϴٰ� �����ϴ� ���� = ������� �����̸鼭 ���� �� ������ ���
// dp

#include <iostream>

using  namespace std;
int subSequence[1000] = {};
pair<int, int> dp[1000] = {}; // ���� = first, ���� = second
void longestSubSequence(int n); 
int main()
{
    int n; cin >> n;
    longestSubSequence(n);
}

void longestSubSequence(int n)
{
    int first; cin >> first;
    int result = 1;
    subSequence[0] = first;
    dp[0] = {1, 1};
    for(int i = 1; i < n; i++)
    {
        int current; cin >> current;
        subSequence[i] = current;
        pair<int, int> maxNum = {0, 0};
        for(int j = 0; j < i; j++)
        {
            if(dp[j].first > maxNum.first && current > subSequence[j]) //�����Ҷ��� max�� ����
            {
                maxNum.first = dp[j].first;   
            }
            
            if(current < subSequence[j]) //�����Ҷ��� max�� ����
            {
                int increase = 0, decrease = 0;
                if(dp[j].first > maxNum.second) increase = dp[j].first;
                if(dp[j].second > maxNum.second) decrease = dp[j].second;
                maxNum.second = max(maxNum.second, max(increase, decrease));
            }
        }
        dp[i] = {maxNum.first +1, maxNum.second + 1};
        result = max(dp[i].first, max(dp[i].second, result));
    }
    cout << result;
} 
