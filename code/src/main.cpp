#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


typedef std::vector<int> VecInt;

using MapInt = std::map<int, size_t>;

// Generating random numbers:


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);
    
    // now use the function call distr(gen) whenever you need a new random number
    // for example:
    // int rNum1 = distr(gen);
    int rNum2 = distr(gen);

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
    for (std::pair<const int, size_t>& item: m)
    {
        item.first += number;
    }
    for (MapInt::iterator it = m.begin(); it != m.end(); ++it)
    {
        it->first += number;
    }
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

    size_t el;

    // bool result = query(mapInt, 5, el);

    int k = 5;
    // std::pair<bool, size_t> outPair = query(mapInt, k);



    return 0;
}
