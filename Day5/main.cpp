#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    // string longestPalindrome(string s)
    // {
    //     int n = s.size();

    //     if (n == 0)
    //     {
    //         return "";
    //     }

    //     int maxLen = 1;
    //     string maxSubStr = s.substr(0, 1);

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + maxLen; j < n; j++)
    //         {
    //             if (isPalindrome(s, i, j))
    //             {
    //                 maxLen = j - i + 1;
    //                 maxSubStr = s.substr(i, maxLen);
    //             }
    //         }
    //     }

    //     return maxSubStr;
    // }

    // bool isPalindrome(string s, int i, int j)
    // {
    //     while (i < j)
    //     {
    //         if (s[i] != s[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    string longestPalindrome(string s)
    {
        int n = s.size();

        if (n == 0)
        {
            return "";
        }

        int maxLen = 1;
        string maxSubStr = s.substr(0, 1);

        for (int i = 0; i < n; i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLen)
            {
                maxLen = len;
                maxSubStr = s.substr(i - (len - 1) / 2, len);
            }
        }

        return maxSubStr;
    }
    int expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main()
{
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}