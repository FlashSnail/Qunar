// QunarOnlineTest2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

/*��Ӣ����ĸa-z���ֱ��ʾ��ֵ0-25, �γ�һ��26���Ƶ���ֵ��ʾ����
��Ҫ��дһ������������a-z��ʾ��26������ֵ���ַ�����ת��Ϊ��Ӧ��10������ֵ��

����
���������ж��飬ÿ��ռһ�У��������a-z֮����ַ���

���
����Ӧ��ʾ��10��������


��������
ba
bcd
gibbon
goodboy

�������
26
731
74962693
2026285376


Hint
������ת���߼���*/

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