+ overview
  + how to start multiple threads
  + concurrent data access
  + mutexes adn locks, condition variables, atomics
+ async()
  + overview

    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/cf0f85ef-adea-41fd-aa0e-ac63e1488928)

  + example
 
    the example is faster than single thread version, when is same fast as the single thread version when the platform is not support parallel.
    ```cpp
    int func1(){
      ...
      return 1;
    }
  
    int func2(){
      ...
      return 2;
    }
  
    int main(){
      std::future<int> result1(std::async(func1));
      int result2 = func2();
      int result = result1.get() + result2;
    }
    ```
+ if the operator return anything, using:
  ```cpp
  std::future<void> result(std::async(...));
  ```
+ using a lambda
  ```cpp
  std::async([]{...});
  ```
+ force func to launch now
  ```cpp
  std::async(std::launch::async, foo); // if cannot launch when call, it throws a std::system_eror exception
  ```
    
