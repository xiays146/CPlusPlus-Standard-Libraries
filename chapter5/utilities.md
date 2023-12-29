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
