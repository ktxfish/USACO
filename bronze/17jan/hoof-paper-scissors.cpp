#include <fstream>

#define MAX_N 100

std::ifstream fin("hps.in");
std::ofstream fout("hps.out");

int N;
int rec[MAX_N][2];
const int rot[6][3] = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}
    };
int max_win;

bool winning(const int (& game)[2]) {
    // assume 1 = hoof, 2 = paper, 3 = scissors
    if (game[0] == 1) {
        if (game[1] == 3)
            return true;
        return false;
    } else if (game[0] == 2) {
        if (game[1] == 1)
            return true;
        return false;
    } else if (game[1] == 2)
        return true;
    return false;
}

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> rec[n][0] >> rec[n][1];
    for (int r = 0; r < 6; ++r) {
        int win = 0;
        for (int n = 0; n < N; ++n)
            if (winning({
                rot[r][rec[n][0] - 1],
                rot[r][rec[n][1] - 1]
                }))
                ++win;
        if (win > max_win)
            max_win = win;
    }
    fout << max_win << '\n';
    return 0;
}
