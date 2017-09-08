# piscine_startfleet
 algorithm implementation, big O
 
##BigO
 How do analyze algorithms and how can we compare algorithms against each other?
 We use bigO to objectively compare algarithms
 we can not use "time to run" as an objective measurement, because that will depend on the speed of the computer itself and hardware capabilities.
 We could compare the amount of space they take in memory
 we could also compare how much time it takes each function to run
 Now we want to develop a notation to objectively compare the efficiency of these two algorithms.
 A good place to start would be to compare the number of assignments each algorithm makes.
 
  Big-O notation describes how quickly runtime will grow relative to the input as the input get arbitrarily large.
  Let's examine some of these points more closely:
  Remember, we want to compare how quickly runtime will grows, not compare exact runtimes, since those can vary depending on hardware.
  Since we want to compare for a variety of input sizes, we are only concerned with runtime grow relative to the input. This is why we use n for notation.
  As n gets arbitrarily large we only worry about terms that will grow the fastest as n gets large, to this point, Big-O analysis is also known as asymptotic analysis
  
  choose algorithms that stay away from any exponential, quadratic, or cubic behavior!
  choose consant: 1, logarithmic: log(n), linear:n, log linear: nlog(n) 
  3n, n+1 --> n
  worst case and best case scenarios 
  
  Space Complexity
  
  binary search O(log(n))
 
  
