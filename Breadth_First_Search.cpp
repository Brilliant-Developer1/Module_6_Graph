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
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> que;

    que.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        // section 1 A node is being processed
        // working as lavel order
        cout << "Node: " << u << endl;

        for (int v : adj[u])
        {
            // section 2 : child processing
            if (visited[v] == true)
                continue;
            que.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            // section 3 : child processing
        }
        // section 4 same as section 1
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // weited hole

        adj[v].push_back(u); // weited hole
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Level of " << i << ": " << level[i] << endl;
    }
    return 0;
}
/*
12
11
1 2
1 3
1 10
2 4
2 5
3 9
5 6
5 7
7 8
10 11
10 12

Node: 1
Node: 2
Node: 3
Node: 10
Node: 4
Node: 5
Node: 9
Node: 11
Node: 12
Node: 6
Node: 7
Node: 8
Level of 1: 0
Level of 2: 1
Level of 3: 1
Level of 4: 2
Level of 5: 2
Level of 6: 3
Level of 7: 3
Level of 8: 4
Level of 9: 2
Level of 10: 1
Level of 11: 2
Level of 12: 2

*/