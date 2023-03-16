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
    vector<string> permutation(string S) {
        vector<string> res;
        res.push_back(S);
        int SLen = S.size();
        for (int i = 0; i < SLen; ++i) {
            int size = res.size();
            for (int j = i + 1; j < SLen; ++j) {
                for (int index = 0; index < size; ++index) {
                    res.push_back((swap(res[index], i, j)));
                }
            }
        }
        return res;
    }

    string swap(string s, int pos1, int pos2) {
        s[pos1] ^= s[pos2];
        s[pos2] ^= s[pos1];
        s[pos1] ^= s[pos2];
        return s;
    }
};


int main() {
    Solution s;

}