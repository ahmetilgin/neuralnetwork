#ifndef IMP
#define IMP

#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <time.h>

using namespace std;
vector< vector < vector < double > > > siniflar;
vector< vector < double > > aktifSinif;
vector< double > xyzKoordinatlari;


#define en 600
#define boy 600
int hesaplandi = false;
float secilenX;
float secilenY;
float secilenZ;
bool zSecildi = false;
int sinifSayisi;
float pixel = 1.0/boy;
int value = 1;
float fark = boy/2;
int zsec=0;
static int pencere;
static int menu_id;
double w[3];
double vi[2][4];



using namespace std;

void sinifSayisiniBelirle(){
cout<<"Sinif Sayisini Giriniz.."<<endl;
cin>>sinifSayisi;
for(int i = 0 ; i < sinifSayisi ; i++){
    siniflar.push_back(aktifSinif);
}
}



void  bolgeBelirle(float x,float y)
{
    float degerX = (2*(x-fark)*pixel);
    float degerY = (2*(fark-y)*pixel);
    secilenX = degerX;
    secilenY = degerY;
    xyzKoordinatlari.push_back(degerX);
    xyzKoordinatlari.push_back(degerY);



}


void menu(int say){
  if(say == 0){
    glutDestroyWindow(pencere);
    exit(0);
  }else{
    value = say;
  }
  glutPostRedisplay();
}
void menuOlustur(){

    string  a = "Class ";
    stringstream ss;
    menu_id = glutCreateMenu(menu);
    for(int i = 1;i <= sinifSayisi;i++){
       ss<<a<<i;
       glutAddMenuEntry(ss.str().c_str(),i);
       ss.str("");
    }
    glutAddMenuEntry("Hesapla",sinifSayisi+1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void yaziYaz(){
glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos3f(0.9, 0.05, 0);
char x = 'X';
char y = 'y';
char z = 'z';
void * font = GLUT_BITMAP_TIMES_ROMAN_24;
glutBitmapCharacter(font, x);
char e = '-';
glRasterPos3f(-0.9, 0.05, 0);
glutBitmapCharacter(font, e);
glRasterPos3f(-0.88, 0.05, 0);
glutBitmapCharacter(font, x);
glRasterPos3f(0, 0.9, 0);
glutBitmapCharacter(font, y);
glRasterPos3f(0, -0.9, 0);
glutBitmapCharacter(font, y);
glRasterPos3f(-0.02, -0.9, 0);
glutBitmapCharacter(font, e);
glRasterPos3f(0, 0.02, 0.9);
glutBitmapCharacter(font, z);
glRasterPos3f(0, 0.02, -0.9);
glutBitmapCharacter(font, z);
glRasterPos3f(0, 0.02, -0.92);
glutBitmapCharacter(font, e);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

    glutPostRedisplay();
}


// KÜBÜN SAĞI SOLU ARKASI ÖNÜ
void kubCiz(){


    glEnable(GL_LINE_SMOOTH);
    glLineWidth(3);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    glColor3f(0,1,0);
    glVertex3f(0,0,-1);
    glVertex3f(0,0,1);
    glColor3f(1,0,0);
    glVertex3f(0,-1,0);
    glVertex3f(0,1,0);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    //sag üst z ekseninde çizgi
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    //sol üst z ekseninde
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);

    glVertex3f(0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    glVertex3f(-0.5,  0.5, 0.5);
    glVertex3f(-0.5,  -0.5, 0.5);

    glVertex3f(-0.5,  -0.5, -0.5);
    glVertex3f(0.5,  -0.5, -0.5);

    glVertex3f(-0.5,  -0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.5,  0.5, 0.5);
    glVertex3f(0.5,  0.5, 0.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.5,  -0.5, 0.5);
    glVertex3f(0.5,  -0.5, 0.5);
    glEnd();
    glColor3f(1,0,0);
    glutPostRedisplay();

}
void secilenNoktalariEkranaBas(){

int oAnkiClassinBoyutu;
int vectorunBoyutu = siniflar.size();
glPointSize(5);
glColor3f(0,0,1);
glBegin(GL_POINTS);
double x,y,z;
if(zSecildi == false){
    for(float i = -1; i < 1; i = i + 0.0001){
        glVertex3f(secilenX,secilenY,i);
    }
}


for(int i = 0; i < vectorunBoyutu; i++){
    oAnkiClassinBoyutu = siniflar[i].size();
    for(int j = 0; j < oAnkiClassinBoyutu; j++){
    if(i == 1){
    glColor3f(1,0,0);
    }
    if(i ==2){
    glColor3f(1,0,0);
    }
        x = siniflar[i][j][0];
        y = siniflar[i][j][1];
        z = siniflar[i][j][2];
        glVertex3f(x,y,z);
    }

}
glEnd();
glutPostRedisplay();


}
void duzlemleriCiz(){

glBegin(GL_POINTS);
glPointSize(1);
for(int index= 0 ; index < sinifSayisi ; index++){
for(float i = -0.5 ; i < 0.5 ; i = i + 0.01){
    for(float j = -0.5 ; j < 0.5 ; j = j + 0.01){
        glColor3f(i*2+0.3,i,i);
        glVertex3f(i,j,(vi[index][0] * i + vi[index][1]* j - vi[index][3])/-vi[index][2]);
    }
}
}
glEnd();

}

void cizim(){
      glClearColor(255,1,1,1);
      glClear(GL_COLOR_BUFFER_BIT);







    yaziYaz();
    secilenNoktalariEkranaBas();
    duzlemleriCiz();
    kubCiz();
    glutSwapBuffers();

}




void klavye(unsigned char karakter,int a, int b){

    if(karakter == 'w')
    {
        glRotated(1,1,0,0);
    }
    if(karakter == 's')
    {
        glRotated(-1,1,0,0);
    }
    if(karakter == 'a')
    {
        glRotated(1,0,1,0);
    }
    if(karakter == 'd')
    {
        glRotated(-1,0,1,0);
    }
    glutPostRedisplay();
}



void zBolgeBelirle(int x,int y){
    secilenZ =(2*(x-fark)*pixel);
    xyzKoordinatlari.push_back(secilenZ);
    xyzKoordinatlari.push_back(-1);
    siniflar[value-1].push_back(xyzKoordinatlari);
    xyzKoordinatlari.clear();
    zSecildi = true;
}




void  mouse(int a,int b,int x, int y )
{

    if(a == 0 && b == 0){
        zsec = zsec + 1;
    }
    if((a == 0 && b== 0) && (zsec % 2 == 1))
    {
       bolgeBelirle(x,y);
       zSecildi = false;
       glRotated(90,0,1,0);
    }
    if((zsec % 2 == 0) && a == 0 && b ==0 ){
        //2.tık için Z bolgesi
        zBolgeBelirle(x,y);
        glRotated(-90,0,1,0);
    }

}

void rastgeleAgirlikBelirleWV(){

srand(time(NULL));

for(int i = 0; i < 4;i++ ){
   w[i] = rand()% 3;
}
for(int i = 0;i < sinifSayisi ; i++){
    for(int j = 0; j < 4;j++){
        vi[i][j] = rand() % 2;
    }

}
}
double fnet(double x){
    return x/2;
}

void calcNeuraNetwork(){

int sinifSayisi = siniflar.size();
int araKatmanSayisi = 2;
double beklenenC1 = 1;
double beklenenc2 = -1;
double toplam[araKatmanSayisi];
for(int isinif = 0;;isinif++){
    for(int eleman = 0;;eleman++){


    //Katman üzerinde çarpma
    for(int araKatman =0;araKatman < araKatmanSayisi ;araKatman++){
            int sizeSinif = siniflar[isinif].size();
            if(sizeSinif != 0){
                for(int ji= 0 ; ji < 4 ; ji++){
                    toplam[araKatman] += vi[araKatman][ji] * siniflar[isinif][eleman][ji];
                }
            }
    }


}
}


}







#endif // IMP
