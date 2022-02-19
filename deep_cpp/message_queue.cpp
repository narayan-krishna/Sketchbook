#include <iostream>
#include <thread>
#include <queue>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <unistd.h>

class MessageQueue {
    private:
        std::queue<std::string> message_queue;

        std::mutex send_m;
        std::mutex recv_m;
        std::condition_variable cv_1;
        std::condition_variable cv_2;
        bool signal = 0;

    public:
        void send(std::string message) {

            std::unique_lock<std::mutex> lg(send_m);
            cv_1.wait(lg, [&]{ return signal == 0; });

            std::cout << "sent: " << message << std::endl;
            message_queue.push(message);
            signal = 1;
            cv_2.notify_one();
            lg.unlock();

            //how do i make it so that you can send until someone tries to recv
        }

        std::string recv() {

            std::unique_lock<std::mutex> lg(recv_m);
            cv_2.wait(lg, [&]{ return signal == 1; });

            std::string message = message_queue.front();
            std::cout << "received: " << message << std::endl;
            message_queue.pop();
            signal = 0;
            cv_1.notify_one();
            lg.unlock();

            return message;
        }
};

void sender_thread (MessageQueue *q) {
    std::vector<std::string> messages{"1", "2", "3", "4", "5", "6", "7"};

    for (std::string msg : messages) {
        q->send(msg);
        sleep(1);
    }
}

void recv_thread (MessageQueue *q) {
    std::vector<std::string> messages;
    for (int i = 0; i < 7; i ++) {
        messages.push_back(q->recv());
        sleep(1);
    }
}

int main () {

    MessageQueue *q = new MessageQueue;
    std::thread t1(sender_thread, q);
    std::thread t2(recv_thread, q);

    t1.join();
    t2.join();

    return 0;
}

