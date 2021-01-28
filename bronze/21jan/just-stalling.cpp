#include <algorithm>
#include <iostream>

#define MAX_N 20

int N;
int cow[MAX_N], stall[MAX_N];
long long ways = 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    for (int n = 0; n < N; ++n)
        std::cin >> cow[n];
    std::sort(cow, cow + N);
    for (int n = 0; n < N; ++n)
        std::cin >> stall[n];
    std::sort(stall, stall + N);

    for (int n = 0; n < N; ++n) {
        int sat = 0;
        for (int m = N - 1; m >= 0 && stall[m] >= cow[n]; --m)
            ++sat;
        ways *= sat - (N - n - 1);
    }
    std::cout << ways << '\n';
    return 0;
}
