#include <iostream>
#include "../stack.h"
using namespace std;

int main()
{
  int values[] = {1, 5, 4, 3, 2, 6, 7, 8, 9};
  chrisimos::stack<int> s;
  int N = sizeof(values)/sizeof(values[0]);
  
  
  for(int i = 0; i < N; i++)
  {
    s.push(values[i]);
    cout << s.top() << " ";
  }
  
  cout << endl;
  
  while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  
  cout << endl;
  
  return 0;
}
