#include <bitset>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

//using std::bitset;
//using std::cout;
//using std::count;
//using std::endl;
//using std::max;
//using std::min;
//using std::set;
//using std::stack;
//using std::string;
//using std::stringstream;
//using std::vector;
//using std::unordered_map;
//using std::to_string;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int n = array.size();
        int sum = 0;
        unordered_map<int, int> record;
        record[0] = -1;
        int index = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (array[i][0] >= '0' && array[i][0] <= '9') {
                ++sum;
            } else {
                --sum;
            }
            auto it = record.find(sum);
            if (it == record.end()) {
                record[sum] = i;
            } else {
                if (len < i - it->second) {
                    index = it->second + 1;
                    len = i - it->second;
                }
            }
        }
        if (len == 0) {
            return vector<string>();
        } else {
            return vector<string>(array.begin() + index, array.begin() + index + len);
        }
    }
};


int main() {
    Solution s;
    vector<string> test = {"A", "1"/*, "B", "C", "D", "2", "3", "4", "E", "5", "F", "G", "6", "7", "H", "I", "J", "K",
                           "L", "M"*/};
    vector<string> ans = s.findLongestSubarray(test);
    for (const auto &str : ans) {
        cout << str << "\t";
    }
    cout << endl;
}