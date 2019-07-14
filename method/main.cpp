#include <iostream>

void fibonacci(int n){
	size_t f;
	size_t prev = 1, last = 1;
	std::cout<<last<<" ";
	for(size_t i = 1; i < n; i++){
		std::cout<<last<<" ";
		size_t temp = last;
		last = last + prev;
		prev = temp;
	}
}

int main ( int argc, char * argv[] ){
	fibonacci( 9 );
}