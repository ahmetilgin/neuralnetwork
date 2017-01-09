#ifndef TANIMLA_H
#define TANIMLA_H
#include <stdlib.h>
#include <iostream>



struct Noktalar{

float x,y,z;

struct Noktalar * sonraki;
};

struct Siniflar{

Noktalar * basEleman;
Siniflar();
void yeniNoktaXYZ(float a,float b,float c);
};


Siniflar::Siniflar()
{
    basEleman = NULL;
}

void Siniflar::yeniNoktaXYZ(float a,float b, float c){
	Noktalar* v = new Noktalar;
    v->x = a;
    v->y = b;
    v->z = c;
    if (basEleman == NULL) basEleman = v;
	else
	{
		Noktalar* ilk = basEleman;
		while (ilk->sonraki != NULL) ilk = ilk->sonraki;
		ilk->sonraki = v;
	}
}


#endif // TANIMLA
