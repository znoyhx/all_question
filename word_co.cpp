//
// Created by a on 24-12-4.
//

#include "word_co.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
	string word, article;
	getline(cin, word);       // 读取单词
	//用getline可以将空格也读进去，单纯的cin无法读取空格
	getline(cin, article);    // 读取文章

	// 转为小写，进行大小写不敏感的匹配
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	transform(article.begin(), article.end(), article.begin(), ::tolower);
	//transform前两个参数是要进行处理的字符串的输入输出迭代器，第三个参数是要结果的迭代器，最后一个参数是转换函数，会将
	//会将前面的word迭代器范围内的字符串都进行函数操作并通过第三个参数的迭代器输出到结果迭代器，在这里还是word本身

	int count = 0;
	int firstPos = -1;
	int pos = 0;              // 记录文章遍历的字符位置

	for (size_t i = 0; i <= article.size() - word.size(); i++) {
		// 判断前后是否是单词边界，防止标点符号干扰
		// 这里的判断条件是，如果当前字符是单词的第一个字符，或者当前字符和前一个字符是空格，
		// 并且当前字符和后一个字符是空格，则认为当前子串是单词边界
		if ((i == 0 || article[i - 1] == ' ') &&
			(i + word.size() == article.size() || article[i + word.size()] == ' ')) {
			// 检查当前子串是否与目标单词匹配
			if (article.substr(i, word.size()) == word)//相当于利用大小和提取的快速判断，而不用find，因为对于find来说
				//需要不断的去寻找字符串，而且find只能找第一次出现，需要不断更新起始位置去找多次，不如一遍遍去遍历
			{
				count++;
				if (firstPos == -1) {
					firstPos = i;//很巧妙的方法去记录第一次出现的位置，利用条件的唯一性可以记录第一次
				}
			}
		}
	}

	if (count > 0) {
		cout << count << " " << firstPos << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}