#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<long long> arr;
    vector<long long> tree;

    void buildSegmentTree(int index, int left, int right)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        buildSegmentTree(2 * index + 1, left, mid);
        buildSegmentTree(2 * index + 2, mid + 1, right);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    long long querySegmentTree(int arrayLeft, int arrayRight, int treeLeft, int treeRight, int treeIndex)
    {
        if (treeRight < arrayLeft || treeLeft > arrayRight)
            return 0;
        if (treeLeft >= arrayLeft && treeRight <= arrayRight)
            return tree[treeIndex];
        int mid = (treeLeft + treeRight) / 2;
        long long left = querySegmentTree(arrayLeft, arrayRight, treeLeft, mid, 2 * treeIndex + 1);
        long long right = querySegmentTree(arrayLeft, arrayRight, mid + 1, treeRight, 2 * treeIndex + 2);
        return (left + right);
    }

    void updateSegmentTree(int arrayIndex, int newVal, int treeLeft, int treeRight, int treeIndex)
    {
        if (treeLeft == treeRight)
        {
            tree[treeIndex] = newVal;
            return;
        }
        int mid = (treeLeft + treeRight) / 2;
        if (mid >= arrayIndex)
            updateSegmentTree(arrayIndex, newVal, treeLeft, mid, 2 * treeIndex + 1);
        else
            updateSegmentTree(arrayIndex, newVal, mid + 1, treeRight, 2 * treeIndex + 2);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

public:
    SegmentTree(vector<long long> &nums)
    {
        arr = nums;
        n = arr.size();
        tree.resize(4 * n);
        buildSegmentTree(0, 0, n - 1);
    }

    long long query(int left, int right)
    {
        return querySegmentTree(left, right, 0, n - 1, 0);
    }

    void update(int index, int val)
    {
        return updateSegmentTree(index, val, 0, n - 1, 0);
    }
};
