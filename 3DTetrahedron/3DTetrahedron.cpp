// 3DTetrahedron.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <glut.h>

int c = 0;

void Triangle(GLfloat A[], GLfloat B[], GLfloat C[])
{
    glBegin(GL_TRIANGLES);
   // glColor3f(0, 1, 0);
      glShadeModel(GL_SMOOTH);

      glColor3f(c / 255.0, 0, 0);
      glVertex3fv(A);

      glColor3f(c / 255.0, 0, 0);
      glVertex3fv(B);

      glColor3f(0, 1, 0);
      glVertex3fv(C);
    glEnd();
}

void Tetra(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[])
{
   // glColor3f(1, 1, 1);
    Triangle(V1, V2, V3);

   // glColor3f(1, 0, 0);
    Triangle(V1, V3, V4);

   // glColor3f(0, 1, 0);
    Triangle(V2, V3, V4);

   // glColor3f(0, 0, 1);
    Triangle(V1, V2, V4);
}

void Div(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], int n)
{
    GLfloat V12[3], V23[3], V31[3], V14[3], V24[3], V34[3];
    if (n > 0)
    {
        V12[0] = (V1[0] + V2[0]) / 2;
        V12[1] = (V1[1] + V2[1]) / 2;
        V12[2] = (V1[2] + V2[2]) / 2;

        V23[0] = (V2[0] + V3[0])  / 2;
        V23[1] = (V2[1] + V3[1])  / 2;
        V23[2] = (V2[2] + V3[2])  / 2;

        V31[0] = (V3[0] + V1[0])  / 2;
        V31[1] = (V3[1] + V1[1])  / 2;
        V31[2] = (V3[2] + V1[2])  / 2;

        V14[0] = (V1[0] + V4[0])  / 2;
        V14[1] = (V1[1] + V4[1])  / 2;
        V14[2] = (V1[2] + V4[2])  / 2;

        V24[0] = (V2[0] + V4[0])  / 2;
        V24[1] = (V2[1] + V4[1])  / 2;
        V24[2] = (V2[2] + V4[2])  / 2;

        V34[0] = (V3[0] + V4[0])  / 2;
        V34[1] = (V3[1] + V4[1])  / 2;
        V34[2] = (V3[2] + V4[2])  / 2;

        Div(V1, V12, V31, V14, n - 1);
        Div(V12, V2, V23, V24, n - 1);
        Div(V31, V23, V3, V34, n - 1);
        Div(V14, V24, V34, V4, n - 1);
       
    }
    else
    
    Tetra(V1, V2, V3, V4);
}

void mydisplay()
{
    GLfloat P[4][3] =
    {
        {-0.5,-0.5, 0.5},
        { 0.5,-0.5, 0.5},
        {   0, 0.5, 0.5},
        {   0, -0.16,-0.5},
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Div(P[0], P[1], P[2], P[3], 2);

   

    glutSwapBuffers();
   
}

int main()
{
    char* str = new char[0];
    int arg = 0;
    glutInit(&arg, &str);
    glutInitWindowPosition(250, 50);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OpenGl Programe");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
