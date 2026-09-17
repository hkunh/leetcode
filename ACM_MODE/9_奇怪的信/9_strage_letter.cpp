#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0;
        // 如果题目可能出现负数，
        // 取绝对值后再逐位处理
        long long x = n;
        if(x < 0)
        {
            x = -x;
        }
        // 特殊情况：0 本身这一位就是偶数，
        // 但加 0 对结果没有影响，
        // 所以不需要单独处理也没问题。
        while(x > 0)
        {
            // 取个位
            int digit = x % 10;
            // 偶数则累加
            if(digit % 2 == 0)
            {
                sum += digit;
            }
            x = x / 10;
        }
        cout << sum << "\n";
        // 每组数据下面输出一个空行
        cout << '\n';
    }
    return 0;
}