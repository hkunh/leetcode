#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int N;
    // 多组测试数据，直到 EOF
    while(cin >> N)
    {
        // parent[x] 表示 x 的父亲
        int parent[31] = {0};
        for(int i = 0; i < N; ++i)
        {
            int a, b;
            cin >> a >> b;
            parent[a] = b;
        }
        // --------------------------------------------------
        // 1. 从小明 1 开始向上找祖先
        //
        // ancestorDistance[x]
        // 表示小明 1 到祖先 x 相隔多少代
        //
        // 例如：
        //
        // 1 -> 3 -> 5 -> 6
        //
        // ancestorDistance[1] = 0
        // ancestorDistance[3] = 1
        // ancestorDistance[5] = 2
        // ancestorDistance[6] = 3
        // --------------------------------------------------
        unordered_map<int, int> ancestorDistance;
        int person = 1;
        int distance = 0;
        while(person != 0)
        {
            ancestorDistance[person] = distance;
            person = parent[person];
            distance++;
        }
        // --------------------------------------------------
        // 2. 从小宇 2 开始向上寻找
        //
        // 找到第一个也属于小明祖先链的人，
        // 这个就是最近共同祖先。
        // --------------------------------------------------
        person = 2;
        int distanceYu = 0;
        while(person != 0 && ancestorDistance.find(person) == ancestorDistance.end())
        {
            person = parent[person];
            distanceYu++;
        }
        int distanceMing = ancestorDistance[person];
        // --------------------------------------------------
        // 3. 比较两个人距离共同祖先的代数
        //
        // 小明距离更远：
        // 小明辈分更低
        // => 小宇是长辈
        //
        // 小宇距离更远：
        // 小宇辈分更低
        // => 小宇是晚辈
        //
        // 相同：
        // 同辈
        // --------------------------------------------------
        if(distanceYu < distanceMing)
        {
            cout << "You are my elder" << "\n";
        }
        else if(distanceYu > distanceMing)
        {
            cout << "You are my younger" << "\n";
        }
        else{
            cout << "You are my brother" << "\n";
        }
    }
}