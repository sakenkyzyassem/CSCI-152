
#ifndef STACK_INCLUDED 
#define STACK_INCLUDED  1

#include <iostream>
#include <initializer_list>
#include <vector>

// I have told that there are at least 4 ways to implement stack:
// 1. Do your own memory management using arrays on the heap. This is task 01.
// 2. Use std::vector from the library. This is this implementation.
// 3. Use a linked list doing own management. This approach I will show in 
//    class on tuesday. 
// 4. Use std::list from the library.
// 
// If done well, rpn( ) will work with any of the implementation.
// 
// Note that the implementation below is NOT A SOLUTION OF TASK 1, 
// because task 1 requires that you do the memory management by yourself. 

class stack 
{
   std::vector< double > data; 

public: 
   stack( ) { } 
      // Constructs empty stack. 

   // Essential methods (copy constructor, assignment and destructor)
   // must be written only, when the default behavior is insufficient.
   // The default behavior of an essential method is always to apply the 
   // essential method on the fields of the struct/class separately. 
   // In this case, the default behaviour of std::vector< > is already
   // what we want, so we don't write essential methods.  

   stack( std::initializer_list<double> init )
   {
      for( double d : init )
         data. push_back(d); 
   }

      // So that you can write s = { 1,2,3 };
      // You can use init. size( ) to see the size, and
      // for( double d : init ) to go through all 
      // elements in the initializer_list. 

   void push( double d ) { data. push_back(d); } 

   void pop( ) { data. pop_back( ); } 

   void clear( ) { data. clear( ); } 

   void reset( size_t s );

   double peek( ) const { return data. back( ); } 

   size_t size( ) const { return data. size( ); } 

   bool empty( ) const { return data. size( ) == 0; } 

   friend std::ostream& operator << ( std::ostream& , const stack& ); 
}; 

std::ostream& operator << ( std::ostream& , const stack& );

#endif


