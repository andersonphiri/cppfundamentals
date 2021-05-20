#pragma once
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <Windows.h>
std::list<int> g_Data;
std::list<int> g_DataBackground;
const int SIZE = 5000000;
// the long running operation
void LongRunningOperation() {
	std::cout << "[DOWNLOADER] started operation" << std::endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		g_Data.push_back(i);
	}
	std::cout << "[DOWNLOADER] finished operation" << std::endl;
}
void LongRunningOperationBackground() {
	std::cout << "[BACKGROUND] started operation" << std::endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		g_DataBackground.push_back(i);
	}
	std::cout << "[BACKGROUND] finished operation" << std::endl;
}
// passing arguments to thread functions
void Download(std::string& filename) {
	std::cout << "[DOWNLOADER ref] started operation. downloading file: " << filename << std::endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		g_Data.push_back(i);
	}
	std::cout << "[DOWNLOADER ref] finished downloading file: "<< filename << std::endl;
}
void Download2(const std::string& filename) {
	std::cout << "[DOWNLOADER cref] started operation. downloading file: " << filename << std::endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		g_Data.push_back(i);
	}
	std::cout << "[DOWNLOADER cref] finished downloading file: " << filename << std::endl;
}


// mutual exclusion and thread safety
std::list<int> threadSafeList;
const int SIZEMUTEX = 10000;
std::mutex g_Mutex;
void LongRunningOperation1() {
	std::cout << "[DOWNLOADER mutex worker 1] started operation" << std::endl;
	for (size_t i = 0; i < SIZEMUTEX; i++)
	{
		// acquire lock
		//if (g_Mutex.try_lock()) {
		//	threadSafeList.push_back(i);
		//	g_Mutex.unlock(); // release lock
		//}
		g_Mutex.lock();
		threadSafeList.push_back(i);
		g_Mutex.unlock(); // release lock
		
	}
	std::cout << "[DOWNLOADER mutex worker 1] finished operation" << std::endl;
}
void LongRunningOperation2() {
	std::cout << "[DOWNLOADER mutex worker 2] started operation" << std::endl;
	for (size_t i = 0; i < SIZEMUTEX; i++)
	{
		// acquire lock
		//if (g_Mutex.try_lock()) {
		//	threadSafeList.push_back(i);
		//	g_Mutex.unlock(); // release lock
		//}
		g_Mutex.lock();
		threadSafeList.push_back(i);
		g_Mutex.unlock(); // release lock

	}
	std::cout << "[DOWNLOADER mutex worker 2] finished operation" << std::endl;
}
void LockGuardExample() {
	std::cout << "[DOWNLOADER lock guard worker 2] started operation" << std::endl;
	for (size_t i = 0; i < SIZEMUTEX; i++)
	{
		std::lock_guard<std::mutex> mtx(g_Mutex);
		threadSafeList.push_back(i);
		//g_Mutex.unlock(); // no need to release lock, mtx will take care
	}
	std::cout << "[DOWNLOADER lock guard worker 2] finished operation" << std::endl;
}


int RunMutexes() {
	std::thread thLRO1(LongRunningOperation1);
	std::thread thLRO2(LongRunningOperation2);
	thLRO1.join();
	thLRO2.join();
	std::cout << "The thread safe count is: " << threadSafeList.size() << std::endl;
	return 0;
}

int ThreadInformation() {
	std::thread t1(LockGuardExample);
	HANDLE handle = t1.native_handle(); // only works in windows
	SetThreadDescription(handle, L"Anderson thread 1");
	auto id = t1.get_id();
	// get the number of available cpus
	int cores = std::thread::hardware_concurrency();
	t1.join();
	std::cout << "The number of available CPU cores: " << cores << std::endl;

	return 0;

}
