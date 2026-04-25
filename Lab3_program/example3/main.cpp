#include "class.h"

int main()
{
MyDerived1 a(3);
a.display();
cout << a.x << " " << a.p << " " << a.y << " " << a.z << endl;
cout << a.getX() << " " << a.getP() << " " << a.getY() << " " << a.getZ() << 
endl;
}