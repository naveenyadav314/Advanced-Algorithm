#include <iostream>
using namespace std;

int main() {
    int num;
    // number of array elements
    cout << "Enter number of elements in the array: ";
    cin >> num;

    int arr[num];
    // taking array elements from user
    cout << "Enter " << num << " numbers: ";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    // target value
    int target;
    cout << "Enter target value: ";
    cin >> target;

    int index1 = -1, index2 = -1;

    // checking all pairs
    for (int j = 0; j < num; j++) {
        for (int k = j + 1; k < num; k++) {
            if (arr[j] + arr[k] == target) {
                index1 = j;
                index2 = k;
                break;
            }
        }
        if (index1 != -1) break; // beaking outer loop
    }
    // printing correct indexes
    cout << "Output: [" << index1 << ", " << index2 << "]" << endl;

    return 0;
}
