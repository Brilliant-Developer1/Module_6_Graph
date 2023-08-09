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
vector<int> adj[N]; // unweited er jonno
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{

    // section 1
    // actions needed in enry point
    visited[u] = true;
    // cout << "node:" << u << endl;
    for (int v : adj[u])
    {
        // section 2
        // actions bfore entring his new chiled
        if (visited[v])
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        // section 3
        // actions after exitting from chiled
        height[u] = max(height[u], height[v] + 1);
    }
    // section 4
    // actions before exiting u node
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v;

        adj[u].push_back(v); // weited hole

        adj[v].push_back(u); // weited hole
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Depth " << i << ": " << depth[i] << endl;
    }
    cout << "*******************\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Height " << i << ": " << height[i] << endl;
    }

    return 0;
}

/*
graph 1
10
9
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9
grphn 2
9
10
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9
*/