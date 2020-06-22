#include <iostream>
#include <vector>
#include <GL/freeglut.h>
using namespace std;

vector<char> keyList;
bool downState = false;
int x_coord, y_coord;

void displayResult() {
	system("cls");
	cout << "X Coord : " << x_coord << " | " << "Y Coord : " << y_coord << endl;
	for (int i = 0; i < int(keyList.size()); i++) {
		cout << keyList.at(i) << " ";
	}
	glutPostRedisplay();
}

void keyDownFun(unsigned char key, int x, int y) {
	keyList.push_back(key);
	displayResult();
}

void keyUpFun(unsigned char key, int x, int y) {
	remove(keyList.begin(), keyList.end(), key);
	keyList.pop_back();
	displayResult();
}


void mouseFun(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		downState = true;
	}
	else {
		downState = false;
	}
}


void motionFun(int x, int y) {
	if (downState == true) {
		x_coord = x;
		y_coord = y;
	}

	displayResult();
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
	glutMotionFunc(motionFun);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	myInit();
	glutMainLoop();
	return 0;
}