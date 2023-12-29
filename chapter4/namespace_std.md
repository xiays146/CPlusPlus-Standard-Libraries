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
  #include <stdlib.h>
  ```
+ exceptions when error
  + for language support
  + for logic errors
  + for runtime errors     
  + use *what()* 
