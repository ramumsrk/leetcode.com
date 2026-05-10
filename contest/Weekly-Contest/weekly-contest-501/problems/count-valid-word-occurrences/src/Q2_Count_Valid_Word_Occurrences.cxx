#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
            string string_from_chunks {};
            for (const auto& chunk : chunks) {
                string_from_chunks.append(chunk);
            }
            int queries_size {static_cast<int>(queries.size())};
            vector<int> occurrences(0,0);            
            for (int i {}; i < queries_size; i += 1) {
                int query_length {static_cast<int>(queries[i].length())};
                int string_from_chunks_length {static_cast<int>(string_from_chunks.length())};
                int occurrence {};
                for (int j {}; j < string_from_chunks_length; j += 1) {
                    string sub_str {string_from_chunks.substr(j,query_length)};
                    if (queries[i] == sub_str) {
                        occurrence += 1;
                    }
                }
                occurrences.push_back(occurrence);
            }
            return occurrences;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution * solution = new Solution();
    while (T) {
        int chunks_N {};
        cin>>chunks_N;
        vector<string> chunks(chunks_N,"");
        for (auto& chunk : chunks) {
            cin>>chunk;
        }
        int queries_N {};
        cin>>queries_N;
        vector<string> queries(queries_N,"");
        for (auto& query : queries) {
            cin>>query;
        }
        vector<int> occurrences {solution->countWordOccurrences(chunks,queries)};
        for (const auto& occurrence: occurrences) {
            cout<<occurrence<<' ';
        }cout<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}