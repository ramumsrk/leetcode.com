#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

auto
firstUniqueEven(
    const vector<int>& nums
) -> int {
    // even numbers and their occurrences
    map<int,int> n_o;
    // build a map of even numbers and their
    // occurrences from a vector
    for (int i {}; i < static_cast<int>(nums.size()); i += 1) {
        if (nums[i]%2 == 0) {
            if (!n_o.contains(nums[i])) {
                n_o[nums[i]] = 1;
            } else {
                n_o[nums[i]] += 1;
            }
        }
    }
    // there are no even numbers in input vector
    if (n_o.size() == 0) return -1;
    // key of first even number that has only 1
    // occurence in input vector. -1 if there is
    // no such occurrence
    int key {-1};
    // check the first even number that has an
    // occurrence of only 1
    for (const auto& [k, v] : n_o) {
        if (v == 1) {
            key = k;
            break;
        }
    }
    // look-up the index of the even number in
    // vector
    for (int i {}; i < static_cast<int>(nums.size()); i += 1) {
        if (key == nums[i]) {
            key = nums[i];
            break;
        }
    }
    return key;
}

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
        int result {firstUniqueEven(nums)};
        cout<<result<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}