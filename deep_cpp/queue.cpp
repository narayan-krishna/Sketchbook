#include <queue>
#include <vector>
#include <iostream>

int main () {
    std::queue<int> q;
    std::vector<int> v{1,2,4,7,1,3};

    for (int i : v) {
        q.push(i);
    }

    std::cout << q.front() << std::endl;
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;

    return 0;
}