
#include <iostream>
#include <vector>
#include <algorithm>

#include "stack.h"
#include "timer.h" 
#include "timetable.h"


// Print a vector of integers:

std::ostream& operator << ( std::ostream& out, const std::vector< int > & vect )
{
   for( size_t i = 0; i != vect. size( ); ++ i )
      out << i << " : " << vect[i] << "\n";

   return out;
}


// Create a vector of size k filled with random ints:

std::vector< int > randomvector( size_t k )
{
   std::vector< int > res;
   for( size_t i = 0; i != k; ++ i )
      res. push_back( rand( ));
   return res;
}

void bubble_sort( std::vector< int > & vect )
{
   if( vect. size( ) < 2 ) return;
      // Every shorter vector is sorted.

   bool sorted = false;
   while( !sorted ) 
   {
      sorted = true; 
      for( size_t i = 0; i + 1 != vect. size( ); ++ i )
      {
         if( vect[i] > vect[i+1] )
         {
            std::swap( vect[i], vect[i+1] );
            sorted = false;
         }
      }
   }

}


void restore_heap( std::vector< int > & vect, size_t s )
{
   size_t p = 0;
   while( 2 * p + 1 < s )
   {
      if( 2 * p + 2 == s )
      {
         if( vect[p] < vect[ 2 * p + 1 ] )
            std::swap( vect[p], vect[ 2 * p + 1 ] );
         return; 
      }
      else
      {
         if( vect[p] < vect[ 2 * p + 1 ] || vect[p] < vect[ 2 * p + 2 ] )
         {
            if( vect[ 2 * p + 1 ] < vect[ 2 * p + 2 ] )
            {
               std::swap( vect[p], vect[ 2 * p + 2 ] );
               p = 2 * p + 2;
            }
            else
            { 
               std::swap( vect[p], vect[ 2 * p + 1 ] );
               p = 2 * p + 1;
            }
         }
         else
            return; 
      }
   }
}


void heap_sort( std::vector< int > & vect )
{
   if( vect. size( ) < 2 ) return;
      // Every shorter vector is sorted.

   // In the first pass, we establish the heap condition:

   for( size_t i = 1; i != vect. size( ); ++ i )
   {
      for( size_t p = i; p != 0; p = ( p - 1 ) / 2 )
      {
         if( vect[p] > vect[ ( p-1 ) / 2 ] )
            std::swap( vect[p], vect[ ( p - 1 ) / 2 ] );
      }      
   }

   size_t i = vect. size( );
   while(i)
   {
      --i;
      std::swap( vect[0], vect[i] );
     
      // And we restore heap condition between 0 and i: 

      restore_heap( vect, i ); 
   }

}


void quick_sort( std::vector< int > & vect )
{
   std::sort( vect. begin( ), vect. end( ));   
}


std::list< int > :: iterator 
findmin( std::list< int > :: iterator p1,
         std::list< int > :: iterator p2 )
{
   if( p1 == p2 ) 
      return p2;

   auto min = p1 ++ ;
   while( p1 != p2 )
   {
      if( *p1 < *min )
         min = p1;
      ++ p1;
   }

   return min; 
}


void insertion_sort( std::list< int > & lst ) 
{
   for( auto p = lst. begin( ); p != lst. end( ); ++ p ) 
   {
      auto m = findmin( p, lst. end( )); 
      std::swap( *p, *m ); 
   }
}

 
int main( int argc, char* argv[] )
{
   timetable alg1("quick1");
   timetable alg2("bubble1");
   timetable alg3("heap1");
   timetable alg4("insertion1");

   for(size_t s = 1000; s < 100000; s = 2 * s){
      std::vector<int> vect = randomvector (s);
      auto vect2 = vect;
      auto vect3 = vect;

      timer t;

      quick_sort(vect);
      alg1.insert( s, t.time() );
      t.clear();
      
      bubble_sort(vect2);
      alg2.insert( s, t.time() );
      t.clear();

      heap_sort(vect3);
      alg3.insert( s, t.time() );
      t.clear();

      std::list<int> lst;
      insertion_sort(lst);
      alg4.insert( s, t.time() );
   }

   std::cout << alg1 << "\n";
   std::cout << alg2 << "\n";
   std::cout << alg3 << "\n";
   std::cout << alg4 << "\n";

  /* timetable stacktimes( "stack with doubling" );
   for( size_t s = 1000; s < 200000; s = s + s )
   {
      timer tt;
      stack st;
      for( size_t i = 0; i < s; ++ i )
         st.push(i);
      stacktimes. insert( s, tt. time( ));
   }
   std::cout << stacktimes << "\n";*/

   return 0; 
}

 
