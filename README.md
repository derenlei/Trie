# Trie
A simple implementation of Trie in CPP  

### Short Description:  
**Build**: Read in a bunch of sentences, prefixed by a weigtht and separated by newlines.  
**Search**: For any given prefix phrase, list all possible completions of that phrase sorted by weight.  

### Example input/output:  
If the input looked like (note the empty line):  
2 The man ate  
5 The man SITS  
1 the cat ate  
777 This doesn't over lap  

The  

The code will return  
man SITS  
man ate  
cat ate  
man 2  
