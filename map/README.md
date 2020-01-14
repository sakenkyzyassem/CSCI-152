# Map

### Format:
map( std::pair< std::string, unsigned int > )

### Run:
```
# In Linux Commend Line:
g++ main.cpp map.cpp -o any_name
~? ./any_name
```

### Functions:
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
