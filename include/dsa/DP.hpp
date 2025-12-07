#pragma once
#include <vector>
using namespace std;

class DP {
public:
    int fibonacci(int n);
    int knapsack(vector<int>& weights, vector<int>& values, int W);
};
