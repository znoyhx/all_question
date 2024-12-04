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
	getline(cin, article);    // 读取文章

	// 转为小写，进行大小写不敏感的匹配
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	transform(article.begin(), article.end(), article.begin(), ::tolower);

	int count = 0;
	int firstPos = -1;
	int pos = 0;              // 记录文章遍历的字符位置

	for (size_t i = 0; i <= article.size() - word.size(); i++) {
		// 判断前后是否是单词边界
		if ((i == 0 || article[i - 1] == ' ') &&
			(i + word.size() == article.size() || article[i + word.size()] == ' ')) {
			// 检查当前子串是否与目标单词匹配
			if (article.substr(i, word.size()) == word) {
				count++;
				if (firstPos == -1) {
					firstPos = i;
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