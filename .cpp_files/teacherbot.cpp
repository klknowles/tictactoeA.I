#include "communicatortictac.h"
#include <iostream>
using namespace std;
double changeweight1a[5];
double changeweight1b[5];
double changeweight1c[5];
double changeweight1d[5];
double changeweight1e[5];
double changeweight1f[5];
double changeweight1g[5];
double changeweight1h[5];
double changeweight1i[5];
double changeweight2a[9];
double changeweight2b[9];
double changeweight2c[9];
double changeweight2d[9];
double changeweight2e[9];
double weighterror[45];
double layer1errora[5];
double layer1errorb[5];
double layer1errorc[5];
double layer1errord[5];
double layer1errore[5];
double layer1errorf[5];
double layer1errorg[5];
double layer1errorh[5];
double layer1errori[5];
double errorsum = 0;
int choice;
double learningrate = 0.1;
void botgrade(double change);
void weight_adjust();
void boteval(bool nummoves) {
	int j = 0;
	if (nummoves) {
		double  change = (-1*responselayer[choice]);
		botgrade(change);
	}

}
void botgrade(double change) {
	

			if (choice == 1) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2a[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errora[j] = (change * midlayerweight2a[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1a[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 2) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2b[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errorb[j] = (change * midlayerweight2b[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1b[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 3) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2c[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errorc[j] = (change * midlayerweight2c[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1c[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			
			}
			else if (choice == 4) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2d[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errord[j] = (change * midlayerweight2d[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1d[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 5) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2e[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errore[j] = (change * midlayerweight2e[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1e[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 6) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2f[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errorf[j] = (change * midlayerweight2f[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1f[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 7) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2g[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errorg[j] = (change * midlayerweight4[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1g[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 8) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2h[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1errorh[j] = (change * midlayerweight4[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1h[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else{
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight2i[j] + errorsum;
				}
				int k = 0;
				for (int j = 0; j < 5; j++) {
					layer1errori[j] = (change * midlayerweight4[j]) / errorsum;
				}
				for (int j = 0; j < 5; j++) {
					changeweight1i[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			if (choice == 1) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errora[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errora[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errora[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errora[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errora[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 2) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errorb[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errorb[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errorb[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errorb[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errorb[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 3) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errorc[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errorc[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errorc[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errorc[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errorc[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 4) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errord[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errord[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errord[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errord[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errord[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}

			}
			else if (choice == 5) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errord[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errord[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errord[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errord[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errord[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 6) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errorf[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errorf[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errorf[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errorf[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errorf[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 7) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errorg[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errorg[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errorg[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errorg[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errorg[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 8) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errorh[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errorh[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errorh[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errorh[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errorh[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			else if (choice == 9) {
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1errori[0] * gridval[j] * midlayer1[0] * (1 - midlayer1[0]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2b[j] = learningrate * layer1errori[1] * gridval[j] * midlayer1[1] * (1 - midlayer1[1]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2c[j] = learningrate * layer1errori[2] * gridval[j] * midlayer1[2] * (1 - midlayer1[2]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2d[j] = learningrate * layer1errori[3] * gridval[j] * midlayer1[3] * (1 - midlayer1[3]);
				}
				for (int j = 0; j < 9; j++) {
					changeweight2e[j] = learningrate * layer1errori[4] * gridval[j] * midlayer1[4] * (1 - midlayer1[4]);
				}
			}
			/*
			int i = 0;
			while (i == 0) {
				/*for (int j = 0; j < 10; j++) {
					errorsum = midlayerweight1[j] + errorsum;
				}
				for (int j = 0; j < 10; j++) {
					layer1error[9] = (change * midlayerweight4[j] / errorsum) + layer1error[9];
				}
				int k = 1;
				int o = 0;
				for (int j = 0; j < 9; j++) {
					changeweight2a[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[0] * (1 - midlayer1[0]);
					k++;
					o++;
				}
				i++;
			}
			while (i == 1) {
				int k = 1;
				int o = 0;
				for (int j = 9; j < 18; j++) {
					changeweight4[j] = learningrate * layer1error[o] * gridval[k] * midlayer1[1] * (1 - midlayer1[1]);
					k++;
					o++;
				}
				i++;
			}
			while (i == 2) {
				int k = 1;
				int o = 0;
				for (int j = 18; j < 27; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[2] * (1 - midlayer1[2]);
					k++;
					o++;
				}
				i++;
			}
			while (i == 3) {
				int k = 0;
				int o = 0;
				for (int j =27 ; j < 36; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[3] * (1 - midlayer1[3]);
					k++;
					o++;
				}
				i++;
			}
			while (i == 4) {
				int k = 0;
				int o = 0;
				for (int j = 36; j < 45; j++) {
					changeweight4[j] = learningrate * layer1error[o] * gridval[k] * midlayer1[4] * (1 - midlayer1[4]);
					k++;
					o++;
				}
				i++;
			}
			while (i == 5) { 
				int k = 0;
				for (int j = 25; j < 30; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[4] * (1 - midlayer1[k]);
					k++;
				}
				i++;
			}
			while (i == 6) {
				int k = 0;
				for (int j = 30; j < 35; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[4] * (1 - midlayer1[2]);
					k++;
				}
				i++;
			}
			while (i == 7) {
				int k = 0;
				for (int j = 35; j < 40; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[4] * (1 - midlayer1[3]);
					k++;
				}
				i++;
			}
			while (i == 8) {
				int k = 0;
				for (int j = 40; j < 45; j++) {
					changeweight4[j] = learningrate * layer1error[0] * gridval[k] * midlayer1[4] * (1 - midlayer1[4]);
					k++;
				}
				i++;
			}*/
			weight_adjust();
}