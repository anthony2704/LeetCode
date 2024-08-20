// Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int longest = 0;

        for (auto num : nums)
        {
            s.insert(num);
        }

        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int currentNum = it;
                int currentStreak = 1;

                while (s.find(currentNum + 1) != s.end())
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
