#ifndef SIG_TYPE_H
#define SIG_TYPE_H

typedef struct {
	double tn;
	double tk;
	double tm;
	double u;
	double a;
	double b;
	int n;
} IN_SIGNAL;

typedef struct {
	double point;
	double mult;
} OUT_SIGNAL;

#endif
