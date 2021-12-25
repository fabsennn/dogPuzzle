#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct CARD {
	int number;
	string n[1][2];
	string e[1][2];
	string s[1][2];
	string w[1][2];
	int rotation;
};

CARD rotateCard(CARD card) {
	card.rotation += 90 % 360;
	string temp1 = card.n[0][0];
	string temp2 = card.n[0][1];
	card.n[0][0] = card.e[0][0];
	card.n[0][1] = card.e[0][1];
	card.e[0][0] = card.s[0][0];
	card.e[0][1] = card.s[0][1];
	card.s[0][0] = card.w[0][0];
	card.s[0][1] = card.w[0][1];
	card.w[0][0] = temp1;
	card.w[0][1] = temp2;

	return card;
}

bool checkPuzzle(CARD puzzle[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 2) {
				//farbe muss gleich sein
				if (puzzle[i][j].s[0][0] != puzzle[i + 1][j].n[0][0])
					return false;
				//Körperteil muss ungleich sein
				if (puzzle[i][j].s[0][1] == puzzle[i + 1][j].n[0][1])
					return false;
			}
			if (j != 2) {
				if (puzzle[i][j].s[0][0] != puzzle[i][j + 1].n[0][0])
					return false;
				if (puzzle[i][j].s[0][1] == puzzle[i][j + 1].n[0][1])
					return false;
			}
		}
	}
	return true;
}

int main() {
	CARD card1;
	card1.number = 1;
	card1.n[0][0] = "braun";
	card1.n[0][1] = "kopf";
	card1.e[0][0] = "dreiecke";
	card1.e[0][1] = "rumpf";
	card1.s[0][0] = "kreise";
	card1.s[0][1] = "rumpf";
	card1.w[0][0] = "gestrichelt";
	card1.w[0][1] = "kopf";
	card1.rotation = 0;

	CARD card2;
	card2.number = 2;
	card2.n[0][0] = "kreise";
	card2.n[0][1] = "kopf";
	card2.e[0][0] = "gestrichelt";
	card2.e[0][1] = "rumpf";
	card2.s[0][0] = "braun";
	card2.s[0][1] = "rumpf";
	card2.w[0][0] = "dreiecke";
	card2.w[0][1] = "kopf";
	card2.rotation = 0;

	CARD card3;
	card3.number = 3;
	card3.n[0][0] = "gestrichelt";
	card3.n[0][1] = "kopf";
	card3.e[0][0] = "kreise";
	card3.e[0][1] = "rumpf";
	card3.s[0][0] = "gestrichelt";
	card3.s[0][1] = "rumpf";
	card3.w[0][0] = "dreiecke";
	card3.w[0][1] = "kopf";
	card3.rotation = 0;

	CARD card4;
	card4.number = 4;
	card4.n[0][0] = "dreiecke";
	card4.n[0][1] = "kopf";
	card4.e[0][0] = "kreise";
	card4.e[0][1] = "rumpf";
	card4.s[0][0] = "gestrichelt";
	card4.s[0][1] = "rumpf";
	card4.w[0][0] = "gestrichelt";
	card4.w[0][1] = "kopf";
	card4.rotation = 0;

	CARD card5;
	card5.number = 5;
	card5.n[0][0] = "kreise";
	card5.n[0][1] = "kopf";
	card5.e[0][0] = "dreiecke";
	card5.e[0][1] = "rumpf";
	card5.s[0][0] = "braun";
	card5.s[0][1] = "rumpf";
	card5.w[0][0] = "gestrichelt";
	card5.w[0][1] = "kopf";
	card5.rotation = 0;

	CARD card6;
	card6.number = 6;
	card6.n[0][0] = "gestrichelt";
	card6.n[0][1] = "kopf";
	card6.e[0][0] = "braun";
	card6.e[0][1] = "rumpf";
	card6.s[0][0] = "kreise";
	card6.s[0][1] = "rumpf";
	card6.w[0][0] = "dreiecke";
	card6.w[0][1] = "kopf";
	card6.rotation = 0;

	CARD card7;
	card7.number = 7;
	card7.n[0][0] = "kreise";
	card7.n[0][1] = "kopf";
	card7.e[0][0] = "dreiecke";
	card7.e[0][1] = "rumpf";
	card7.s[0][0] = "braun";
	card7.s[0][1] = "rumpf";
	card7.w[0][0] = "dreiecke";
	card7.w[0][1] = "kopf";
	card7.rotation = 0;

	CARD card8;
	card8.number = 8;
	card8.n[0][0] = "braun";
	card8.n[0][1] = "kopf";
	card8.e[0][0] = "kreise";
	card8.e[0][1] = "rumpf";
	card8.s[0][0] = "braun";
	card8.s[0][1] = "rumpf";
	card8.w[0][0] = "dreiecke";
	card8.w[0][1] = "kopf";
	card8.rotation = 0;

	CARD card9;
	card9.number = 9;
	card9.n[0][0] = "braun";
	card9.n[0][1] = "kopf";
	card9.e[0][0] = "gestrichelt";
	card9.e[0][1] = "rumpf";
	card9.s[0][0] = "kreise";
	card9.s[0][1] = "rumpf";
	card9.w[0][0] = "gestrichelt";
	card9.w[0][1] = "kopf";
	card9.rotation = 0;

	CARD cardArray[9];
	cardArray[0] = card1;
	cardArray[1] = card2;
	cardArray[2] = card3;
	cardArray[3] = card4;
	cardArray[4] = card5;
	cardArray[5] = card6;
	cardArray[6] = card7;
	cardArray[7] = card8;
	cardArray[8] = card9;


	CARD puzzle[3][3];
	//iterate through all permutations
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int counter = 0;
	//try all permutations
	do {
		int k = 0;
		//add current permutation into array
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				puzzle[i][j] = cardArray[a[k] - 1];
				k++;
			}
		}

		//rotate current permutation into all possible orientations
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

			}
		}
		//check array
		if (checkPuzzle(puzzle)) {
			cout << a;
			std::cin.ignore();
		}
		

		if (counter % 10000 == 0)
			cout << counter << endl;
		counter++;
	} while (std::next_permutation(a, a + 9));
	//}



	return 0;
}