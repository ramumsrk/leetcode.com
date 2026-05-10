#include <vector>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        vector<int> concatWithReverse(vector<int>& nums) {
            int nums_size {static_cast<int>(nums.size())};
            vector<int> ans(2*nums_size,0);
            for (int i {}, j {nums_size-1}; i < (2*nums_size); i += 1) {
                if (i <= nums_size-1) {
                    ans[i] = nums[i];
                } else {
                    ans[i] = nums[j];
                     j -= 1;
                }
            }
            return ans;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution * solution = new Solution();
    while (T) {
        int N {};
        cin>>N;
        vector<int> nums(N,0);
        for (auto& e : nums) {
            cin>>e;
        }
        vector<int> ans {solution->concatWithReverse(nums)};
        for (const auto& e : ans) {
            cout<<e<<' ';
        }cout<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}