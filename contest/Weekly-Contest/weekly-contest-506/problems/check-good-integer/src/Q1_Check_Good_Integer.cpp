#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

class Solution {
    public:
        bool checkGoodInteger(int n) {
            constexpr int BASE_TEN {10};
            int remainder {}, quotient {}, digitSum {}, squareSum {};
            while (n > 0) {
                remainder = n % BASE_TEN;
                quotient = n / BASE_TEN;
                n = quotient;
                digitSum += remainder;
                squareSum += remainder * remainder;
            }
            return squareSum - digitSum >= 50; 
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution solution {};
    while (t) {
        int n {};
        cin>>n;
        bool isGoodInteger {solution.checkGoodInteger(n)};
        cout<<boolalpha<<isGoodInteger<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}