#pragma once
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashMap {
private:
    static const int TABLE_SIZE = 101;

    struct Pair {
        string key;
        string value;
        Pair(string k, string v) : key(k), value(v) {}
    };

    vector<list<Pair>> table;

    int hashFunction(const string& key);

public:
    HashMap();

    void insert(const string& key, const string& value);
    bool find(const string& key, string& value);
    void remove(const string& key);
};
