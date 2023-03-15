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
    int rows;
    int cols;
    bool find = false;

    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> path;
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1])
            return path;
        dfs(obstacleGrid, path, visited, 0, 0);
        return path;
    }

    bool
    dfs(vector<vector<int>> &obstacleGrid, vector<vector<int>> &path,
        vector<vector<bool>> &visited, int row, int col) {
        if (find) return true;
        if (row >= rows || col >= cols || visited[row][col])
            return false;
        visited[row][col] = true;
        path.push_back({row, col});
        if ((row == rows - 1) && (col == cols - 1)) {
            find = true;
            return true;
        }
        if (row + 1 < rows && obstacleGrid[row + 1][col] != 1) {
            if (dfs(obstacleGrid, path, visited, row + 1, col)) {
                return true;
            }
        }
        if (col + 1 < cols && obstacleGrid[row][col + 1] != 1) {
            if (dfs(obstacleGrid, path, visited, row, col + 1)) {
                return true;
            }
        }
        path.pop_back();
        return false;
    }
};


int main() {
    Solution s;

}