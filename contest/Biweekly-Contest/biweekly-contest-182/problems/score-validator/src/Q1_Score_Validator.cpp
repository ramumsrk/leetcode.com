#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        vector<int> scoreValidator(vector<string>& events) {
            int score {}, counter {};
            vector<int> result(2,0);
            map<string,int> str_int = {
                {"0", 0},
                {"1", 1},
                {"2", 2},
                {"3", 3},
                {"4", 4},
                {"6", 6}
            };
            int events_size {static_cast<int>(events.size())};
            for (int i {}; counter < 10 && i < events_size; i += 1) {
                if (str_int.contains(events[i])) {
                    score += str_int[events[i]];
                } else if (events[i] == "W") {
                    counter += 1;
                } else if (events[i] == "WD") {
                    score += 1;
                } else if (events[i] == "NB") {
                    score += 1;
                }
            }
            result[0] = score;
            result[1] = counter;
            return result;
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
        vector<string> events(N,"");
        for (auto& event : events) {
            cin>>event;
        }
        vector<int> result {solution->scoreValidator(events)};
        for (const auto& e : result) {
            cout<<e<<' ';
        }cout<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}