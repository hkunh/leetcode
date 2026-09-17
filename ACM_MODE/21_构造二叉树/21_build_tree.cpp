#include <iostream>
#include <string>
using namespace std;
string buildPostOrder(string& preorder, string& inorder)
{
    if(preorder.empty())
    {
        return "";
    }
    // 前序遍历的第一个字符一定是根节点
    char root = preorder[0];
    // cout << root << "\n";
    // 在中序遍历中找到根节点位置
    int rootPos = inorder.find(root);
    // cout << rootPos << "\n";
    string leftInorder = inorder.substr(0, rootPos);
    string rightInorder = inorder.substr(rootPos + 1);
    // 左子树节点个数
    int leftSize = leftInorder.size();
    // 前序遍历结构：
    //
    // root | 左子树 | 右子树
    //
    // 所以根据 leftSize 切分
    string leftPreorder = preorder.substr(1, leftSize);
    string rightPreorder = preorder.substr(leftSize + 1);
    // 后序遍历：
    //
    // 左子树 -> 右子树 -> 根
    return 
        buildPostOrder(leftPreorder, leftInorder) +
        buildPostOrder(rightPreorder, rightInorder) +
        root;

}

int main()
{
    string preorder;
    string inorder;
    while(cin >> preorder >> inorder)
    {
        // 多组测试数据
        // 每组包含：
        // 前序遍历字符串 + 中序遍历字符串
        cout << buildPostOrder(preorder, inorder) << "\n";
    }
    return 0;
}