#include <iostream>
using namespace std;
int main()
{
    int M, K;
    // 多组测试数据
    // 0 0 表示输入结束
    while(cin >> M >> K)
    {
        if(M == 0 && K == 0)
        {
            break;
        }
        int days = M;
        int current = M;
        while(current >= K)
        {
            // 当前这一轮能获得的奖励
            int reward = current / K;
            // 奖励的话费也可以继续使用，
            // 所以增加可使用天数
            days += reward;

            // 当前没有凑够 K 的剩余部分
            // 加上刚刚得到的奖励，
            // 继续参与下一轮活动
            current = current % K + reward;
        }
        cout << days << "\n";
    }
    return 0;
}