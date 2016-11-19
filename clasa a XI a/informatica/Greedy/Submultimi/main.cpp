#include <iostream>
#include <fstream>

using namespace std;


ifstream in("Submultimi.in");
ofstream out("Submultimi.txt");

int x ,n;

void greedy(){
  in>>n;

  for(int i = 1; i <= n; i++){
    in>>x;
    if(x>0)out<<x<<' ';
  }
}

int main(){
  greedy();
  return 0;
}
