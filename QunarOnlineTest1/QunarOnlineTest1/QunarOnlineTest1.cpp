// QunarOnlineTest1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*����һ�ö�������ǰ�򣨸������ң��������󡢸����ң��Ĵ�ӡ���������˶��������㣨�������ң���ӡ�����
����һ�ö�����ǰ��1 2 4 5 3������4 2 5 1 3�����Թ�������ͼ��ʾ��������


�����ӡ�Ľ����Ϊ��1 2 3 4 5��

����
��һ��ֻ��һ�����֣���ʾ�������Ľڵ���n��1<=n<=1000��;
�ڶ�����a1,a2,...,an(1<=ai<=1000)��ɵ��������У��ÿո�ָ�������ʾǰ���ӡ�����
��������b1,b2,...,bn(1<=bi<=1000)��ɵ��������У��ÿո�ָ�������ʾ�����ӡ�����

���
c1,c2,...,cn���ÿո�ָ�����ʾ�����ӡ�Ľ����


��������
5
1 2 4 5 3
4 2 5 1 3

�������
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

