#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using std::min;
using std::stack;
using std::string;
using std::vector;
using std::unordered_map;
using std::to_string;

class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 < runningCost || customers.empty())
            return -1;
        int res = -1;
        int deal = 0;
        int waiting = 0;
        int maxProfit = 0;
        int nowProfit = 0;
        int count = customers.size();
        for (int i = 0; i < count || waiting > 0; ++i) {
            if (i < count)
                waiting += customers[i];
            ++deal;
            if (waiting <= 4) {
                nowProfit += (waiting * boardingCost - runningCost);
                waiting = 0;

            } else {
                nowProfit += (4 * boardingCost - runningCost);
                waiting -= 4;
            }
            if (nowProfit > maxProfit) {
                res = deal;
                maxProfit = nowProfit;
            }
        }
        return res;
    }
};


int main() {

}