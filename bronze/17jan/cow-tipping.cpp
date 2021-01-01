#include <fstream>

#define MAX_N 10

std::ifstream fin("cowtip.in");
std::ofstream fout("cowtip.out");

int N;
bool tip[MAX_N][MAX_N];
int app;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n) {
        fin.get();
        for (int m = 0; m < N; ++m) {
            char c;
            fin.get(c);
            if (c == '1')
                tip[n][m] = true;
        }
    }
    for (int i = N - 1; i >= 0; --i)
        for (int j = N - 1; j >= 0; --j)
            if (tip[i][j]) {
                for (int n = 0; n <= i; ++n)
                    for (int m = 0; m <= j; ++m)
                        tip[n][m] = !tip[n][m];
                ++app;
            }
    fout << app << '\n';
    return 0;
}
