#include <iostream>
#include <list>
using namespace std;

// Class representing a key-value pair
class KeyValuePair {
public:
    int key;
    string value;

    KeyValuePair(int k, string v) {
        key = k;
        value = v;
    }
};

// Class representing a Hash Table
class HashTable {
private:
    int tableSize; // Size of the hash table
    list<KeyValuePair>* table; // Array of linked lists

public:
    // Constructor
    HashTable(int size) {
        tableSize = size;
        table = new list<KeyValuePair>[tableSize];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Hash function to compute the index for a given key
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert a key-value pair into the dictionary
    void Insert(int key, string value) {
        int index = hashFunction(key);
        KeyValuePair kvp(key, value);

        // Search for existing key in the linked list at the computed index
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                // Key already exists, update the value
                it->value = value;
                return;
            }
        }

        // Key not found, insert a new key-value pair at the end of the linked list
        table[index].push_back(kvp);
    }

    // Find the value associated with a given key
    string Find(int key) {
        int index = hashFunction(key);

        // Search for the key in the linked list at the computed index
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                // Key found, return the corresponding value
                return it->value;
            }
        }

        // Key not found
        return "Key not found";
    }

    // Delete a key-value pair from the dictionary
    void Delete(int key) {
        int index = hashFunction(key);

        // Search for the key in the linked list at the computed index
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                // Key found, erase the key-value pair
                table[index].erase(it);
                return;
            }
        }

        // Key not found, do nothing
    }
};

int main() {
    // Create a HashTable with a size of 10
    HashTable dictionary(10);

    // Insert key-value pairs
    dictionary.Insert(1, "Apple");
    dictionary.Insert(2, "Banana");
    dictionary.Insert(3, "Orange");

    // Find values using keys
    cout << dictionary.Find(2) << endl; // Output: Banana
    cout << dictionary.Find(4) << endl; // Output: Key not found

    // Delete a key-value pair
    dictionary.Delete(1);

    // Find the deleted key
    cout << dictionary.Find(1) << endl; // Output: Key not found

    return 0;
}
