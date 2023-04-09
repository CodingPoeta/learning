// compare async & packaged_task & promise+future

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

int main()
{
    std::packaged_task<int()> task([](){ 
            std::chrono::milliseconds dura( 2000  );
            std::this_thread::sleep_for( dura  );
            return 0; 
            });
    std::future<int> f1 = task.get_future();
    std::thread(std::move(task)).detach();

    std::future<int> f2 = std::async(std::launch::async, [](){ 
            std::chrono::milliseconds dura( 2000  );
            std::this_thread::sleep_for( dura  );
            return 0; 
            });

    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([](std::promise<int> p){ 
            std::chrono::milliseconds dura( 2000  );
            std::this_thread::sleep_for( dura  );
            p.set_value(0); 
            },
            std::move(p)).detach();

    std::cout << "Waiting..." << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
        << f1.get() << " " << f2.get() << " " << f3.get() << "\n";
    return 0;
}
