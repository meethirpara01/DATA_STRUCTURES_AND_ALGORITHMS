// 5. Debug the code. Return true if the number is member of fibonacci series else false.
#include<iostream>
using namespace std;
bool checkMember(int n){
  int f1 = 1, f2 = 1;
  if(n==0 && n==1){
      return true;
  }
  else{
      while(1){
          int temp = f1 + f2;
          f1 = f2;
          f2 = temp;
          if(temp==n){
              return false;
          }
          else if(temp>n){
              return true;
          }
      }
  }

}

int main()
{
  int n;
  cin >> n;
  bool ans = checkMember(n);
  (ans) ? cout << "Number Is Member Of Fibonachi Serise" << endl : cout << "Number Not Member Of Fibonachi Serise" << endl; 
}

// I'L CHANGE FUNCTION TYPE