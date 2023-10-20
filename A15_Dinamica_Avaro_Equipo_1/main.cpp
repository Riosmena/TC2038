// ====================================================
// File: main.cpp
// Authors: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Date: Thursday, August 31th, 2023
// ====================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Dynamic Programming solution
vector<int> dynamicChange(int price, int payment, vector<int>& denominations) {
    int n = denominations.size();
    vector<int> dp(price + 1, INT_MAX); // Vector to store minimum coin counts for each price
    vector<int> coinsUsed(price + 1, 0); // Vector to store the denomination used for each price

    // Base case:
    dp[0] = 0; // Zero coins needed for a price of zero

    for (int i = 1; i <= price; ++i) {
        for (int j = 0; j < n; ++j) {
            // Update if using the current denomination reduces the coin count
            if (denominations[j] <= i && dp[i - denominations[j]] + 1 < dp[i]) {
                dp[i] = dp[i - denominations[j]] + 1;
                coinsUsed[i] = denominations[j];
            }
        }
    }

    vector<int> change;
    int remaining = payment - price;

    // Find the denominations used to make the change
    while (remaining > 0) {
        change.push_back(coinsUsed[remaining]);
        remaining -= coinsUsed[remaining];
    }

    return change;
}

// Dynamic Programming solution complexity: O(n^2)
// =======================================================

// Greedy Programming solution
vector<int> greedyChange(int price, int payment, vector<int>& denominations) {
    vector<int> change;
    int remaining = payment - price;
    int idx = denominations.size() - 1;

    // Choose the largest denomination that fits the remaining amount
    while (remaining > 0 && idx >= 0) {
        if (denominations[idx] <= remaining) {
            change.push_back(denominations[idx]);
            remaining -= denominations[idx];
        } 
        else {
            --idx;
        }
    }

    return change;
}

// Greedy Programming solution complexity: O(n)
// ======================================================

int main(int argc, char* argv[]) {
    int N, P, Q;

    cout << "Number of denominations: ";
    cin >> N;

    vector<int> denominations(N);
    for (int i = 1; i <= N; ++i) {
        cout << "Input the denomination " << i << " value: ";
        cin >> denominations[i - 1];
    }
    
    cout << "Input a price: ";
    cin >> P; 
    cout << "Input the paid quantity: ";
    cin >> Q;

    vector<int> dynamicResult = dynamicChange(P, Q, denominations);
    vector<int> greedyResult = greedyChange(P, Q, denominations);

    // Output with dynamic programming solution
    cout << "\nDynamic Programming Result:";
    for (int coin : dynamicResult) {
        cout << " " << coin;
    }

    // Output with greedy programming solution
    cout << "\nGreedy Programming Result:";
    for (int coin : greedyResult) {
        cout << " " << coin;
    }

    return 0;
}
