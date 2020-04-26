#include "communicatortictac.h"
#include <iostream>
using namespace std;
double changeweight1[45];
double changeweight4[45];
double weighterror1[45];
double layer1error[10];
double errorsum = 0;
int choice;
double learningrate = 0.4;
void botgrade(double change);
void weight_adjust();
void boteval(bool nummoves) {
	int j = 0;
	if (nummoves) {
		double  change = -responselayer[choice];
		botgrade(change);
	}

}
void botgrade(double change) {
	

			if (choice == 1) {
				int k = 0;
				for (int j = 0; j < 5; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 0; j < 5; j++) {
					layer1error[0] = (change * midlayerweight4[j] / errorsum) + layer1error[0];
				}
				for (int j = 0; j < 5; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 2) {
				int k = 0;
				for (int j = 5; j < 10; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 5; j < 10; j++) {
					layer1error[1] = (change * midlayerweight4[j] / errorsum) + layer1error[1];
				}
				for (int j = 5; j < 10; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
				
			}
			else if (choice == 3) {
				int k = 0;
				for (int j = 10; j < 15; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 10; j < 15; j++) {
					layer1error[2] = (change * midlayerweight4[j] / errorsum) + layer1error[2];
				}
				for (int j = 10; j < 15; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			
			}
			else if (choice == 4) {
				int k = 0;
				for (int j = 15; j < 20; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 15; j < 20; j++) {
					layer1error[3] = (change * midlayerweight4[j] / errorsum) + layer1error[3];
				}
				for (int j = 15; j < 20; j++) {
					changeweight1[j] = learningrate * change * midlayer1[3] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 5) {
				int k = 0;
				for (int j = 20; j < 25; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 20; j < 25; j++) {
					layer1error[4] = (change * midlayerweight4[j] / errorsum) + layer1error[4];
				}
				for (int j = 20; j < 25; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 6) {
				int k = 0;
				for (int j = 25; j < 30; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 25; j < 30; j++) {
					layer1error[5] = (change * midlayerweight4[j] / errorsum) + layer1error[5];
				}
				for (int j = 25; j < 30; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 7) {
				int k = 0;
				for (int j = 30; j < 35; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 30; j < 35; j++) {
					layer1error[7] = (change * midlayerweight4[j] / errorsum) + layer1error[7];
				}
				for (int j = 30; j < 35; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else if (choice == 8) {
				int k = 0;
				for (int j = 35; j < 40; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				for (int j = 35; j < 40; j++) {
					layer1error[8] = (change * midlayerweight4[j] / errorsum) + layer1error[8];
				}
				for (int j = 35; j < 40; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			else{
				for (int j = 40; j < 45; j++) {
					errorsum = midlayerweight4[j] + errorsum;
				}
				int k = 0;
				for (int j = 40; j < 45; j++) {
					layer1error[9] = (change * midlayerweight4[j] / errorsum) + layer1error[9];
				}
				for (int j = 40; j < 45; j++) {
					changeweight1[j] = learningrate * change * midlayer1[k] * responselayer[choice] * (1 - responselayer[choice]);
					k++;
				}
			}
			int i = 0;
			while (i == 0) {
				/*for (int j = 0; j < 10; j++) {
					errorsum = midlayerweight1[j] + errorsum;
				}
				for (int j = 0; j < 10; j++) {
					layer1error[9] = (change * midlayerweight4[j] / errorsum) + layer1error[9];
				}*/
				int k = 1;
				int o = 0;
				for (int j = 0; j < 9; j++) {
					changeweight4[j] = learningrate * layer1error[o] * gridval[k] * midlayer1[0] * (1 - midlayer1[0]);
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
			/*while (i == 5) { 
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