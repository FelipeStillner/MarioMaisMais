#include "Principal.h"

int main()
{
  Principal p;

  p.exec();

  p.~Principal();

  return 0;
}