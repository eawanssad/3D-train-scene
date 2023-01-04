#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
void display();
void reshape(int w,int h);
void timer(int);
float x;
GLfloat anglePyramid = 0.0f;
//GLfloat angleCube = 0.0f;
int zRotated=0;
float cx=0,cy=0,cz=0,vx=0,vy=0,vz=0,rx=0,ry=0;

//----------------------keyboard--------------------------
void keyboard(unsigned char Key,int x,int y)
    {
    if(Key=='w'){cz-=0.1;} if(Key=='s'){cz+=0.1;}//forward and back clouds
    if(Key=='a'){cx-=0.1;} if(Key=='d'){cx+=0.1;}//left and right clouds
    if(Key=='4'){vx-=0.1;} if(Key=='6'){vx+=0.1;}//left and right train
    if(Key=='1'){ry-=0.12;} if(Key=='2'){ry+=0.12;}//up and down rain
    if(Key=='7'){rx-=0.12;} if(Key=='o'){rx+=0.12;}//left and right rain
    glutPostRedisplay();
    }

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void moon (){
        glPushMatrix ();
        glColor3f (1,1,1);
       glTranslatef    (-9.7+x, 6.5, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 0,1,0);
       glutSolidSphere(0.7,10, 40);
      glPopMatrix ();
}

