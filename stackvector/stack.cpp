
#include "stack.h"

void stack::reset( size_t s )
{
   while( data. size( ) > s )
      data. pop_back( );
}

std::ostream& operator << ( std::ostream& out, const stack& st )
{
   out << "[ ";
   for( size_t i = 0; i != st. size( ); ++ i )
   {
      if( i != 0 ) 
         out << ", ";

      out << st. data[i];
   }
   out << " ]";
   return out; 
}
 
