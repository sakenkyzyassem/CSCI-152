# Set 

### Format:
set < std::string >

### Run:
```
# In Linux Commend Line:
~? g++ main.cpp set.cpp -o any_name
~? ./any_name
```

### Functions:
```
 - equal( std::string& s1, std::string& s2 ) # case insensitive check of two strings s1 & s2
 - contains(std::string& el) # checks if a string el exists in the set
                            # if exists returns true, false otherwise
 - insert(std::string& el) # inserts given string el 
                          # returns true if the insertion was a success (string el was not present in the set)
                          # false otherwise
 - insert(const set& s) # insers elements in set s and returns the number of elements added to the set
 - remove(std::string& el) # removes and returns true in case a string s was in the set
                          # returns false otherwise
 - remove(const set& s) # removes elements in the set s and returns the number of successes 
 - size() # returns the number of elements in a set
 - clear() # deletes all elements in a set
 - subset(set& s1, set& s2) # rturns true if s1 is a subset of s2
```
