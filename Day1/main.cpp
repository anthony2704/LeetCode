#include <iostream>

using namespace std;

/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

class Solution
{
public:
    string reverseWords(string s)
    {

        // Approach 1
        string res = "";
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (word.size() > 0)
                {
                    res = word + " " + res;
                    word = "";
                }
            }
            else
            {
                word += s[i];
            }
        }
        if (word.size() > 0)
        {
            res = word + " " + res;
        }
        return res.substr(0, res.size() - 1);
    }
};

int main()
{
    Solution sol;
    string s = "the sky is blue";
    cout << sol.reverseWords(s) << endl;
    return 0;
}