#include <iostream>
#include <memory>
#include "tqueue.h"


// Simple queue on pointers
int main(int argc, char** argv) { 
	TQueue queue;
	Trapezoid tr;

	std::cout << "Enter n: ";
	int n; std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> tr;	
		std::cout << tr << std::endl;	
		queue.Push(tr);
		std::cout << queue;
		std::cout << std::endl;
		std::cout << "Length: " << queue.Length() << std::endl;
	}

	//for (int i = 0; i < n; i++) {
		queue.Pop();
		queue.Pop();
		queue.Pop();
		std::cout << queue;
		std::cout << std::endl;
		std::cout << "Length: " << queue.Length() << std::endl;
	//}
	
	return 0;
}
