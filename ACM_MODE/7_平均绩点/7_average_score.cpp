#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string line;
    // 每一行是一组测试数据
    // 一直读取到 EOF
    while(getline(cin, line))
    {
        stringstream ss(line);
        char grade;
        int sum = 0; //总绩点
        int count = 0; //课程数量
        bool valid = true;

        // 从当前这一行中不断读取成绩
        while(ss >> grade)
        {
            switch(grade)
            {
                case 'A':
                    sum += 4;
                    break;
                case 'B':
                    sum += 3;
                    break;
                case 'C':
                    sum += 2;
                    break;
                case 'D':
                    sum +=1;
                    break;
                case 'F':
                    sum +=0;
                    break;
                default:
                    valid = false;
                    break;
            }
            count++;
        }
        if(!valid)
        {
            cout << "Unknown" << "\n";
        }
        else{
            double average = static_cast<double>(sum) / count;
            // fixed：
            // 使用普通小数形式
            //
            // setprecision(2)：
            // 保留两位小数
            cout << fixed
                 << setprecision(2)
                 << average
                 << "\n";
        }
    }
    return 0;
}