#include "game_of_life.h"
#include <ctime>

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	return round((rand() % 100) < 25);
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j]) {
				std::cout << "*";
			}
			else {
				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}


void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_sljedeca_generacija[i][j] = celija_zauzeta(i, j);
		}
	}

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

bool game_of_life::celija_zauzeta(int a, int b)
{
	int brojSusjeda = 0;
	if (_generacija[a - 1][b - 1] && a != 0 && b != 0) {
		brojSusjeda++;
	}
	if (_generacija[a - 1][b] && a != 0) {
		brojSusjeda++;
	}
	if (_generacija[a - 1][b + 1] && a != 0 && b != STUPACA - 1) {
		brojSusjeda++;
	}
	if (_generacija[a][b - 1] && b != 0) {
		brojSusjeda++;
	}
	if (_generacija[a][b + 1] && b != STUPACA - 1) {
		brojSusjeda++;
	}
	if (_generacija[a + 1][b - 1] && a != REDAKA - 1 && b != 0) {
		brojSusjeda++;
	}
	if (_generacija[a + 1][b] && a != REDAKA - 1) {
		brojSusjeda++;
	}
	if (_generacija[a + 1][b + 1] && a != REDAKA - 1 && b != STUPACA - 1) {
		brojSusjeda++;
	}

	if (_generacija[a][b] && brojSusjeda < 2) {
		return 0;
	}
	if (_generacija[a][b] && brojSusjeda > 3) {
		return 0;
	}
	if (_generacija[a][b] && (brojSusjeda == 2 || brojSusjeda == 3)) {
		return 1;
	}
	if (!_generacija[a][b] && brojSusjeda == 3) {
		return 1;
	}
	else {
		return _generacija[a][b];
	}
}