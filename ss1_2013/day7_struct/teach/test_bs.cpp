// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
using namespace std;
int main () {
  int myints[] = {10,20,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  sort(v.begin(),v.end());
  cout << max_element(v.begin(),v.end())-v.end();
  return 0;
}
