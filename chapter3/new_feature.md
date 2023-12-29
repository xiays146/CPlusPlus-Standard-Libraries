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
+ noexcept
  ```cpp
  void foo (int a) noexcept(x > 0){
    // do something
    // throw no exception when param x > 0
  }
  ```
+ constexpr
  enable expressions be evaluted at compile time
  ```cpp
  constexpr int square(int x){
    return x * x;
  }
  float array[square(2)];  // --> use a const value to init a float array

  std::array<float, std::numeric_limits<char>::max()> data;  // --> the max char from numeric is a const value
  ```
+ variadic templates
  ```cpp
  void print() {}
  
  template <typename T, typename ...Ts>
  void print(const T& fisrt, const Ts&... others){
    // std::cout << first << std::endl;
    print(others...);
  }
  ```
+ lambdas
  ```cpp
  auto func = [=, &x, y](const auto& e){ 
    return e * 3 + x - y;
    ++x;
    }
  ```
