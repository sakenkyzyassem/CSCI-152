
#include "set.h"

bool equal( const std::string& s1, const std::string& s2 ){

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

size_t hash( const std::string& st ){

	size_t hash_val = 0, pow = 1;
	for( auto it = st.begin(); it != st.end(); it++){
		char ch = tolower( *it );
		hash_val += pow * ch;
		pow *= 31;
	}

	return hash_val;
}

bool set::contains( const std::string& s ) const{
      
    size_t ind = hash( s ) % buckets.size();
 
    for( auto it = buckets[ind].begin(); 
        it != buckets[ind].end(); it++){
        	if ( equal( *it, s ) )
         		return true;
        }

    return false;
}

bool set::simp_insert( const std::string& s ){

	if ( !contains(s) ){
		size_t ind = hash( s ) % buckets.size();

		buckets[ind].push_back( s );
	
		set_size++;
		return true;
	}
	else
		return false;
}

bool set::insert( const std::string& s ){

	if( simp_insert( s ) ){
		
		if ( loadfactor() >= max_load_factor)
			rehash( buckets.size() * 2 );

		return true;
	}
	return false;
}

void set::rehash( size_t newbucketsize ){
	
	if( newbucketsize < 4 )
		newbucketsize = 4;

	std::vector< std::list< std::string >> newbuckets =
	std::vector< std::list< std::string >> ( newbucketsize );

	for( size_t i = 0; i < buckets.size(); i++){
		for(auto it = buckets[i].begin();
			it != buckets[i].end(); ++it){
			size_t ind = hash( *it ) % newbuckets.size();
			newbuckets[ind].push_back( *it );
		}
	}
	buckets = newbuckets;
}

bool set::remove( const std::string& s ){

	if( contains( s ) ){
		size_t ind = hash(s) % buckets.size();

		for( auto it = buckets[ind].begin(); 
			it != buckets[ind].end(); it++){
				if ( equal( *it, s ) ){
					buckets[ind].erase(it);
					set_size--;
					break;
				}
		}

		return true;
	}
	else
		return false;
}

void set::clear( ){

	for( size_t ind = 0; ind != buckets.size(); ++ind )
		buckets[ind].clear();

	set_size = 0;
}

std::ostream& set::print( std::ostream& out ) const{

	for( size_t i = 0; i < buckets.size(); ++i ){
		
		out<<"bucket["<<i<<"]:  { ";
		
		for(std::list<std::string> :: const_iterator
		 it = buckets[i].begin(); 
		 it != buckets[i].end(); it++)
			if( it != buckets[i].begin() )
				out<<", "<<*it;
			else
				out<<*it;

		out<<" }\n";
	}

	return out;
}



std::ostream& set::printstatistics( std::ostream& out ) const
{
   std::cout << "set size =            " << size( ) << "\n";
   std::cout << "load factor =         " << loadfactor( ) << " ( max = " << max_load_factor << " )\n";
   std::cout << "standard deviation =  " << standarddev( ) << "\n";
   return out;
}


