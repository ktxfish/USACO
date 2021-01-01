#include <algorithm>
#include <fstream>

#define MAX_N 100

std::ifstream fin("angry.in");
std::ofstream fout("angry.out");

int N;
int loc[MAX_N];
int max_x;

int get_right(int n, int t) {
    int i = n + 1;
    while (i < N && loc[i] - loc[n] <= t)
        ++i;
    if (i == n + 1)
        return n;
    return get_right(i - 1, t + 1);
}
int get_left(int n, int t) {
    int i = n - 1;
    while (i >= 0 && loc[n] - loc[i] <= t)
        --i;
    if (i == n - 1)
        return n;
    return get_left(i + 1, t + 1);
}

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> loc[n];
    std::sort(loc, loc + N);

    for (int n = 0; n < N; ++n) {
        int x = get_right(n, 1) - get_left(n, 1) + 1;
        if (x > max_x)
            max_x = x;
    }
    fout << max_x << '\n';
    return 0;
}
