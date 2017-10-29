// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include "Trie.h"

using namespace std;

Trie::Trie(){
  head.word = "Root";
  head.childrenNum = -1;
  head.weight = -1;
  max = &head;
}

Trie::~Trie(){
  for (int i=0; i < gc.size(); i++) {
    delete gc[i];
  }
}

// Insert complete sentence based on insertWord function
void Trie::insertSentence(vector<string> words){

  map<string, Node*> *current_tree = &head.children;
  Node* currentParent = &head;
  map<string, Node*>::iterator it;

  for(int i = 1; i < words.size(); i++){
    string word = words[i];

    if((it = current_tree->find(word)) != current_tree->end()){
      current_tree = &it->second->children;
      currentParent = it->second;
      continue;
    }

    if(it == current_tree->end()){
      // Create a new node for Trie
      Node* newNode = new Node();
      newNode->word = word;
      newNode->childrenNum = 0;
      if(i == words.size() - 1) { newNode->weight = atoi(words[0].c_str()); }
      else { newNode->weight = -1; }

      // Add 1 to childrenNum of parent node except head
      currentParent->childrenNum += 1;
      head.childrenNum = -1;
      // Check Max
      if(max->childrenNum == -1) {max = newNode; }
      else if(max->childrenNum < currentParent->childrenNum) { max = currentParent; }

      (*current_tree)[word] = newNode;
      current_tree = &newNode->children;
      gc.push_back(newNode);
    }
  }


}

// Build complte trie tree based on insertSentence function
void Trie::build_trie(vector< vector<string> > sentences){
    for(int i = 0; i < sentences.size(); i++){
      insertSentence(sentences[i]);
    }
}

// Store to map starts from current_tree and store in map
void Trie::storeSuffixHelper(map<string, Node*> current_tree,
  map<int, string, greater<int> >& sentenceMap, string& sentence){
  //cout << "The numebr of prefix found is " << current_tree.size() << endl;
  if(current_tree.empty()) { return; }
  for(map<string, Node*>::iterator it = current_tree.begin(); it != current_tree.end(); it++){
    //cout << it->second->word << endl;
    // Case 1: last node
    if(it->second->children.empty()){
      sentence += it->first;
      sentenceMap[it->second->weight] = sentence;
      //cout << "suffix:" << sentence << endl;
      sentence = "";
    }
    // case 2: not last node but is the end of one sentence
    else if(it->second->weight != -1){
      sentence += it->first;
      sentenceMap[it->second->weight] = sentence;
    }
    // case 3: not end of one sentence
    else {
      sentence = sentence + it->first  + " ";
      storeSuffixHelper(it->second->children, sentenceMap, sentence);
    }
  }

}

// Store all suffix into a map. Key is the weight of the last word in suffix
void Trie::storeSuffix(bool& contain, vector<string> prefix, map<int, string, greater<int> >& sentenceMap){
  // Find the node that contain the last word of the prefix
  map<string, Node*> current_tree = head.children;
  map<string, Node*>::iterator it;
  for(int i = 0; i < prefix.size(); i++){
    string word = prefix[i];
    if((it = current_tree.find(word)) == current_tree.end()){
      cout << "No Valid completion" << endl;
      contain = false;
      return;
    }
    current_tree = it->second->children;
  }
  // Store suffix into sentenceMap
  string sentence = "";
  storeSuffixHelper(current_tree, sentenceMap, sentence);
}

// print all suffix based on weight
void Trie::printSuffixList(vector<string> prefix){
  map<int, string, greater<int> > sentenceMap;
  bool contain = true;
  storeSuffix(contain, prefix, sentenceMap);
  if(contain){
    for(map<int, string, greater<int> >::iterator it = sentenceMap.begin(); it != sentenceMap.end(); it++){
      cout << it->second << endl;
    }
  }
}

// Print node which has maximum children
void Trie::printMax(){
  cout << max->word + " " << max->children.size() << endl;
}
