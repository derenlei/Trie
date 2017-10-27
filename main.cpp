#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Trie.h"

using namespace std;

int main(){
  vector< vector<string> > sentences;
  string line;
  while (true) {
    getline(cin, line);
    if (line.empty()) { break; }
    // Convert line into vector and add into sentences
    istringstream iss(line);
    vector<string> sentence{istream_iterator<string>{iss},
                  istream_iterator<string>{}};
    sentences.push_back(sentence);
    line = "";
  }
  // Build trie
  Trie trie = new trie();
  build_trie(sentences);
  // Input prefix
  String prefix;
  cin << prefix;
  // Convert prefix into vector
  istringstream iss(prefix);
  vector<string> prefixVector{istream_iterator<string>{iss},
                istream_iterator<string>{}};
  prefixVector.push_back(prefix);
  // Print result
  printSuffixList(prefixVector);
  printMax();
  return 0;
}
