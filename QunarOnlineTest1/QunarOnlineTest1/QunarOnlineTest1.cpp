// QunarOnlineTest1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*给定一棵二叉树的前序（根、左、右）和中序（左、根、右）的打印结果，输出此二叉树按层（从左往右）打印结果。
例如一棵二叉树前序：1 2 4 5 3；中序：4 2 5 1 3。可以构建出下图所示二叉树：


按层打印的结果则为：1 2 3 4 5。

输入
第一行只有一个数字，表示二叉树的节点数n（1<=n<=1000）;
第二行由a1,a2,...,an(1<=ai<=1000)组成的整数序列（用空格分隔）—表示前序打印结果；
第三行由b1,b2,...,bn(1<=bi<=1000)组成的整数序列（用空格分隔）—表示中序打印结果。

输出
c1,c2,...,cn，用空格分隔—表示按层打印的结果。


样例输入
5
1 2 4 5 3
4 2 5 1 3

样例输出
1 2 3 4 5
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	int indexOfRoot;
	vector<int>	left_pre;
	vector<int>	left_vin;
	vector<int>	right_pre;
	vector<int>	right_vin;
	//	TreeNode* Root = new TreeNode(pre[0]);
	if (pre.size() == 0 || vin.size() == 0)
	{
		return NULL;
	}
	TreeNode* Root = new TreeNode(pre[0]);
	for (int i = 0; i < vin.size(); i++)
	{
		if (vin[i] == pre[0])
		{
			indexOfRoot = i;
			break;
		}
	}
	for (int i = 0; i < indexOfRoot; i++)
	{
		left_pre.push_back(pre[i + 1]);
		left_vin.push_back(vin[i]);
	}
	for (int i = indexOfRoot + 1; i < vin.size(); i++)
	{
		right_pre.push_back(pre[i]);
		right_vin.push_back(vin[i]);
	}
	Root->left = reConstructBinaryTree(left_pre, left_vin);
	Root->right = reConstructBinaryTree(right_pre, right_vin);
	return Root;
}

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> node;
	queue<TreeNode*> q;
	if (root == NULL)
	{
		return node;
	}
	while (root != NULL)
	{
		node.push_back(root->val);

		if (root->left != NULL)
		{
			q.push(root->left);
		}
		if (root->right != NULL)
		{
			q.push(root->right);
		}
		if (q.empty())
			break;
		if (!q.empty())
		{
			root = q.front();
			q.pop();
		}

	}
	return node;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,element;
	vector<int> pre, vin, ans;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> element;
			pre.push_back(element);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> element;
			vin.push_back(element);
		}
		ans = PrintFromTopToBottom(reConstructBinaryTree(pre, vin));
		for (auto i:ans)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

