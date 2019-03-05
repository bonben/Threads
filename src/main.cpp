#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>


const int n_iterations = 10000000;
const int n_loop  = 4;
const int n_tests = 10;


void start_thread(std::mutex* mutex, int tid)
{

	mutex->lock();
	// critical part
	mutex->unlock();

	return;
}

// parallel version
long long compute_threads (int n_threads)
{
	auto sum = 0ll;

	std::mutex mutex;
	std::vector<std::thread> threads(n_threads);

	for (auto i = 0; i < n_loop; i++)
		threads[i] = std::thread(start_thread, &mutex, i);

	for (auto i = 0; i < n_loop; i++)
		threads[i].join();

	return sum;
}

// sequential version
long long compute (int  n_loop) 
{
	long long sum = 0;
	// compute sum
	return sum;
}

int main(int argc, char const *argv[])
{
	auto sum = 0ll;

	// Compute with threads
	std::cout << "Compute with threads   :"                   << std::endl;
	auto time = std::chrono::steady_clock::now();
	for (auto i = 0; i < n_tests; i++)
		sum = compute_threads(n_loop);
	auto delta = std::chrono::steady_clock::now() - time;
	std::cout << "Time  : " << (float) delta.count() /1000000 << std::endl;
	std::cout << "Result: " << sum                            << std::endl;

	// Compute without threads
	std::cout << "Compute without threads :"                  << std::endl;
	time = std::chrono::steady_clock::now();
	for (auto i = 0; i < n_tests; i++)
		sum = compute(n_loop);
	delta = std::chrono::steady_clock::now() - time;
	std::cout << "Time  : " << (float) delta.count() /1000000 << std::endl;
	std::cout << "Result: " << sum                            << std::endl;

	return 0;
}

