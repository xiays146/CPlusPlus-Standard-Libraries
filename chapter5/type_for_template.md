+ type traits   
  + simplize overload
  ```cpp
  template <typename t>
  void foo_impl(t val, true_type); // provide integral verison

  
  template <typename t>
  void foo_impl(t val, false_type); // provide floating-point verison
  
  template <typename T>
  void foo(T val)
  {
    foo_impl(val, std::is_integral<T>());
  }
  ```
  ```cpp
  template <typename T1, typename T2>
  typename std::comman_type<T1, T2>::type min(const T1&x, const T2&y);
  ```
+ reference wrapper
  + use *std::ref()* or *std::cref()* allows function templates to work on references without specialization
  ```cpp
  template <typename T>
  void foo(T val);
 
  int x;
  foo(std::ref(x)); // T becomes int &
  foo(std::cref(x)); // T becomes const int &
  
  ```
  ```cpp
  std::vector<MyClass&> coll; // error
  std::vector<std::reference_wrapper<MyClass>> coll; // ok
  ```
+ function type wrapper
  + allows you to use callable objects(functions, member functions, function objects, and lambdas) as first-class objects
  ```cpp
  void func(int x, int y);

  // initialize collections of tasks
  std::vector<std::function<void(int, int)>> tasks;
  tasks.push_back(func);
  tasks.push_back([](int x, int y){
    // do something
  });

  // call tasks
  for (const auto e : tasks) // auto --> std::function<void(int, int)>
  {
    e(13, 45);
  }
  ```
+ min and max value
  ```cpp
  std::min(a, b, cmp);
  std::max(a, b, cmp);
  std::max<float>(a, b, cmp); // explictly the type of template arguments
  std::minmax(a, b, cmp); // return a std::pair<>
  ```
+ swap values
  + save time by swapping internal members rather than by assigning the objects
+ std comparison operators
  + four function template define the comparison operators !=, >, <=, >= by calling the operators == and <, in <utility>
  ```cpp
  #include <utility>
  class X{
    public:
        bool operator==(const X& x) const; 
        bool operator<(const X& x) const; 
        // other impl
  };

  void foo()
  {
    using namespace std::rel_ops; // make !=, >, etc., available in global scope
    X a, b;
    if (a != b)
    {
        // ok 
    }
    if (a > b)
    {
        // ok
    }
  }
  ```