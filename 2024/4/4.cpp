#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    // Reads the crossword puzzle into a vector of strings
    string word = "XMAS", wordReversed{word.rbegin(), word.rend()};
    vector<string> crossword;
    string line;
    while (getline(input, line)) {
        crossword.push_back(line);
    }
    input.close();

    int numAppearances = 0;
    size_t crosswordWidth = crossword.at(0).size();
    size_t crosswordHeight = crossword.size();

    // Search for the word horizontally
    for (size_t j = 0; j < crosswordHeight; ++j) {
        for (size_t i = 0; i < crosswordWidth - 3; ++i) {
            if (crossword.at(j).substr(i, 4) == word ||
                crossword.at(j).substr(i, 4) == wordReversed)
                numAppearances++;
        }
    }

    // Search for the word vertically
    for (size_t i = 0; i < crosswordWidth; ++i) {
        for (size_t j = 0; j < crosswordHeight - 3; ++j) {
            string concatenation{
                crossword.at(j).at(i), crossword.at(j + 1).at(i),
                crossword.at(j + 2).at(i), crossword.at(j + 3).at(i)};
            if (concatenation == word || concatenation == wordReversed)
                numAppearances++;
        }
    }

    // Search for the word diagonally (bottom-left to top-right)
    for (size_t k = 3; k <= crosswordHeight * 2 - 2; ++k) {
        size_t i = k < crosswordHeight ? 0 : (k + 1) - crosswordHeight;
        size_t j = k < crosswordHeight ? k : crosswordHeight - 1;
        for (; j >= 3 && i < crosswordWidth - 3; ++i, --j) {
            string concatenation{
                crossword.at(j).at(i), crossword.at(j - 1).at(i + 1),
                crossword.at(j - 2).at(i + 2), crossword.at(j - 3).at(i + 3)};
            if (concatenation == word || concatenation == wordReversed)
                numAppearances++;
        }
    }

    // Search for the word diagonally (top-left to bottom-right)
    for (size_t k = 3; k <= crosswordWidth * 2 - 2; ++k) {
        size_t i = k < crosswordWidth ? k : crosswordWidth - 1;
        size_t j = k < crosswordWidth ? 0 : (k + 1) - crosswordWidth;
        for (; i >= 3 && j < crosswordHeight - 3; --i, ++j) {
            string concatenation{
                crossword.at(j).at(i), crossword.at(j + 1).at(i - 1),
                crossword.at(j + 2).at(i - 2), crossword.at(j + 3).at(i - 3)};
            if (concatenation == word || concatenation == wordReversed)
                numAppearances++;
        }
    }

    cout << "Total occurrences of \"XMAS\": " << numAppearances << endl;
    return 0;
}
