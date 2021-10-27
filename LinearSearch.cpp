#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> shuffle(int size) {
    int r, tmp;
    vector<int> array;

    for(int i = 0; i < size; i++) {
        array.push_back(i);
    }

    for(int i = size - 1; i > 0; i--) {
        r = rand() % i; //iで割ると0~iの範囲の乱数が生成できる
        tmp = array[r];
        array[r] = array[i];
        array[i] = tmp;
    }

    return array;
}

int main() {
    int n, value;
    vector<int> arr;
    cout << "n = ";
    cin >> n;

    arr = shuffle(n);
    for(int value = 0; value < n; value++) {
        for(int i = 0; i < n; i++ ) {
            if(arr[i] == value) {
                cout << "found : arr[" << i << "]" << endl;
                break;
            }
        }
    }
    return 0;
}