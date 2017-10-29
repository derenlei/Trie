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

vector<string> strToVec(string sentence){
  vector<string> vec;
  string element = "";
  for(int i=0; i < sentence.length(); i++){
    if(sentence[i] == ' '){
      vec.push_back(element);
      element = "";
    }
    else if (i == sentence.length() - 1){
      element += sentence[i];
      vec.push_back(element);
    }
    else{
      element += sentence[i];
    }
  }
  return vec;
}

int main(){

  Trie trie;
  vector< vector<string> > sentences;
  string line;
  while (true) {
    getline(cin, line);
    if (line.empty()) { break; }
    // Convert line into vector and add into sentences
    vector<string> sentence = strToVec(line);
    sentences.push_back(sentence);
    line = "";
  }

  // Build trie
  trie.build_trie(sentences);

  // Input prefix
  string prefix;
  getline(cin, prefix);

  // Convert prefix into vector
  vector<string> prefixVector = strToVec(prefix);
  // Print result
  trie.printSuffixList(prefixVector);
  trie.printMax();
  return 0;
}
