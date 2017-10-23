// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <string>
#include <map>
#include <vector>
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

// Insert complete sentence based on insertWord function
void Trie::insertSentence(vector<string> words){

  map<string, Node*> *current_tree = &head.children;
  Node* currentParent = head;
  map<string, Node*>::iterator it;

  for(int i = 1; i < words.size(); i++){
    string word = words[i];

    if((it = current_tree->find(word)) != current_tree->end()){
      current_tree = &it->second->children;
      currentParent = &it->second;
      continue;
    }

    if(it == current_tree->end()){
      // Create a new node for Trie
      Node* newNode = new Node();
      newNode->word = word;
      newNode->childrenNum = 0;
      if(i == words.size() - 1) { newNode->weight = atoi(words[0]); }
      else { newNode->weight = -1; }

      // Add 1 to childrenNum of parent node
      currentParent->childrenNum += 1;
      // Check Max
      if(max.childrenNum < currentParent->childrenNum) { max = currentParent; }

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

// TODO
void Trie::storeSuffixHelper(map<string, Node*> current_tree, map<int, string, less<int>> map){
  if(current_tree.empty()) { return; }
  String sentence = "";
  for(map<string, Node*>::iterator it = current_tree.begin(); it != current_tree.end(); it++){
    sentence = sentence + it->first  + " ";
    storeSuffixHelper(it->second->children, map);
  }

}

// Store all suffix into a map. Key is the weight of the last word in suffix
void Trie::storeSuffix(bool contain, vector<string> prefix, map<int, string, less<int>> map){
  // Find the node that contain the last word of the prefix
  map<string, Node*> current_tree = head.children;
  map<string, Node*>::iterator it;
  for(int i = 0; i < words.size(); i++){
    string word = words[i];
    if((it = current_tree.find(word)) == current_tree.end()){
      cout << "No Valid completion" << endl;
      contain = false;
      return;
    }
    current_tree = it->second->children;
  }

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
