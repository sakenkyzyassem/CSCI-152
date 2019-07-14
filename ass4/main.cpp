#include <iostream>
#include <string>
#include "set.h"
#include <cmath>
#include <sstream>
#include <algorithm>
#include <set>

int tests_run = 0;
int tests_correct = 0;

bool equal(const std::string& s1, const std::string& s2){
	if(s1.size() != s2.size()) return false;
	for(int i = 0; i < s1.size(); i++)
		if(s1[i] != s2[i]) return false;
	return true;
}

void checkString( const std::string s, const std::string&  given, const std::string& correct )
{
   tests_run++;	
   if( !equal(given, correct) )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkBool( const std::string s, const bool&  given, const bool& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkSizet( const std::string s, const size_t&  given, const size_t& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}


void checkDouble( const std::string s, const double& given, const double& correct )
{
   tests_run++;	
   if( std::abs( given - correct ) <= std::abs( correct ) * 1.0E-14 )
   {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   } else {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   }
}

int main(){
	std::string message = "EQUAL (abcde, abcde)";
	checkBool(message, set::equal( "abcde", "abcde" ), 1);
	message = "EQUAL (ABCDE, abcde)";
	checkBool(message, set::equal( "ABCDE", "abcde" ), 1);
	message = "EQUAL (aaaa, aaa)";
	checkBool(message, set::equal( "aaaa", "aaa" ), 0);
	message = "EQUAL (aaa, aaaa)";
	checkBool(message, set::equal( "aaa", "aaaa" ), 0);
	message = "EQUAL (abcde, edcba)";
	checkBool(message, set::equal( "abcde", "edcba" ), 0);
	message = "EQUAL (ab1Cde, ab1cde)";
	checkBool(message, set::equal( "ab1Cde", "ab1cde" ), 1);
	
	set s1;
	
	message = "SIZE()";
	checkSizet(message, s1.size(), 0);
	message = "INSERT (nolan)";
	checkBool(message, s1.insert("nolan"), 1);
	message = "INSERT (spielberg)";
	checkBool(message, s1.insert("spielberg"), 1);
	message = "INSERT (eastwood)";
	checkBool(message, s1.insert("eastwood"), 1);
	message = "INSERT (hitchcock)";
	checkBool(message, s1.insert("hitchcock"), 1);
	message = "SIZE()";
	checkSizet(message, s1.size(), 4);
	message = "INSERT (cameron)";
	checkBool(message, s1.insert("cameron"), 1);
	message = "INSERT (kubrick)";
	checkBool(message, s1.insert("kubrick"), 1);
	message = "SIZE()";
	checkSizet(message, s1.size(), 6);
	message = "INSERT (easTwooD)";
	checkBool(message, s1.insert("easTwooD"), 0);
	message = "INSERT (cameRon)";
	checkBool(message, s1.insert("cameRon"), 0);
	message = "INSERT (kuBricK)";
	checkBool(message, s1.insert("kuBricK"), 0);
	message = "SIZE()";
	checkSizet(message, s1.size(), 6);
	
	message = "CONTAINS (SPIELBERG)";
	checkBool(message, s1.contains("SPIELBERG"), 1);
	message = "CONTAINS (COPPOLA)";
	checkBool(message, s1.contains("COPPOLA"), 0);
	message = "CONTAINS (hitchcock)";
	checkBool(message, s1.contains("hitchcock"), 1);
	message = "CONTAINS (cameroni)";
	checkBool(message, s1.contains("cameroni"), 0);
	
	message = "REMOVE (scott)";
	checkBool(message, s1.remove("scott"), 0);
	message = "REMOVE (camerON)";
	checkBool(message, s1.remove("camerON"), 1);
	message = "REMOVE (cameron)";
	checkBool(message, s1.remove("cameron"), 0);
	message = "SIZE()";
	checkSizet(message, s1.size(), 5);
	
	message = "CONTAINS (SPIELBERG)";
	checkBool(message, s1.contains("SPIELBERG"), 1);
	message = "CONTAINS (hitchcock)";
	checkBool(message, s1.contains("hitchcock"), 1);	

	message = "INSERT (Kurosawa)";
	checkBool(message, s1.insert("Kurosawa"), 1);
	message = "INSERT (finCHER)";
	checkBool(message, s1.insert("finCHER"), 1);
	message = "INSERT (TaRaNtINo)";
	checkBool(message, s1.insert("TaRaNtINo"), 1);
	message = "INSERT (scorsese)";
	checkBool(message, s1.insert("scorsese"), 1);
	message = "SIZE()";
	checkSizet(message, s1.size(), 9);
	
	set s2 = {"chaplin", "bay", "jackson", "fincher"};
	message = "SIZE()";
	checkBool(message, s2.size(), 4);
	message = "CONTAINS (bay)";
	checkBool(message, s2.contains("bay"), 1);
	message = "CONTAINS (howard)";
	checkBool(message, s2.contains("howard"), 0);
	
	message = "INSERT (set s2)";
	checkSizet(message, s1.insert(s2), 3);
	message = "SIZE()";
	checkSizet(message, s1.size(), 12);
	message = "CONTAINS (chaplin)";
	checkBool(message, s1.contains("chaplin"), 1);
	message = "CONTAINS (jackson)";
	checkBool(message, s1.contains("jackson"), 1);
	
	set s3 = {"besson", "polanski", "fincher", "spielberg", "tarantino"};
	message = "SIZE()";
	checkSizet(message, s3.size(), 5);	
	message = "CONTAINS (polanski)";
	checkBool(message, s3.contains("polanski"), 1);
	message = "REMOVE (set s3)";
	checkSizet(message, s1.remove(s3), 3);
	message = "SIZE()";
	checkSizet(message, s1.size(), 9);
	message = "CONTAINS (spielberg)";
	checkBool(message, s1.contains("spielberg"), 0);
	message = "CONTAINS (polanski)";
	checkBool(message, s1.contains("polanski"), 0);
		
	s2.clear();
	message = "SIZE()";
	checkSizet(message, s2.size(), 0);
	message = "INSERT(besson)";
	checkBool(message, s2.insert("besson"), 1);
	message = "INSERT(fincher)";
	checkBool(message, s2.insert("fincher"), 1);
	message = "SUBSET (s2, s3)";
	checkBool(message, subset(s2, s3), 1);
	message = "SUBSET (s2, s1)";
	checkBool(message, subset(s2, s1), 0);
	set s4;
	message = "SUBSET (s4, s3)";
	checkBool(message, subset(s4, s3), 1);	
	
	std::stringstream ss_q;
	ss_q << s1;
	std::string sss(ss_q.str());
	tests_run++;
	if(sss.size() > 58 && sss.size() < 100)
		tests_correct++;

	message = "INSERT (set s2)";
	checkSizet(message, s4.insert(s2), 2);
	message = "EQUAL (set s2, set s4)";
	checkSizet(message, equal(s2, s4), 1);
	message = "EQUAL (set s1, set s4)";
	checkSizet(message, equal(s1, s4), 0);
	
	std::cout << "\nTESTS RUN: " << tests_run << std::endl;
	std::cout << "\nTESTS CORRECT: " << tests_correct << std::endl;		
	return 0;
}
