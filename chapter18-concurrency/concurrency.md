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
  + if use async(),, please try to pass all objects by value so that async() uses only local copies.
  + shared_future<>
  + avoid data race
  + as for async(), you can pass anything that is callable object, like function, member function, function object, lambda adn so on.
+ threads and promises
  + example
    ```cpp
    void doSomething(){
      ...
    }
    std::thread th(doSomething);
    th.join();
    ```
  + std::this_thread::get_id()
  + the only way to identify a thread, such as a master thread, is to compare it to its saved ID when it started.
    ```cpp
    std::thread::id masterID;
    void foo(){
      if (std::this_thread::get_id() == masterID){
        ...
      }
      ...
    }
    std::thread master(foo);
    masterID = master.get_id();
    ...
    std::thread salve(foo);
    ...
    ```
  + std::promise<typenmae>
  + std::packaged_task<>
+ start a thread om detail
  + operations of class future<>
    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/c7999e43-0a5f-48e9-b8e9-feb226ecff44)
  + operations of class thread
    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/8a6c8e9d-099d-4fee-8b58-3c8fb0d37928)
  + operation of this_thread  
    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/0716d784-5cc7-4025-b1ed-0b9be7b13eef)
+ problems
  + rules
    + The only safe way to concurrently access the same data by multiple threads without synchronization is when ALL threads only READ the data.
  + solve
    + mutexes and locks
    + condition variables
    + atomic data types
+ Mutexes adn lccks
  + example
    ```cpp
    int val;
    std::mutex lock;

    // thread 1
    lock.lock();
    val++; // operate val
    ...
    lock.unlock();

    // thread 2
    lock.lock();
    --val;
    ...
    lock.unlock();
    ```
  + lock and unlock automatically
    ```cpp
    int val;
    std::mutex lock;

    // thread 1
    {
      std::lock_guard<std::mutex> lg(lock);
      val++; // operate val
      ...
    } // ensure taht lock gets released here
    // thread 2
    {
      std::lock_guard<std::mutex> lg(lock);
      --val;
      ...
    }
    ```
  + maybe you need recursive_mutex sometime
  + multiple locks --> std::lock()
  + lock_guard and unique_guard example
    ```cpp
    ...
    bool readyFlag;
    std::mutex readyFlagMutex;

    void func1(){
      // do something thread2 needs as preparation
      ...
      {
        std::lock_guard<std::mutex> lg(readyFlagMutex);
        readyFlag = true;
      }
    }

    void func2(){
      // wait unitl readyFlag is true
      {
        std::unique_lock<std::mutex> ul(readyFlag);
        while (!readFlag){
          ul.unlock();
          std::this_thread::yield(); // hint to reschedule to the next thread
          std::this_thread::sleep_For(std::chrono::milliseconds(100)); // sleep for thread1 to access readyFlag
          ul.lock();
        }
      } // release lock

      // do whatever shall happen after thread1 has prepared things
      ...
    }
    
    ...
    ```
  + lazy initialization
    ```cpp
    class MyClass{
      private:
        mutable std::once_flag initDataFlag;
        void initData() const; // prepare data
      public:
        data getData() { // access data 
          std::call_once(initDataFlag, &MyClass::initData, this); // when access data, init it
          ...
      }
    };
    ```
+ condition variables
  + example 1
    ```cpp
    // include header
    bool readyFlag;
    std::mutex readMutex;
    std::condition_variable readCOndVar；

    void f1(){
      // do something thread2 needs as preparation
      ...
      {
        std::lock_guard<std::mutex> lg(readyFlagMutex);
        readyFlag = true;
      }
    readyCondVar.notify_one();
    }

    void f2(){
      // wait unitl readyFlag is true
      {
        std::unique_lock<std::mutex> ul(readyMUtex);
        readyCondVar.wait(ul, []{ return readyFlag; });
      } // release lock
      // do whatever shall happen after thread1 has prepared things
      ...
    }

    int main() {
      auto f1 = std::async(std::launch::async, f1);
      auto f2 = std::async(std::launch::async, f2);
    }
    ```
    
