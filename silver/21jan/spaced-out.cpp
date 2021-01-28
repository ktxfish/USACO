#include <algorithm>
#include <iostream>

#define MAX_N 1000

int N;
int beauty[MAX_N][MAX_N];
int sum_n, sum_m;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    for (int n = 0; n < N; ++n)
        for (int m = 0; m < N; ++m)
            std::cin >> beauty[n][m];

    for (int n = 0; n < N; ++n) {
        int a = 0;
        for (int m = 0; m < N; m += 2)
            a += beauty[n][m];
        int b = 0;
        for (int m = 1; m < N; m += 2)
            b += beauty[n][m];
        sum_n += std::max(a, b);
    }
    for (int m = 0; m < N; ++m) {
        int a = 0;
        for (int n = 0; n < N; n += 2)
            a += beauty[n][m];
        int b = 0;
        for (int n = 1; n < N; n += 2)
            b += beauty[n][m];
        sum_m += std::max(a, b);
    }
    std::cout << std::max(sum_n, sum_m) << '\n';
    return 0;
}
