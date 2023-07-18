#include <iostream>

int main()
{
  std::cout << "William Gao, AUV" << std::endl;

  int x = 5;
  int y = 7;
  int z = 15;
  int v = 8;
  double divResult = (double)(x + y )/ (double)v;

  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::cout << "The sum of " << x << ", " << y << ", and "<< z <<" is " << x + y + z << std::endl;
  std::cout << "The sum of " << x << " and " << y << " divided by "<< v <<" is " <<   divResult<< std::endl;

  return 0;
}