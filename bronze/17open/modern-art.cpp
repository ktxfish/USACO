#include <fstream>

#define MAX_N 10

std::ifstream fin("art.in");
std::ofstream fout("art.out");

int N;
char art[MAX_N][MAX_N + 1];
bool can[10];
int num_can;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> art[n];
    for (int n = 0; n < N; ++n)
        for (int m = 0; m < N; ++m)
            can[art[n][m] - '0'] = true;
    for (int c = 1; c <= 9; ++c) {
        int x1 = N, y1 = N, x2 = -1, y2 = -1;
        for (int n = 0; n < N; ++n)
            for (int m = 0; m < N; ++m)
                if (art[n][m] - '0' == c) {
                    if (n < x1)
                        x1 = n;
                    if (m < y1)
                        y1 = m;
                    if (n > x2)
                        x2 = n;
                    if (m > y2)
                        y2 = m;
                }
        if (x1 == N)
            continue;
        for (int n = x1; n <= x2; ++n)
            for (int m = y1; m <= y2; ++m)
                if (art[n][m] - '0' != c)
                    can[art[n][m] - '0'] = false;
    }
    for (int c = 1; c <= 9; ++c)
        if (can[c])
            ++num_can;
    fout << num_can << '\n';
    return 0;
}
