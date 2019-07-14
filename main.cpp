#include <iostream>
#include <string>
#include <map>
#include <list>

#include "stack.h"

struct comparator{

	bool operator () (const std::string key1, const std::string key2){
		return key1.size() < key2.size();
	}

};

stack fibonacci(int n){
	double num = 0;
	stack st;
	st.push(1.0);

	for(size_t i = 1; i < n; i++){
		if(i != 1){
			double m1 = st.peek();st.pop();
			double m2 = st.peek();
			num = m1 + m2;
			st.push(m1); st.push(num);
		}
		else{
			double m = st.peek(); 
			num += m;
			st.push(num);
		}
	}

	return st;
}

int main( int argc, char * argv [] ){
	
	
	stack st = fibonacci(5.0);

	for(int i = 0; i<5; i++){
		std::cout<<st.peek()<<" ";
		st.pop();
	}


	std::map<std::string, size_t, comparator> english = { { "one", 1 }, { "two", 2 }, { "three", 3 },
	{ "four", 4 }, { "five", 5 } };

	std::list <std::string> str = {"Hello", "my", "name", "is"};

	for(auto el: str){
		try{
			english.at(el) = el.size() *2 ;
		}
		catch(std::out_of_range err){
			std::cout<<"string "<<el<<" does not exists\n";
		}
	}

	for( auto p: english)
		std::cout<<p.first<<" || "<<p.second<<"\n";

}