#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>

int main( int argc, char * argv [ ] ){

	std::map< std::string, unsigned int > english =
	{ { "one", 1 }, { "two", 2 }, { "three", 3 },
	{ "four", 4 }, { "five", 5 } };

	for( const auto& p : english )
	std::cout << p. first << " => " << p. second << "\n";

	auto p = english. insert( {"six", 6 } );
	p = english. insert( { "ten", 10 } );
	
	std::cout << "for key " << ( p. first -> first );
	if( p. second )
		std::cout << " inserted ";
	else
		std::cout << " the existing value is ";
	std::cout << ( p. first -> second ) << "\n";

	std::unordered_map< std::string, unsigned int > kazakh =
	{ { "bir", 1 }, { "eki", 2 }, { "ues", 3 },
	{ "toert", 4 }, { "bes", 5 } };
	std::string s = "eki";
	auto st = kazakh. find( s ); // Use ‘auto’ in real code.
	// Returns valid iterator (referring to a pair)
	// if element exists, otherwise. end( ).
	if( st != kazakh. end( ))
	std::cout << ( st -> first ) << " = "
	<< ( st -> second ) << "\n";
	else
	std::cout << s << " not found";

}