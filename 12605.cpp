#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int n;
    string arg_temp;
    stringstream temp;
    string word_temp;
    stack<string> arg;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        getline(cin, arg_temp);
        
        temp.str(arg_temp);
        while(temp >> word_temp)
        {
            arg.push(word_temp);
        }
        
        cout << "Case #" << (i+1) << ": ";

        while(!arg.empty())
        {
            cout << arg.top() << " ";
            arg.pop();
        }

        cout << "\n";
        temp.clear();
    }
    return 0;
}