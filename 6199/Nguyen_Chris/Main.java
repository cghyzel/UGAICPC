
import java.util.ArrayList;
import java.util.Scanner;

class Main {
	
	static Scanner sc = new Scanner(System.in);
	static double[] answer = new double[1000];
	static int answerIndex = 0;
	static int[][] cities = new int[1000][2];
	static int numCities;
	
	public static void main(String[] args) {
		do {
			numCities = sc.nextInt();		
			if (numCities == 0) {
				for (int k = 0; k < answerIndex; ++k) System.out.printf("%.2f\n", answer[k]);
				sc.close();
				System.exit(0);
			} else if (numCities == 1) {
				sc.nextInt();
				sc.nextInt();
				answer[answerIndex++] = 0;
				continue;
			}
			for (int i = 0; i < numCities; ++i) {
				cities[i][0] = sc.nextInt();
				cities[i][1] = sc.nextInt();
			}
			sort(cities, numCities);
			for (int i = 0; i < numCities; ++i) {
				System.out.println(cities[i][0] + "\t" + cities[i][1]);
			}
			answer[answerIndex++] = minDist(cities, numCities);
		} while(true);
	} // main
	
	static int[] getClosestCity(int[][] cities, int numCitiesAtOrBelow, int currentCity[]) {

		boolean foundFirstTarget = false;
		int[] targetCity = null;
		for (int i = 0; i < numCitiesAtOrBelow; ++i) {
			if (foundFirstTarget == false) {
				if (cities[i][1] != currentCity[1] || cities[i][0] != currentCity[0])
					targetCity = cities[i];
				foundFirstTarget = true;
			}
			else if ((cities[i][1] != currentCity[1] || cities[i][0] != currentCity[0])
				&& dist(cities[i], currentCity) < dist(targetCity, currentCity))
				targetCity = cities[i];
		}

		if (targetCity == null) System.out.println("SOMETHING WENT VERY WRONG");
		return targetCity;
	}
	
	static double minDist(int[][] cities, int numCities) {
		double totalDist = 0;
		for (int i = 1; i < numCities; ++i) { // compute distance
			int sameLineCities = 0;
			for (int j = i+1; j < numCities; ++j) { // find all the cities on the same line
				if (cities[j][1] == cities[i][1]) sameLineCities++;
				else break;
			}
			System.out.println("i: " + i + "\tslc: " + sameLineCities);
			if (sameLineCities == 0) {
				
			}
			int[] currentCity = cities[i];
			int[] targetCity = getClosestCity(cities, i + sameLineCities + 1, currentCity);
			totalDist += dist(targetCity, currentCity);
			System.out.println("Dist: " + dist(targetCity, currentCity));
		}
		return totalDist;
	} // minDist
	
	static double dist(int[] a, int[] b) {
		return Math.sqrt(Math.abs((a[0]-b[0])*(a[0]-b[0])) 
				+ Math.abs((a[1]-b[1])*(a[1]-b[1])));
	}
	
	/*
	 * Not the best sorting algorithm to use. A better one will 
	 * replace this one when I have more time.
	 */
	static void sort(int[][] cities, int numCities) {
		for (int i = 0; i < numCities; i += 1) {
			for (int j = 0; j < numCities; j += 1) {
				if (cities[i][1] < cities[j][1]) {
					int[] temp = cities[i];
					cities[i] = cities[j];
					cities[j] = temp;
				}
			}
		}
	}

} // Tsunami2





//int[] targetCity = cities[0];		
//
//System.out.println("dist current -> target: " + dist(currentCity, cities[i]));



/*
	System.out.println("\nCITIES BELOW: " + "(" + currentCity[0] + "," + currentCity[1] + ")");
	if (numCitiesAtOrBelow == 0)
		System.out.println("No cities are below.");
	else
		System.out.println(cities[0][0] + "\t" + cities[0][1]);
*/
	


//System.out.	println("Target City: " + "(" + targetCity[0] + ", " + targetCity[1] + ")");
//System.out.println("Current City: " + "(" + currentCity[0] + ", " + currentCity[1] + ")");

