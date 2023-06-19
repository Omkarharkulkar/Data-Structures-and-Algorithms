#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_KICKS = 500;  // Maximum number of evictions allowed during insertion

class CuckooFilter 
{
private:
    vector<string> table;  // Cuckoo filter table
    size_t size;                     // Size of the table

    size_t hash(const std::string& value, size_t seed) const 
	{
        size_t hash = seed;
        for (size_t i = 0; i < value.length(); ++i) 
		{
            hash = hash * 31 + value[i];
        }
        return hash % size;
    }

    size_t altHash(size_t index, const string& value) const 
	{
        size_t seed = index % 2 == 0 ? 17 : 31;
        return hash(value, seed);
    }

public:
    CuckooFilter(size_t tableSize) : size(tableSize) 
	{
        table.resize(size);
    }

    bool insert(const std::string& value) 
	{
        if (contains(value))
            return true;

        size_t index1 = hash(value, 0);
        size_t index2 = altHash(index1, value);

        if (table[index1].empty()) 
		{
            table[index1] = value;
            return true;
        }
        if (table[index2].empty()) 
		{
            table[index2] = value;
            return true;
        }

        size_t index = index1;
        for (int i = 0; i < MAX_KICKS; ++i) 
		{
            size_t altIndex = altHash(index, table[index]);
            swap(table[index], table[altIndex]);
            
            if (table[altIndex].empty()) 
			{
                table[altIndex] = value;
                return true;
            }
            index = altIndex;
        }

        return false;  // Maximum evictions reached, insert failed
    }

    bool contains(const string& value) const 
	{
        size_t index1 = hash(value, 0);
        size_t index2 = altHash(index1, value);
        return table[index1] == value || table[index2] == value;
    }
};

int main() 
{
    srand(static_cast<unsigned>(time(NULL)));

    size_t tableSize;

    cout << "Enter Cuckoo filter table size: ";
    cin >> tableSize;

    CuckooFilter cuckooFilter(tableSize);

    cout << "Enter values to insert (type 'done' to stop):\n";
    string value;
    while (true) 
	{
        cin >> value;
        if (value == "done")
            break;
        cuckooFilter.insert(value);
    }

    cout << "Enter values to check (type 'done' to stop):\n";
    while (true) 
	{
        cin >> value;
        if (value == "done")
            break;
        cout << "Contains " << value << "? " << (cuckooFilter.contains(value) ? "Yes" : "No") << std::endl;
    }

    return 0;
}

