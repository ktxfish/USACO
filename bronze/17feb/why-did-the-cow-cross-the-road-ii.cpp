#include <algorithm>
#include <fstream>

std::ifstream fin("circlecross.in");
std::ofstream fout("circlecross.out");

struct Cow {
    int a = -1, b;
} cow[26];
int pair;

int main() {
    for (int p = 0; p < 52; ++p) {
        char c;
        fin.get(c);
        int i = c - 'A';
        if (cow[i].a == -1)
            cow[i].a = p;
        else
            cow[i].b = p;
    }
    std::sort(cow, cow + 26, [](Cow a, Cow b){ return a.a < b.a; });
    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j)
            if (cow[j].a < cow[i].b && cow[i].b < cow[j].b)
                ++pair;
    fout << pair << '\n';
    return 0;
}
