#include <stdio.h>
#include "sig_type.h"
#include "math.h"

void sig_gen(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, double *u_in, double *u_out) {
	double t = in_sig.tn;
	double dt = (in_sig.tk - in_sig.tn)/(in_sig.n-1);
	for(int i = 0; i < in_sig.n; i++) {

		//Generate input signal
		if (t < in_sig.tm) {
			u_in[i] = in_sig.u*(1-exp(-in_sig.a*(t - in_sig.tn)));
		} else {
			u_in[i] = in_sig.u*(1-exp(-in_sig.a*(in_sig.tm - in_sig.tn))) * exp(-in_sig.b * (t - in_sig.tm));
		}
		
		//Generate output signal
		if (u_in[i] < out_sig.point) {
			u_out[i] = u_in[i]*out_sig.mult;
		} else {
			u_out[i] = out_sig.point * out_sig.mult;
		}
		t+= dt;
	}
}
