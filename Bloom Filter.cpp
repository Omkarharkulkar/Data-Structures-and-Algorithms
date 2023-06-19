#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BloomFilter 
{
private:
    vector<bool> filter;  // Bit vector for storing filter data
    size_t size;               // Size of the filter
    size_t numHashes;          // Number of hash functions

    size_t hash1(const string& value) const 
	{
        size_t hash = 0;
        for (size_t i = 0; i < value.length(); ++i) 
		{
            hash = 31 * hash + value[i];
        }
        return hash % size;
    }

    size_t hash2(const string& value) const 
	{
        size_t hash = 5381;
        for (size_t i = 0; i < value.length(); ++i) 
		{
            hash = ((hash << 5) + hash) + value[i];
        }
        return hash % size;
    }

public:
    BloomFilter(size_t filterSize, size_t numHashFunctions)
	    : size(filterSize), numHashes(numHashFunctions), filter(filterSize, false) {}

    void insert(const std::string& value) 
	{
        for (size_t i = 0; i < numHashes; ++i) 
		{
            size_t index = (hash1(value) + i * hash2(value)) % size;
            filter[index] = true;
        }
    }

    bool contains(const string& value) const 
	{
        for (size_t i = 0; i < numHashes; ++i) 
		{
            size_t index = (hash1(value) + i * hash2(value)) % size;
            if (!filter[index])
                return false;
        }
        return true;
    }
};

int main() 
{
    size_t filterSize, numHashFunctions;
    
    filterSize = 1000;
    numHashFunctions = 2;
    
    BloomFilter bloomFilter(filterSize, numHashFunctions);

    cout << "Enter values to insert (type 'done' to stop):\n";
    string value;
    while (true) 
	{
        cin >> value;
        if (value == "done")
            break;
        bloomFilter.insert(value);
    }

    cout << "Enter values to check (type 'done' to stop):\n";
    while (true) 
	{
        cin >> value;
        if (value == "done")
            break;
        cout << "Contains " << value << "? " << (bloomFilter.contains(value) ? "Yes" : "No") << std::endl;
    }

    return 0;
}

