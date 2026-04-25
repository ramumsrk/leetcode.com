#include <vector>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::accumulate;
using std::begin;
using std::end;

class Solution {
    public:
        int compareBitonicSums(vector<long long int>& nums) {
            int nums_size = static_cast<int>(nums.size());
            vector<long long int> asc_part(0,0), desc_part(0,0);
            int sum_asc_part {}, sum_desc_part {}, result {};
            for (int i {1}; i < nums_size; i += 1) {
                if (i == nums_size-1) {
                    desc_part.push_back(nums[i]);
                } else if (nums[i-1] < nums[i]) {
                    asc_part.push_back(nums[i-1]);
                } else if (nums[i-1] > nums[i]) {
                    desc_part.push_back(nums[i-1]);
                }
            }
            sum_asc_part = accumulate(begin(asc_part), end(asc_part), int {});
            sum_desc_part = accumulate(begin(desc_part), end(desc_part), int {});
            if (sum_desc_part > sum_asc_part) {
                result = 1;
            } else if (sum_desc_part == sum_asc_part) {
                result = -1;
            }
            return result;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution * solution = new Solution();
    while (t) {
        int n {};
        cin>>n;
        vector<long long int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        cout<<solution->compareBitonicSums(nums)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}