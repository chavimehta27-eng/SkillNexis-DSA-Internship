#include <bits/stdc++.h>
using namespace std;
int knapsack(int weight[], int value[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                                dp[i - 1][w]);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main(){
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[n], value[n];
    cout << "Enter weights of items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << "Enter values of items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    cout << "Maximum value = "
         << knapsack(weight, value, n, capacity);
    return 0;
}
