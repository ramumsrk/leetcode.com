#include <string>
#include <cstdlib>
#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::bitset;
using std::boolalpha;

class Solution {
    public:
        bool isPalindromic(string s) {
            int s_length {static_cast<int>(s.length())};
            string another_s {};
            int ch {};
            for (int i {}; i < s_length; i += 1) {
                ch = s[i];
                bitset<8> b {static_cast<long long unsigned int>(ch)};
                for (const auto& e : b.to_string()) {
                    another_s.push_back(e);
                }
            }
            cout<<another_s<<endl;
            int another_s_length {static_cast<int>(another_s.length())};
            int start {};
            int end {another_s_length-1};
            bool is_palindromic {true};
            for (;start <= end; start += 1, end -= 1) {
                if (another_s[start] != another_s[end]) {
                    is_palindromic = false;
                    break;
                }
            }
            return is_palindromic;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution solution {};
    while (t) {
        string s {};
        cin>>s;
        cout<<boolalpha<<solution.isPalindromic(s)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}