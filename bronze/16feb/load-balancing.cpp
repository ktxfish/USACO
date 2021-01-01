#include <algorithm>
#include <fstream>
#include <set>

#define MAX_N 100

std::ifstream fin("balancing.in");
std::ofstream fout("balancing.out");

int N, B;
struct Cow {
    int x, y;
} cow[MAX_N];
std::set<int> xcord, ycord;
int M = MAX_N;

int main() {
    fin >> N >> B;
    for (int n = 0; n < N; ++n) {
        fin >> cow[n].x >> cow[n].y;
        xcord.insert(cow[n].x);
        ycord.insert(cow[n].y);
    }
    for (int x : xcord)
        for (int y : ycord) {
            int a = 0, b = 0, c = 0, d = 0;
            for (int n = 0; n < N; ++n)
                if (cow[n].x <= x && cow[n].y <= y)
                    ++a;
                else if (cow[n].x <= x && cow[n].y > y)
                    ++b;
                else if (cow[n].x > x && cow[n].y <= y)
                    ++c;
                else
                    ++d;
            int m = std::max({a, b, c, d});
            if (m < M)
                M = m;
        }
    fout << M << '\n';
    return 0;
}
