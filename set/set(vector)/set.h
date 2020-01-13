
// Lab Exercise 4.

#ifndef SET_INCLUDED
#define SET_INCLUDED    1 

#include <iostream>
#include <string>
#include <vector>

class set
{
   std::vector< std::string > data;

public: 
   set( ) = default;   // empty set.
   set( const set& s ) = default;
   set& operator = ( const set& s ) = default; 
   ~set( ) = default;
   
   set( std::initializer_list< std::string > init ){
      for(std::string el: init){
         if( !contains( el ) )
            data.push_back( el );
      }
}
 
   bool contains( const std::string& s ) const;
    
   bool insert( const std::string& s );

   size_t insert( const set& s );

   bool remove( const std::string& s );

   size_t remove( const set& s );
   
   size_t size( ) const { return data.size(); }
   void clear( ) { data.clear( ); }


   using const_iterator = std::vector< std::string > :: const_iterator;
   const_iterator begin( ) const { return data. begin( ); }
   const_iterator end( ) const { return data. end( ); }

   static bool equal( const std::string& s1, const std::string& s2 );
};


std::ostream& operator << ( std::ostream& out, const set& s );

bool subset( const set& s1, const set& s2 );

inline bool equal( const set& s1, const set& s2 )
{
   return subset( s1, s2 ) && subset( s2, s1 );
}

#endif


