#include <fstream>

std::ifstream fin("tttt.in");
std::ofstream fout("tttt.out");

char board[3][4];
bool win[26][26];
int single, team;

int main() {
    for (int i = 0; i < 3; ++i)
        fin >> board[i];

    for (int i = 0; i < 3; ++i)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            win[board[i][0] - 'A'][board[i][0] - 'A'] = true;
    for (int i = 0; i < 3; ++i)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            win[board[0][i] - 'A'][board[0][i] - 'A'] = true;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        win[board[0][0] - 'A'][board[0][0] - 'A'] = true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        win[board[0][2] - 'A'][board[0][2] - 'A'] = true;
    for (int k = 0; k < 26; ++k)
        if (win[k][k])
            ++single;

    for (int i = 0; i < 3; ++i) {
        int a = -1, b;
        if (board[i][0] == board[i][1] && board[i][0] != board[i][2])
            a = board[i][0] - 'A', b = board[i][2] - 'A';
        else if (board[i][0] == board[i][2] && board[i][0] != board[i][1] ||
            board[i][1] == board[i][2] && board[i][1] != board[i][0])
            a = board[i][0] - 'A', b = board[i][1] - 'A';
        if (a != -1)
            win[a][b] = true, win[b][a] = true;
    }
    for (int i = 0; i < 3; ++i) {
        int a = -1, b;
        if (board[0][i] == board[1][i] && board[0][i] != board[2][i])
            a = board[0][i] - 'A', b = board[2][i] - 'A';
        else if (board[0][i] == board[2][i] && board[0][i] != board[1][i] ||
            board[1][i] == board[2][i] && board[1][i] != board[0][i])
            a = board[0][i] - 'A', b = board[1][i] - 'A';
        if (a != -1)
            win[a][b] = true, win[b][a] = true;
    }
    if (board[0][0] == board[1][1] && board[0][0] != board[2][2])
        win[board[0][0] - 'A'][board[2][2] - 'A'] = true,
        win[board[2][2] - 'A'][board[0][0] - 'A'] = true;
    else if (board[0][0] == board[2][2] && board[0][0] != board[1][1] ||
        board[1][1] == board[2][2] && board[1][1] != board[0][0])
        win[board[0][0] - 'A'][board[1][1] - 'A'] = true,
        win[board[1][1] - 'A'][board[0][0] - 'A'] = true;
    if (board[0][2] == board[1][1] && board[0][2] != board[2][0])
        win[board[0][2] - 'A'][board[2][0] - 'A'] = true,
        win[board[2][0] - 'A'][board[0][2] - 'A'] = true;
    else if (board[0][2] == board[2][0] && board[0][2] != board[1][1] ||
        board[1][1] == board[2][0] && board[1][1] != board[0][2])
        win[board[0][2] - 'A'][board[1][1] - 'A'] = true,
        win[board[1][1] - 'A'][board[0][2] - 'A'] = true;
    for (int k = 0; k < 26; ++k)
        for (int h = k + 1; h < 26; ++h)
            if (win[k][h])
                ++team;
    fout << single << '\n' << team << '\n';
    return 0;
}
