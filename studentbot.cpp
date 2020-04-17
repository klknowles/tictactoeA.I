#include "communicatortictac.h"
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;


int playernum = player;
double midlayer1[5];
double midlayer2[5];
double midlayer3[5];
double midlayerweight1[50];
double midlayerweight2[25];
double midlayerweight3[25];
double midlayerweight4[50];
double responselayer[10];
int botcalc() {
	if (player = 2) {
		for (int i = 1; i <= 9; i++) {
			if (grid[i] == 'X') {
				gridval[i] = 0;
			}
			else if (grid[i] == 'O') {
				gridval[i] = 1;
			}
		}
		ifstream file1("weights1.txt");
		if (file1.is_open()) {
			for (int i = 0; i < 50; i++)
			{
				file1 >> midlayerweight1[i];
			}
		}
		file1.close();
		ifstream file2("weights2.txt");
		if (file2.is_open()) {
			for (int i = 0; i < 25; i++)
			{
				file2 >> midlayerweight2[i];
			}
		}
		file2.close();
		ifstream file3("weights3.txt");
		if (file3.is_open()) {
			for (int i = 0; i < 25; i++)
			{
				file3 >> midlayerweight3[i];
			}
		}
		file3.close();
		ifstream file4("weights4.txt");
		if (file4.is_open()) {
			for (int i = 0; i < 50; i++)
			{
				file4 >> midlayerweight3[i];
			}
		}
		file4.close();
		//hidden layer 1 input calculation and output//
		for (int j = 1; j <= 5; j++) {
			double subval = 0;
			if (j == 1) {
				for (int i = 1; i <= 10; i++) {
					subval = (midlayerweight1[i-1] * gridval[i]) + subval;
					midlayer1[j]=subval;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 2) {
				for (int i = 11; i <= 20; i++) {
					subval = (midlayerweight1[i-1] * gridval[i]) + subval;
					midlayer1[j]=subval;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 3) {
				for (int i = 21; i <= 30; i++) {
					subval = (midlayerweight1[i - 1] * gridval[i]) + subval;
					midlayer1[j]=subval;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 4) {
				for (int i = 31; i <= 40; i++) {
					subval = (midlayerweight1[i - 1] * gridval[i]) + subval;
					midlayer1[j]=subval;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 5) {
				for (int i = 41; i <= 50; i++) {
					subval = (midlayerweight1[i - 1] * gridval[i]) + subval;
					midlayer1[j]=subval;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
		}
		//hidden laer 2 input calculation and output//
		for (int j = 1; j <= 5; j++) {
			double subval = 0;
			if (j == 1) {
				for (int i = 1; i <= 5; i++) {
					subval = (midlayerweight2[i - 1] * midlayer1[i]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 2) {
				for (int i = 6; i <= 10; i++) {
					subval = (midlayerweight2[i - 1] * midlayer1[j]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 3) {
				for (int i = 11; i <= 15; i++) {
					subval = (midlayerweight1[i - 1] * midlayer1[j]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 4) {
				for (int i = 16; i <= 20; i++) {
					subval = (midlayerweight1[i - 1] * midlayer1[j]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 5) {
				for (int i = 21; i <= 25; i++) {
					subval = (midlayerweight1[i - 1] * midlayer1[j]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
		}
		//hidden laer 3 input calculation and output//
		for (int j = 1; j <= 5; j++) {
			double subval = 0;
			if (j == 1) {
				for (int i = 1; i <= 5; i++) {
					subval = (midlayerweight3[i - 1] * midlayer2[i]) + subval;
					midlayer3[j]=subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 2) {
				for (int i = 6; i <= 10; i++) {
					subval = (midlayerweight3[i - 1] * midlayer2[j]) + subval;
					midlayer3[j] = subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 3) {
				for (int i = 11; i <= 15; i++) {
					subval = (midlayerweight3[i - 1] * midlayer2[j]) + subval;
					midlayer3[j] = subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 4) {
				for (int i = 16; i <= 20; i++) {
					subval = (midlayerweight3[i - 1] * midlayer2[j]) + subval;
					midlayer3[j] = subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 5) {
				for (int i = 21; i <= 25; i++) {
					subval = (midlayerweight3[i - 1] * midlayer2[j]) + subval;
					midlayer3[j] = subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
		}
		//final layer input calculation and output//
		for (int j = 1; j <= 10; j++) {
			double subval = 0;
			if (j == 1) {
				for (int i = 1; i <= 10; i++) {
					subval = (midlayerweight4[i - 1] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 2) {
				for (int i = 11; i <= 20; i++) {
					subval = (midlayerweight4[i - 1] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 3) {
				for (int i = 21; i <= 30; i++) {
					subval = (midlayerweight4[i - 1] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 4) {
				for (int i = 31; i <= 40; i++) {
					subval = (midlayerweight4[i - 1] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 5) {
				for (int i = 41; i <= 50; i++) {
					subval = (midlayerweight4[i - 1] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
		}
		double max = 0;
		for (int i = 1; i <= 9; i++) {
			if (responselayer[i] > max) {
				max = responselayer[i];
			}
		}
		for (int i = 1; i <= 9; i++) {
			if (max == responselayer[i]) {
				return i;
			}
		}

	}
	return 0;
}