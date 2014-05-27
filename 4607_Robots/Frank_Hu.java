// Not Solved

import java.util.ArrayList;
import java.util.Scanner;

class Main {
	static int cities = 0;
	// First array spot = city
	// Second array is cartesian point, there are two, the first is X and the
	// second is Y.
	static int[][] cityCartesians = new int[1000][2];
	static int totalCable = 0;
	static int totalCitiesOnSamePlane = 0;
	static int[] penalty;
	static int penaltyScore;
	static ArrayList<Double> answers = new ArrayList<>();
	static Scanner myScanner = new Scanner(System.in);

	static double distance(int cityOne, int cityTwo) {
		Double s = Math.sqrt(Math.pow(cityCartesians[cityOne][0]
				- cityCartesians[cityTwo][0], 2)
				+ Math.pow(cityCartesians[cityOne][1]
						- cityCartesians[cityTwo][1], 2));
		if (s < 0) {
			s = -s;
		} else
			return s;
		return s;
	}

	static void swap(int city, int k) {

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

	static void sort() {
		for (int city = 1; city < cities; city++) {
			if (distance(city, city + 1) + distance(city + 1, city + 2) > (penalty[city + 1] + distance(
					city, city + 2))) {
				swap(city, city + 1);
				penaltyScore += penalty[city + 1];

			}
		}
	}

	static void process() {
		sort();

		for (int city = 0; city < cities; city++) {
			for (int k = 0; k < cities; k++) {
				if (cityCartesians[city][1] == cityCartesians[k][1])
					totalCitiesOnSamePlane++;
			}
		}

		for (int city = 0; city < cities; city++) {
			int currentLeastRopeCity = 0;
			for (int sameCityY = 0; sameCityY < totalCitiesOnSamePlane; sameCityY++) {
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

	static boolean penaltyIsMore(int city, int sameCityY) {
		if (penalty[city + 1] > distance(city, sameCityY) + 1) {
			return false;
		}
		return true;
	}

	public static void main(String[] args) {
		while (true) {
			cities = myScanner.nextInt();
			if (cities == 0) {
				for (Double e : answers) {
					System.out.printf("%.3f", e);
					System.out.println();

				}
				System.exit(0);
			}

			penalty = new int[cities + 3];
			cityCartesians[0][0] = 0;
			cityCartesians[0][1] = 0;
			penalty[0] = 0;
			penalty[cities - 1] = 0;
			for (int city = 1; city < cities + 1; city++) {
				cityCartesians[city][0] = myScanner.nextInt();
				cityCartesians[city][1] = myScanner.nextInt();
				penalty[city] = myScanner.nextInt();

			}
			cityCartesians[cities + 1][0] = 100;
			cityCartesians[cities + 1][1] = 100;
			process();
			double distance = 0;
			for (int city = 0; city < cities + 1; city += 1) {
				distance += distance(city, city + 1);

			}
			if (cities > 1) {
				distance += cities + 1 + penaltyScore;
				answers.add(distance);
			} else if (cities == 1) {
				cityCartesians[2][0] = 100;
				cityCartesians[2][1] = 100;
				answers.add(distance(0, 1) + distance(1, 2) + 2);
			}
		}
	}
}
