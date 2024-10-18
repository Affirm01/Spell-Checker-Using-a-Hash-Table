/*
 * Name: Ethan Smith
 * Date Submitted: Oct 21st 2024
 * Lab Section: 003
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

using namespace std;

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    hash<string> stringHash;
    int insertIndex = stringHash(word) % table.size();
    for (const string& existingWord : table[insertIndex]) {
        if (existingWord == word) {
            return;
        }
    }
    table[insertIndex].push_back(word);
    num_elems++;
    if (num_elems == size) {
        size = size * 2;
    }
}

bool Stringset::find(string word) const
{
    hash<string> stringHash;
    int insertIndex = stringHash(word) % table.size();
    for (list<string>::const_iterator it = table[insertIndex].begin(); it != table[insertIndex].end(); ++it) {
        if (*it == word) {
            return 1;
        }
    }
    return 0;
}

void Stringset::remove(string word)
{
    hash<string> stringHash;
    int insertIndex = stringHash(word) % table.size();
    for(list<string>::iterator it = table[insertIndex].begin(); it != table[insertIndex].end(); ++it) {
            if (*it == word) {
                it = table[insertIndex].erase(it);
                num_elems--;
            }
        }
    
}