#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <locale>
using namespace std;

/*
 *		The Boyer-Moore algorithm executes in O(n+m) where n is the size of the text and m is the size
 *	of the pattern that we want to find the text.
 * */

// Return the positions where the match happens
vector<int> BoyerMoore(string str, string pattern)
{
	vector<int> posicoes;
	int u[256], i, j, k;

	if(str.size() < pattern.size()) return posicoes;

	for(i = 0; i < 256; i++) u[i] = 0;
	for(i = 0; i < pattern.size(); i++) u[(int)pattern[i]] = i;
	k = pattern.size()-1;
	

	while(k < str.size())
	{
		i = pattern.size()-1, j = k;

		while(i >= 0 && str[j] == pattern[i]) i--, j--;
		
		// I make an push_back in the resulting vector os positions if i < 0.
		// The case which i < 0 means that all characters of the pattern matched with a part of the text.
		if(i < 0) posicoes.push_back(k-pattern.size()+1);
		if(k == str.size()-1) break;

		k += pattern.size() - u[(int)str[k+1]];
	}

	return posicoes;
}

int main()
{
	vector<int> result = BoyerMoore("abracadabra", "abra");

	for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
		cout << "Match at position " << *it << endl;
	
	return 0;
}
