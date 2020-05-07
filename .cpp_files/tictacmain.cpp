#include <iostream>
#include "communicatortictac.h"

using namespace std;


int checkwin();
void board();
char grid[10] = { 'n', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
double gridval[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int main() {
	int l = 0;
	int n = 0;
	int o = 0;
	int m = 0;
	int p = 0;
	int i;
	int j = 0;
	int k = 0;
	int choice;
	int player = 1;
	char mark; 
	do {
		bool fail = true;
		board();
		player = (player % 2) ? 1 : 2;

		cout << "Player " << player << ", enter a number:  ";
		if (player == 1) {
			cin >> choice;
		}
		else if (player == 2) {
			choice = botcalc();
			j++;
		}
		mark = (player == 1)?'X':'O';

		if (choice == 1 && grid[1] == '1') {
			grid[1] = mark;
		}
		else if (choice == 2 && grid[2] == '2') {
			grid[2] = mark;
		}
		else if (choice == 3 && grid[3] == '3') {
			grid[3] = mark;
		}
		else if (choice == 4 && grid[4] == '4') {
			grid[4] = mark;
		}
		else if (choice == 5 && grid[5] == '5') {
			grid[5] = mark;
		}
		else if (choice == 6 && grid[6] == '6') {
			grid[6] = mark;
		}
		else if (choice == 7 && grid[7] == '7') {
			grid[7] = mark;
		}
		else if (choice == 8 && grid[8] == '8') {
			grid[8] = mark;
		}
		else if (choice == 9 && grid[9] == '9') {
			grid[9] = mark;
		}
		else {
			cout << "Invalid move!! ";
			if (player == 2) {
				cout << "You selected the wrong spot: " << choice;
				boteval(fail);
			}
			
			/*player--;
			cin.ignore();
			cin.get();*/
		}
		i = checkwin();

		player++;
	} while (i == -1);
	board();
	if (i == 1) {

		cout << "==>\aPlayer "<<--player<<" win " << endl;
		while (k < 10) {
			cout << gridval[k] << " ";
			
			k++;

		}
		cout << endl;
		while (m < 5) {
			cout << midlayer3[m] << " ";
			m++;
		}
		cout << endl;
		while (n < 5) {
			cout << midlayer2[n] << " ";
			n++;
		}
		cout << endl;
		while (o < 5) {
			cout << midlayer1[o] << " ";
			o++;
		}
		cout << endl;
		while (p < 25) {
			cout << midlayerweight1[p] << " ";
			p++;
		}
		cout << endl;
		while (l < 10) {
			cout << responselayer[l] << " ";
			l++;
		}
		
		/*cout << endl << "Do you want to play again? (Y) or (N) ";
		cin >> h;
		if (h == 'Y') {

		}*/
	}
	else {
		cout << "==>\aGame draw";
	}
	cin.ignore();
	cin.get();
	return 0;
}

int checkwin() {
	if (grid[1] == grid[2] && grid[2] == grid[3]) {
		return 1;
	}
	else if (grid[4] == grid[5] && grid[5] == grid[6]) {
		return 1;
	}
	else if (grid[7] == grid[8] && grid[8] == grid[9]) {
		return 1;
	}
	else if (grid[1] == grid[5] && grid[5] == grid[9]) {
		return 1;
	}
	else if (grid[3] == grid[5] && grid[5] == grid[7]) {
		return 1;
	}
	else if (grid[1] == grid[4] && grid[4] == grid[7]) {
		return 1;
	}
	else if (grid[2] == grid[5] && grid[5] == grid[8]) {
		return 1;
	}
	else if (grid[3] == grid[6] && grid[6] == grid[9]) {
		return 1;
	}
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3'
		&& grid[4] != '4' && grid[5] != '5' && grid[6] != '6'
		&& grid[7] != '7' && grid[8] != '8' && grid[9] != '9') {
		return 0;
	}
	else {
		return -1;
	}
}

	void board() {
		system("cls");
		cout << "\n\n\tTic Tac Toe\n\n";

		cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
		cout << endl;

		cout << "       |       |       " << endl;
		cout << "   " << grid[1] << "   |" << "   " << grid[2] << "   |" << "   " << grid[3] << "   " << endl;
		cout << "_______|_______|_______" << endl;
		cout << "       |       |       " << endl;
		cout << "   " << grid[4] << "   |" << "   " << grid[5] << "   |" << "   " << grid[6] << "   " << endl;
		cout << "_______|_______|_______" << endl;
		cout << "       |       |       " << endl;
		cout << "   " << grid[7] << "   |" << "   " << grid[8] << "   |" << "   " << grid[9] << "   " << endl;
		cout << "       |       |       " << endl;
}