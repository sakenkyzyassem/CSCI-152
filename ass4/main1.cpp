
#include <random>
#include <sstream>

#include "set.h"
#include "timetable.h"
#include "timer.h"

// Append a number to string.

std::string addnumber( std::string s, long unsigned int i ) 
{
   std::ostringstream ind;
   ind << i;
   s += ind. str( );
   return s;
}
 

int main( int argc, char* argv[ ] )
{
   set abc = { "Assem", "Akhida", "Aru", "ARU" };
   std::cout<<abc<<"\n";

   abc.insert( "Assel" );
   abc.insert( "Aisha" );
   abc.insert( "Ayazhan" );
   abc.insert( "Akhida" );

   std::cout<<abc<<"\n";

   std::cout<< set::equal( "AsSem", "Assem" )<<"\n";
   std::cout<< set::equal( "Akhida", "Aru" )<<"\n";

   set def = { "aSSEL", "aIShA", "aYAZHAN" };
   std::cout<< subset( def, abc )<<"\n";
   std::cout<< subset( abc, def )<<"\n";

   std::cout<< abc.insert(def)<<"\n";
   std::cout<< def <<"\n";
   std::cout<< abc <<"\n";

   std::cout<< def.size() <<"\n";
   std::cout<< abc.size() <<"\n";

   abc.clear();
   def.clear();
   std::cout<< def <<"\n";
   std::cout<< abc <<"\n";

   set kaz; 

   std::cout << set::equal( "aStana", "AsTaNa" ) << "\n";
      // true  
   std::cout << set::equal( "astana", "Almaty" ) << "\n";
      // false. 
   std::cout << set::equal( "astana", "astana" ) << "\n"; 
      // true. 

   kaz. insert( "aqtobe" ); 
   std::cout << kaz. contains( "Aqtobe" ) << "\n";
   std::cout << kaz. contains( "Aqtau" ) << "\n";

   kaz. insert( "SZYMKENT" );
   std::cout << kaz. contains( "szymkent" ) << "\n";

   set szy;
   szy.insert( "szymkent" );
   std::cout<<subset( szy , kaz )<<"\n";

   std::cout << kaz << "\n"; 
   kaz. remove( "Szymkent" );
   std::cout << kaz << "\n";
   kaz. remove( "Aqtobe" );
   std::cout << kaz << "\n";

   timetable tab( std::string( "set" ));
   for( size_t s = 1000; s < 20000; s = 2 * s ) 
   {
      set someset1;

      timer tt; 
      size_t nr = 0;
      for( size_t k = 0; k != s; ++ k )
      {
         nr += someset1. insert( addnumber( "aa", rand( )));
         nr += someset1. insert( addnumber( "bb", rand( )));
      }

      auto someset2 = someset1;

      if( nr != someset1. size( )) throw std::runtime_error( "counting went wrong" );

      for( const auto& el : someset2 ) 
      {
         nr -= someset1. remove( el );  
      }

      if( nr != 0 || someset1. size( ) != 0 )
         throw std::runtime_error( "counting went wrong" ); 

      tab. insert( s, tt. time( )); 
   } 
  
   std::cout << tab << "\n"; 
   std::cout << "totaltime " << tab. totaltime( ) << "\n";

}


