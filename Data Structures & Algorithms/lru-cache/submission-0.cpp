#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Stores {key, value}, from most recently used to least recently used
    list<pair<int, int>> cache;

    // Maps key -> position in the list
    unordered_map<int, list<pair<int, int>>::iterator> positions;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // find() returns an iterator, not a boolean
        auto it = positions.find(key);

        if (it == positions.end()) {
            return -1;
        }

        // Move this entry to the front because it was just used
        cache.splice(cache.begin(), cache, it->second);

        return it->second->second; // iterator->second is the value
    }

    void put(int key, int value) {
        auto it = positions.find(key);

        if (it != positions.end()) {
            // Key already exists: update its value
            it->second->second = value;

            // Move it to the front because it was just used
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        // Add new key-value pair to the front
        cache.push_front({key, value});
        positions[key] = cache.begin();

        // Remove least recently used item if over capacity
        if (cache.size() > capacity) {
            auto leastRecentlyUsed = cache.back();
            positions.erase(leastRecentlyUsed.first);
            cache.pop_back();
        }
    }
};