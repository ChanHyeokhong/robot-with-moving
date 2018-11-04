#include <GL/glut.h>
#include <math.h>
#define BASE_HEIGHT 4.0/2
#define BASE_RADIUS 1.0/2
#define HEAD_HEIGHT 1.25/2
#define HEAD_RADIUS 0.75/2
#define NECK_HEIGHT 0.5/2
#define EYE_LEVEL 0.75/2
#define NOSE_LENGTH 0.5/2
#define LOWER_ARM_HEIGHT 3.0/2
#define LOWER_ARM_WIDTH 0.5/2
#define ARM_TRANSLATION 0.22/2
static GLfloat theta[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
GLUquadricObj *p;
GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = {50.0f};
void base(void);
void head(void);
void neck(void);
void lower_rarm(void);
void lower_larm(void);
void init(void);
void display(void);
void reshape (int, int);
void keyboard(unsigned char, int, int);

void base (void) {
double angle, angleInc;
int i;
angle = 3.14159265 / 180;
angleInc = angle;
glPushMatrix();
ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 0.0;
diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glRotatef (-90.0, 1.0, 0.0, 0.0);
gluQuadricDrawStyle(p, GLU_FILL);
gluCylinder (p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20);
glPopMatrix();
}

void neck (void) {
glPushMatrix();
ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 0.0;
diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glTranslatef(0.0, BASE_HEIGHT, 0.0);
glRotatef (-90.0, 1.0, 0.0, 0.0);
gluQuadricDrawStyle(p, GLU_FILL);
gluCylinder (p, HEAD_RADIUS/2, HEAD_RADIUS/2, HEAD_HEIGHT, 8, 6);
glPopMatrix();
}

void head (void) {
glPushMatrix();
ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 1.0;
diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glRotatef (-90.0, 1.0, 0.0, 0.0);
gluQuadricDrawStyle(p, GLU_FILL);
gluCylinder (p, HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT, 20, 20);
glTranslatef (0.25, -HEAD_RADIUS+0.12, EYE_LEVEL);
ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glPushMatrix();
ambient[0] = 1.0; ambient[1] = 0.5; ambient[2] = 0.0;
diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.0;
specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glPopMatrix();
}

void lower_rarm(void) {
glPushMatrix();
ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, ARM_TRANSLATION);
glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
glutSolidCube(1.0);
glPopMatrix();
}

void lower_larm(void) {
glPushMatrix();
ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, -ARM_TRANSLATION);
glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
glutSolidCube(1.0);
glPopMatrix();
}

void display(void) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(-5.0, 3.0, 0.0, 2.0, 2.0, -1.0, 0.0, 2.0, 0.0);
base();
neck();
glPushMatrix();
glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT/2, 0.0);
glRotatef(theta[2], 1.0, 0.0, 0.0);
glRotatef(theta[1], 0.0, 1.0, 0.0);
head();
glPopMatrix();
glPushMatrix();
glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
glRotatef(180.0, 0.0, 0.0, 1.0);
glRotatef(270.0, 0.0, 1.0, 0.0);
glRotatef(theta[4], 0.0, 0.0, 1.0);
lower_rarm();
glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
glRotatef(0.0, 0.0, 0.0, 180.0);
glRotatef(theta[6], 0.0, 0.0, 1.0);
glPopMatrix();
glPushMatrix();
glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
glRotatef(180.0, 0.0, 0.0, 1.0);
glRotatef(270.0, 0.0, 1.0, 0.0);
glRotatef(theta[3], 0.0, 0.0, 1.0);
lower_larm();
glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
glRotatef(0.0, 0.0, 0.0, 180.0);
glRotatef(theta[5], 0.0, 0.0, 1.0);
glPopMatrix();
glFlush();
glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y) {
switch (key) {
case 'q': theta[3] -= 5.0; break;
case 'a': theta[3] += 5.0; break;
case 'w': theta[4] -= 5.0; break;
case 's': theta[4] += 5.0; break;
}
glutPostRedisplay();
}

void reshape(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(80.0, (GLfloat) w / (GLfloat) h, 0.5, 100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void init (void) { 
glEnable(GL_LIGHTING); 
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
p = gluNewQuadric();
}

int main(int argc, char **argv) {
glutInit(&argc, argv);
glutCreateWindow("·Îº¿");
init();
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
