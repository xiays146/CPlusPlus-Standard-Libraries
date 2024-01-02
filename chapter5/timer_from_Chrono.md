+ durations
  + use *ratio* to sepcify the fraction
  + a duration is a combination of a value representing the number if ticks and a fraction representing the unit in seconds
  ```cpp
  std::chrono::duration<int> twentySeconds(20);
  std::chrono::duration<double, std::ratio<60>> halfAMinute(0.5); // 60/1 --> one second
  std::chrono::duration<long, std::ratio<1, 1000>> oneMillisecond(1); // 1000/1 --> one second
  ```
  + easily calculating two duration in different unit 
  ```cpp
  chrono::seconds d1(42); // 42 seconds
  chrono::milliseconds d2(10); // 10 milliseconds
  auto d3 = d1 - d2; // 41990 milliseconds
  auto less = d1 > d2; // true
  ```
+ clocks and time-points
  + use steady_clock to count time but not system_clock when there is possible if timer is changed when code running