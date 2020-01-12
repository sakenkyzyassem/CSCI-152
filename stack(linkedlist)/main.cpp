
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "stack.h"

// This is part of an evaluator for expressions in RPN. 
// If you implemented your stack correctly, it will work. 

// Is s an operator with one argument?

bool isoperator1( const std::string& s )
{
   return s == "exp" || s == "log" || s == "sqrt";
}

// Is s an operator with two arguments?

bool isoperator2( const std::string& s )
{
   return s == "+" || s == "-" || s == "*" || s == "/" ||
          s == "==" || s == "!=";
}

double apply1( const std::string& s, double d1 )
{
   // std::cout << "applying " << s << " on " << d1 << "\n";

   if( s == "exp" ) return exp(d1);
   if( s == "log" ) return log(d1);
   if( s == "sqrt" ) return sqrt(d1);
   
   std::abort( );  // Unreachable, if program written correctly. 
}
 
double apply2( const std::string& s, double d1, double d2 )
{
   // std::cout << "applying " << s << " on " << d1 << " and " << d2 << "\n";

   if( s == "+" ) return d1 + d2;
   if( s == "-" ) return d1 - d2; 
   if( s == "*" ) return d1 * d2;
   if( s == "/" ) return d1 / d2; 
   if( s == "==" ) return d1 == d2;
   if( s == "!=" ) return d1 != d2;

   std::abort( );  // Unreachable, if written well.
}

double makedouble( const std::string& s )
{
   return atof( s. c_str( ));
}

// Evaluate an expression in RPN:
 
double rpn( const std::vector<std::string> & expr )
{
   stack st; 

   for( const auto& e : expr )
   {
      std::cout << "next token " << e << "      ->   ";
      
      if( isoperator2( e )) 
      {
         if( st. size( ) < 2 ) 
            throw std::runtime_error( "no two numbers on stack" );

         double d2 = st. peek( ); st. pop( );
         double d1 = st. peek( ); st. pop( );
 
         st. push( apply2( e, d1, d2 )); 
      } 
      else 
      {
         if( isoperator1(e))
         {
            if( st. size( ) < 1 )
               throw std::runtime_error( "no number on stack" );

            double d1 = st. peek( ); st. pop( );
            st. push( apply1( e, d1 ));
         }
         else
            st. push( makedouble( e ));
      }
      std::cout << st << "\n";

   }

   if( st. size( ) != 1 )
      throw std::runtime_error( "expression is not well-formed" );
   
   return st. peek( ); 
}

int main( int argc, char* argv [ ] )
{
   // If you stack was implemented correctly, you can 
   // test the expression in the slides. The outcome is 116.

   std::vector< std::string > example = 
      { "100", "4", "3", "*", "2", "*", "1", "*", "+", "8", "-" };
   for( const std::string s : example )
      std::cout << s << " ";
   std::cout << "\n";
   std::cout << "The outcome is " << rpn( example ) << "\n\n";

   // sqrt(2) * sqrt(2) = 2.

   example = { "2", "sqrt", "2", "sqrt", "*" };
   for( const auto& s : example )
      std::cout << s << " ";
   std::cout << "\n";
   std::cout << "The outcome is " << rpn( example ) << "\n\n";

   stack s = { 1, 2, 3, 4, 5 };
   std::cout << s << "\n";
   s. reset(2 );
   std::cout << s << "\n";
   std::cout << s. empty( ) << "\n";
   return 0;
}

