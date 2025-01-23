#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Solution:
- Sort the array, then iterate through the array. (-ve...0...+ve)
- For each element, use two pointers to find the other two elements.
- If the sum is less than 0, increment the left pointer.
- If the sum is greater than 0, decrement the right pointer.
- If the sum is 0, add the triplet to the result.
- Skip duplicates.
- Time complexity: O(n^2)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
            return {};

        if (nums[0] > 0)
            return {};

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++)
        {

            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) /**/
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};