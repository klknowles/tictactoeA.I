#include "communicatortictac.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;
void weight_adjust() {
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int aa = 0, bb = 0, cc = 0, dd = 0, ee = 0, ff = 0, gg = 0, hh = 0, ii = 0;

	for (int i = 0; i < 9; i++) {
		midlayerweight1a[i] = changeweight2a[i] + midlayerweight1a[i];
		midlayerweight1b[i] = changeweight2b[i] + midlayerweight1b[i];
		midlayerweight1c[i] = changeweight2c[i] + midlayerweight1c[i];
		midlayerweight1d[i] = changeweight2d[i] + midlayerweight1d[i];
		midlayerweight1e[i] = changeweight2e[i] + midlayerweight1e[i];
	}
	for (int i = 0; i < 5; i++) {
		midlayerweight2a[i] = changeweight1a[i] + midlayerweight2a[i];
		midlayerweight2b[i] = changeweight1b[i] + midlayerweight2b[i];
		midlayerweight2c[i] = changeweight1c[i] + midlayerweight2c[i];
		midlayerweight2d[i] = changeweight1d[i] + midlayerweight2d[i];
		midlayerweight2e[i] = changeweight1e[i] + midlayerweight2e[i];
		midlayerweight2f[i] = changeweight1f[i] + midlayerweight2f[i];
		midlayerweight2g[i] = changeweight1g[i] + midlayerweight2g[i];
		midlayerweight2h[i] = changeweight1h[i] + midlayerweight2h[i];
		midlayerweight2i[i] = changeweight1i[i] + midlayerweight2i[i];
	}
	for (int i = 0; i < 45; i++) {
		if (i < 9) {
			midlayerweight1[a] = midlayerweight1a[i];
			a++;
		}
		else if (i < 18) {
			midlayerweight1[b] = midlayerweight1b[i];
			b++;
		}
		else if (i < 27) {
			midlayerweight1[c] = midlayerweight1c[i];
			c++;
		}
		else if (i < 36) {
			midlayerweight1[d] = midlayerweight1d[i];
			d++;
		}
		else if (i < 45) {
			midlayerweight1[e] = midlayerweight1e[i];
			e++;
		}
	}
	for (int i = 0; i < 45; i++) {
		if (i < 5) {
			midlayerweight2[i] = midlayerweight2a[aa];
			aa++;
		}
		else if (i < 10) {
			midlayerweight2[i] = midlayerweight4[bb];
			bb++;
		}
		else if (i < 15) {
			midlayerweight2[i] = midlayerweight4[cc];
			cc++;
		}
		else if (i < 20) {
			midlayerweight2[i] = midlayerweight4[dd];
			dd++;
		}
		else if (i < 25) {
			midlayerweight2[i] = midlayerweight4[ee];
			ee++;
		}
		else if (i < 30) {
			midlayerweight2[i] = midlayerweight2f[ff];
			ff++;
		}
		else if (i < 35) {
			midlayerweight2[i] = midlayerweight2g[gg];
			gg++;
		}
		else if (i < 40) {
			midlayerweight2[i] = midlayerweight2h[hh];
			hh++;
		}
		else if (i < 45) {
			midlayerweight2[i] = midlayerweight2i[ii];
			ii++;
		}
	}
	ofstream myfile;
	myfile.open("weights1.txt");
	for (int count = 0; count < 45; count++) {
		myfile << midlayerweight1[count] << " ";
	}
	myfile.close();
	ofstream myfile1;
	myfile1.open("weights4.txt");
	for (int count = 0; count < 45; count++) {
		myfile1 << midlayerweight2[count] << " ";
	}
	myfile1.close();
}