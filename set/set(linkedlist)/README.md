# Set 

### Format:
set < std::string >

### Run:
```
# In Linux Commend Line:
~? g++ main.cpp set.cpp -o any_name
# OR
~? g++ check.cpp set.cpp -o any_name
~? ./any_name
```

### Functions:
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
