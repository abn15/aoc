#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 
using namespace std;
int main() {
    ifstream ifs{"input.txt"};
    if (!ifs.is_open()) return -1;

    vector<string> crossword;
    for (string line = "";getline(ifs, line);) {
        crossword.push_back(line);
    }

    int numAppearances = 0;

    // Goes through all the A's and checks if they form the X-MAS cross
    for (size_t j = 1; j < crossword.size() - 1; ++j) {
        for (size_t i = 1; i < crossword.at(0).size() - 1; ++i) {
            // Don't care if it's not an A
            if (crossword.at(j).at(i) != 'A') continue;

            // Checks that the surrounding letters are what we want
            bool valid = true;
            for (const pair<int, int>& delta : vector<pair<int, int>>{ {-1, -1}, {-1, 1}, {1, -1}, {1, 1} }) {
                int dx = delta.first;
                int dy = delta.second;
                char ch = crossword.at(j + dy).at(i + dx);
                if (ch != 'M' && ch != 'S') valid = false;
            }
            if (!valid) continue;

            // Makes sure it's the pattern we need
            if (crossword.at(j - 1).at(i - 1) == crossword.at(j + 1).at(i + 1)) continue;
            if (crossword.at(j - 1).at(i + 1) == crossword.at(j + 1).at(i - 1)) continue;

            numAppearances++;
        }
    }

    cout << numAppearances <<endl;

    return 0;
}
