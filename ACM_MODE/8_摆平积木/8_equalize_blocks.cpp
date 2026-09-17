#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        vector<int> heights(n);
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> heights[i];
            sum += heights[i];
        }
        // 最终每一堆应该达到的平均高度
        int average = sum / n;
        int moves = 0;
        for(int h : heights)
        {
            if(h > average)
            {
                moves += h - average;
            }
        }
        // 输出最少移动次数
        cout << moves << "\n";
        // 每组结果下面输出一个空行
        cout << "\n";
    }
}