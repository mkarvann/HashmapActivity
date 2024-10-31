template <typename KeyType, typename ValueType>
class HashMap 
{
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


}