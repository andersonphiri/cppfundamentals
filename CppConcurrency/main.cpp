#include <iostream>
#include <list>
#include <thread>
#include "ThreadsManagement.h"

int main() {
	std::string file{ "applicants.pdf" };
	std::cout << "[MAINUSER] started operation" << std::endl;
	std::thread thLongRunningOperation(LongRunningOperation);
	std::thread thbackgroundOperation(LongRunningOperationBackground);
	std::thread thDownloadthreadByRef(Download, std::ref(file));
	std::thread thDownloadthreadByConstRef(Download2, std::cref(file));
	std::cout << "[MAINUSER] started another operation" << std::endl;
	// wait for child thread to complete
	// check if child is joinable because a detached thread is not joinable
	if (thLongRunningOperation.joinable())
	{
		thLongRunningOperation.join();
	}
	if (thDownloadthreadByRef.joinable())
	{
		thDownloadthreadByRef.join();
	}

	if (thDownloadthreadByConstRef.joinable())
	{
		thDownloadthreadByConstRef.join();
	}

	// detach the background
	thbackgroundOperation.detach();
	//PAUSE TO WAIT FOR other background thread

	// mutex example
	auto rmresult = RunMutexes();
	system("pause");
	return 0;
}
// https://subscription.packtpub.com/video/programming/9781800566668/p15/video15_6/std-thread-functions-and-std-this-thread-namespace