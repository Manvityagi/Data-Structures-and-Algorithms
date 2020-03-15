static bool sortByVal(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

vector<pair<int, int>> vec;

// copy key-value pairs from the map to the vector
map<int, int>::iterator it2;
for (it2 = mp.begin(); it2 != mp.end(); it2++)
{
    vec.push_back(make_pair(it2->first, it2->second));
}

// // sort the vector by increasing order of its pair's second value
sort(vec.begin(), vec.end(), sortByVal);