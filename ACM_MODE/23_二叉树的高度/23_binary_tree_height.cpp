#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int getHeight(
    const string& preorder,
    int preL,
    int preR,
    const string& inorder,
    int inL,
    int inR
)
{
    if(preL > preR)
    {
        return 0;
    }
    char root = preorder[preL];
    int rootPos = inorder.find(root,inL);
    // --------------------------------------------------
    // 3. 计算左子树节点数量
    //
    // inorder：
    //
    // inL ... rootPos-1
    //
    // 都属于左子树
    // --------------------------------------------------
    int leftSize = rootPos - inL;
    // --------------------------------------------------
    // 4. 递归计算左子树高度
    //
    // 前序：
    //
    // 根 | 左子树 | 右子树
    //
    // 左子树范围：
    //
    // preL+1
    // 到
    // preL+leftSize
    // --------------------------------------------------
    int leftHeight = getHeight(
        preorder,
        preL + 1,
        preL + leftSize,
        inorder,
        inL,
        rootPos - 1
    );

    // --------------------------------------------------
    // 5. 递归计算右子树高度
    //
    // 右子树前序范围：
    //
    // preL + leftSize + 1
    // 到
    // preR
    // --------------------------------------------------
    int rightHeight = getHeight(
        preorder,
        preL + leftSize +1,
        preR,
        inorder,
        rootPos + 1,
        inL
    );

    return max(leftHeight, rightHeight) + 1;
}
int main()
{
    int N;
    while(cin >> N)
    {
        string preorder;
        string inorder;
        cin >> preorder;
        cin >> inorder;
        int height = getHeight(preorder, 0, N - 1, inorder, 0, N - 1);
        cout << height << "\n";
    }
}