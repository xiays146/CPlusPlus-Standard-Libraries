+ shared_ptr
  + multiple reference to a same object
  ```cpp
  use_count()
  make_shared<>()
  * // access object
  -> // access members
  ```
  + when the last owner end the ownership, it delete the resource associated
  ```cpp
  // when using new[], you have to pass a custom delete func
  std::shared_ptr<int> p (new int[10],
                          [](int* p){ delete[] p;});
  ```
  ```cpp
  class FileDeleter{
    private:
        std::string filename;
    public:
        FileDeleter (const std:;string& fn) : filename(fn) {}
        void operator()(std::ofstream * fp){
            fp->close();                    // close file
            std::remove(filename.c_str());  // delete file
        }
  };

  int main(){
    std::shared_ptr<std::ofstream> fp(new std::ofstream("test.txt"),
                                      FileDeleter("test.txt"));
  }
  ```
  + always directly initialize a smart pointer when you create the object with its associated resource
  ```cpp
  int *p = new int;
  shared_ptr<int> sp1(p); // ok
  shared_ptr<int> sp2(p); // error

  shared_ptr<int> sp3(new int);
  shared_ptr<int> sp4(sp4); // ok
  ```
  + use *.reset()* to give up all the ownership and set pointer to empty
  + use *.get()* to get the stored pointer
  + is not thread safe in general

+ unique_ptr