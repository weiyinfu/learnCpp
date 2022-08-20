#include <chrono>
#include <ctime>
#include <iostream>
long long currentTimeMillis() {
    using namespace std::chrono;
    time_point<system_clock, milliseconds> tp =
            time_point_cast<milliseconds>(system_clock::now());
    auto tmp = duration_cast<milliseconds>(tp.time_since_epoch());
    long long timestamp = tmp.count();
    return timestamp;
}
long fibonacci(unsigned n) {
  if (n < 2)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
  std::cout << currentTimeMillis() << std::endl;
  auto start = std::chrono::system_clock::now();
  std::cout << "f(42) = " << fibonacci(42) << '\n';
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << "s\n";
}