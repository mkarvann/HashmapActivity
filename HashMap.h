
template <typename KeyType, typename ValueType>
class HashMap {
private:
    struct Cell {
        KeyType key;
        ValueType value;
        Cell* link;

        Cell(KeyType k, ValueType v) : key(k), value(v), link(nullptr) {}
    };

    Cell** buckets;
    int nBuckets;
    int size;

    int hashCode(const KeyType& key) const {
        return std::hash<KeyType>()(key) % nBuckets;
    }

public:
    HashMap(int bucketsCount) : nBuckets(bucketsCount), size(0) {
        buckets = new Cell*[nBuckets] {};
    }

    ~HashMap() {
        clear();
        delete[] buckets;
    }

    void clear() {
        for (int i = 0; i < nBuckets; ++i) {
            Cell* current = buckets[i];
            while (current) {
                Cell* temp = current;
                current = current->link;
                delete temp;
            }
            buckets[i] = nullptr;
        }
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    bool containsKey(const KeyType& key) const {
        int index = hashCode(key);
        Cell* current = buckets[index];
        while (current) {
            if (current->key == key) {
                return true;
            }
            current = current->link;
        }
        return false;
    }

    void remove(const KeyType& key) {
        int index = hashCode(key);
        Cell* current = buckets[index];
        Cell* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->link = current->link;
                } else {
                    buckets[index] = current->link;
                }
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->link;
        }
    }
};
