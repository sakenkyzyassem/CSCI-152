
#include "queue.h"


void queue::ensure_capacity( size_t c ) 
{
   if( current_capacity < c )
   {

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      if( c < 8 ) 
         c = 8;
 
      double* newdata = new double[c];
      for( size_t s = 0; s < current_size; ++ s )
      {
         newdata[s] = data[ begin ];
         begin = next( begin );
      }

      current_capacity = c;
      begin = 0;
      end = current_size;

      delete[] data;
      data = newdata;
   }
}

void queue::printfields( std::ostream& out ) const
{
   out << "   current_size =     " << current_size << "\n";
   out << "   current_capacity = " << current_capacity << "\n";
   out << "   begin =            " << begin << "\n";
   out << "   end =              " << end << "\n";
}

void queue::checkinvariant( ) const 
{

   if( current_capacity == 0 )
   {
      std::cout << "current capacity == 0\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( begin >= current_capacity ) 
   {
      std::cout << "begin >= current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( end >= current_capacity )
   {
      std::cout << "end >= current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( current_size > current_capacity )
   {
      std::cout << "current_size > current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( ( begin + current_size ) % current_capacity != end )
   {
      std::cout << 
         "distance between begin and end does not fit to current_size\n";
      printfields( std::cout );  
      std::abort( );
   }
}

queue::queue( )
	: current_size{ 0 },
      current_capacity{ 5 },
      begin{ 0 },
      end{ 0 },  
      data{ new double [current_capacity] } 
{ }

queue::queue( const queue& q )
	: current_size{ q.current_size },
      current_capacity{ q.current_capacity },
      begin{ 0 },
      end{ q.current_size },  
      data{ new double [ current_capacity ] } 
{
	size_t j = q.begin;
	for(size_t i = 0; i < size(); i++)
	{
		data[i] = q.data[j];
		j = q.next(j);
	}
}

const queue& queue::operator = ( const queue& q )
{
	ensure_capacity( q.size() );

	if(size() != q.current_size)
	{
		delete[] data;
		current_size = q.current_size;
		data = new double [ current_size ];
	}
	size_t j = q.begin;
	begin = 0;
	end = size();

	for(size_t i = 0; i < size(); i++)
	{
		data[i] = q.data[j];
		j = q.next(j);
	}

	return q;
}

queue::queue( std::initializer_list<double> init )
	: current_size{ 0 },
      current_capacity{ init.size() },
      begin{ 0 },
      end{ 0 },  
      data{ new double [current_capacity] } 
{
	for( double el: init)
		push(el);
}

void queue::push( double d )
{
	ensure_capacity( end + 2 );
	data[ end ] = d;
	++end;
	++current_size;

}

void queue::pop( )
{
	if(size() != 0)
	{
		++begin;
		--current_size;
	}
	else
		std::runtime_error( "pop: queue is empty" );
}

// It's a present for you:
std::ostream& operator << ( std::ostream& out, const queue& q )
{
   out << "[";
   size_t i = q. begin; 
   for( size_t s = 0; s < q. size( ); ++ s )
   {
      if(s) out << ", ";
      else out << " ";
      out << q. data[i];

      i = q.next(i); 
   }
   out << " ]";
   return out;
}

