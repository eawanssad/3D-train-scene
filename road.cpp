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



//------------------------------  display   -------------------------------//
void display (void)
{
    void drawGrid();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -20);
    moon();
    road();




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
