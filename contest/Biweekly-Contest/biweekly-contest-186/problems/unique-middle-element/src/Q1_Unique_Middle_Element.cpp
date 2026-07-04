#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>

using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

class Solution {
    public:
        bool isMiddleElementUnique(vector<int>& nums) {
            map<int, int> element_count;
            for (const auto& e : nums) {
                if (!element_count.contains(e)) {
                    element_count[e] = 1;
                } else {
                    element_count[e] += 1;
                }
            }
            for (const auto& [k, v] : element_count) {
                cout<<"element: "<<k<<" count: "<<v<<endl;
            }
            int nums_size {static_cast<int>(nums.size())};
            int middle_element_index {nums_size/2};
            return element_count[nums[middle_element_index]] == 1 ? true : false;
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
        cout<<boolalpha<<solution.isMiddleElementUnique(nums)<<endl;
        t -= 1;
    }
}