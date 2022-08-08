#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<unsigned long long, unsigned long long> tmp;

unsigned long long fibonacci(unsigned long long n)
{
    if(n == 1 || n == 2) return 1;
    if(n % 2 == 0)
    {
        unsigned long long k = n/2;
        auto it = tmp.find(k);
        auto it2 = tmp.find(k-1);
        unsigned long long a, b;
        if(it == tmp.end())
        {
            a = fibonacci(k);
            tmp.insert({k,a});
        }
        else
        {
            a = it->second;
        }
        if(it2 == tmp.end())
        {
            b = fibonacci(k-1);
            tmp.insert({k-1,b});
        }
        else
        {
            b = it2->second;
        }
        return ((2*b + a)*a) % 1000000;
    }
    else
    {
        unsigned long long k = n/2 + 1;
        auto it = tmp.find(k);
        auto it2 = tmp.find(k-1);
        unsigned long long a, b;
        if(it == tmp.end())
        {
            a = fibonacci(k);
            tmp.insert({k,a});
        }
        else
        {
            a = it->second;
        }
        if(it2 == tmp.end())
        {
            b = fibonacci(k-1);
            tmp.insert({k-1,b});
        }
        else
        {
            b = it2->second;
        }
        return (a * a + b * b) % 1000000;
    }
} 

int main()
{
    unsigned long long n;
    cin >> n;

    cout << fibonacci(n);
}