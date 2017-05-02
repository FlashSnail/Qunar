// QunarOnlineTest2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

/*用英文字母a-z来分别表示数值0-25, 形成一个26进制的数值表示法。
需要你写一个方法，将用a-z表示的26进制数值的字符串，转化为对应的10进制数值。

输入
输入数据有多组，每组占一行，包含多个a-z之间的字符。

输出
所对应表示的10进制数。


样例输入
ba
bcd
gibbon
goodboy

样例输出
26
731
74962693
2026285376


Hint
做进制转换逻辑。*/

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	int val=0;
	map<char, int> dic;
	long long ans;
	for (char i = 'a'; i <= 'z'; i++)
	{
		dic[i] = val++;
	}
	while (cin>>str)
	{
		ans = 0;
		for (int i = str.length()-1; i >= 0; i--)
		{
			ans += pow(26, i)*dic[str[str.length() - 1 - i]];
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}