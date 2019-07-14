
#include "stack.h"

// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c ) 
{
   if( current_capacity < c ) 
   {

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}

stack:: stack( ) 
  : current_size { 0 },
    current_capacity { 5 },
    data { new double [current_capacity] }
{ }

stack:: stack ( const stack& s ) :
   current_size { s.current_size },
   current_capacity { s.current_capacity },
   data { new double [current_capacity] } 
{
   for(size_t i = 0; i < current_size; ++i)
      data[i] = s.data[i];
}

stack:: stack ( std::initializer_list<double> d ) :
   current_size { d.size() },
   current_capacity { d.size() },
   data { new double[ current_capacity ] } 
{
   size_t i = 0;
   for ( double el: d ) 
   {
      data[i] = el;
      i++; 
   }
}

const stack& stack::operator = ( const stack& s )
{
   ensure_capacity ( s.current_capacity );

   if ( size() != s.size() )
   {
      delete[] data;
      current_size = s.size();
      data = new double [ current_size ];
   }

   for(size_t i = 0; i < current_size; i++)
      data[i] = s.data[i];

   return s;
}

void stack:: push ( double d ) 
{
   ensure_capacity  ( size() + 1 );

   data[ size() ] = d ; 
   current_size += 1;
}

void stack:: pop( ) 
{
   if( size() != 0 ) 
         current_size -= 1;
   else 
      throw std::runtime_error( "pop: stack is empty" );
}

std::ostream& operator << ( std::ostream& out, const stack& s) 
{
   for( size_t i = 0; i < s.size(); i++) 
      out << s.data[i]<<" ";

   return out;
}




