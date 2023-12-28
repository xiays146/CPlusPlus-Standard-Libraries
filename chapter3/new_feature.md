+ template expressions
  ```cpp
  vectot<vector<int> >; //--> ok in each c++ vesion
  
  vectot<vector<int>>;  //--> ok since c++11
  ```

+ nullptr
  + use nullptr but not NULL

+ auto
  + use auto to simplize code

+ initializer_list
  + construct class
  + process multi parameters in functions

+ range-based loop
  ```
  for(a : b){
    c;
  }
  for(int i ： {1, 2, 3, 4}){
    // print i
  }
  ```
+ rvalue and lvalue
  ```cpp
  T && value
  ```
+ raw string literals
  ```cpp
  R"(xxx-string-here-xxx)"
  ```
