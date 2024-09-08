#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class DSU
{
private:
    int components;
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n, int type = 0)
    {
        components = n;
        size.resize(n + type, 1);
        parent.resize(n + type);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = findParent(parent[a]);
    }

    bool join(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return false;
        if (size[a] > size[b])
        {
            parent[b] = a;
            size[a] += size[b];
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
        }
        components--;
        return true;
    }

    bool isConnected()
    {
        return components == 1;
    }
};

int main()
{
    // Example usage
    // DSU dsu(20);
    // dsu.join(2, 5);
    // dsu.join(1, 10);
}
