#include <iostream>
#include "trapezoid.h"
#include "tqueue.h"
 
// Simple queue on pointers
int main(int argc, char** argv) {
/* 	Trapezoid tr1, tr2;

	std::cin >> tr1;
	std::cin >> tr2;

    std::cout << "Area 1 = " << tr1.Area() << std::endl;
    std::cout << "Vertex Number 1 = " << tr1.VertexesNumber() << std::endl;

    std::cout << "Area 2 = " << tr2.Area() << std::endl;
    std::cout << "Vertex Number 2 = " << tr2.VertexesNumber() << std::endl;

	tr1 == tr2;

	Trapezoid tr10;

	tr10 = tr1;

	std::cout << tr1 << std::endl << tr2 << std::endl << tr10 << std::endl; */  
	TQueue queue;

	Trapezoid tr3, tr5, tr6, tr7;

	std::cin >> tr3;	
	std::cout << tr3 << std::endl;	
	queue.Push(tr3);
	std::cout << queue;
	std::cout << std::endl;
	
	std::cin >> tr5;
	queue.Push(tr5);
	std::cout << queue;
	std::cout << std::endl;
	
	std::cin >> tr6;
	queue.Push(tr6);
	std::cout << queue;
	std::cout << std::endl;

	std::cin >> tr7;	
	queue.Push(tr7);
	std::cout << queue;
	std::cout << std::endl;

	std::cout << queue;
	
	Trapezoid t;

	std::cout << std::endl;

	if (queue.Empty())
		std::cout << "Empty" << std::endl;
	else 
		std::cout << "Not empty" << std::endl;
	
	std::cout << "Length: " << queue.Length() << std::endl;

	std::cout << "Top: " << queue.Top();
	std::cout << std::endl;

	queue.Pop();

	std::cout << queue;
	std::cout << std::endl;

queue.Pop();
queue.Pop();
queue.Pop();
	std::cout << queue;
	std::cout << std::endl;
	
	return 0;
}
