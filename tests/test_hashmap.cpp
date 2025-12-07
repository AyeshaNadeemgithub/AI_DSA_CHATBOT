#include <iostream>
#include "../include/dsa/HashMap.hpp"

using namespace std;

int main() {

    HashMap map;

    cout << "---- TESTING HASHMAP ----" << endl;

    // INSERT TEST
    map.insert("name", "Alice");
    map.insert("city", "Karachi");
    map.insert("lang", "C++");

    cout << "Inserted 3 key-value pairs." << endl;

    // FIND TEST
    string value;

    if (map.find("name", value))
        cout << "Found 'name': " << value << endl;
    else
        cout << "Key 'name' not found!" << endl;

    if (map.find("city", value))
        cout << "Found 'city': " << value << endl;
    else
        cout << "Key 'city' not found!" << endl;

    if (!map.find("unknown", value))
        cout << "'unknown' correctly reported as not found." << endl;

    // REMOVE TEST
    map.remove("city");
    cout << "Removed key 'city'." << endl;

    if (!map.find("city", value))
        cout << "Confirmed: 'city' no longer exists." << endl;

    cout << "---- HASHMAP TEST COMPLETE ----" << endl;

    return 0;
}
