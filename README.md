# Spell Checker Using a Hash Table  
  
## Overview
This project is a simple spell checker that utilizes a hash table to store words efficiently. The hash table structure allows quick insertions, deletions, and searches of words. Additionally, it includes a spellcheck function to suggest alternatives for misspelled words.  

## Implementation  
- **Hash Table**: The 'Stringset' class implemetns a hash table of vectors of linked lists to handle collisions. A load factor threshold of 0.7 triggers resizing to maintain efficiency.  
  
- **Functions**:
  - `insert(string word)`: Adds a word to the hash table.
  - `find(string word)`: Checks if a word exists in the hash table.
  - `remove(string word)`: Removes a word from the hash table.
  - `resizeTable()`: Doubles the table size when the load factor is exceeded.
  - `spellcheck(const Stringset& words, string word)`: Finds alternative spellings that differ by one character.
- **loadStringset(Stringset& words, string filename)**: Loads a word list from a file.

## Usage
To use this program, call the `loadStringset()` function to populate the hash table, then use `insert`, `find`, and `remove` to manage words or `spellcheck` for alternative suggestions.

## Files
- **stringset.h**: Defines the `Stringset` class and its members.
- **stringset.cpp**: Implements the methods for word management and resizing.
- **main.cpp** (test file): Provides sample tests for inserting, finding, and removing words.

## Author
- **Name**: Ethan Smith
- **Date Submitted**: October 21, 2024
- **Lab Section**: 003
