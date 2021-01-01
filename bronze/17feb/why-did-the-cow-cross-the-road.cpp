#include <fstream>

#define MAX_ID 10

std::ifstream fin("crossroad.in");
std::ofstream fout("crossroad.out");

int N;
int side[MAX_ID + 1];
int cross;

int main() {
    for (int id = 1; id <= 10; ++id)
        side[id] = -1;
    fin >> N;
    for (int n = 0; n < N; ++n) {
        int id, s;
        fin >> id >> s;
        if (side[id] == -1)
            side[id] = s;
        else if (side[id] != s)
            ++cross, side[id] = s;
    }
    fout << cross << '\n';
    return 0;
}
