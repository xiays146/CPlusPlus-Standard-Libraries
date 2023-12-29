+ namesapce std
  ```cpp
  using namesapce std
  cout << hex << 3.1 << endl;
  ```
  + pay attention to accidental name clashes or different behavior when using directive namesapce, such as in header files
+ header files
  + have no extensions
  ```cpp
  #include <iostream>
  #include <string>   // string class from C++
  #include <cstring>  // char* func from C
  #include <stdlib.h> // C header files
  ```
+ exceptions when error
  + for language support
  + for logic errors
  + for runtime errors     
  + use *what()*, *code()* to view the detail info
  + use *exception_ptr* to store the exception object and process it later
  + deriving from class *exception* to construct your own exception class
+ callable objects
  + pass a function object as args
  ```cpp
  void func(int x, int y);
  auto foo = [](){return 0;}
  // use func and foo as args
  ```
+ support for concurrency and multithreading
+ add *new* and *delete* operaters