void road(){
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-9, -6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-6, -6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-3, -6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0, -6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(3, -6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(6,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);

    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(9,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);

    glPopMatrix();
//////////////////////////////////road gray
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-4,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-7,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-10,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-1,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(2,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(7,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4.1,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10,-6, 3);
    glScalef(2,-0.002,50);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();


}

void background(){

    ///////////////////////background houses

    glColor3f(0.7,0.4,0.5);
    glPushMatrix();
    glTranslatef(-9.6,2, 3);
    glScalef(3,-5,2);
    glutSolidCube(1);
    glColor3f(1,1,1);
    glPopMatrix();
//////////////////////the door
    glColor3f(0.6,0.4,0.1);
    glPushMatrix();
    glTranslatef(0,1,7);
    glScalef(3,5,5);
    glutSolidCube(0.5);
    glPopMatrix();
////////////////////window

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-1.4,3.4,7);
    glScalef(2,2,0.5);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();


    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(1.4,3.4,7);
    glScalef(2,2,0.5);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0.7,0.8,0.6);
    glPushMatrix();
    glTranslatef(-3.2,0.2,7);
    glScalef(2,2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(2,1,0.7);
    glPushMatrix();
    glTranslatef(-7,0.2,7);
    glScalef(2,2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(2,1,0.7);
    glPushMatrix();
    glTranslatef(-7,0.7,7);
    glScalef(2,2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(2,1,0.7);
    glPushMatrix();
    glTranslatef(-6.8,2.3,7);
    glScalef(2,2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();


    glColor3f(0.9,0.7,0.1);
    glPushMatrix();
    glTranslatef(-4.4,0.3,9);
    glScalef(2,2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(3,0.3,9);
    glScalef(2,3,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(2.6,1.7,9);
    glScalef(1,1,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(3.5,1.7,9);
    glScalef(1,1,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(5.5,0.3,9);
    glScalef(2,3,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f (0, 0, 0);
     glPushMatrix ();
       glTranslatef    (-4.7,0.3,9);//to change position on screen
       glRotatef       (70, 2,0,-700);
       glRotatef       (0, 1,0,0);// points where
       glutSolidCone(0.1,0.2, 50,50);
    glPopMatrix ();

    glColor3f (0, 0, 0);
     glPushMatrix ();
       glTranslatef    (-3,0.2,9);//to change position on screen
       glRotatef       (70, 2,0,-700);
       glRotatef       (0, 1,0,0);// points where
       glutSolidCone(0.1,0.2, 50,50);
    glPopMatrix ();

    glColor3f (0, 0, 0);
     glPushMatrix ();
       glTranslatef    (0.4,0.7,9);//to change position on screen
       glRotatef       (70, 2,0,-700);
       glRotatef       (0, 1,0,0);// points where
       glutSolidCone(0.1,0.2, 50,50);
    glPopMatrix ();

    glColor3f (0, 0, 0);
     glPushMatrix ();
       glTranslatef    (2.6,0.4,9);//to change position on screen
       glRotatef       (70, 2,0,-700);
       glRotatef       (0, 1,0,0);// points where
       glutSolidCone(0.1,0.2, 50,50);
    glPopMatrix ();


    glColor3f(3,3,1);
    glPushMatrix();
    glTranslatef(0,1,7);
    glScalef(3,5,3);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();


    glColor3f(3,3,1);
    glPushMatrix();
    glTranslatef(-5,0.9,7);
    glScalef(3,5,2);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();


    glColor3f(3,3,1);
    glPushMatrix();
    glTranslatef(0,2,7);
    glScalef(9,-10,2);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslatef(-3,0.6,5);
    glScalef(9,-4,3);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0.8,0.1,0.1);
    glPushMatrix();
    glTranslatef(4.3,1.4,5);
    glScalef(6,8,-3);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();

    glColor3f(0.7,0.7,0.7);
    glPushMatrix();
    glTranslatef(7,0.6,5);
    glScalef(3,5,2);
    glutSolidCube(0.5);
    glColor3f(1,1,1);
    glPopMatrix();




}
void clouds (){

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-7+cx, 6, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.6,10, 40);
      glPopMatrix ();
/////////////////////////////rain1


    glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-7.6+rx, 5.2+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-7.3+rx, 4.9+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

    glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-6.3+rx, 4.7+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-6.6+rx, 5+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-6.9+rx,4.5+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-6.1+rx,5.2+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();
///////////////////////////////////////////////rain2


    glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.3+rx, 5.4+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.3+rx, 5.8+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

    glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6.4+rx, 5.7+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6.5+rx, 5.4+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6.9+rx,5.7+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6.1+rx,5.6+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6+rx,5.2+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7+rx,5.2+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.8+rx,5.2+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.7+rx,5.6+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();

       glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.8+rx,5.9+ry, 0.0);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (0, 1,0,0);
       glutSolidSphere(0.09,10, 40);
      glPopMatrix ();
////////////////////////////////////////////////////
        glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-7.6+cx, 6, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.4,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (-6.3+cx, 6, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.5,10, 40);
      glPopMatrix ();

      ///////////////////////////////////////////////// clouds
      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7+cx, 6.5, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.6,10, 40);
      glPopMatrix ();

        glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (7.6+cx, 6.5, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.4,10, 40);
      glPopMatrix ();

      glPushMatrix ();
        glColor3f (0.7, 0.9,1);
       glTranslatef    (6.3+cx, 6.5, 0.0+cz);
       glRotatef       (90.0, 1,0,0);
       glRotatef       (zRotated, 1,0,0);
       glutSolidSphere(0.5,10, 40);
      glPopMatrix ();
}
void train (){


    glPushMatrix();
    glTranslatef(-1+vx,-1,15);
    glScalef(3,-2,2);
    glutSolidCube(0.5);
    glColor3f(1,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1+vx,-1,15);
    glScalef(3,-2,2);
    glutSolidCube(0.5);
    glColor3f(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3+vx,-0.8,15);
    glScalef(3,-3,2);
    glutSolidCube(0.5);
    glColor3f(1,1,0);
    glPopMatrix();
//////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(3+vx,-0.8,15);
    glScalef(2.1,2.5,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,0);
    glPopMatrix();
////////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(1+vx,-0.9,15);
    glScalef(2.1,1.2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1+vx,-0.9,15);
    glScalef(2.1,1.2,0.1);
    glutSolidCube(0.5);
    glColor3f(1,1,0);
    glPopMatrix();
//////////////////////////////////

    glPushMatrix();
    glTranslatef(0+vx,-1,15);
    glScalef(1,-0.3,1);
    glutSolidCube(0.5);
    glColor3f(0,0,0);
    glPopMatrix();
//color
    glPushMatrix();
    glTranslatef(2+vx,-1,15);
    glScalef(1,-0.3,1);
    glutSolidCube(0.5);
    glColor3f(0,1,0);
    glPopMatrix();
}

void pyramid(){
   // glTranslatef(0.0f, 0.0f, -2.0f);  // Move left and into the screen
    //glRotatef(anglePyramid, 0.5f, 6.0f, 0.0f);
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(0.8f, 0.9f, 1.0f);     // Red
      glVertex3f( 0.0f-7.5, 1.0f+4, 0.0f+1);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f-7.5, -1.0f+4, 1.0f+1);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f-7.5, -1.0f+4, 1.0f+1);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f-7.5, 1.0f+4, 0.0f+1);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f-7.5, -1.0f+4, 1.0f+1);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f-7.5, -1.0f+4, -1.0f+1);

      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f-7.5, 1.0f+4, 0.0f+1);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f-7.5, -1.0f+4, -1.0f+1);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f-7.5, -1.0f+4, -1.0f+1);

      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f-7.5, 1.0f+4, 0.0f+1);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f-7.5,-1.0f+4,-1.0f+1);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f-7.5,-1.0f+4, 1.0f+1);
   glEnd();

