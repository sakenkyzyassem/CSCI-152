
#include "set.h"

bool set::equal( const std::string& s1, const std::string& s2 ){

	if ( s1.size() == s2.size() ){

		for(auto it1 = s1.begin(), it2 = s2.begin(); 
			it1 != s1.end(), it2 != s2.end(); ++it1, ++it2 ){
			char ch1 = tolower( *it1 );
			char ch2 = tolower( *it2 );

			if( ch1 != ch2 )
				return false;

		}
		return true;
	}
	else
		return false;
	
}

bool set::contains( const std::string& el ) const{

	for( auto it = data.begin(); it != data.end(); ++it ){
		if( equal(*it, el) )
			return true;
	}

	return false;
}

bool set::insert( const std::string& el ){

	if( !contains(el) ){
		data.push_back(el);
		return true;
	}

	return false;
}

size_t set::insert( const set& s ){
	size_t n = 0;
	for(auto it = s.begin(); it != s.end(); ++it ){
		if( insert( *it ) )
			++n;
	}

	return n;
}

bool set::remove( const std::string& el ){
	
	if( contains(el) ){
		for(auto it = data.begin(); it != data.end(); ++it ){
			
			if( equal(*it, el) ){	
				std::swap( *it, data.back() );
				break;
			}
		}
		//std::cout<<"\n";
		data.pop_back();
		return true;	
	}

	return false;
}

size_t set::remove( const set& s ){
	size_t n = 0;

	for(auto it = s.begin(); it != s.end(); ++it ){
		if( remove( *it ) )
			++n;
	}

	return n;
}	

std::ostream& operator << ( std::ostream& out, const set& s ){
	
	out<<"{ ";
	for(set::const_iterator it = s.begin(); it != s.end(); ++it){
		if( it != s.begin() )
			out<<", ";
		out<< *it;
	}
	out<<" }";

	return out;
}

bool subset( const set& s1, const set& s2 ){

	size_t subs;
	for(auto it1 = s1.begin(); it1 != s1.end(); ++it1 ){
		subs = 0;
		for(auto it2 = s2.begin(); it2 != s2.end(); ++it2 ){
			if( set::equal( *it1, *it2 ) ){
				subs = 1;
				break;
			}
		}
		if ( subs == 0 )
			return false;
	}

	return subs;
}

