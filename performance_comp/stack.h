
#ifndef STACK_INCLUDED 
#define STACK_INCLUDED  1

#include <iostream>
#include <initializer_list>

class stack 
{
   size_t current_size;
   size_t current_capacity; 

   double* data; 

   void ensure_capacity( size_t c );

public: 
   stack( );               

   stack( const stack& s );

   ~stack( )  { delete[] data; }

   const stack& operator = ( const stack& s );

   stack( std::initializer_list<double> d );

   void push( double d );  

   void pop( );

   void clear( ) { current_size = 0; }

   void reset( size_t s ) { current_size = s; }

   double peek( ) const { return data[size()-1]; }

   size_t size( ) const { return current_size; } 

   bool empty( ) const{ return current_size == 0; } 

   friend std::ostream& operator << ( std::ostream& , const stack& ); 
}; 

std::ostream& operator << ( std::ostream& , const stack& );

#endif