//////////////////////////////////////////////////////cub

   anglePyramid += 0.2f;



}
void cubem(){
       // glRotatef(angleCube, 0.2f, 0.0f, 0.0f);
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

      glColor3f(1.0f,1.0f, 1.0f);     // Green
      glVertex3f( 1.0f+7.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5, 1.0f-3,  1.0f+4);
      glVertex3f( 1.0f+7.5, 1.0f-3,  1.0f+4);

      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f+7.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+7.5, -1.0f-3, -1.0f+4);


      glColor3f(0.0f, 1.0f, 0.0f);     //green
      glVertex3f( 1.0f+7.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+7.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3, 1.0f+4);
      glVertex3f( 1.0f+7.5, -1.0f-3, 1.0f+4);


      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f+7.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5,  1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+7.5,  1.0f-3, -1.0f+4);


      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f+7.5,  1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+7.5,  1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+7.5, -1.0f-3,  1.0f+4);


      glColor3f(1.0f, 1.0f, 1.0f);     // Magenta
      glVertex3f(1.0f+7.5,  1.0f-3, -1.0f+4);
      glVertex3f(1.0f+7.5,  1.0f-3,  1.0f+4);
      glVertex3f(1.0f+7.5, -1.0f-3,  1.0f+4);
      glVertex3f(1.0f+7.5, -1.0f-3, -1.0f+4);
   glEnd();  // End of drawing color-cube
   //////////////////////////////////////////////////////
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

      glColor3f(0.0f, 0.0f, 1.2f);
      glVertex3f( 1.0f+4.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, 1.0f-3,  1.0f+4);
      glVertex3f( 1.0f+4.5, 1.0f-3,  1.0f+4);

      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex3f( 1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+4.5, -1.0f-3, -1.0f+4);


      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f+4.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, 1.0f+4);
      glVertex3f( 1.0f+4.5, -1.0f-3, 1.0f+4);


      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+4.5,  1.0f-3, -1.0f+4);

      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f+4.5,  1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3,  1.0f+4);


      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f(1.0f+4.5,  1.0f-3,  1.0f+4);
      glVertex3f(1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(1.0f+4.5, -1.0f-3, -1.0f+4);
   glEnd();  // End of drawing color-cube
////////////////////////////////////////////////////////

     glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

      glColor3f(0.0f, 0.4f, 1.2f);     // Green
      glVertex3f( 1.0f+4.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, 1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, 1.0f-3,  1.0f+4);
      glVertex3f( 1.0f+4.5, 1.0f-3,  1.0f+4);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+4.5, -1.0f-3, -1.0f+4);

      // Front face  (z = 1.0f)
      glColor3f(0.0f, 1.0f, 0.0f);     //green
      glVertex3f( 1.0f+4.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, 1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, 1.0f+4);
      glVertex3f( 1.0f+4.5, -1.0f-3, 1.0f+4);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f( 1.0f+4.5,  1.0f-3, -1.0f+4);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f+4.5,  1.0f-3,  1.0f+4);
      glVertex3f(-1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3, -1.0f+4);
      glVertex3f(-1.0f+4.5, -1.0f-3,  1.0f+4);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 1.0f, 1.0f);     // Magenta
      glVertex3f(1.0f+4.5,  1.0f-3, -1.0f+4);
      glVertex3f(1.0f+4.5,  1.0f-3,  1.0f+4);
      glVertex3f(1.0f+4.5, -1.0f-3,  1.0f+4);
      glVertex3f(1.0f+4.5, -1.0f-3, -1.0f+4);
   glEnd();  // End of drawing color-cube








}

void torus(){
    glPushMatrix();
    glColor3f(0.5,0.4,0);
    glTranslatef(0.01,3.4,7);
    glRotatef(-4.0,1,0,0);
    glutSolidTorus(0.04,0.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-9.7+x, 6.5, 0.0);
    glRotatef(-90.0,1,0,0);
    glutSolidTorus(0.02,0.9,50,50);
    glPopMatrix();
}

//------------------------------  display   -------------------------------//
void display (void)
{
    void drawGrid();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -20);
    moon();
    road();
    background();
    clouds ();
    train();
    pyramid ();
    cubem();
    torus();
    glutSwapBuffers();
    anglePyramid += 0.2f;




}



//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

	x+=0.01;
	}
int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition (200 , 0);
    glutInitWindowSize (1200 , 800);
    glutCreateWindow       ("20100779");

    glutKeyboardFunc(keyboard);

    glutDisplayFunc (display);
   // sndPlaySound("background.way",SND_ASYNC|SND_LOOP);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);
    glutTimerFunc(0,timer,0);
    glClearColor(0.8,0.8,0.8,0);
    //glRotatef(90,1,1,0);

    texture();


    glutMainLoop();
}
