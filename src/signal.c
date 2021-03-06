#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "sig_type.h"
#include <math.h>
#include "strio.h"

void sig_gen(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, double *time, double *u_in, double *u_out) {
	double t = in_sig.tn;
	double dt = (in_sig.tk - in_sig.tn)/(in_sig.n-1);
	double mult = out_sig.u2/out_sig.u1;
	for(int i = 0; i < in_sig.n; i++) {
		
		//Generate time array
		time[i] = t;
		//Generate input signal
		if (t < in_sig.tm) {
			u_in[i] = in_sig.u*(1-exp(-in_sig.a*(t - in_sig.tn)));
		} else {
			u_in[i] = in_sig.u*(1-exp(-in_sig.a*(in_sig.tm - in_sig.tn))) * exp(-in_sig.b * (t - in_sig.tm));
		}
		
		//Generate output signal
		if (u_in[i] < out_sig.u1) {
			u_out[i] = u_in[i]*mult;
		} else {
			u_out[i] = out_sig.u2;
		}
		t+= dt;
	}

}

double sig_duration(double *arr, int n, double tn, double tk) {
	double min = arr[0], max = arr[0];
	for (int i=1; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	//Длительность входного и выходного сигналов
	double durat = 0;
	double dt = (tk-tn)/(n-1);
	for (int i = 0; i < n; i++) {
		 if (arr[i] >= min + 0.5 * (max - min))
			 durat+=dt;
	}
	return durat;
}

void print_signal(FILE* stream, const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig,
		const double* time, const double* u_in, const double* u_out,
		double dur_in, double dur_out) {
	fprintf(stream, "Parametrs are:\n");
	fprintf(stream, "For input signal:\n");
	fprintf(stream,"u: %.3lf V, tn: %.3lf sec, t1: %.3lf sec, tk: %.3lf sec, a: %.3lf 1/sec, b: %.3lf 1/sec\n",
		       	in_sig.u, in_sig.tn, in_sig.tm, in_sig.tk, in_sig.a, in_sig.b);
	fprintf(stream, "For output signal:\n"); 
	fprintf(stream, "u1: %.3lf V, u2: %.3lf V\n", out_sig.u1, out_sig.u2);
	fprintf(stream, "In %d points\n", in_sig.n);
	fprintf(stream, "%6s | %6s | %6s | %6s\n", "Number", "time", "Uin", "Uout");
	for (int i = 0; i < in_sig.n; i++) {
	  fprintf(stream, "%6.3d | %6.3lf | %6.3lf | %6.3lf\n", i+1, time[i], u_in[i], u_out[i]);
	}
	
	fprintf(stream, "Duration of input signal impuls is: %lf"
			"\n	  of output:		     %lf\n",
			dur_in, dur_out);
}

void maxima(int n, double* time, double* u_in, double* u_out) {
	FILE* file = fopen("time", "w+");
	for (int i = 0; i < n; i++) {
		fprintf(file, "%lf ", time[i]);
	}
	fclose(file);
	file = fopen("u_in", "w+");
	for (int i = 0; i < n; i++) {
		fprintf(file, "%lf ", u_in[i]);
	}
	fclose(file);
	file = fopen("u_out", "w+");
	for (int i = 0; i < n; i++) {
	     fprintf(file, "%lf ", u_out[i]);
	}
	fclose(file);
}
