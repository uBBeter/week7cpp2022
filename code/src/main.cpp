#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <set>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


typedef std::vector<int> VecInt;

using MapInt = std::map<int, size_t>;
using MultiMapInt = std::multimap<int, size_t>;

// Generating random numbers:


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);
    
    // now use the function call distr(gen) whenever you need a new random number
    // for example:
    // int rNum1 = distr(gen);
    // int rNum2 = distr(gen);

    VecInt v;

    for (size_t i = 0; i < n; ++i)
    {
            v.push_back(distr(gen));
    }
    return v;
    // these will be two different random numbers
    // add many distr(gen) numbers to a vector
}


// consider using range-based loops for printing
void printVec(const VecInt& vecInt)
{
    for (int x: vecInt)
    {
        cout << x << endl;
    }
}

using MapInt = std::map<int, size_t>;

MapInt makeMap(const VecInt& v)
{
    MapInt mapInt;
    for (int item: v)
    {
        if (mapInt.count(item) != 0) // element in map
        {
            ++mapInt[item];
        }
        else
        {
            mapInt[item] = 1;
            mapInt.insert({item, 1});
            mapInt.insert(std::pair<int, size_t>(item, 1));
        }
    }
    return mapInt;
}

bool query(const MapInt& mapInt, int key, size_t& value)
{
    if (mapInt.count(key))
    {
        value = mapInt.at(key);
        return true;
    }
    return false;
}

std::map<int, bool> makeMapBool(const MapInt& m, int r, int q)
{
    std::map<int, bool> mapBool;
    size_t value;
    for (int i = r; i < q; ++i)
    {
        bool queryResult = query(m, i, value);
        mapBool[i] = queryResult;
        mapBool.insert({i, queryResult});
    }
    return mapBool;
}


std::set<int> makeSet(const MapInt& m, int r, int q)
{
    std::set<int> setInt;
    size_t value;
    for (int i = r; i < q; ++i)
    {
        bool queryResult = query(m, i, value);
        if (queryResult)
        {
            setInt.insert(i);
        }
    }
    return setInt;
}


MultiMapInt makeMultiMap(const VecInt& v)
{
    MultiMapInt mapInt;

    for (size_t i = 0; i < v.size(); ++i)
    {
        mapInt.insert({v[i], i});
    }
    return mapInt;
}


void printMultiMap(const MultiMapInt& mapInt)
{
    for (const std::pair<const int, size_t>& item: mapInt)
    {
        cout << "Element " << item.first << " appears " << item.second << std::endl;
    }
}


void printRange(std::multimap<int, size_t> mm, int start, int end)
{
    MultiMapInt::const_iterator itBegin = mm.lower_bound(start);
    MultiMapInt::const_iterator itEnd = mm.upper_bound(end);
    for (MultiMapInt::const_iterator it = itBegin; it != itEnd; ++it)
    {
        cout << "Element " << it->first << " appears " << it->second << std::endl;
    }
}


void printMultiMap(const MultiMapInt& mapInt)
{
    for (const std::pair<const int, size_t>& item: mapInt)
    {
        cout << "Element " << item.first << " appears " << item.second << std::endl;
    }
}


void printMapBool(const std::map<int, bool>& mapBool)
{
    for (const std::pair<const int, bool>& item: mapBool)
    {
        cout << "Element " << item.first << " value: " << item.second << std::endl;
    }
}

void printMap(const MapInt& mapInt)
{
    for (const std::pair<const int, size_t>& item: mapInt)
    {
        // cout << item.first;
        cout << "Element " << item.first << " appears " << item.second << std::endl;
        // item.second;
    }
    for (MapInt::const_iterator it = mapInt.begin(); it != mapInt.end(); ++it)
    {
        it->first;
    }
}
// Element 1 appears 10 times
// 2: 4
// 6: 1

void addNumberToValues(MapInt& m, int number)
{
    // for (std::pair<const int, size_t>& item: m)
    // {
    //     item.first += number;
    // }
    // for (MapInt::iterator it = m.begin(); it != m.end(); ++it)
    // {
    //     it->first += number;
    // }
    // for
    // {
        // value += number
    // }

}

// A function that modifies the map by adding a given number to all values of the map.
// Is this possible for keys?

int main()
{
    cout << "Enter three integers: n, r, q\n";
    int n;
    int r;
    int q;

    cin >> n >> r >> q;

    VecInt vecInt = generateVector(n, r, q);

    printVec(vecInt);
    
    MapInt mapInt = makeMap(vecInt);
    printMap(mapInt); 

    // removeNegative(mapInt);
    addNumberToValues(mapInt, 10);
    printMap(mapInt); 

    std::map<int, bool> mapBool = makeMapBool(mapInt, r, q);

    printMapBool(mapBool);

    // int k = 5;
    // std::pair<bool, size_t> outPair = query(mapInt, k);



    return 0;
}
