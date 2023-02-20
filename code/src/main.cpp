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
    
    // now use the function call distr(gen) whenever you need a new randon number
    // for example:
    int rNum1 = distr(gen);
    int rNum2 = distr(gen);
    // these will be two different random numbers
    // add many distr(gen) numbers to a vector
}



using MapInt = std::map<int, size_t>;


// consider using range-based loops for printing
void printVec(const VecInt& vecInt);



void printMap(const MapInt& mapInt)
{
    int t = 1;
    for(MapInt::const_iterator it = mapInt.begin(); it != mapInt.end(); std::advance(it, t))
    {
        cout << "Key is " << it->first;
        cout << " Value is " << it->second << endl;

        for (int i = 0; i < t; ++i)
        {
            ++it;
        }
    }

    for(const std::pair<const int, size_t>& kv_pair: mapInt)
    {
        cout << "Key is " << kv_pair.first;
        cout << " Value is " << kv_pair.second << endl;
    }
}


MapInt makeMap(const VecInt& v)
{
    MapInt mapInt;
    for(int item: v)
    {
        if (mapInt.count(item) != 0) // item is in map
            ++mapInt[item];
        else
            mapInt[item] = 1;
    }
    return mapInt;
}


bool query(const std::map<int, size_t>& m, int k, size_t& element)
{
    k = 1000;
}


int main()
{
    cout << "Enter three integers: n, r, q\n";
    int n;
    int r;
    int q;
    //        4    10   1000
    // cin >> n >> r >> q;
    //  18 200 494 900



    // VecInt v = generateVector(n, r, q);
    // 1 2 3 2 1 2 1 2 2 3 1 

    // MapInt m = makeMap(v)

    //{
    //    1: 4,
    //    2: 5,
    //    3: 2
    //}
    MapInt m;
    m[18] = 1;
    m[200] = 1;
    printMap(m);
    // cout << m[0] << endl;


    bool success;
    size_t value18 = 0;
    int k = 18;
    success = query(m, k, value18);

    // success = true
    // value18 = 1
    // k = 18


    return 0;
}
