#include <map>
#include <cstdlib>
#include <iostream>

using std::map;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        int digitFrequencyScore(int n) {
            map<int,int> digit_occurrence;
            int local_n {n} , remainder {}, digit_frequency_score {};
            constexpr int BASETEN {10};
            while (local_n > 0) {
                remainder = local_n % BASETEN;
                if (!digit_occurrence.contains(remainder)) {
                    digit_occurrence[remainder] = 1;
                } else {
                    digit_occurrence[remainder] += 1;
                }
                local_n /= BASETEN;
            }
            for (const auto& [key, value] : digit_occurrence) {
                digit_frequency_score += key*value;
            }
            return digit_frequency_score;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution solution {};
    while (T) {
        int n {};
        cin>>n;
        int digit_frequency_score {solution.digitFrequencyScore(n)};
        cout<<digit_frequency_score<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}