#include <string>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::boolalpha;

class Solution {
    public:
        bool validDigit(int n, int x) {
            int digit {};
            int x_count {};
            bool result {false};
            while (n > 0) {
                digit = n%10;
                if (x == digit) {
                    x_count += 1;
                }
                n /= 10;
            }
            if (
                (x != digit)
                &&
                (x_count >= 1)
            ) result = true;
            return result;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution * solution = new Solution();
    while (t) {
        int n {}, x {};
        cin>>n>>x;
        cout<<boolalpha<<solution->validDigit(n,x)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}