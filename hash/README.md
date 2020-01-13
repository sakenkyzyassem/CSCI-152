# Hash table

### Run:
```
# In Linux Commend Line:
g++ main.cpp set.cpp -o any_name
~? ./any_name
```

### Functions:
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
                          
