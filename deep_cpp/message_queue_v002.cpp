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
        std::condition_variable send_condition;
        std::condition_variable recv_condition;
        bool can_send = true;
        bool can_recv = false;

    public:
        void send(std::string message) {

            std::unique_lock<std::mutex> glock(send_m);
            send_condition.wait(glock, [&]{ return can_send == true; });

            std::cout << "sent: " << message << std::endl;
            message_queue.push(message);
            can_recv = true;
            recv_condition.notify_one();
            glock.unlock();

        }

        std::string recv() {

            std::unique_lock<std::mutex> glock(recv_m);
            recv_condition.wait(glock, [&]{ return can_recv == true; });

            //block sending after receiving is deemed possible
            can_send == false; send_condition.notify_one(); 

            //get message
            std::string message = message_queue.front();
            std::cout << "received: " << message << std::endl;
            message_queue.pop();

            //if the queue is empty, we can no longer receive
            if (message_queue.empty()) {
                can_recv = false;
                recv_condition.notify_one();
            }

            //unlock sending
            can_send = true; send_condition.notify_one(); 
            glock.unlock();

            return message; //return message
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
    sleep(1);
    std::vector<std::string> messages;
    for (int i = 0; i < 7; i ++) {
        messages.push_back(q->recv());
        sleep(1);
    }
}

int main () {

    MessageQueue *q = new MessageQueue;
    std::thread t1(sender_thread, q);
    sleep(3);
    std::thread t2(recv_thread, q);

    try {

    } catch (...) {
        t1.join();
        t2.join();
    }

    t1.join();
    t2.join();

    return 0;
}

