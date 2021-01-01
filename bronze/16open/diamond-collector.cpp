#include <fstream>

#define MAX_S 10000

std::ifstream fin("diamond.in");
std::ofstream fout("diamond.out");

int N, K;
int num[MAX_S + 1];
int max_show;

int main() {
    fin >> N >> K;
    for (int n = 0; n < N; ++n) {
        int s;
        fin >> s;
        ++num[s];
    }
    for (int s = 1; s <= MAX_S; ++s)
        num[s] += num[s - 1];
    for (int s = 1; s <= MAX_S - K; ++s) {
        int show = num[s + K] - num[s - 1];
        if (show > max_show)
            max_show = show;
    }
    fout << max_show << '\n';
    return 0;
}
