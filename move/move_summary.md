# Lessons Learned

* *const* disables move semantics
* Don't return by *const* value
* *const&&* is possible, but a semantic contradiction
* To always adopt values you can take by value and move
  - if move is cheap
* T&& and auto&& are *universal/forwarding references
  - Unliess T is not a local function template parameter
  - Unless the argument is const
  - Unless T is a type expression (e.g. T::value_type)
* std::string&& can be a universal reference 
  - in full specializations
* Universal references do not always forward
* Getters should return by value or should be overloaded on reference qualifiers
* Use auto&& in a generic range-based *for* loop
* The range-based *for* loop is broken
  - when iterating over references to temporaries
* Use std::move() for member functions
