# CSCI-152 (Performance and Data Structures)

## Description:
Implementations of hash tables, map, queue and stack in c++. 

## Content:
```
CSCI-152
|
|---performance_comp
|   |_ sorttests.cpp
|   |_ Makefile
|   |_ stack.cpp
|   |_ stack.h
|   |_ timer.h
|   |_ timetable.h
|
|---queue
|   |_ main.cpp
|   |_ Makefile
|   |_ queue.cpp
|   |_ queue.h
|   |_ timer.h
|   |_ timetable.h
|
|---set
|   |_ set(linkedlist)
|   |   |_ main.cpp
|   |   |_ Makefile
|   |   |_ set.cpp
|   |   |_ set.h
|   |   |_ check.cpp
|   |   |_ timer.h
|   |   |_ timetable.h
|   |  
|   |_ set(vector)
|   |   |_ main.cpp
|   |   |_ main1.cpp
|   |   |_ main11.cpp
|   |   |_ Makefile
|   |   |_ set.cpp
|   |   |_ set.h
|   |   |_ timer.h
|   |   |_ timetable.h
|   |   
|   |_hash
|   |   |_ main.cpp
|   |   |_ Makefile
|   |   |_ set.cpp
|   |   |_ set.h
|   |   |_ timer.h
|   |   |_ timetable.h
|   |
|   |_map
|   |   |_ main.cpp
|   |   |_ Makefile
|   |   |_ map.cpp
|   |   |_ map.h
|   |   |_ timer.h
|   |   |_ timetable.h
|
|---stack
    |_ stack(linkedlist)
    |   |_ main.cpp
    |   |_ Makefile
    |   |_ stack.cpp
    |   |_ stack.h
    |   |_ timer.h
    |   |_ timetable.h
    |  
    |_ stack(vector)
        |_ main.cpp
        |_ Makefile
        |_ stack.cpp
        |_ stack.h
        |_ timer.h
        |_ timetable.h
        
```
----------------------------------------------------------
## Data structures:

### Hash table

#### Run:
```
# In Linux Commend Line:
g++ main.cpp set.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - contains(std::string& s) # checks if a string s exists in the set
                            # if exists returns true, false otherwise
 - insert(std::string& s) # inserts given string s into the set
 - remove(std::string& s) # removes and returns true in case a string s is in the set
                          # returns false otherwise
 - size() # returns the number of strings/elements in a set
 - isempty() # checks whether the set is empty or not (boolean function)
 - loadfactor() # calculates and returns the load factor of a set (average number of elements in a bucket)
 - standardev() # calculates and returns the std of elements in a set
 - clear() # deletes all the elements in a set
 - getnrbuckets() # returns the number of buckets in a set
 - getbucket(int i) # returns a list of strings in a i-th bucket 
```

### Map

#### Format:
map< std::pair< std::string, unsigned int > >

#### Run:
```
# In Linux Commend Line:
g++ main.cpp map.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - contains_key(std::string& key) # checks if a key exists in the set
                            # if exists returns true, false otherwise
 - insert(std::string& key, unsigned int val) # inserts given key and a value into the set
                                              # returns true if the insertion was a success (key was not present inthe set), false otherwise
 - at(std::string& key) # returns the value of the key in a set
                        # it is possible to change the value of a key, but not to create a new key
                        # throws an exception if the key is not present 
                        # HINT: use [] to add a key with defaault value 0 for it
 - remove(std::string& s) # removes and returns true in case a key was in the set
                          # returns false otherwise
 - size() # returns the number of pairs of elements in a set
 - isempty() # checks whether the set is empty or not (boolean function)
 - loadfactor() # calculates and returns the load factor of a set (average number of elements in a bucket)
 - standardev() # calculates and returns the std of elements in a set
 - clear() # deletes all the pairs of elements in a set
 - getnrbuckets() # returns the number of buckets in a set
 - getbucket(int i) # returns a list of strings in a i-th bucket 
 - rehash(int newnrofbuckets) #rehashes all of the pairs to fit in the given newnrofbuckets
 - check_rehash() # checks whether the loadfactor() > max_load_facotor (3.0 by defult)
                  # in which case doubles the number of buckets and rehashes every element, does nothing otherwise
```

### Queue

#### Format:
queue( double d )

#### Run:
```
# In Linux Command Line:
g++ main.cpp queue.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - push(double d) # push given double d to the end of the list
 - pop() # removes the first element in the list
         # throws an std::runtime_error if the list is empty
 - peek() # returns the first element in the list
 - size() # returns the number of elements in a list
 - clear() # deletes all the elements in a list
 - empty() # returns true if the list is empty
```     

### Set 

#### Format:
set < std::string >

#### Run:
```
# In Linux Commend Line:
~? g++ main.cpp set.cpp -o any_name
# OR
~? g++ check.cpp set.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - top () # returns the element at the top
 - contains(std::string& s) # checks if a string s exists in the set
                            # if exists returns true, false otherwise
 - insert(std::string& s) # inserts given string s 
                          # returns true if the insertion was a success (string s was not present in the set)
                          # false otherwise
 - remove(std::string& s) # removes and returns true in case a string s was in the set
                          # returns false otherwise
 - size() # returns the number of elements in a set
 - height() # returns the height of the tree
 - isempty() # checks whether the set is empty or not (boolean function)
 - clear() # deletes all elements in a set
 - checksorted() #checks if the tree is sorted, throws an exception if it is not
```

### Set 

#### Format:
set < std::string >

#### Run:
```
# In Linux Commend Line:
~? g++ main.cpp set.cpp -o any_name
~? ./any_name
```

#### Functions:
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

### Stack (linked list)

#### Format:
stack < double val >

#### Run:
```
# In Linux Command Line:
g++ main.cpp stack.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - push(double d) # push given double d to the top of the list
 - pop() # removes the top element in the list
 - peek() # returns the top element in the list
 - size() # returns the number of elements in a list
 - clear() # deletes all the elements in a list
 - empty() # returns true if the list is empty
 - reset( int s ) #removes s number of elements from the top of the list
```

### Stack (vector)

#### Format:
stack < double val >

#### Run:
```
# In Linux Command Line:
g++ main.cpp stack.cpp -o any_name
~? ./any_name
```

#### Functions:
```
 - push(double d) # push given double d to the top of the list
 - pop() # removes the top element in the list
 - peek() # returns the top element in the list
 - size() # returns the number of elements in a list
 - clear() # deletes all the elements in a list
 - empty() # returns true if the list is empty
 - reset( int s ) #removes s number of elements from the top of the list
```
