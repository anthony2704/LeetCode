#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }

        return i == n ? 1 : 0;
    }
};