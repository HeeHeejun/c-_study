//(플5) 가장 긴 증가하는 부분 수열 5
// 수열이 주어지면 lcs의 길이와 lcs를 출력
// 이진탐색

#include <iostream>
#include <vector>

using namespace std;
long long LCS[2][1000001] = {};
int dp[2][1000001] = {};
vector<int> result;
void findLCS(int n);
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
    int n; cin >> n;
    findLCS(n);
}
void findLCS(int n)
{
    int size = 0;
    for(int i = 0; i < n; i++)
    {
        //cout << "i : " << i << "\n";
        long long current; cin >> current;
        LCS[0][i] = current;
        auto it = lower_bound(LCS[1], LCS[1] + size, current);
        (*it) = current;
        dp[1][it-LCS[1]] = i + 1;
        if(it-LCS[1] > 0) {dp[0][i] = dp[1][it-LCS[1]-1];}
        if(it-LCS[1] > size - 1) {size++;}
        
        // for(int j = 0; j <= i; j++){cout << LCS[0][j] << " ";}
        // cout << "\n";
        // for(int j = 0; j <= i; j++){cout << dp[0][j] << " ";}
        // cout << "\n";
        // for(int j = 0; j < size; j++){cout << LCS[1][j] << " ";}
        // cout << "\n";
        // for(int j = 0; j < size; j++){cout << dp[1][j] << " ";}
        // cout << "\n";
    }
    cout<< size << "\n";
    for(int i = dp[1][size-1] - 1; i != -1; i = dp[0][i] - 1){result.push_back(LCS[0][i]);}
    for(auto i = result.rbegin(); i != result.rend(); i++){cout << *i << " ";}
}

