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
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.cbegin(), nums.cend(), k) - nums.cbegin();
        unordered_map<int, int> count{{0, 1}};
        for (int i = pos - 1, x = 0; i >= 0; --i) {
            x += nums[i] < k ? 1 : -1;
            ++count[x];
        }
        int ans = count[0] + count[-1];
        int len = nums.size();
        for (int i = pos + 1, x = 0; i < len; ++i) {
            x += nums[i] > k ? 1 : -1;
            ans += count[x] + count[x - 1];
        }
        return ans;
    }

};


int main() {
    Solution s;

}