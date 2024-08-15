#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int minJump = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            minJump++;
            if (nums[i] >= minJump)
            {
                minJump = 0;
            }
        }

        return minJump == 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.canJump(nums) << endl;
    return 0;
}