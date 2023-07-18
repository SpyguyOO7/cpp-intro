#include <iostream>

int add(int x, int y){
  return x + y;
}

int subtract(int x, int y){
  return x - y;
}

int multiply(int x, int y){
  return x * y;
}

int divide(int x, int y){
  return x/y;
}

int main()
{
  std::cout << "William Gao, AUV" << std::endl;

  int x = 5;
  int y = 7;
  int z = 15;
  int v = 8;
  double divResult = (double)(x + y )/ (double)v;

  //int p=1;

  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::cout << "The sum of " << x << ", " << y << ", and "<< z <<" is " << x + y + z << std::endl;
  std::cout << "The sum of " << x << " and " << y << " divided by "<< v <<" is " <<   divResult<< std::endl;
  std::cout << "The sum of " << x << " and " << y << " added using the add function is "<< add(x,y) <<std::endl;
  std::cout << "The difference of " << x << " and " << y << " subtracted using the subtract function is "<< subtract(x,y) <<std::endl;
  std::cout << "The product of " << x << " and " << y << " multiplied using the multiply function is "<< multiply(x,y) <<std::endl;
  std::cout << "The dividend of " << x << " and " << y << " divided using the divide function is "<< divide(x,y) <<std::endl;

  //int ok = 1;

  return 0;
}
