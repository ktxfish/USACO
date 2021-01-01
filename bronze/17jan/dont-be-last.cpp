#include <fstream>
#include <map>
#include <string>

#define MAX_N 100
#define MAX_AMT 100
#define NAMES {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"}

std::ifstream fin("notlast.in");
std::ofstream fout("notlast.out");

int N;
std::map<std::string, int> milk;

int main() {
    for (std::string name : NAMES)
        milk[name] = 0;
    fin >> N;
    for (int n = 0; n < N; ++n) {
        std::string name;
        int amt;
        fin >> name >> amt;
        milk[name] += amt;
    }
    int min_amt = MAX_N * MAX_AMT;
    int min2_amt = MAX_N * MAX_AMT + 1;
    for (std::pair<std::string, int> cow : milk)
        if (cow.second < min_amt) {
            int t = min_amt;
            min_amt = cow.second;
            min2_amt = t;
        } else if (cow.second > min_amt && cow.second < min2_amt)
            min2_amt = cow.second;

    bool multi = false;
    std::string min2_name = "";
    for (std::pair<std::string, int> cow : milk)
        if (cow.second == min2_amt) {
            if (min2_name == "")
                min2_name = cow.first;
            else
                multi = true;
        }
    fout << (multi || min2_name == "" ? "Tie\n" : min2_name + '\n');
    return 0;
}
