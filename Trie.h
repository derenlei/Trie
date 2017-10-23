// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <map>

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
      // Insert on word (subsentence) into the trie tree
      void insertWord(string word, bool lastWord, int weight);
      // Insert complete sentence based on insertWord function
      void insertSentence(vector<string> words);
      // Store all suffix into a map. Key is the weight of the last word in suffix
      void storeSuffix(string prefix, map<int, string, less<int>> map);
      // Used for deleting nodes
      vector<Node*> gc;
};

#endif
