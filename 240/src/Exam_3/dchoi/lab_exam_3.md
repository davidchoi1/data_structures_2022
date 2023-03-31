# Lab Exam 3

## Description
The **Trie** data structure, a.k.a., a digital tree or prefix tree, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. This data structure is often used in tandem with others to speed up lookups on keys.

The trie, short for "re**trie**val", was named by its inventor, Edward Fredkin, in 1960. The "k" in "k-ary search tree", represents the size of the alphabet used to create the strings that the structure stores, (k = |$\Sigma$|), the alphabet's cardinality. 

A trie can be used to replace a hash table, over which it has the following advantages:
- Searching for a node with an associated key of size $m$ has the complexity of $O(m)$, whereas an imperfect hash function may have numerous colliding keys, and the worst-case lookup speed of such a table would be $O(N)$, where $N$ denotes the total number of nodes within the table.
- Tries do not need a hash function for the operation, unlike a hash table; there are also no collisions of different keys in a trie.
- Buckets in a trie, which are analogous to hash table buckets that store key collisions, are necessary only if a single key is associated with more than one value.
- String keys within the trie can be sorted using a predetermined alphabetical ordering.

Tries are used for sorting, full-text searches, search engines, bioinformatics, netword routing and more.

## Task
Create a set using a Trie data structure:
	Set ADT
		Insert: inserts a string into the trie
		Delete: removes a string from the node. 
		Contains: returns true is the trie contains the search term or false otherwise. The contanment is based on full-containment, not substrings.

For this program we will assume $\Sigma=\{abcdefghijklmnopqrstuvwxyz\}$ (only lowercase)
$\therefore|\Sigma|=26$

The following classes are provided **and should not be modified**:
- TrieNode: node for the trie structure
- Set: interface for the trie structure
- test program: try_trie.cpp

### Requirements
- Test the trie thoroughly.
- *Your project must compile to get a score.*
- Be sure to include your name in the test program.
- the Trie should be implemented in separate header and cpp files since it only takes strings.




```
CSCI 240                        © Prof. Dominick Atanasio                      Mt Sac
```

