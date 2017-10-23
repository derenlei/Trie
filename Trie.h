// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

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

      void build_trie(vector< vector<string> > sentences, int length);
      // print all suffix based on weight
      void printSuffixList(string prefix, map<int, string, less<int>> map);
      // Print node which has maximum children
      void printMax();

    private:
      Node head;
      Node max;

      // Insert complete sentence based on insertWord function
      void insertSentence(vector<string> words);
      // Store all suffix into a map. Key is the weight of the last word in suffix
      void storeSuffix(bool contain, string prefix, map<int, string, less<int>> map);
      // Used for deleting nodes
      vector<Node*> gc;
};

#endif
