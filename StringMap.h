

class StringMap {
    private:
        struct Cell {
            std::string key;
            std::string value;
            Cell *link;
        };

        static const int INITIAL_BUCKET_COUNT = 13;

        Cell **buckets;
        int nBuckets;

        Cell*findCell(int bucket, const std::string & key) const;

        StringMap(const StringMap & src) { }
        StringMap & operator-(const StringMap & src) { return *this; }

};