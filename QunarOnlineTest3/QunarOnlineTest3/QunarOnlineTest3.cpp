// QunarOnlineTest3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*��һ�������б�һ����ʼ���ʺ�һ�����յ��ʣ���ʼ������Ҫͨ�������б��𲽱任�����յ��ʣ���任�������̱任·�����ȡ�
�任����ÿ��ֻ�ܱ䶯1����ĸ�����ɽ���λ�ã��磺��abc���cba���ڱ䶯��2����ĸ����ÿ�α任ֻ�ܴӵ����б���ѡȡ��
���磺��ʼ����hot�����յ���dog�������б�[got, dot, god, dog, lot, log]����̱任·��Ϊ[hot,dot,dog]����̱任·������Ϊ3��
ע�������б��а������յ��ʣ���������ʼ���ʣ��б���ÿһ��ʳ������ʼ���ʡ����յ�����ͬ���б��е��ʲ��ظ���������ĸ��ΪСд��

����
�������������У���һ��Ϊ��ʼ���ʣ��ڶ���Ϊ���յ��ʣ�������Ϊ�����б����ʺ͵���֮���Կո�ָ

���
��̱任·�����ȡ�


��������
hot
dog
got dot god dog lot log

�������
3

Hint
Ѱ�����·������㷨��*/
/*int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> path;
	string org, end;
	string ele;
	vector<string> word;
	int diff_end;
	vector<int> diff_word_org;
	vector<int> diff_word_end;
	vector<int> temp;
	while (cin>>org)
	{
		cin >> end;
		diff_end = 0;
		while (cin>>ele)
		{
			word.push_back(ele);
			if (cin.get() == '\n')
			{
				break;
			}
		}
		diff_word_org.resize(word.size());
		diff_word_end.resize(word.size());
		path.push_back(org);
		path.push_back(end);
		while (org != end)
		{
			for (int i = 0; i < org.length(); i++)
			{
				if (org[i] != end[i])
				{
					diff_end++;
				}
			}
			for (int i = 0; i < word.size(); i++)
			{
				for (int j = 0; j < word[i].length(); j++)
				{
					if (org[j] != word[i][j])
					{
						diff_word_org[i]++;
					}
					if (end[j] != word[i][j])
					{
						diff_word_end[i]++;
					}
				}
			}
			for (int i = 0; i < diff_word_org.size(); i++)
			{
				if (diff_word_org[i] == 1)
				{
					temp.push_back(i);
				}
			}
			int small;
			small = diff_word_end[temp[0]];
			for (int i = 0; i < temp.size(); i++)
			{				
				if (diff_word_end[temp[i]] < small)
				{
					small = diff_word_end[temp[i]];
				}
			}
		
			int index = distance(diff_word_end.begin(), small);
			org = word[index];
		}
		cout << path.size()-1 << endl;
		path.clear();
		word.clear();
	}
	return 0;
}*/
vector<vector<string>> result_;
void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path,	const string& word)
{
	if (prevMap[word].size() == 0)
	{
		path.push_back(word);
		vector<string> curPath = path;
		reverse(curPath.begin(), curPath.end());
		result_.push_back(curPath);
		path.pop_back();
		return;
	}

	path.push_back(word);
	for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
	{
		GeneratePath(prevMap, path, *iter);
	}
	path.pop_back();
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{

	result_.clear();
	unordered_map<string, vector<string>> prevMap;
	for (auto iter = dict.begin(); iter != dict.end(); ++iter)
	{
		prevMap[*iter] = vector<string>();
	}
	vector<unordered_set<string>> candidates(2);
	int current = 0;
	int previous = 1;
	candidates[current].insert(start);
	while (true)
	{
		current = !current;
		previous = !previous;
		for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
		{
			dict.erase(*iter);
		}
		candidates[current].clear();
		for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
		{
			for (size_t pos = 0; pos < iter->size(); ++pos)
			{
				string word = *iter;
				for (int i = 'a'; i <= 'z'; ++i)
				{
					if (word[pos] == i)
					{
						continue;
					}
					word[pos] = i;
					if (dict.count(word) > 0)
					{
						prevMap[word].push_back(*iter);
						candidates[current].insert(word);
					}
				}
			}
		}
		if (candidates[current].size() == 0)
		{
			return result_;
		}
		if (candidates[current].count(end))
		{
			break;
		}
	}
	vector<string> path;
	GeneratePath(prevMap, path, end);
	return result_;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<string>> path;
	string org, end;
	string ele;
	unordered_set<string> word;
	int diff_end;
	vector<int> diff_word_org;
	vector<int> diff_word_end;
	vector<int> temp;
	while (cin >> org)
	{
		cin >> end;
		diff_end = 0;
		while (cin >> ele)
		{
			word.insert(ele);
			if (cin.get() == '\n')
			{
				break;
			}
		}
		path = findLadders(org, end, word);
		cout << path.back().size() << endl;
	}

	system("pause");
	return 0;
}

	

