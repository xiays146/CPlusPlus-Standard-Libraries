+ pairs and tuples
  + pair<>
  ```cpp
  typedef std::pair<int, float> IntFloatPair;
  IntFloatPair p(2, 5.1);

  std::get<0>(p);
  p.first;
  std::get<1>(p);
  p.second;
  std::tuple_size<IntFloatPair>::value; // --> 2
  std::tuple_element<0, IntFloatPair>::type; // --> int
  ```
+ tuple<>
  + accept aribitrary number of template arugments, defined as follow:
  ```cpp
  namespace std
  {
   template <typename ...Types> 
   class tuples;
  }
  ```
  + use *get<no_runtime_index>()* to access elements
  + use *make_tuple()* to create tuple , or (element1, element2, element3...), or initializer list
  + support for a reference arguments, so modify an element from tuple
  ```cpp
  using namespace std;
  
  string s;
  make_tuple(ref(s));  // yields type *tuple<string&>*, where the element refers to s

  tuple<float, int> test(1.2, 6);
  float x;
  int y;
  tie(ignore, y) = test; // create reference to y, while ignore the first value
  ```