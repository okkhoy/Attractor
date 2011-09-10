/**
 * Lorenz Attractor: An example of a non-linear dynamic system that exhibit 
 * chaotic flow.
 * In the current form, the program generates 10000 lorenz attractor points
 * initially. It is the plot that is animated. 
 * This seems to be a not-so-efficient animation mechanism.
 *
 * A variable 'count' is maintained to indicate the latest point to be plotted.
 * We plot all the points from 0 to count for every single iteration, giving
 * an impression of a continuous animated line.
 * We need to find out if there is a more efficient mechanism of doing this.
 *
 *
 * Team: Zoozoos
 * 		 Akshay Narayan 		- MT2010009
 *		 Dheryata Jaisinghani 	- MT2010034
 */

#include "Headers.h"

Point *p0, *p1;
Point *pt0, *pt1;

double a,b,c;

int count;


void init() {
	glClearColor(0.0,0.0,0.0,1.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-55.0, 55.0, -55.0, 55.0, -55.0, 55.0);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glMatrixMode(GL_MODELVIEW);	
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	// Draw the Attractor!
	glPointSize(2.0);
	glBegin(GL_LINES);
	for (int i = 1; i < count; i++) {	
		glColor3f(1.0,0.0,0.0);
		glVertex3f(pt0[i].x, pt0[i].y, pt0[i].z);
		glVertex3f(pt0[i-1].x, pt0[i-1].y, pt0[i-1].z);
		glColor3f(0.0,0.0,1.0);
		glVertex3f(pt1[i].x, pt1[i].y, pt1[i].z);
		glVertex3f(pt1[i-1].x, pt1[i-1].y, pt1[i-1].z);
	}
	glEnd();
	
	glFlush();

}




int main(int argc, char** argv) {
	
	p0 = new Point;
	p1 = new Point;

	p0->x = 0.0; p0->y = 1.0; p0->z = 0.0;
	
	p1->x = 0.0; p1->y = 1.00001; p1->z = 0.0;
	
	a = 10.0;
	b = 28.0;
	c = 8.0/3.0;
	
	pt0 = new Point[10000];
	pt1 = new Point[10000];
	lorenzFunction();
		
	count = 1;
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Lorenz Attractor");

	glutTimerFunc(20, lorenzFunction_animate, 1);
	glutDisplayFunc(display);

	init();
	
	glutMainLoop();
	
	return 0;
}
