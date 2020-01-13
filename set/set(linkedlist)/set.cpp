
#include "set.h"

void print( std::ostream& out, const treenode* n, size_t indent )
{

   for( size_t i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


void checksorted( 
          treenode* n, 
          const std::string* lowerbound, 
          const std::string* upperbound )
{
   while(n) 
   {
      if( lowerbound && !before( *lowerbound, n -> val ))
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         std::abort( );
      }

      if( upperbound && !before( n -> val, *upperbound ))
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         std::abort( );
      }

      checksorted( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


// Used by copy constructor and assignment:

void writecopy( treenode** to, treenode* from )
{
   while( from )
   {
      *to = new treenode{ from -> val };

      writecopy( & (*to) -> left, from -> left );
      to = & (*to) -> right;
      from = from -> right;
   }
}

// Used by destructor:

void deallocate( treenode* n )
{
   while(n)
   {
      deallocate( n -> left );
      treenode* bye = n;
      n = n -> right;
      delete bye;
   }
}

size_t log_base2( size_t s ){

   size_t ans = 0;
   while( s > 1 ){
      ++ans;
      s = s / 2;
   }

   return ans;
}

// From previous task:

bool equal( const std::string& s1, const std::string& s2 ){

   if ( s1.size() == s2.size() ){

      for(auto it1 = s1.begin(), it2 = s2.begin(); 
         it1 != s1.end(), it2 != s2.end(); ++it1, ++it2 ){
         char ch1 = tolower( *it1 );
         char ch2 = tolower( *it2 );

         if( ch1 != ch2 )
            return false;

      }
      return true;
   }
   else
      return false;

}

bool before( const std::string& s1, const std::string& s2 ){

   for(auto it1 = s1.begin(), it2 = s2.begin(); 
      it1 != s1.end(), it2 != s2.end(); it1++, it2++ ){
      
      char ch1 = tolower( *it1 );
      char ch2 = tolower( *it2 );
      
      if( ch1 == ch2 )
         continue;
      else if( ch1 > ch2 )
         return false;
      else
         return true;  
   }
   if( s1.size() < s2.size() )
      return true;
   else
      return false;
}


const treenode* find( const treenode* n, const std::string& el ){

   if ( !n )
      return NULL;   

   if( equal( n -> val, el ) )
      return n;
   else if( before( n -> val, el ) )
      return find( n -> right, el );
   else
      return find( n -> left, el );
   
}

treenode** find( treenode** n, const std::string& el ){

   if( (*n) == nullptr || equal ( (*n) -> val, el ) )
      return &(*n);
   
   if( before( (*n) -> val, el ) )
      return find( & (*n) -> right, el );
   else
      return find( & (*n) -> left, el );
}

void rightinsert( treenode** into, treenode* n ){
   
   while( (*into) != nullptr )
      into = & ( (*into) -> right );

   (*into) = n;
}


size_t size( const treenode* n ){

   if( n == nullptr )
      return 0;
   else
      return 1 + size( n -> left ) + size( n -> right );

}

size_t height( const treenode* n ){

   if ( n ){
      size_t left_max, right_max;

      left_max = height(n -> left);
      right_max = height(n -> right);
      
      if( left_max > right_max)
         return left_max + 1;
      else
         return right_max + 1;
   }
   else
      return 0;
      
}

bool set::contains( const std::string& el ) const 
{
   return find( tr, el ) != nullptr; 
}

 
bool set::insert( const std::string& el ){

   if ( !contains( el ) ){
      treenode** temp;
      temp = find( &tr, el );   

      treenode* new_node = new treenode{ el };
      *temp = new_node;

      return true;
   }

   return false;
}

bool set::remove( const std::string& el ){

   if( contains( el ) ){
      treenode** n;
      n = find( &tr, el );

      if( (*n) -> left == nullptr && (*n) -> right == nullptr ){
         delete *n;
         *n = nullptr;
      }
      else if( (*n) -> left == nullptr){ 
         treenode* temp = *n;
         *n = (*n) -> right;
         delete temp;
      }
      else if ( (*n) -> right == nullptr ){
         treenode* temp = *n;
         *n = (*n) -> left;
         delete temp;
      }
      else{
         rightinsert( & (*n) -> left, (*n) -> right );
         treenode* temp = *n;
         *n = (*n) -> left;
         delete temp;
      }

      return true;
   }

   return false;
}


void set::checksorted( ) const
{
   ::checksorted( tr, nullptr, nullptr );
}


std::ostream& set::print( size_t indent, std::ostream& out ) const
{
   ::print( out, tr, indent );
   return out;
}


