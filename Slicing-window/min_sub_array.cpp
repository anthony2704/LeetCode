#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define INT_MAX 1000000

using namespace std;

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        // initialize the window
        int i = 0, j = 0;
        int sum = 0;
        int min_len = INT_MAX;

        while (j < n)
        {

            // expand the window
            sum += nums[j];

            // shrink the window
            while (sum >= target)
            {
                min_len = min(min_len, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};