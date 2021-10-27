#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, value, left, right;
    vector<int> arr;
    cout << "n = ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        arr.push_back(i);
    }

    for(int value = 0; value < n; value++) {
        left = 0;
        right = n-1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid] > value) {
                right = mid - 1;
            } else if(arr[mid] < value) {
                left = mid + 1;
            } else {
                cout << "found : arr[" << arr[mid] << "]" << endl;
                break;
            }
            // cout << mid << endl;
            // cout << "left = " << left << ": right = " << right << endl;
        }
    }
    return 0;
}