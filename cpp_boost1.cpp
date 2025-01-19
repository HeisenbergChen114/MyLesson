#include <iostream>
#include <boost/thread.hpp>

void threadFunction() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    boost::thread myThread(threadFunction);
    myThread.join();

    return 0;
}