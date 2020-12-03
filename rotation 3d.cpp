

#include <windows.h>
#include <GL/glut.h>
#include <Gl/glu.h>
#include <GL/gl.h>
#include <stdio.h>

void display ();
void reshape(int,int);
void timer(int);

void init()
{
    glClearColor(0.0, 0.0, 0.0,1.0);
    glEnable(GL_DEPTH_TEST );
}

int main(int argc, char**argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

   glutInitWindowPosition(200,100);
   glutInitWindowSize(500,500);

   glutCreateWindow("window 1");

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutTimerFunc(0,timer, 0);
   init();

   glutMainLoop();

}


float angle =0.0;


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    angle+=0.8;
    if(angle>360.0)
        angle=angle-360.0;
}


void reshape(GLsizei w, GLsizei h)
{

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,50.0);
    glMatrixMode(GL_MODELVIEW);

}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);


   glLoadIdentity();
   glTranslatef(-1.5f, 0.0f, -6.0f);
   glRotatef(angle ,1.0 ,1.0, 1.0);

   glBegin(GL_TRIANGLES);

      glColor3f(3.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 0.5f, 0.0f);

      glVertex3f(-0.5f, -0.5f, 0.5f);

      glVertex3f(0.5f, -0.5f, 0.50f);


      glVertex3f(0.0f, 0.5f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.5f, -0.5f, 0.5f);


      glVertex3f(0.0f, -0.5f, -0.5f);


      glVertex3f(0.0f, 0.5f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(0.5f, -0.5f, -0.5f);

      glVertex3f(-0.5f, -0.5f, -0.5f);


      glVertex3f( 0.0f, 0.5f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3f(-0.5f,-0.5f,-0.5f);

      glVertex3f(-0.5f,-0.5f, 0.5f);
   glEnd();

   glutSwapBuffers();
}






