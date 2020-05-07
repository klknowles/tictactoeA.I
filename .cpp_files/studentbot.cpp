#include "communicatortictac.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;

int a = 0, b = 0, c = 0, d = 0, e = 0;
int aa = 0, bb = 0, cc = 0, dd = 0, ee = 0, ff = 0, gg = 0, hh = 0, ii = 0;
int player;
double midlayer1[5];
double midlayer2[5];
double midlayer3[5];
double midlayerweight1[50];
double midlayerweight2[50];
double midlayerweight3[25];
double midlayerweight4[50];
double midlayerweight1a[9];
double midlayerweight1b[9];
double midlayerweight1c[9];
double midlayerweight1d[9];
double midlayerweight1e[9];
double midlayerweight2a[5];
double midlayerweight2b[5];
double midlayerweight2c[5];
double midlayerweight2d[5];
double midlayerweight2e[5];
double midlayerweight2f[5];
double midlayerweight2g[5];
double midlayerweight2h[5];
double midlayerweight2i[5];
double responselayer[10];
template <typename T>
size_t find_max_index(const T data[], size_t size);
int botcalc() {
		for (int i = 1; i <= 9; i++) {
			if (grid[i] == 'X') {
				gridval[i] = 2;
			}
			else if (grid[i] == 'O') {
				gridval[i] = 0;
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
		for (int i = 0; i < 45; i++) {
			if (i < 9) {
				midlayerweight1a[a] = midlayerweight1[i];
				a++;
			}
			else if (i < 18) {
				midlayerweight1b[b] = midlayerweight1[i];
				b++;
			}
			else if (i < 27) {
				midlayerweight1c[c] = midlayerweight1[i];
				c++;
			}
			else if (i < 36) {
				midlayerweight1d[d] = midlayerweight1[i];
				d++;
			}
			else if (i < 45) {
				midlayerweight1e[e] = midlayerweight1[i];
				e++;
			}
		}
		for (int i = 0; i < 45; i++) {
			if (i < 5 ) {
				midlayerweight2a[aa] = midlayerweight4[i];
				aa++;
			}
			else if (i < 10) {
				midlayerweight2b[bb] = midlayerweight4[i];
				bb++;
			}
			else if (i < 15) {
				midlayerweight2c[cc] = midlayerweight4[i];
				cc++;
			}
			else if (i < 20) {
				midlayerweight2d[dd] = midlayerweight4[i];
				dd++;
			}
			else if (i < 25) {
				midlayerweight2e[ee] = midlayerweight4[i];
				ee++;
			}
			else if (i < 30) {
				midlayerweight2f[ff] = midlayerweight4[i];
				ff++;
			}
			else if (i < 35) {
				midlayerweight2g[gg] = midlayerweight4[i];
				gg++;
			}
			else if (i < 40) {
				midlayerweight2h[hh] = midlayerweight4[i];
				hh++;
			}
			else if (i < 45) {
				midlayerweight2i[ii] = midlayerweight4[i];
				ii++;
			}
		}
		//hidden layer 1 input calculation and output//
		for (int j = 0; j < 5; j++) {
			double subval = 0;
			if (j == 0) {
				int k = 1;
				subval = 0;
				for (int i = 0; i < 9; i++) {
					
					subval = (midlayerweight1a[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 1) {
				int k = 1;
				subval = 0;
				for (int i = 0; i < 9; i++) {
					
					subval = (midlayerweight1b[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 2) {
				int k = 1;
				subval = 0;
				for (int i = 0; i < 9; i++) {
					subval = (midlayerweight1c[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
				
			}
			else if (j == 3) {
				int k = 1;
				subval = 0;
				for (int i = 0; i < 9; i++) {
					subval = (midlayerweight1d[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
			else if (j == 4) {
				int k = 1;
				subval = 0;
				for (int i = 0; i < 9; i++) {
				
					subval = (midlayerweight1[i] * gridval[k]) + subval;
					midlayer1[j]=subval;
					k++;
				}
				midlayer1[j] = 1 / (1 + exp(-midlayer1[j]));
			}
		}
		//hidden laer 2 input calculation and output//
		/*for (int j = 0; j <5; j++) {
			double subval = 0;
			if (j == 0) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2[i] * midlayer1[i]) + subval;
					midlayer2[j]=subval;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 1) {
				int k = 0;
				for (int i = 5; i < 10; i++) {
					
					subval = (midlayerweight2[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 10; i < 15; i++) {
					
					subval = (midlayerweight2[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 15; i < 20; i++) {
					
					subval = (midlayerweight2[i] * midlayer1[k]) + subval;
					midlayer2[j]=subval;
					k++;
				}
				midlayer2[j] = 1 / (1 + exp(-midlayer2[j]));
			}
			else if (j == 4) {
				int k = 0;
				for (int i = 20; i < 25; i++) {

					subval = (midlayerweight2[i] * midlayer1[k]) + subval;
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
		}*/
		//final layer input calculation and output//
		for (int j = 1; j < 5; j++) {
			double subval = 0;
			if (j == 1) {

				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2a[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 2) {
				int k = 0;
				for (int i = 0; i < 5; i++) {
					
					subval = (midlayerweight2b[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 3) {
				int k = 0;
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2c[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
					k++;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
				
			}
			else if (j == 4) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2d[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 5) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2e[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 6) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2f[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 7) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2g[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 8) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2h[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
				}
				responselayer[j] = 1 / (1 + exp(-responselayer[j]));
			}
			else if (j == 9) {
				for (int i = 0; i < 5; i++) {
					subval = (midlayerweight2i[i] * midlayer1[i]) + subval;
					responselayer[j] = subval;
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