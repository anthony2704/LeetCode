#include <iostream>

using namespace std;

class Solution{
    public:
        int reserve(int x)
        {
            long r = 0;
            while(x)
            {
                r = r * 10 + x % 10; // 123 -> 3 -> r
                x = x / 10; //123 -> 12
            }

            // if(x > INT_MAX || x < INT_MIN) return 0;

            return (int)r;
        }
};

int main(){
    int x = 123;
    Solution a;
    cout << a.reserve(x) << endl;
}