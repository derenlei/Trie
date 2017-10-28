// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node {
  string word;
  map<string, Node*> children;
  int weight;
  int childrenNum;
};

class Trie {
    public:
      Trie();
      ~Trie();

      void build_trie(vector< vector<string> > sentences);
      // print all suffix based on weight
      void printSuffixList(vector<string> prefix);
      // Print node which has maximum children
      void printMax();

    private:
      Node head;
      Node max;

      // Insert complete sentence based on insertWord function
      void insertSentence(vector<string> words);
      // Store all suffix into a map. Key is the weight of the last word in suffix
      void storeSuffix(bool& contain, vector<string> prefix, map<int, string, less<int> >& sentenceMap);
      void storeSuffixHelper(map<string, Node*> current_tree, map<int, string,
                                          less<int> >& sentenceMap, string& sentence);
      // Used for deleting nodes
      vector<Node*> gc;
};

#endif
