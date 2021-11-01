#include <iostream>
#include <list>
#include <thread>
#include <vector>
#include <time.h>
using namespace std;

int Hash(int x, int table_size) {
    return x%table_size;
}

void Search(int value, int t_size, vector<list<int>> table) {

    //cout << "thread_id = " << this_thread::get_id() << endl;
    list<int>::iterator itr;

    int chain_index = 0;
    for(itr = table[Hash(value, t_size)].begin(); itr != table[Hash(value, t_size)].end(); itr++) {
        if(value == *itr) {
            //cout << "value = " << *itr << " key = " << Hash(value, t_size) << " index = " << chain_index << endl;
        }
        chain_index++;
    }
}

int main() {
    int n, t_size;
    int p = max(thread::hardware_concurrency(), 1u);
    cout << "concurrency = " << p << endl;
    cout << "n = ";
    cin >> n;
    cout << "table_size = ";
    cin >> t_size;
    vector<list<int>> table(t_size);
    vector<thread> threads;

    clock_t start = clock();

    for(int i = 0; i < n; i++) {
        table[Hash(i, t_size)].push_back(i);
    }

    for(int i = 0; i < p; i++) {
        threads.emplace_back(Search, i, t_size, table);
    }

    for(auto& t: threads) {
        t.join();
    }

    clock_t end = clock();

    cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

}