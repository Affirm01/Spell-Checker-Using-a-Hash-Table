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
    int insertIndex = stringHash(word) % table.size(); // Calculates the index in the hash table

    // Checks for duplicates in the linked list at the calculated index
    for (const string& existingWord : table[insertIndex]) {
        if (existingWord == word) { // Does not insert if word is already in list
            return; // Exits
        }
    }

    table[insertIndex].push_back(word); // Inserts word into linked list
    num_elems++; // Increments the number of total elements in hash table

    // Checks if load factor exceeds the threshold
    if (num_elems >= load_factor * size) {
        resizeTable(); // Resizes table if needed
    }
}

void Stringset::resizeTable() {
    int newSize = size * 2; // Doubles the size of the table
    vector<list<string>> newTable(newSize); // Creates a new table

    // Rehashes all existing elements into the new table
    for (const auto& bucket : table) { // Iterates through the linked list in the hash table
        for (const auto& str : bucket) { // Iterates through the string in the linked list
            int newHashValue = hash<string>()(str) % newSize; // Calculates new hash value 
            newTable[newHashValue].push_back(str); // Inserts into the table
        }
    }

    table.swap(newTable); // Swaps the old table with the new table
    size = newSize; // Sets size to the new size
}

bool Stringset::find(string word) const
{
    hash<string> stringHash;
    int insertIndex = stringHash(word) % table.size(); // Calculates the index in hash table

    // Iterates through the linked list at the calculated index
    for (list<string>::const_iterator it = table[insertIndex].begin(); it != table[insertIndex].end(); ++it) {
        if (*it == word) { // Checks if current word matches the word to find
            return 1; // True when found
        }
    }
    return 0; // False if not found
}

void Stringset::remove(string word)
{
    hash<string> stringHash;
    int insertIndex = stringHash(word) % table.size(); // Calculates index in hash table

    // Iterates through the linked list at the calculated index
    for(list<string>::iterator it = table[insertIndex].begin(); it != table[insertIndex].end(); ++it) {
            if (*it == word) { // Checks if current word is the right word to remove
                it = table[insertIndex].erase(it); // Removes the word
                num_elems--; // -1 number of elements after removing
                return; // Exits after removing
            }
        }
    
}