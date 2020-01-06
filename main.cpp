#include <iostream>
#include <thread>
//#include <list>
//#include <string>
#include "ProgVar.cpp"

std::mutex mutex_lock;
static int counter = 0;

void inc() {
	std::cout << "in function inc thread num is:" << std::this_thread::get_id() << " " << std::endl;

	for (int i = 0; i < 4; ++i) {
		mutex_lock.lock();
		++counter;
		std::cout << "in for loop in inc, thread num is:" << std::this_thread::get_id() << std::endl;
		mutex_lock.unlock();
	}
}

void shit() {
	for (int i = 0; i < 100000; ++i) {
		++counter;
//		printf("shit's i is: %d \n", i);
	}
}

int main() {
//	std::cout << "Hello, World!" << std::endl;
//
//	std::thread t1(inc);
//	std::thread t2(inc);
//	std::thread t3(inc);

//	for (int i = 100000; i > 0; --i) {
//		--counter;
//		printf("main's i is: %d \n", i);
//	}
//	std::this_thread::sleep_for(std::chrono::milliseconds(100000));
//	t1.join();
//	std::this_thread::sleep_for(std::chrono::milliseconds(100000));
//	t2.join();
//	std::this_thread::sleep_for(std::chrono::milliseconds(100000));
//	t3.join();
//	using namespace std;
//	auto *l = new list<const char *>;
//	l->push_front("first");
//	l->push_front("second");
//	list<const char *> *temp = l;
//	temp->push_front("third");
//	for (int i = 0; i < 3; ++i) {
//		cout<< "l: " << l->front() << endl;
//		cout << "temp: " << temp->front() << endl;
//
//	}

	ProgVar *p = new ProgVar(3, "/sim/path");
	p->SetSim("sim/second");
	std::cout << p->GetSim() << std::endl;

//	printf("counter value is: %d \n", counter);
	return 0;
}