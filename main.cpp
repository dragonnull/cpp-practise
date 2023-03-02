#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class StackOfPlates
{
public:
    StackOfPlates(int cap)
    {
        if (cap < 0)
            stackSize = 0;
        else
            stackSize = cap;
    }

    void push(int val)
    {
        if (stackSize == 0)
            return;
        if (setOfStacks.size() == 0)
            setOfStacks.push_back(vector<int>{val});
        else if (setOfStacks.back().size() == stackSize)
            setOfStacks.push_back(vector<int>{val});
        else
            setOfStacks.back().push_back(val);
    }

    int pop()
    {
        if (setOfStacks.size() == 0)
            return -1;
        int res = setOfStacks.back().back();
        setOfStacks.back().pop_back();
        if (setOfStacks.back().size() == 0)
            setOfStacks.pop_back();
        return res;
    }

    int popAt(int index)
    {
        if (setOfStacks.size() == 0 || setOfStacks.size() <= index)
            return -1;
        int res = setOfStacks[index].back();
        setOfStacks[index].pop_back();
        if (setOfStacks[index].size() == 0)
            setOfStacks.erase(setOfStacks.begin() + index);
        return res;
    }

private:
    vector<vector<int>> setOfStacks{};
    int stackSize = 0;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

int main()
{
    std::cout << "Hello, world!" << std::endl;
}