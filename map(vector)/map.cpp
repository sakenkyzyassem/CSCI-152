
#include "map.h"

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

map::listofpairs::const_iterator 
map::find( const listofpairs& lst, const std::string& key )
{
   auto p = lst. begin( );
   while( p != lst. end( ) && !equal( p -> first, key ))
      ++ p;
   return p; 
}

map::listofpairs::iterator
map::find( listofpairs& lst, const std::string& key )
{
   auto p = lst. begin( );
   while( p != lst. end( ) && !equal( p -> first, key ))
      ++ p;
   return p;
}
  
bool map::contains_key( const std::string& key ) const{
   
   listofpairs lst = getbucket( key );
   auto p = find( lst, key );

   if(  p != lst.end() )
      return true;
   else
      return false;
}

bool map::insert( const std::string& key, unsigned int val ){

   listofpairs& lst = getbucket( key );
   auto p = find( lst, key );

   if( p == lst.end() ){
      lst.emplace_back( key, val );
      map_size++;
      check_rehash();
      return true;
   }
   else
      return false;
}

unsigned int& map::operator[] ( const std::string& key ){
   
   insert( key, 0 );

   listofpairs& lst = getbucket( key );
   auto p = find( lst, key );

   return p -> second;
}

unsigned int& map::at( const std::string& key ){
   
   listofpairs& lst = getbucket( key );
   auto p = find( lst, key );

   if(  p != lst.end() )
      return p -> second; 
   else
      throw std::out_of_range( "at( ): string not found" );
}

unsigned int map::at( const std::string& key ) const {

   listofpairs lst = getbucket( key );
   auto p = find( lst, key );

   if( p != lst.end() )
      return p -> second;
   else
      throw std::out_of_range( "at( ): string not found" );
} 

void map::rehash( size_t newbucketsize ){

   if( newbucketsize < 4 )
      newbucketsize = 4;

   std::vector< listofpairs > newbuckets{ newbucketsize };

   for( size_t i = 0; i < buckets.size(); i++){
      for(auto it = buckets[i].begin();
         it != buckets[i].end(); ++it){
         size_t ind = hash( it -> first ) % newbuckets.size();
         newbuckets[ind].emplace_back( *it );
      }
   }
   buckets = newbuckets;
}

void map::check_rehash( ){

   if( loadfactor() > max_load_factor )
      rehash( 2 * buckets.size() );

}

bool map::remove( const std::string& key ){
   
   listofpairs lst = getbucket( key );
   auto p = find( lst, key );

   if( p != lst.end() ){
      lst.erase(p);
      map_size--;
      return true;
   }
   else
      return false;
}

double map::standarddev( ) const  
{
   double sum = 0.0;
   double lf = loadfactor();

   for ( const auto& l : buckets )
   {
      double dif = l.size() - lf;
      sum += dif*dif;
   }

   return sqrt( sum / buckets. size( ));
}

void map::clear( ) 
{
   for( auto& l : buckets )
      l. clear( ); 

   map_size = 0; 
}

std::ostream& map::print( std::ostream& out ) const{
   
   for( size_t i = 0; i < buckets.size(); ++i ){
      
      out<<"bucket["<<i<<"]:  { ";
      
      for( auto it = buckets[i].begin(); it != buckets[i].end(); it++)
         if( it != buckets[i].begin() )
            out<<", "<<it -> first<<"/"<<it -> second;
         else
            out<<it -> first<<"/"<<it -> second;

      out<<" }\n";
   }

   return out;
}

std::ostream& map::printstatistics( std::ostream& out ) const
{
   out << "set size =            " << size( ) << "\n";
   out << "load factor =         " << loadfactor( ) << " ( max = " << 
                                      max_load_factor << " )\n";
   out << "standard deviation =  " << standarddev( ) << "\n";
   return out;
}


