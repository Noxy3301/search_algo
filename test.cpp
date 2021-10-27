#include <iostream>
#include <thread>
#include <exception>
void
do_worker1 (int a, int b) {
        std::cout << __PRETTY_FUNCTION__ << " " << a << " " << b << std::endl;
}
 
int
main (int argc, char *argv[]) {
        try {
                std::thread t1(do_worker1, 1,2);
                t1.join();
        } catch (std::exception &ex) {
                std::cerr << ex.what() << std::endl;
        }
        return (0);
}