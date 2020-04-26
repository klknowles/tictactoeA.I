#pragma once
/*extern int player;
extern char grid[10];
extern double gridval[10];
double gridans[];*/
extern char grid[10];
extern double gridval[10];
extern double midlayer1[5];
extern double midlayer2[5];
extern double midlayer3[5];
extern double midlayerweight1[50];
extern double midlayerweight2[25];
extern double midlayerweight3[25];
extern double midlayerweight4[50];
extern double responselayer[10];
extern double changeweight1[45];
extern double changeweight4[45];
extern double weighterror1[45];
extern double layer1error[10];
int botcalc();
void weight_adjust();
void boteval(bool nummoves);
