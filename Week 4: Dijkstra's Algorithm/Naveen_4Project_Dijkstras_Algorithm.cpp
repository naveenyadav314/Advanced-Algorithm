#include <iostream>
using namespace std;

int main() {
    int nodeCount; // total number of nodes
    cout << "Enter number of nodes: ";
    cin >> nodeCount;

    char nodeList[10]; // node labels
    for (int nodeSlot = 0; nodeSlot < nodeCount; nodeSlot++) {
        cout << "Enter name of node " << nodeSlot + 1 << ": ";
        cin >> nodeList[nodeSlot];
    }

    int edgeWeights[10][10]; // adjacency matrix
    cout << "Enter the edge weights (use 0 for no direct connection):\n";
    for (int rowNode = 0; rowNode < nodeCount; rowNode++) {
        for (int colNode = 0; colNode < nodeCount; colNode++) {
            if (rowNode == colNode) {
                edgeWeights[rowNode][colNode] = 0; // self distance
            } else if (rowNode < colNode) {
                cout << nodeList[rowNode] << " to " << nodeList[colNode] << ": ";
                cin >> edgeWeights[rowNode][colNode];
                if (edgeWeights[rowNode][colNode] == 0) edgeWeights[rowNode][colNode] = 9999;
                edgeWeights[colNode][rowNode] = edgeWeights[rowNode][colNode]; // symmetric
            }
        }
    }

    char startPoint, endPoint;
    cout << "Enter starting node: ";
    cin >> startPoint;
    cout << "Enter ending node: ";
    cin >> endPoint;

    int distanceTracker[10]; // shortest distances from start
    int visitFlag[10];       // visited nodes
    int pathBacktrack[10];   // previous nodes in path

    int startIdx = -1;
    for (int checkIdx = 0; checkIdx < nodeCount; checkIdx++) {
        if (nodeList[checkIdx] == startPoint) startIdx = checkIdx;
    }

    for (int idx = 0; idx < nodeCount; idx++) {
        distanceTracker[idx] = 9999;
        visitFlag[idx] = 0;
        pathBacktrack[idx] = -1;
    }
    distanceTracker[startIdx] = 0;

    for (int stepCounter = 0; stepCounter < nodeCount; stepCounter++) {
        int currentNode = -1;
        int minimumDistance = 9999;

        for (int idx = 0; idx < nodeCount; idx++) {
            if (!visitFlag[idx] && distanceTracker[idx] < minimumDistance) {
                minimumDistance = distanceTracker[idx];
                currentNode = idx;
            }
        }

        if (currentNode == -1) break; // no more nodes to visit
        visitFlag[currentNode] = 1;

        for (int neighborNode = 0; neighborNode < nodeCount; neighborNode++) {
            if (!visitFlag[neighborNode] && edgeWeights[currentNode][neighborNode] != 9999) {
                int candidateDistance = distanceTracker[currentNode] + edgeWeights[currentNode][neighborNode];
                if (candidateDistance < distanceTracker[neighborNode]) {
                    distanceTracker[neighborNode] = candidateDistance;
                    pathBacktrack[neighborNode] = currentNode;
                }
            }
        }
    }

    int endIdx = -1;
    for (int idx = 0; idx < nodeCount; idx++) {
        if (nodeList[idx] == endPoint) endIdx = idx;
    }

    if (distanceTracker[endIdx] == 9999) {
        cout << "No path from " << startPoint << " to " << endPoint << " exists.\n";
    } else {
        cout << "Cost of shortest path: " << distanceTracker[endIdx] << "\n";
        cout << "Path: ";
        int pathTrail[10];
        int trailLength = 0;
        int traceNode = endIdx;
        while (traceNode != -1) {
            pathTrail[trailLength++] = traceNode;
            traceNode = pathBacktrack[traceNode];
        }
        for (int printIdx = trailLength - 1; printIdx >= 0; printIdx--) {
            cout << nodeList[pathTrail[printIdx]];
            if (printIdx > 0) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}
