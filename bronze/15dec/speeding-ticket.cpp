#include <fstream>

#define MAX_LEN 100

std::ifstream fin("speeding.in");
std::ofstream fout("speeding.out");

int N, M;
struct Seg {
    int beg, end, spd;
} road[MAX_LEN], cow[MAX_LEN];
int max_over;

int main() {
    fin >> N >> M;
    fin >> road[0].end >> road[0].spd;
    road[0].beg = 0;
    for (int n = 1; n < N; ++n) {
        road[n].beg = road[n - 1].end;
        int len, spd;
        fin >> len >> spd;
        road[n].end = road[n].beg + len;
        road[n].spd = spd;
    }
    fin >> cow[0].end >> cow[0].spd;
    cow[0].beg = 0;
    for (int m = 1; m < M; ++m) {
        cow[m].beg = cow[m - 1].end;
        int len, spd;
        fin >> len >> spd;
        cow[m].end = cow[m].beg + len;
        cow[m].spd = spd;
    }
    for (int n = 1, m = 0; m < M; ++m) {
        if (road[n - 1].end > cow[m].beg &&
            road[n - 1].spd < cow[m].spd &&
            cow[m].spd - road[n - 1].spd > max_over)
            max_over = cow[m].spd - road[n - 1].spd;
        while (n < N && road[n].beg < cow[m].end) {
            if (road[n].spd < cow[m].spd &&
                cow[m].spd - road[n].spd > max_over)
                max_over = cow[m].spd - road[n].spd;
            ++n;
        }
    }
    fout << max_over << '\n';
    return 0;
}
