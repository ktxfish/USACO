#include <algorithm>
#include <fstream>
#include <string>

#define MAX_N 100

std::ifstream fin("measurement.in");
std::ofstream fout("measurement.out");

int N;
struct Rec {
    int day, who, amt;
} rec[MAX_N];
int milk[3] = {7, 7, 7};
bool on[3] = {true, true, true};
int adj;

int idx(std::string name) {
    if (name == "Bessie")
        return 0;
    if (name == "Elsie")
        return 1;
    return 2;
}

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n) {
        std::string name;
        fin >> rec[n].day >> name >> rec[n].amt;
        rec[n].who = idx(name);
    }
    std::sort(rec, rec + N, [](Rec a, Rec b){ return a.day < b.day; });
    for (int n = 0; n < N; ++n) {
        milk[rec[n].who] += rec[n].amt;
        int max_amt = 0;
        for (int i = 0; i < 3; ++i)
            if (milk[i] > max_amt)
                max_amt = milk[i];

        bool need_adj = false;
        for (int i = 0; i < 3; ++i)
            if (milk[i] == max_amt) {
                if (!on[i])
                    need_adj = true, on[i] = true;
            } else if (on[i]) {
                need_adj = true, on[i] = false;
            }
        if (need_adj)
            ++adj;
    }
    fout << adj << '\n';
    return 0;
}
