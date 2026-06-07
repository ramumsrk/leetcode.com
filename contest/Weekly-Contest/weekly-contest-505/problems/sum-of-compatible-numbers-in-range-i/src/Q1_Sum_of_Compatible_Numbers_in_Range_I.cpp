#include <cstdlib>
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::abs;

class Solution {
    public:
        int sumOfGoodIntegers(int n, int k) {
            int sum_of_all_x {};
            for (int x {}; x <= (n+k); x += 1) {
                if (
                    (abs(n-x) <= k)
                    &&
                    ((n & x) == 0)
                ) {
                    sum_of_all_x += x;
                }
            }
            return sum_of_all_x;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution solution {};
    while (t) {
        int n {}, k {};
        cin>>n>>k;
        cout<<solution.sumOfGoodIntegers(n, k)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}