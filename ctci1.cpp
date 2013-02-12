#include "main.h"
#include <algorithm>
#include <cstring>

bool unique1(std::string s)
{
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			if (s[i] == s[j])
				return false;
	return true;
}

bool unique2(std::string s)
{
	bool b[256];
	for (int i = 0; i < 255; i++)
		b[i] = false;
	for (int i = 0; i < s.size(); i++) {
		if (b[s[i]])
			return false;
		else
			b[s[i]] = true;
	}
	return true;
}

void reverse(char* s)
{
	int len = strlen(s);
	for (int i = 0; i < len/2; i++)
		std::swap(s[i], s[len-1-i]);
}

bool is_permutation(std::string s1, std::string s2)
{
	if (s1.size() != s2.size())
		return false;
	int a1[256];
	int a2[256];
	for (int i = 0; i < 255; i++) {
		a1[i] = 0;
		a2[i] = 0;
	}
	for (int i = 0; i < s1.size(); i++) {
		a1[s1[i]]++;
		a2[s2[i]]++;
	}
	for (int i = 0; i < 255; i++)
		if (a1[i] != a2[i])
			return false;	
	return true;
}
