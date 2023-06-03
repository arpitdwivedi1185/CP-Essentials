#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    vector<int> segment_tree;

public:
    SegmentTree(const vector<int> &nums)
    {
        int seg_size = (4 * nums.size()) + 1;
        segment_tree.resize(seg_size);
        build(0, 0, nums.size() - 1, nums);
    }

    void build(int tree_index, int low, int high, const vector<int> &nums)
    {
        if (low == high)
        {
            segment_tree[tree_index] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * tree_index + 1, low, mid, nums);
        build(2 * tree_index + 2, mid + 1, high, nums);
        segment_tree[tree_index] = segment_tree[2 * tree_index + 1] + segment_tree[2 * tree_index + 2];
    }

    int query(int tree_index, int tree_low, int tree_high, int query_low, int query_high)
    {
        if (query_low > tree_high || query_high < tree_low)
        {
            return 0;
        }
        if (query_low >= tree_low && tree_high <= query_high)
        {
            return segment_tree[tree_index];
        }
        int mid = (tree_low + tree_high) / 2;
        int left = query(2 * tree_index + 1, tree_low, mid, query_low, query_high);
        int right = query(2 * tree_index + 2, mid + 1, tree_high, query_low, query_high);
        return left + right;
    }

    void update(int tree_index, int tree_low, int tree_high, int query_index, int value)
    {
        if (tree_low == tree_high)
        {
            segment_tree[tree_index] = value;
            return;
        }
        int mid = (tree_low + tree_high) / 2;
        if (query_index <= mid)
        {
            update(2 * tree_index + 1, tree_low, mid, query_index, value);
        }
        else
        {
            update(2 * tree_index + 2, mid + 1, tree_high, query_index, value);
        }
        segment_tree[tree_index] = segment_tree[2 * tree_index + 1] + segment_tree[2 * tree_index + 2];
    }
};
