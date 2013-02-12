#include "main.h"
#include <cassert>

int main()
{
	assert(unique1(""));
	assert(unique1("a"));
	assert(!unique1("aa"));
	assert(unique1("asdfjkl;"));
	assert(!unique1("asdfjkl;a"));
	assert(unique2(""));
	assert(unique2("a"));
	assert(!unique2("aa"));
	assert(unique2("asdfjkl;"));
	assert(!unique2("asdfjkl;a"));
	char s[][10] = {"", "abc", "abcd"};
	char r[][10] = {"", "cba", "dcba"};
	for (int i = 0; i < 3; i++) {
		reverse(s[i]);
		assert(strcmp(s[i], r[i]) == 0);
	}
	assert(is_permutation("abcd", "dcba"));
	assert(!is_permutation("abcd", "ddcba"));
}
