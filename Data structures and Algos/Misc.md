### NP-completeness 
- Decision problem: A problem with a yes or no answer.
- **P** is a complexity class that represents the set of all decision problems that can be solved in polynomial time. 
That is, given an instance of the problem, the answer yes or no can be decided in polynomial time.
- **NP** (Non-deterministic polynomial time) is a complexity class that represents the set of all decision problems for which the instances where the answer is "yes" have proofs that can be verified in polynomial time.



### Travelling Salesman (NP hard) : DP Solution (exponential solution - Held–Karp algorithm)
- Brute force : n! solution
![alt tag](https://qph.ec.quoracdn.net/main-qimg-344b9a414a293792a807072fd78ae3fc?convert_to_webp=true)
- The problem can be described as: find a tour of N cities in a country (assuming all cities to be visited are reachable), the tour should (a) visit every city just once, (b) return to the starting point and (c) be of minimum distance.
- Suupose you have visited a few cities and you are at city **j**, the information you need is : which city are you in? (j) and the previous cities which you have visited (so that we don't visit them again)



