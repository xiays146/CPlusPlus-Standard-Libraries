+ overview
  + numeric_limits
  + ratio<>
  + numeric algorithms
  + valarray
+ random numbers and distributions
  + usage
  ```cpp
  std::default_random_engine dre;
  std::uniform_int_distribution< int > di(10, 20);  // [10, 20]
  for (size_t i = 0; i < 20; i++) {
      std::cout << di(dre) << " ";
  }
  std::cout << std::endl;
  
  std::uniform_real_distribution< double > dr(10.0, 20.0);  // [10.0, 20.0]
  for (size_t i = 0; i < 8; i++) {
      std::cout << dr(dre) << " ";
  }
  std::cout << std::endl;
  
  std::vector< int > v = {1, 2, 3, 4, 5, 6, 7};
  std::shuffle(v.begin(), v.end(), dre);

  unsigned int seed = ...; // maybe timestamp now
  std::default_random_engine dre2(seed); // use seed for the initial engine state

  // do not use a termporary engines
  std::shuffle(v.begin(), v.end(), std::default_random_engine()); // first shuffling
  std::shuffle(v.begin(), v.end(), std::default_random_engine()); // second shuffling with engine with fisrt state
  ```
  + engines
    + uniform_int_distribution
   
      ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/d0645e61-2a4d-4299-bd2a-d46a9b3b93ad)

    + uniform_real_distribution
   
      ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/f5251efb-e07a-4191-b332-9248416bc6a3)

    + bernoulli_distribution
   
      ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/470f4810-2916-4227-9592-828915c6354b)

    + poisson_distribution
   
      ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/c7657adf-13e6-42db-af8e-f9dae158e831)

    + normal_distribution
   
      ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/6f96aa18-9670-48af-bd05-bb546fafecad)

  + complex numbers
    + complex<>
  + global numeric functions
    + <cmath> and <cstdlib>

    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/427770fd-43da-4cfd-a10a-a3c47fd281fe)

    ![image](https://github.com/xiays146/c-standard-libraries-NMJ/assets/48829659/520c3d68-7b18-4e70-914e-202952932cfa)

    


    
