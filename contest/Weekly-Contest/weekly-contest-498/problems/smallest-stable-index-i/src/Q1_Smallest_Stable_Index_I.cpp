#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max_element;
using std::min_element;
using std::begin;
using std::end;

class Solution {
    public:
        int firstStableIndex(vector<int>& nums, int k) {
            int nums_size = static_cast<int>(nums.size());
            vector<int> results (0,0);
            int smallest_stable_index {};
            for (int i {}; i < nums_size; i += 1) {
                int max_i {*max_element(begin(nums), begin(nums)+i)};
                int min_i {*min_element(begin(nums)+i, end(nums))};
                if ((max_i - min_i) <= k) {
                    results.push_back(i);
                }
            }
            int results_size = static_cast<int>(results.size());
            if (results_size == 0) {
                smallest_stable_index = -1;
            } else {
                smallest_stable_index = results[0];
            }
            return smallest_stable_index;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    while (t) {
        int n {};
        cin>>n;
        vector<int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        int k {};
        cin>>k;
        Solution * solution = new Solution();
        int smallest_stable_index {solution->firstStableIndex(nums, k)};
        cout<<smallest_stable_index<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}