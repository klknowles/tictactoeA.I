#include "communicatortictac.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;


int player;
double midlayer1[5];
double midlayer2[5];
double midlayer3[5];
double midlayerweight1[50];
double midlayerweight2[25];
double midlayerweight3[25];
double midlayerweight4[50];
double responselayer[10];
template <typename T>
size_t find_max_index(const T data[], size_t size);
int botcalc() {
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
				file4 >> midlayerweight4[i];
			}
		}
		file4.close();
		//hidden layer 1 input calculation and output//
		for (int j = 1; j <= 5; j++) {
			double subval = 0;
			if (j == 1) {
				int k = 0;
				for (int i = 1; i < 10; i++) {
					
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 10; i < 19; i++) {
					
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 19; i < 28; i++) {
					
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
				
			}
			else if (j == 4) {
				int k = 0;
				for (int i = 28; i < 37; i++) {
					
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 5) {
				int k = 0;
				for (int i = 37; i < 46; i++) {
				
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
		}
		//hidden laer 2 input calculation and output//
		for (int j = 0; j <5; j++) {
			double subval = 0;
			if (j == 1) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2[i] * midlayer1[i]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 5; i < 10; i++) {
					
					subval = (midlayerweight2[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 10; i < 15; i++) {
					
					subval = (midlayerweight1[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 4) {
				int k = 0;
				for (int i = 15; i < 20; i++) {
					
					subval = (midlayerweight1[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 5) {
				int k = 0;
				for (int i = 20; i < 25; i++) {

					subval = (midlayerweight1[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
		}
		//hidden laer 3 input calculation and output//
		for (int j = 0; j < 5; j++) {
			double subval = 0;
			if (j == 0) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight3[i] * midlayer2[i]) + subval;
					midlayer3[j]=subval;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 1) {
				int k = 0;
				for (int i = 5; i < 10; i++) {
				
					subval = (midlayerweight3[i] * midlayer2[k]) + subval;
					midlayer3[j] = subval;
					k++;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 10; i < 15; i++) {
					
					subval = (midlayerweight3[i] * midlayer2[k]) + subval;
					midlayer3[j] = subval;
					k++;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 15; i < 20; i++) {
					
					subval = (midlayerweight3[i] * midlayer2[k]) + subval;
					midlayer3[j] = subval;
					k++;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
			else if (j == 4) {
				int k = 0;
				for (int i = 20; i < 25; i++) {
				
					subval = (midlayerweight3[i] * midlayer2[k]) + subval;
					midlayer3[j] = subval;
					k++;
				}
				midlayer3[j] = 1 / (1 + exp(-midlayer3[j]));
			}
		}
		//final layer input calculation and output//
		for (int j = 1; j <= 10; j++) {
			double subval = 0;
			if (j == 1) {

				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight4[i] * midlayer3[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 5; i < 10; i++) {
					
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 10; i <15; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 4) {
				int k = 0;
				for (int i = 15; i < 20; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 5) {
				int k = 0;
				for (int i = 20; i <25; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 6) {
				int k = 0;
				for (int i = 25; i <30; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 7) {
				int k = 0;
				for (int i = 30; i <35; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 8) {
				int k = 0;
				for (int i = 35; i < 40; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 9) {
				int k = 0;
				for (int i = 40; i <45; i++) {
					subval = (midlayerweight4[i] * midlayer3[k]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
		}
		return find_max_index(responselayer, 10);

	
}
template <typename T>
size_t find_max_index(const T data[], size_t size) {
	size_t max_index = 0;
	for (size_t i = 1; i < size; ++i)
		if (data[i] > data[max_index])
			max_index = i;
	return max_index;
}
