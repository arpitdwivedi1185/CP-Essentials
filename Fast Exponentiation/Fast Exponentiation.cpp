#include <iostream>
using namespace std;

long long ModularExponentiation(long long base, long long exponent, const long long MOD = 1e9 + 7)
{
    if (base == 1 || exponent == 0)
        return 1;
    long long halfAns = ModularExponentiation(base, exponent / 2);
    long long ans = (halfAns * halfAns) % MOD;
    return (exponent % 2) ? (ans * base) % MOD : ans;
}

int main()
{
    // Example usage
    // int a = ModularExponentiation(2, 10);
    // cout << a << endl;
}
