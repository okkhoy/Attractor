#include "Headers.h"

extern Point *p0, *p1;
extern Point *pt0, *pt1;

extern double a,b,c;

extern int count;


void lorenzFunction_animate(int a) {
	
	count++;
	glutPostRedisplay();
	glutTimerFunc(20, lorenzFunction_animate, 1);
	
}

/*
	The lorenz function is implemented in this function, for 2 points: Pt0 & Pt1
	The lorenz equations are given by: 
	
*/
void lorenzFunction() {
	Point p;
	
	double h = 0.01;
	for (int i = 0;i < 8000; i++) {
		p.x = p0->x; p.y = p0->y; p.z = p0->z;
	  	p0->x = p.x + (a * (p.y - p.x)) * h;
		p0->y = p.y + (p.x * (b - p.z) - p.y) * h;
		p0->z = p.z + ((p.x * p.y) - (c * p.z)) * h;
		pt0[i].x = p0->x; pt0[i].y = p0->y; pt0[i].z = p0->z;
		
	  	p.x = p1->x; p.y = p1->y; p.z = p1->z;
		p1->x = p.x + (a * (p.y - p.x)) * h;
		p1->y = p.y + (p.x * (b - p.z) - p.y) * h;
		p1->z = p.z + ((p.x * p.y) - (c * p.z)) * h;
		pt1[i].x = p1->x; pt1[i].y = p1->y; pt1[i].z = p1->z;
	}

}


