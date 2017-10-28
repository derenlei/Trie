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

int main(){
  vector< vector<string> > sentences;
  string line;
  while (true) {
    getline(cin, line);
    if (line.empty()) { break; }
    // Convert line into vector and add into sentences
    istringstream iss(line);
    vector<string> sentence(istream_iterator<string>{iss},
                  istream_iterator<string>{});
    sentences.push_back(sentence);
    line = "";
  }
  // Build trie
  Trie trie;
  trie.build_trie(sentences);
  // Input prefix
  string prefix;
  cin >> prefix;
  // Convert prefix into vector
  istringstream iss(prefix);
  vector<string> prefixVector(istream_iterator<string>{iss},
                istream_iterator<string>{});
  prefixVector.push_back(prefix);
  // Print result
  trie.printSuffixList(prefixVector);
  trie.printMax();
  return 0;
}
