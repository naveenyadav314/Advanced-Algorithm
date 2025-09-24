#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLongestCommonSubstring(string firstString, string secondString) {
    int firstLength = firstString.length();   // length of first string
    int secondLength = secondString.length(); // length of second string

    // DP table to store substring lengths
    vector<vector<int>> lcs_lookupTable(firstLength + 1, vector<int>(secondLength + 1, 0));

    int longest_substring_length = 0; // store max length
    int end_index_first = 0;          // where it ends in first string

    // build LCS lookup table
    for (int indexFirst = 1; indexFirst <= firstLength; indexFirst++) {
        for (int indexSecond = 1; indexSecond <= secondLength; indexSecond++) {
            if (firstString[indexFirst - 1] == secondString[indexSecond - 1]) {
                lcs_lookupTable[indexFirst][indexSecond] =
                    lcs_lookupTable[indexFirst - 1][indexSecond - 1] + 1;

                if (lcs_lookupTable[indexFirst][indexSecond] > longest_substring_length) {
                    longest_substring_length = lcs_lookupTable[indexFirst][indexSecond];
                    end_index_first = indexFirst;
                }
            } else {
                lcs_lookupTable[indexFirst][indexSecond] = 0;
            }
        }
    }

    // extract LCS
    string longestCommonSubstring =
        firstString.substr(end_index_first - longest_substring_length, longest_substring_length);

    // print DP table
    cout << "\nLCS Lookup Table:" << endl;
    for (const auto& row : lcs_lookupTable) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // print result
    cout << "\nLongest Common Substring: " << longestCommonSubstring << endl;
    cout << "Length: " << longest_substring_length << endl;
}

int main() {
    string firstString = "ABAB";
    string secondString = "BABA";

    computeLongestCommonSubstring(firstString, secondString);

    return 0;
}
