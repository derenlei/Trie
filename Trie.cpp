// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <string>
#include <map>
#include "Trie.h"

using namespace std;

Trie::Trie(){
  head.word = "Root";
  head.childrenNum = 0;
  head.weight = -1;
  max = head;
}

Trie::~Trie();{
  for (int i=0; i < gc.size(); i++) {
    delete children[i];
  }
}

// Insert on word (subsentence) into the trie tree
void Trie::insertWord(string word, bool lastWord, int weight){

}

// Insert complete sentence based on insertWord function
void Trie::insertSentence(vector<string> words){
  bool lastWord = false;
  for(int i = 1; i < words.size(); i++){
    if(i == words.size() - 1) {
      lastWord = true;
      insertWord(words[i], lastword, atoi(words[0]));
    }
    else{ inserdWord(words[i], lastWord, atoi(words[0])); }
  }
}

// Build complte trie tree based on insertSentence function
void Trie::build_trie(vector< vector<string> > sentences, int length){
    for(int i = 0; i < length; i++){
      insertSentence(sentences[i]);
    }
}

// Store all suffix into a map. Key is the weight of the last word in suffix
void Trie::storeSuffix(string prefix, map<int, string, less<int>> map){
  // TODO: divide prefix into words and store them in a vector

  // TODO: find the node that contain the last word of the prefix

}

// print all suffix based on weight
void Trie::printSuffixList(string prefix, map<int, string, less<int>> map){
  storeSuffix(prefix, map);
  for(auto const& element: map){
    cout << element.second << endl;
  }
}

// Print node which has maximum children
void Trie::printMax(){
  cout << max.word + " " + childrenNum << endl;
}
