#include <vector>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::accumulate;

class Solution {
    public:
        long long int minArraySum(vector<int>& nums) {
            int nums_size {static_cast<int>(nums.size())};
            for (int i {}; i < nums_size; i += 1) {
                if (i == 0) {
                    if (nums[i+1] != nums[i]) {
                        if (nums[i+1]%nums[i] == 0) {
                            nums[i+1] = nums[i];
                        } else if (nums[i]%nums[i+1]==0) {
                            nums[i] = nums[i+1];
                        }
                    }
                } else if (i == nums_size-1) {
                    if (nums[i-1] != nums[i]) {
                        if (nums[i-1]%nums[i]==0) {
                            nums[i-1]=nums[i];
                        } else if (nums[i]%nums[i-1]==0) {
                            nums[i]=nums[i-1];
                        }
                    }
                } else {
                    if (nums[i+1]!=nums[i]) {
                        if (nums[i+1]%nums[i]==0) {
                            nums[i+1]=nums[i];
                        } else if (nums[i]%nums[i+1]==0) {
                            nums[i]=nums[i+1];
                        }
                    } else if (nums[i-1]!=nums[i]) {
                        if (nums[i-1]%nums[i]==0) {
                            nums[i-1]=nums[i];
                        } else if (nums[i]%nums[i-1]==0) {
                            nums[i]=nums[i-1];
                        }       
                    }
                }
            }
            long long int minimum_possible_sum {accumulate(begin(nums), end(nums), int {})};
            return minimum_possible_sum;
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
        long long int minimum_possible_sum {solution->minArraySum(nums)};
        cout<<minimum_possible_sum<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}