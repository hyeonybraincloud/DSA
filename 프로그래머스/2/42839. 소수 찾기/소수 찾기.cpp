#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> uniquePrimes;
    sort(numbers.begin(), numbers.end());
    
    do {
       for (int len = 1; len <= numbers.size(); len++) {
           for (int i = 0; i + len <= numbers.size(); i++) {
               int num = stoi(numbers.substr(i, len));
               if (isPrime(num))
                   uniquePrimes.insert(num);
           }
       }     
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return uniquePrimes.size();
}