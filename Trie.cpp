// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <string>
#include <map>

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
      
      // Insert on word (subsentence) into the trie tree
      void insertWord(string word);
      // Insert complete sentence based on insertWord function
      void insertSentence(vector<string> words);
      // Build complte trie tree based on insertSentence function
      void build_trie(vector< vector<string> > words, int length);

      // Store all suffix into a map. Key is the weight of the last word in suffix
      void storeSuffix(string prefix, map<int, string> map);
      // print all suffix based on weight
      void printSuffixList();

      // Print node which has maximum children
      void printMax();
      
    private:
      Node head;
      Node max;
      // Used for deleting nodes
      vector<Node*> gc;
};
