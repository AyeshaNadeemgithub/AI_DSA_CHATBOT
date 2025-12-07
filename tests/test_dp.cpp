#include <iostream>
#include "../include/dsa/DP.hpp"

using namespace std;

int main() {

    DP dp;

    // -------- Test Fibonacci --------
    cout << "Testing Fibonacci:\n";
    cout << "fib(0) = " << dp.fibonacci(0) << " (expected 0)\n";
    cout << "fib(1) = " << dp.fibonacci(1) << " (expected 1)\n";
    cout << "fib(6) = " << dp.fibonacci(6) << " (expected 8)\n";
    cout << endl;

    // -------- Test Knapsack --------
    cout << "Testing Knapsack:\n";
    vector<int> weights = {1, 2, 3};
    vector<int> values  = {10, 15, 40};

    int W = 6;
    int result = dp.knapsack(weights, values, W);

    cout << "Knapsack result = " << result << " (expected 65)\n";

    return 0;
}
