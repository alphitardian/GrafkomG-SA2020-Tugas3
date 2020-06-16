#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void keyDownFun(unsigned char key, int x, int y) {
	system("cls");
	cout << key << " pressed" << endl;
}

void keyUpFun(unsigned char key, int x, int y) {
	system("cls");
	cout << key << " pressed" << endl;
}

void mouseFun(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		system("cls");
		cout << "X Coord : " << x << " | " << "Y Coord : " << y << endl;
	}
	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(100, 100);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Ardian Pramudya Alphita - 672018150");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyDownFun);
	glutKeyboardUpFunc(keyUpFun);
	glutMouseFunc(mouseFun);

	myInit();
	glutMainLoop();
	return 0;
}