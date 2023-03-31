// who: Dong Choi
// what: Tests a trie set implementation
// why:  Lab exam 3
// when: 2022-11-15

#include <iostream>


#include "trie.h"

int main(int argc, char const *argv[])
{
	Trie trie;


	std::cout << trie.insert("schwifty") << std::endl;
	std::cout << trie.contains("scwifty") << std::endl;
	return 0;
}