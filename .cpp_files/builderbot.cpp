#include "communicatortictac.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;
void weight_adjust() {
	for (int i = 0; i < 45; i++) {
		midlayerweight1[i] = changeweight4[i] + midlayerweight1[i];
		midlayerweight4[i] = changeweight1[i] + midlayerweight4[i];
	}
	ofstream myfile;
	myfile.open("weights1.txt");
	for (int count = 0; count < 50; count++) {
		myfile << midlayerweight1[count] << " ";
	}
	myfile.close();
	ofstream myfile1;
	myfile1.open("weights4.txt");
	for (int count = 0; count < 50; count++) {
		myfile1 << midlayerweight4[count] << " ";
	}
	myfile1.close();
}