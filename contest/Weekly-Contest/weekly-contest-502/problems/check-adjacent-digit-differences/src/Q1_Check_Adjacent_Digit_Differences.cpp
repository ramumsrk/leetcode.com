#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cmath>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::abs;
using std::boolalpha;

class Solution {
    public:
        bool isAdjacentDiffAtMostTwo(string s) {
            int s_length {static_cast<int>(s.length())};
            map<char,int> char_int {
                {'0', 0},
                {'1', 1},
                {'2', 2},
                {'3', 3},
                {'4', 4},
                {'5', 5},
                {'6', 6},
                {'7', 7},
                {'8', 8},
                {'9', 9},
            };
            int first_number {}, second_number {};
            bool result {true};
            for (int i {}; i <= s_length-2; i += 1) {
                first_number = char_int[s[i]];
                second_number = char_int[s[i+1]];
                if (abs(first_number-second_number)>2){
                    result = false;
                    break;
                }
            }
            return result;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution * solution = new Solution();
    while (T) {
        string s {};
        cin>>s;
        bool result {solution->isAdjacentDiffAtMostTwo(s)};
        cout<<boolalpha<<result<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}