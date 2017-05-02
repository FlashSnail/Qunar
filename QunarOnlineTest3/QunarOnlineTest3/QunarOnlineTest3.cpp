// QunarOnlineTest3.cpp : 定义控制台应用程序的入口点。
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

/*有一个单词列表，一个初始单词和一个最终单词，初始单词需要通过单词列表逐步变换到最终单词，求变换所需的最短变换路径长度。
变换规则：每次只能变动1个字母（不可交换位置，如：从abc变成cba属于变动了2个字母），每次变换只能从单词列表中选取。
例如：初始单词hot，最终单词dog，单词列表[got, dot, god, dog, lot, log]，最短变换路径为[hot,dot,dog]，最短变换路径长度为3。
注：单词列表中包含最终单词，不包含初始单词；列表中每一项单词长度与初始单词、最终单词相同；列表中单词不重复；所有字母均为小写。

输入
输入数据有三行，第一行为初始单词；第二行为最终单词；第三行为单词列表，单词和单词之间以空格分割。

输出
最短变换路径长度。


样例输入
hot
dog
got dot god dog lot log

样例输出
3

Hint
寻找最短路径相关算法。*/
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

	

