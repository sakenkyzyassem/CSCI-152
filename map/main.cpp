
#include <iostream>
#include <sstream>
#include <random>

#include "map.h"
#include "timetable.h"
#include "timer.h"

std::string addnumber( std::string s, long unsigned int i )
{
   std::ostringstream ind;
   ind << i;
   s += ind. str( );
   return s;
}

size_t ascii( std::string s ){
   size_t ascii = 0;
   for(auto it = s.begin(); it != s.end(); it++ ){
      ascii += *it + 0;
   }

   return ascii;
}

int main( int argc, char * argv [ ] )
{
   map groups = { {"blackpink", 4}, {"NCT", 21}, {"NCT 2019", 21}, 
   {"NCT DREAM", 6}, {"Pentagon", 9}, {"IZ*ONE", 12} };

   std::cout<<groups.contains_key("Nct")<<"\n";
   std::cout<<groups.at("Nct DreaM")<<"\n";  

   try{ 
      groups.at("Nct U"); 
   }
   catch( std::out_of_range err ){
      std::cout<<"Error: "<<err.what()<<"\n";
      groups["NCT U"] = 7;
   }

   std::cout<<groups.insert("NcT", 5)<<"\n";
   std::cout<<groups.insert("Taemin", 1)<<"\n";
   std::cout<<groups.insert("Twice", 9)<<"\n";
   std::cout<<groups.insert("NCT U", 5)<<"\n";

   groups["NCT 127"] = 10;

   size_t nct = groups["Iz*one"];
   std::cout<<nct<<"\n";
   groups["NCT 2018"] = groups["Nct 127"] + groups["NCT DREAM"] + 2;
   groups.at("NCT")++;
   groups.at("NCT")--;

   std::cout<<groups.at("Nct 2018")<<"\n";
   std::cout<<groups.at("pentagon")<<"\n";
   std::cout<<groups.remove("k-pop")<<"\n";
   std::cout<<groups.remove("tWiCe")<<"\n";
   groups["TWICE"] = groups["pentagon"];
   map groups2 = groups;
   groups2.insert("EXO", 9);
   groups2.insert("WayV", 7);
   groups2["Red Velvet"] = 5;
   groups2["4Minute"] = 5;
   groups2["WekiMeki"] = groups.at("NCT 127");

   std::cout<<groups<<"\n";
   groups.printstatistics(std::cout);

   std::cout<<groups2<<"\n";
   groups2.printstatistics(std::cout);

   map test;
   size_t i = 0, j =0;

   for(char ch1='a'; ch1 <= 'z'; ch1++ ){
      for(char ch2='A'; ch2 <= 'Z'; ch2++ ){
         test[std::string({ch1, ch2})] = i*3+j;
         j++;
      }
      i++;
   }

   for(char ch1='A'; ch1 <= 'Z'; ch1++ ){
      for(char ch2='a'; ch2 <= 'z'; ch2++ ){
          try{ test.at(std::string({ch1, ch2})); }
          catch(std::out_of_range err){
            std::cout<<"Error "<<err.what()<<"\n";
          }
      }
   }

   std::cout<<test;
   test.printstatistics(std::cout);

   timetable tab( std::string( "map" ));

   for( size_t s = 1000; s < 50000; s = 2 * s )
   {
      map someset1;

      timer tt;
      size_t nr = 0;
      
      for(char ch1='a'; ch1 <= 'z'; ch1++ ){
         for(char ch2='a'; ch2 <= 'z'; ch2++ ){
            size_t z = rand();
            if(z != 0){
               someset1[std::string({ch1, ch2})] = z; 
               if(someset1[std::string({ch1, ch2})] == 0)
                  std::cout<<std::string({ch1, ch2})<<" did wrong\n";
            }
         }
      }

      size_t m, l;
      for( size_t k = 0; k != s; ++ k )
      {
         m = rand(); l = rand();
         while( m != 0 && l!= 0){
            someset1[addnumber("aa", rand( ))] = m ;
            someset1[addnumber("bb", rand( ))] = l ;
            m=0;l=0;
         }
      }

      for( size_t i = 0; i != someset1. getnrbuckets( ); ++ i ) 
      {
         for( const auto& s : someset1. getbucket(i))
         {
            if( s.second == 0 ) 
               std::cout<<s.first<<"==>"<<s.second<<"\n";
         }
      }
      

      auto someset2 = someset1;

      for( size_t i = 0; i != someset1. getnrbuckets( ); ++ i ) 
      {
         for( const auto& s : someset1. getbucket(i))
         {
            try{
               someset2.at( s.first );
            }
            catch(std::runtime_error err){
               std::cout<<"Error "<<err.what()<<"\n";
            }
         }
      }

      for( size_t i = 0; i != someset1. getnrbuckets( ); ++ i ) 
      {
         for( const auto& s : someset1. getbucket(i))
         {
            someset2.at( s. first ) = ascii( s.first );
         }
      }

      
      // We go through someset2, in order to make someset1 empty. 

      nr = someset2.size();
      for( size_t i = 0; i != someset2. getnrbuckets( ); ++ i ) 
      {
         for( const auto& s : someset2. getbucket(i))
         {
            nr -= someset1. remove( s.first ); 
         }
      }

      if( nr != 0 || someset1. size( ) != 0 )
      {
         std::cout << "nr = " << nr << "\n";
         std::cout << "someset1. size( ) = " << someset1. size( ) << "\n";
         throw std::runtime_error( "counting went wrong 2" );
      }

      someset1.clear();
      someset2.clear();

      std::cout << someset1.isempty();

      tab. insert( s, tt. time( ));
   }

   //std::cout<<someset1<<"\n";
   //std::cout<<someset2<<"\n";

   std::cout << tab << "\n";
   std::cout << "totaltime " << tab. totaltime( ) << "\n";

}


