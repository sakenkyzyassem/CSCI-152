
#ifndef STACK_INCLUDED 
#define STACK_INCLUDED  1

#include <iostream>
#include <initializer_list>

// stacknode is an 'incomplete type', because it does not 
// have value semantics. It is used only by stack.
// It is possible to define stacknode inside stack, and to make it
// private. I didn't do that, because it is not the most important
// thing and C++ is already hard like this. 


struct stacknode
{
   double val;
   stacknode* next;

   stacknode( double val )
      : val{ val } 
   { }

};


class stack 
{
   stacknode* first;

public: 
   stack( );               
      // Constructs empty stack. 

   stack( const stack& s );

   ~stack( );

   const stack& operator = ( const stack& s );

   stack( std::initializer_list<double> init ) 
      : stack( )
   {
      for( double d : init )
         push(d); 
   }

   void push( double d );  

   void pop( );

   void clear( );

   void reset( size_t s ); 

   double peek( ) const;

   size_t size( ) const; 

   bool empty( ) const; 

   friend std::ostream& operator << ( std::ostream& , const stack& ); 
}; 

std::ostream& operator << ( std::ostream& , const stack& );

#endif


