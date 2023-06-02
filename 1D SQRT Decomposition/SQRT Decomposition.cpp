#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    vector<int> nums;
    vector<int> blockSum;
    int blockSize;

public:
    NumArray(vector<int> &nums) : nums(nums)
    {
        int n = nums.size();
        blockSize = ceil(sqrt(n));
        blockSum.resize(blockSize);

        for (int i = 0; i < n; i++)
        {
            blockSum[i / blockSize] += nums[i];
        }
    }

    void update(int index, int val)
    {
        int blockIndex = index / blockSize;
        blockSum[blockIndex] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        int total = 0;
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock)
        {
            for (int i = left; i <= right; i++)
            {
                total += nums[i];
            }
        }
        else
        {
            for (int i = left; i < (startBlock + 1) * blockSize; i++)
            {
                total += nums[i];
            }
            for (int i = startBlock + 1; i < endBlock; i++)
            {
                total += blockSum[i];
            }
            for (int i = endBlock * blockSize; i <= right; i++)
            {
                total += nums[i];
            }
        }

        return total;
    }
};

int main()
{
    return 0;
}