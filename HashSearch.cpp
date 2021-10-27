#include <iostream>
#include <vector>
#include <list>
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
    for(int i = 0; i < n; i++) {
        table[Hash(i, t_size)].push_back(i);
    }

    list<int>::iterator itr;

    for(int i = 0; i < n; i++) {
        int chain_index = 0;
        for(itr = table[Hash(i, t_size)].begin(); itr != table[Hash(i, t_size)].end(); itr++) {
            if(i == *itr) {
                cout << "value = " << *itr << " key = " << Hash(i, t_size) << " index = " << chain_index << endl;
            }
            chain_index++;
        }
    }
}