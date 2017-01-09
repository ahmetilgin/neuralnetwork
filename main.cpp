#include "imp.h"
#include <thread>
using namespace std;






int main(int argc, char *argv[])
{

    sinifSayisiniBelirle();
    rastgeleAgirlikBelirleWV();
    // Bunlar   Klasik
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(en,boy);
    glutCreateWindow("Training Multi");
    glutDisplayFunc(cizim);
    glutIdleFunc(cizim);
    glutKeyboardFunc(klavye);
    glutMouseFunc(mouse);
    menuOlustur();
    // Sinif Sayisi kadar siniflar oluşturuluyor
    glutMainLoop();

    return EXIT_SUCCESS;
}
