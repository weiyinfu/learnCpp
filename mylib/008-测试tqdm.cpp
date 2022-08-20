#include <chrono>
#include <iostream>
#include <thread>
#include "clusterkit.hpp"

int main() {
    auto x = clusterkit::tqdm(10, "haha");
    for (int i = 0; i < 10; i++) {
        x.update(1);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}