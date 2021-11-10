#include <iostream>
#include "tqueue.h"


// Simple queue on pointers
int main(int argc, char** argv) { 
	TQueue<Trapezoid> queue;
	std::shared_ptr<Trapezoid> tr(new Trapezoid(1, 2, 3, 4));


	std::cout << queue << std::endl;

	std::shared_ptr<Trapezoid> t;

	std::cout << "Enter n: ";
	int n; std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> *tr;	
		std::cout << *tr << std::endl;
		queue.Push(std::shared_ptr<Trapezoid>(new Trapezoid(*tr)));
		std::cout << queue;
		std::cout << std::endl;
		std::cout << "Length: " << queue.Length() << std::endl;
	}

	queue.Pop();
	std::cout << queue << std::endl;
	
	queue.Pop();
	std::cout << queue << std::endl;
	
	queue.Pop();
	std::cout << queue << std::endl;
	
	return 0;
}
