#include <iostream>
#include <vector>
using namespace std;

void getPrimes(vector<int> &primes, int n)
{
    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
        {
            primes.push_back(p);
        }
    }
}

int main()
{
    // Example Usage
    // vector<int> primes;
    // getPrimes(primes, 20);
}
