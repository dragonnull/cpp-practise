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
    vector<int> findClosedNumbers(int num) {
        bitset<32> small(num);
        bitset<32> bigger(num);

        int s = -1;
        // small, 10 转 01，1移到左侧
        // 找较小值，10 转 01，然后处理交换位置的右侧
        // 处理：把所有的1尽量左靠，0靠右，值会尽量大，只比交换前小一点
        for (int i = 1; i < 32; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                cout << i << endl;
                small.flip(i);
                small.flip(i - 1);
                for (int low = 0, high = i - 2; low < high;) {
                    while (low < high && small[low] == 0) low++;
                    while (low < high && small[high] == 1) high--;
                    small.flip(low);
                    small.flip(high);
                }
                s = (int)small.to_ulong();
                break;
            }
        }

        // bigger, 01转10，1移到最右侧
        // 找较大值同理，01 转 10，然后处理交换位置的右侧
        // 处理：把所有的1尽量靠右，0靠左，值会尽量小，只比交换前大一点
        int b = -1;
        for (int i = 1; i < 32; i++) {
            if (bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i);
                bigger.flip(i - 1);

                for (int low = 0, high = i - 2; low < high;) {
                    while (low < high && bigger[low] == 1) low++;
                    while (low < high && bigger[high] == 0) high--;
                    bigger.flip(low);
                    bigger.flip(high);
                }
                b = (int)bigger.to_ulong();
                break;
            }
        }

        return {b, s};
    }
};


int main() {
    Solution s;
    int test = 4;
    vector<int> res = s.findClosedNumbers(test);
    cout << test << ": " << bitset<32>(test) << endl;
    cout << res[0] << ": " << bitset<32>(res[0]) << endl;
    cout << res[1] << ": " << bitset<32>(res[1]) << endl;
}