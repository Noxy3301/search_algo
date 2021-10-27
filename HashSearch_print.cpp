#include <iostream>
#include <list>
#include <vector>
using namespace std;

int Hash(int x, int table_size) {
    return x%table_size;
}

int main() {
    int n, t_size;
    cout << "n = ";
    cin >> n;
    cout << "table_size = ";
    cin >> t_size;
    list<int> table[t_size];
    list<int>::iterator itr;

    for(int i = 0; i < n; i++) {
        int hoge = rand() % 1000;
        cout << "-- input: " << hoge << " --" << endl;
        table[Hash(hoge, t_size)].push_back(hoge);

        //print
        for(int i = 0; i < t_size; i++) {
            string out = "[" + to_string(i) + "]:";
            for(itr = table[i].begin(); itr != table[i].end(); itr++) {
                out += " -> " + to_string(*itr);
            }
            cout << out << endl;
        }
    }

    int value;
    cout << "value? : ";
    cin >> value;

    int chain_index = 0;
    for(itr = table[Hash(value, t_size)].begin(); itr != table[Hash(value, t_size)].end(); itr++) {
        if(value == *itr) {
            cout << "key = " << Hash(value, t_size) << " index = " << chain_index << endl;
            return 1;
        }
        chain_index++;
    }
    cout << "value not found" << endl;
    return 0;
}