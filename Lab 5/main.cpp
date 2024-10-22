/*
 * Name: Ethan Smith
 * Date Submitted: Oct 21st 2024
 * Lab Section: 003
 * Assignment Name: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>

 using namespace std;
 
//  void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
//  int main()
//  {
//     Stringset wordlist;
//     testStringset(wordlist);
//     return 0;
//  }
 
//  void testStringset(Stringset& words)
//  {
//      string choice;
//      string word;
//      do
//      {
//          cout << "I: insert word" << endl;
//          cout << "F: find word" << endl;
//          cout << "R: remove word" << endl;
//          cout << "P: print words in stringset" << endl;
//          cout << "Q: quit" << endl;
//          cin >> choice;
//          switch (choice[0])
//          {
//              case 'I':
//              case 'i':
//                 cout << "Enter word to insert: ";
//                 cin >> word;
//                 words.insert(word);
//                 break;
//              case 'F':
//              case 'f':
//                 cout << "Enter word to find: ";
//                 cin >> word;
//                 if (words.find(word))
//                 {
//                     cout << word << " in stringset" << endl;
//                 }
//                 else
//                 {
//                     cout << word << " not in stringset" << endl;
//                 }
//                 break;
//              case 'R':
//              case 'r':
//                 cout << "Enter word to remove: ";
//                 cin >> word;
//                 words.remove(word);
//                 break;
//              case 'P':
//              case 'p':
//                 vector<list<string>> t = words.getTable();
//                 int numWords = words.getNumElems();
//                 int tSize = words.getSize();
//                 for(int i=0; i<tSize; ++i)
//                 {
//                     list<string>::iterator pos;
//                     for (pos = t[i].begin(); pos != t[i].end(); ++pos)
//                     {
//                         cout << *pos << endl;
//                     }
//                 }
//                 cout << "Words: " << numWords << endl;
//          }
//      } while (choice[0] != 'Q' && choice[0] != 'q');
//  }
 
 void loadStringset(Stringset& words, string filename)
 {
    string word;
    ifstream File(filename); // Opens and reads file

    if (!File) { // If file does not exist
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // int count = 0;
    while (getline(File, word)) { // Inserts each line of words into words stringset
        words.insert(word);
        // count++;
        // if (count % 10000 == 0) {
        //     cout << count << " words loaded so far." << endl;
        // }
    }
    // cout << "Total words loaded: " << count << endl;
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
    vector<string> alternatives;

    
    for (int i = 0; i < word.length(); i++) { // Iterates over each character position in the word
        char originalChar = word[i];

        for (char c = 'a'; c <= 'z'; c++) { // Tries replacing it with every other character in the alphabet
            if (c != originalChar) {
                // Creates a potential alternative word
                word[i] = c;

                // Checks if the alternative word is in the dictionary
                if (words.find(word)) {
                    alternatives.push_back(word);
                }
            }
        }

        // Restores the original character
        word[i] = originalChar;
    }

    return alternatives;
 }