#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Structure for Huffman Tree Node
struct OddBox {
    char signy;     // character
    int tall;       // frequency
    OddBox* port;   // left child
    OddBox* star;   // right child
    OddBox(char s, int t) {
        signy = s;
        tall = t;
        port = star = NULL;
    }
};

// Comparator for priority queue (to make it a min-heap)
struct SillyPick {
    bool operator()(OddBox* lefty, OddBox* righty) {
        return lefty->tall > righty->tall; // smaller frequency = higher priority
    }
};

// Recursive function to print Huffman codes in Preorder
void loopyRide(OddBox* rooty, string pathy) {
    if (rooty == NULL) return;

    // If leaf node → print the code
    if (rooty->port == NULL && rooty->star == NULL) {
        cout << pathy << " ";
        return;
    }

    // Go left and add "0"
    loopyRide(rooty->port, pathy + "0");

    // Go right and add "1"
    loopyRide(rooty->star, pathy + "1");
}

int main() {
    string seedChars;
    cout << "Enter characters string S: ";
    cin >> seedChars;  // example: abcdef

    cout << "Enter frequencies (space separated): ";
    cin.ignore();

    string oddLine;
    getline(cin, oddLine); // example: 5 9 12 13 16 45

    // Convert frequencies from string to vector of integers
    vector<int> funkyNums;
    int spooky = 0;
    for (int j = 0; j <= (int)oddLine.size(); j++) {
        if (j < (int)oddLine.size() && isdigit(oddLine[j])) {
            spooky = spooky * 10 + (oddLine[j] - '0'); // build number
        } else if (oddLine[j] == ' ' || j == (int)oddLine.size()) {
            funkyNums.push_back(spooky); // save the number
            spooky = 0;
        }
    }

    // Create a priority queue (min-heap) with all characters
    priority_queue<OddBox*, vector<OddBox*>, SillyPick> bucket;

    for (int u = 0; u < (int)seedChars.size(); u++) {
        bucket.push(new OddBox(seedChars[u], funkyNums[u]));
    }

    // Build Huffman tree by combining two smallest nodes until one left
    while (bucket.size() > 1) {
        OddBox* firsty = bucket.top(); bucket.pop();
        OddBox* secondy = bucket.top(); bucket.pop();

        OddBox* mashy = new OddBox('$', firsty->tall + secondy->tall);
        mashy->port = firsty;   // left child
        mashy->star = secondy;  // right child
        bucket.push(mashy);
    }

    // Root of Huffman tree
    OddBox* rooty = bucket.top();

    // Print Huffman codes in preorder
    cout << "\nPreorder Huffman Codes:\n";
    loopyRide(rooty, "");

    return 0;
}
