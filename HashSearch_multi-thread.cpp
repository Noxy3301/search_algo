#include <iostream>
#include <list>
#include <thread>
#include <vector>
using namespace std;

int Hash(int x, int table_size) {
    return x%table_size;
}

int main() {
    int n, t_size;
    int p = max(thread::hardware_concurrency(), 1u);
    cout << "concurrency = " << p << endl;
    cout << "n = ";
    cin >> n;
    cout << "table_size = ";
    cin >> t_size;
    list<int> table[t_size];
    for(int i = 0; i < n; i++) {
        table[Hash(i, t_size)].push_back(i);
    }

    vector<thread> threads;
    list<int>::iterator itr;

    //各スレッドに振り分けてく
    for(int i = 0; i < p; i++) {
        threads.emplace_back([&](int id) {
            //amarinimo tensai sugiru
            int start = n/p * id + min(n%p, id);
            int end = n/p * (id+1) + min(n%p, id+1);
            for(int j = start; j < end; j++) {
                int chain_index = 0;
                for(itr = table[Hash(i, t_size)].begin(); itr != table[Hash(i, t_size)].end(); itr++) {
                    if(i == *itr) {
                        cout << "value = " << *itr << " key = " << Hash(i, t_size) << " index = " << chain_index << endl;
                    }
                    chain_index++;
                }
            }
        },i);
    }

    for(auto& t: threads) {
        t.join();
    }
}