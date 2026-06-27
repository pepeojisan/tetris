#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <cmath>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <conio.h>
#include <Windows.h>

#ifdef __GNUC__
#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")
#endif

using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};

static const auto FAST_IO = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const auto OUTPUT = []()
{
    SetConsoleOutputCP(CP_UTF8);
    return 0;
}();

static const auto ANSI = []()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
    return 0;
}();
