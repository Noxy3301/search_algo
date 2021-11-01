#include <iostream>
#include <list>
#include <thread>
#include <vector>
#include <time.h>
using namespace std;

int Hash(int x, int table_size) {
    return x%table_size;
}

void Search(int start, int end, int t_size, vector<list<int>> table) {

    list<int>::iterator itr;
    int count = 0;

    for(int value = start; value < end; value++) {
        for(itr = table[Hash(value, t_size)].begin(); itr != table[Hash(value, t_size)].end(); itr++) {
            if(value == *itr) {
                count++;
                break;
            }
        }
    }

    cout << "thread id = " << this_thread::get_id() << "; " << count << endl;
}

int main() {
    int n = 1000000, t_size = 100;
    int thread_num = 8;          //手で変えた
    int step = n / thread_num;   //各threadの実行分

    vector<list<int>> table(t_size);    //Hashtable
    vector<thread> threads;

    for(int i = 0; i < n; i++) {
        table[Hash(i, t_size)].push_back(i);
    }

    clock_t start = clock();

    //threadに仕事を割り振る
    for(int i = 0; i < thread_num; i++) {
        threads.emplace_back(Search, i*step, (i+1)*step, t_size, table);
    }

    for(auto& t: threads) {
        t.join();
    }

    clock_t end = clock();

    cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

}