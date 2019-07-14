#include <iostream>
#include <string>

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

	size_t hash_val = 0;
	for( auto it = st.begin(); it != st.end(); it++){
		char ch = tolower( *it );
		hash_val = hash_val * 349 + ch;
	}

	return hash_val;
}

int main(){
	
	std::cout<<equal("Astana", "ASTANA")<<"\n";

	std::cout<<hash("Astana")<<" "<<hash("ASTANA")<<"\n";
}