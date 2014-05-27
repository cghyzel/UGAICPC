//============================================================================
// Name        : 4607.cpp
// Author      :  Frank Hu
// Version     :
// Copyright   : Beerware
// Description : Robotsin C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

static int cities = 0;
// First array spot = city
// Second array is cartesian point, there are two, the first is X and the
// second is Y.
static int cityCartesians[1000][2];
static int totalCitiesOnSamePlane = 0;
static int penalty[1000];
static int penaltyScore;
vector<double> answers;
double distance(int cityOne, int cityTwo);
void swap(int city, int k);
void sort();
void process();
bool penaltyIsMore(int city, int sameCityY);

double distance(int cityOne, int cityTwo) {
	double s = sqrt(
			pow(cityCartesians[cityOne][0] - cityCartesians[cityTwo][0], 2)
					+ pow(
							cityCartesians[cityOne][1]
									- cityCartesians[cityTwo][1], 2));
	if (s < 0) {
		s = -s;
	} else
		return s;
	return s;
}

void swap(int city, int k) {

	if (city == k || city == cities) {
		return;
	}
	for (int city1 = k; city1 <= cities; city1++) {
		cityCartesians[city1][0] = cityCartesians[city1 + 1][0];
		cityCartesians[city1][1] = cityCartesians[city1 + 1][1];
	}

	cities -= 1;
	penaltyScore += penalty[k + 2];
}

void sort() {
	for (int city = 1; city < cities; city++) {
		if (distance(city, city + 1) + distance(city + 1, city + 2)
				> (penalty[city + 1] + distance(city, city + 2))) {
			swap(city, city + 1);
			penaltyScore += penalty[city + 1];

		}
	}
}

void process() {
	sort();

	for (int city = 0; city < cities; city++) {
		for (int k = 0; k < cities; k++) {
			if (cityCartesians[city][1] == cityCartesians[k][1])
				totalCitiesOnSamePlane++;
		}
	}

	for (int city = 0; city < cities; city++) {
		int currentLeastRopeCity = 0;
		for (int sameCityY = 0; sameCityY < totalCitiesOnSamePlane;
				sameCityY++) {
			if (distance(city, sameCityY) < currentLeastRopeCity
					&& !penaltyIsMore(city, sameCityY)) {
				currentLeastRopeCity = sameCityY;
			}
		}
		for (int diffCityY = city; diffCityY > city; diffCityY--) {
			if (distance(diffCityY, city) < currentLeastRopeCity
					&& !penaltyIsMore(diffCityY, city)) {
				currentLeastRopeCity = diffCityY;
			}
		}

	}
}

bool penaltyIsMore(int city, int sameCityY) {
	if (penalty[city + 1] > distance(city, sameCityY) + 1) {
		return false;
	}
	return true;
}

int main() {

	bool quit = false;
	while (!quit) {
		cin >> cities;
		if (cities == 0) {
			for (double e : answers) {
				printf("%.3f\n", e);

			}
			quit = true;
			continue;
			exit(0);
		}

		cityCartesians[0][0] = 0;
		cityCartesians[0][1] = 0;
		penalty[0] = 0;
		penalty[cities - 1] = 0;
		for (int city = 1; city < cities + 1; city++) {
			cin >> cityCartesians[city][0];
			cin >> cityCartesians[city][1];
			cin >> penalty[city];

		}
		cityCartesians[cities + 1][0] = 100;
		cityCartesians[cities + 1][1] = 100;
		process();
		double distance2 = 0;
		for (int city = 0; city < cities + 1; city += 1) {
			distance2 += distance(city, city + 1);

		}
		if (cities > 1) {
			distance2 += cities + 1 + penaltyScore;
			answers.push_back(distance2);
		} else if (cities == 1) {
			cityCartesians[2][0] = 100;
			cityCartesians[2][1] = 100;
			int asdf = distance(0, 1) + distance(1, 2) + 2;
			answers.push_back(asdf);
		}
	}
	//return 0;
}
