#include "dsa/HashMap.hpp"

HashMap::HashMap() : table(TABLE_SIZE) {}

int HashMap::hashFunction(const string& key) {
    int hash = 0;
    for (char c : key) hash = (hash * 31 + c) % TABLE_SIZE;
    return hash;
}

void HashMap::insert(const string& key, const string& value) {
    int index = hashFunction(key);

    for (auto& p : table[index]) {
        if (p.key == key) {
            p.value = value;
            return;
        }
    }
    table[index].push_back(Pair(key, value));
}

bool HashMap::find(const string& key, string& value) {
    int index = hashFunction(key);

    for (auto& p : table[index]) {
        if (p.key == key) {
            value = p.value;
            return true;
        }
    }
    return false;
}

void HashMap::remove(const string& key) {
    int index = hashFunction(key);
    table[index].remove_if([&](const Pair& p){ return p.key == key; });
}
