
#include "stack.h"


// This is called an 'anonymous namespace'. It means that
// the functions in the namespace are local in this file,
// i.e. invisible in other files. 

namespace
{

   // append a copy of the linked list starting in from, 
   // to *to.

   void appendcopy( stacknode* * to, stacknode* from )
   {
      while( from )
      {
         *to = new stacknode{ from -> val };

         to = & ( (*to) -> next );
         // to = & ( (**to). next );     // The same. 

         from = from -> next;
         // from = (*from). next;        // The same. 
      }

      *to = nullptr;
   }


   // deallocate the linked list starting with bye.

   void deallocate( stacknode* bye )
   {
      while( bye )
      {
         stacknode* f = bye;
         bye = bye -> next;
         delete f;  
      }
   }

  
   void copy( stacknode* *to, stacknode* from )
   {
      while( *to && from )
      {
         (*to) -> val = from -> val;
         to = & ( (*to) -> next );
         from = from -> next;
      }

      if( *to )
      {
         deallocate( *to );
         *to = nullptr;
      }
      else
      {
         // This means that *to is empty.
         // from may be empty too. 
  
         appendcopy( to, from );
      }
   }  
}


stack::stack( )
   : first{ nullptr }  
{ }


stack::stack( const stack& s )
{
   appendcopy( &first, s. first ); 
}


// There are two implementations of assignment, the first implementation 
// tries to reuse existing stacknodes as much as possible.
// At the end, if *this has stacknodes left, they are deallocated.
// If s has stacknodes left, *this is extended. 
//
// The second, simpler implementation always deletes *this, 
// and after that allocates a completely new stack with a copy of
// s. 

const stack& stack::operator = ( const stack& s )
{
   copy( & ( this -> first ), s. first );
   return s;

#if 0
   // This is an alternative, simpler implementation.

   // Against self assignment:

   if( first != s. first )
   {
      deallocate( first );
      appendcopy( &first, s. first );  
   }
   return s;
#endif 
}


stack::~stack( )
{
   deallocate( first ); 
}

void stack::push( double d )
{
   stacknode* f = new stacknode{d};
   ( f -> next ) = first;
   first = f; 
}


void stack::pop( )
{
   stacknode* f = first; 
   first = first -> next;
   delete f; 
}

void stack::clear( )
{
   deallocate( first );
   first = nullptr; 
}

void stack::reset( size_t s )
{
   for( size_t k = size( ); k > s; -- k ) 
      pop( ); 
}

double stack::peek( ) const
{
   return first -> val; 
}


size_t stack::size( ) const
{
   size_t s = 0;
   for( const stacknode* f = first; f != nullptr; f = f -> next )
      ++ s;
   return s;
}

bool stack::empty( ) const
{
   return first == nullptr;
}

std::ostream& operator << ( std::ostream& out, const stack& st )
{
   out << "[";
   for( const stacknode* n = st. first; n; n = n -> next ) 
   {
      if( n != st. first ) out << ", ";
      else out << " ";
      out << ( n -> val );
   }
   out << " ]";
   return out;
}

