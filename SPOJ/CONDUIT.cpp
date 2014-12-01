#include <iostream>
#include <math.h>
using namespace std;

const double ZERO = 0.000001;

bool equal(double a, double b)
{
	return (fabs(a-b) <= ZERO);
}

class point {
public:
	double x, y;
	void set(double xx, double yy) {x = xx; y = yy;};
	void print()
	{
		cout << '(' << x << ',' << y << ')';
	};
};

class lineseg {
public :
	point p1, p2;
	point c;			// these two are really vectors
	point cperp;
	void set(double x1, double y1, double x2, double y2) {
		p1.set(x1, y1);
		p2.set(x2, y2);
		c.set(x2-x1, y2-y1);
		cperp.set(y1-y2, x2-x1);
	}
};

class range {
public:
	double t1, t2;
	range *next;
	range()
	{
		t1 = t2 = -1;
		next = 0;
	};
	range(double a, double b) {
		t1 = a;
		t2 = b;
		next = 0;
	};
	range(double a, double b, range* n) {
		t1 = a;
		t2 = b;
		next = n;
	};
	void print()
	{
		cout << '[' << t1 << ',' << t2 << ']';
	};
};

class line {
public:
	point p1;
	point c;
	range rangelist;

	line()
	{};
	void set(point pp1, point cc) {
		p1 = pp1;
		c = cc;
		rangelist.next = new range(0.0, 1.0);
	}

	void add(double t1, double t2) {
//cout << "start add " << endl;
		range* p1= &rangelist;
		while(p1->next != 0 && t1 > p1->next->t2)
			p1 = p1->next;
		if (p1->next == 0)
			p1->next = new range(t1, t2);
		else {
			if (t1 < p1->next->t1)
				p1->next = new range(t1, t2, p1->next);
			if (t2 > p1->next->t2)
				p1->next->t2 = t2;
			p1 = p1->next;
//cout << "add term" << endl;
//print();
//cout << endl;
			range *p2 = p1->next;
			while (p2 != 0) {
				if (p2->t1 > t2)
					break;
				if (p2->t2 > t2)
					p1->t2 = p2->t2;
				p1->next = p2->next;
				delete p2;
				p2 = p1->next;
			}
		}
//cout << "after first mod" << endl;
//print();
//cout << endl;
		p1 = rangelist.next;
		while (p1->next != 0) {
			if (equal(p1->t2, p1->next->t1)) {
				p1->t2 = p1->next->t2;
				range* p2 = p1->next;
				p1->next = p2->next;
				delete p2;
				break;					// can only happen once
			}
			else
				p1 = p1->next;
		}
//cout << "after second mod" << endl;
//print();
//cout << endl;
	};

	void print()
	{
		p1.print();
		cout << ',';
		c.print();
		cout << ":";
		range* p = rangelist.next;
		while (p != 0) {
			p->print();
			cout << ',';
			p = p->next;
		}
	};
};

const int MAXSEGS = 10000;
lineseg segs[MAXSEGS];
int numSegs;
line lines[MAXSEGS];
int numLines;

double dotProd(point p1, point p2)
{
	return p1.x*p2.x + p1.y*p2.y;
}

bool sameLine(lineseg s1, lineseg s2, double &tstart, double &tend)
{
/*
cout << "comparing with ";
s2.p1.print();
cout << '-';
s2.p2.print();
s1.c.print();
s2.cperp.print();
cout << ' ' << dotProd(s1.c, s2.cperp);
cout << endl;
/**/
	if (!equal(dotProd(s1.c, s2.cperp), 0.0))
		return false;
	if (!equal(s1.c.x*(s2.p1.y-s1.p1.y), s1.c.y*(s2.p1.x-s1.p1.x)))
		return false;
	if (!equal(s1.c.x, 0.0)) {
		tstart = (s2.p1.x-s1.p1.x)/s1.c.x;
		tend = (s2.p2.x-s1.p1.x)/s1.c.x;
	}
	else {
		tstart = (s2.p1.y-s1.p1.y)/s1.c.y;
		tend = (s2.p2.y-s1.p1.y)/s1.c.y;
	}
	if (tstart > tend) {
		double temp = tstart;
		tstart = tend;
		tend = temp;
	}
//cout << "  same line!, t values " << tstart << ',' << tend << endl;
	return true;
}

int main()
{
	int i, j;
	cin >> numSegs;
	while (numSegs != 0) {
		for(i=0; i<numSegs; i++) {
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			segs[i].set(x1, y1, x2, y2);
		}
		i=0;
		numLines = 0;
		double tstart, tend;
		while (i < numSegs) {
			lines[numLines].set(segs[i].p1, segs[i].c);
			j=i+1;
//lines[numLines].print();
//cout << endl;
			while (j < numSegs) {
				if (sameLine(segs[i], segs[j], tstart, tend)) {
					lines[numLines].add(tstart, tend);
					segs[j] = segs[--numSegs];
//lines[numLines].print();
//cout << endl;
				}
				else
					j++;
			}
			numLines++;
			i++;
		}
//cout << "numLines = " << numLines << endl;
		int count = 0;
		for(i=0; i<numLines; i++) {
			for(range* p = lines[i].rangelist.next; p != 0; p = p->next)
				count++;
		}
		cout << count << endl;

		cin >> numSegs;
	}
	return 0;
}
