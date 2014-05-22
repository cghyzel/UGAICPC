import java.util.Scanner;

public class RobotProblem {
	static int cities = 0;
	// First array spot = city
	// Second array is cartesian point, there are two, the first is X and the
	// second is Y.
	static int[][] cityCartesians = new int[1000][2];
	static int totalCable = 0;
	static int totalCitiesOnSamePlane = 0;
	static int[] penalty;
	static int penaltyScore;

	public static void takeInput() {
		Scanner myScanner = new Scanner(System.in);
		String s = myScanner.nextLine();

		cities = Integer.parseInt(s);
		penalty = new int[cities + 3];
		System.out.println(cities);
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
	}

	public static double distance(int cityOne, int cityTwo) {
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

	public static void swap(int city, int k) {

		if (city == k || city == cities) {
			return;
		}
		for (int city1 = k; city1 <= cities; city1++) {
			cityCartesians[city1][0] = cityCartesians[city1 + 1][0];
			cityCartesians[city1][1] = cityCartesians[city1 + 1][1];
		}

		cities -= 1;
		penaltyScore += penalty[k + 2];
		System.out.println("swapping " + city + " " + k + " penalty is "
				+ penalty[city] + " Something is wrong?");
	}

	public static void sort() {
		for (int city = 1; city < cities; city++) {
			System.out.println(city + " " + penalty[city] + " " + (city + 1)
					+ " " + penalty[city + 1]);
			if (distance(city, city + 1) + distance(city + 1, city + 2) > (penalty[city + 1] + distance(
					city, city + 2))) {
				System.out.println("running swap with " + city + " "
						+ (city + 1));
				swap(city, city + 1);
				penaltyScore += penalty[city + 1];

			}
		}
	}

	public static void process() {
		takeInput();
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

	public static boolean penaltyIsMore(int city, int sameCityY) {
		if (penalty[city + 1] > distance(city, sameCityY) + 1) {
			return false;
		}
		return true;
	}

	public static void main(String[] asdf) {
		while (true) {
			process();
			double distance = 0;
			System.out.println("cities");
			for (int x = 0; x < cities + 2; x++) {
				System.out.println(x + " x " + cityCartesians[x][0]);
				System.out.println(x + " y " + cityCartesians[x][1]);
				System.out.println("penalty of " + x + " " + penalty[x]);
			}
			for (int city = 0; city < cities + 1; city += 1) {
				System.out.println("distance computed "
						+ distance(city, city + 1));

				distance += distance(city, city + 1);

				System.out.println("Distance after added " + distance);
				System.out.println("City co-ordinates x"
						+ cityCartesians[city][0] + " y "
						+ cityCartesians[city][1]);
				System.out.println("City + 1 co-ordinates x"
						+ cityCartesians[city + 1][0] + " y "
						+ cityCartesians[city + 1][1]);

			}
			System.out.println(penaltyScore);
			distance += cities + 1 + penaltyScore;
			System.out.println(cities);
			System.out.println("Final Distance " + distance
					+ " this is the final score");
			if (cities == 1) {
				cityCartesians[2][0] = 100;
				cityCartesians[2][1] = 100;
				System.out.print("Distance of One city ");
				System.out.println(distance(0, 1) + distance(1, 2) + 2);
			}

		}
	}
}
