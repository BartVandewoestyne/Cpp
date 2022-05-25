#include <atomic>
#include <cstddef>
#include <iostream>
#include <thread>
#include <vector>

namespace {
template <typename Incrementable>
void gobots(Incrementable& value, volatile std::size_t num_incs) {
    // num_incs is volatile to prevent the compiler from optimizing this into
    // value += num_incs.
    for (std::size_t i = 0; i < num_incs; ++i) {
        ++value;
    }
}

template <typename Incrementable>
void run_test(std::size_t const num_threads, std::size_t const num_incs) {
    Incrementable value{0};
    std::vector<std::thread> threads(num_threads);
    for (auto& t : threads) {
        t = std::thread(&gobots<Incrementable>, std::ref(value), num_incs);
    }

    for (auto& t : threads) {
        t.join();
    }
    std::size_t const expected = num_threads * num_incs;
    std::cout << "Value should be " << expected << ". It is: " << value << "\n";
}
}

int main(int argc, char** argv) {
    std::size_t const num_threads = 8;
    std::size_t const num_incs = 10000;
    std::cout << "non atomic: ";
    run_test<std::size_t>(8, num_incs);
    std::cout << "    atomic: ";
    run_test<std::atomic<std::size_t>>(8, num_incs);
}
