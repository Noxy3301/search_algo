#include <iostream>
#include <thread>
#include <vector>
 
using namespace std;
 
void addRef(int x, int y,int &ans){
    ans = x + y;
}
int main() {
    const int N = 5;
    const int x=1, y=2;

    vector<thread> threads;
    vector<int> result(N);

    for (int i=0;i<N;++i)
        threads.push_back(thread(addRef, x, y, ref(result[i])));
    for (thread &t: threads)
        t.join();
    for (int r : result)
        cout<<r<<endl;
    return 0;
}