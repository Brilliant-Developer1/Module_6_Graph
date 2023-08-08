// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
// vector<int> adj[N]; // unweited er jonno
vector<pair<int, int>> adj[N]; // weited er jonno
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // directed hole only nicer first line
        // adj[u].push_back(v); // unweited hole
        adj[u].push_back({v, w}); // weited hole

        // undirected hole ei line o dite hobe
        // adj[v].push_back(u); // unweited hole
        adj[v].push_back({u, w}); // weited hole
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            cout << "(" << j.first << "," << j.second << ")";
        }
        cout << endl;
    }

    return 0;
}
/*
input
4
5
1 2 8
1 3 9
2 4 11
4 3 17
3 2 15

output
(2,8)(3,9)
(1,8)(4,11)(3,15)
(1,9)(4,17)(2,15)
(2,11)(3,17)
*/