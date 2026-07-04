#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        int maxValidPairSum(vector<int>& nums, int k) {
            map<pair<int,int>,int> indexes_sum;
            int max_indexes_sum {};
            int nums_size {static_cast<int>(nums.size())};
            for (int i {}; i <= nums_size-2; i += 1) {
                for (int j {i+1}; j < nums_size; j += 1) {
                    if (j-i >= k) {
                        indexes_sum[{i,j}] = nums[i]+nums[j];
                        if (max_indexes_sum < indexes_sum[{i,j}]) {
                            max_indexes_sum = indexes_sum[{i,j}];
                        }
                    }
                }
            }
            return max_indexes_sum;
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
        vector<int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        int k {};
        cin>>k;
        cout<<solution.maxValidPairSum(nums,k)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}