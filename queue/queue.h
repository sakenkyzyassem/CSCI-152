
#ifndef QUEUE_INCLUDED 
#define QUEUE_INCLUDED  1

#include <iostream>
#include <initializer_list>

struct queue
{
   size_t current_size; 
   size_t current_capacity; 
   size_t begin;
   size_t end;   

   double* data; 

   void ensure_capacity( size_t c );

   size_t next( size_t i ) const 
   {
      i = i + 1; 
      if( i == current_capacity )
         i = 0; 
      return i;
   }

   void checkinvariant( ) const;

   void printfields( std::ostream& ) const;

public: 
   queue( );               
      // Constructs empty queue. 

   queue( const queue& q );

   ~queue( ) { delete[] data; }

   const queue& operator = ( const queue& q );

   queue( std::initializer_list<double> init );

   void push( double d );  

   void pop( );

   void clear( )  
   { 
	  begin = 0; 
	  end = begin;
     current_size = 0; 
   }

   double peek( ) const { return data[ begin ]; }

   size_t size( ) const { return current_size; } 

   bool empty( ) const { return current_size == 0; }
   
   friend std::ostream& operator << ( std::ostream& , const queue& ); 
}; 

std::ostream& operator << ( std::ostream& , const queue& );

#endif


