import java.util.Scanner;

class Main {
	
	static int[][] cities = new int[1000][2];
	static int citiesIndex = 0;
	static int[] sameLineCities = new int[1000]; // act as pointers
	static int sameLineCitiesIndex = 0;
	static boolean[] isConnected; // = new boolean[1000];
		
	static double[] answers = new double[1000];
	static int answersIndex = 0;
	
	public static void main ( String[] args ){
		Scanner sc = new Scanner(System.in);
		do {
			isConnected = new boolean[1000];
			citiesIndex = sc.nextInt();
			sameLineCitiesIndex = 0;
			if (citiesIndex == 0) {
				for (int i = 0; i < answersIndex; ++i) {
					System.out.printf("%.2f\n", answers[i]);
				}
				System.exit(0);
			} else if (citiesIndex == 1) {
				sc.nextInt();	
				sc.nextInt();	
				//System.out.println("0.00");
				answers[answersIndex++] = (0.0);
			} else {
				for (int i = 0; i < citiesIndex; ++i) {
					cities[i][0] = sc.nextInt();
					cities[i][1] = sc.nextInt();
				}
			//	sort();
				//System.out.printf("%.2f\n", calcMinDist());
				answers[answersIndex++] = calcMinDist();
			}
		} while (true);
	} // main
	
	static double calcMinDist() {
		double totalDist = 0;
		double minDist = 1000000;
		double maxInitialDistance = 0;
		int minCity = 0;
		boolean onFirstLevel = true;
		do {
			findSameLineCities();
			if (onFirstLevel) {
				onFirstLevel = false;
				for (int i = 0; i < sameLineCitiesIndex; ++i) {
					isConnected[sameLineCities[i]] = true;
					for (int j = i + 1; j < sameLineCitiesIndex; ++j) {
						if (maxInitialDistance < calcDist( cities[ sameLineCities[i] ], cities[ sameLineCities[j] ] )) {
							maxInitialDistance = calcDist( cities[ sameLineCities[i] ], cities[ sameLineCities[j] ]);
						}
					}
				}
				totalDist += maxInitialDistance;
			} else {
				for (int i = 0; i < sameLineCitiesIndex; ++i) {
					minDist = 1000000;
					minCity = 0;
					for (int j = 0; j < sameLineCitiesIndex; ++j) {
						if (!isConnected[ sameLineCities[j] ]) {
							for (int k = 0; k < citiesIndex; ++k) {
								if (isConnected[k] && calcDist(cities[k], cities[ sameLineCities[j] ]) < minDist) {
									minDist = calcDist(cities[k], cities[ sameLineCities[j] ]);
									minCity = sameLineCities[j];
								}
							}
						}
					}
					if (minDist < 1000000) {
						totalDist += minDist;
						isConnected[minCity] = true;
					}
				}
			}
		} while (!allConnected());
		return totalDist;
	}
	
	static void findSameLineCities() {
		int y = 100001;
		for (int i = 0; i < citiesIndex; ++i) {
			if (cities[i][1] < y && !isConnected[i]) y = cities[i][1];
		}
		for (int i = 0; i < citiesIndex; ++i) {
			if (cities[i][1] == y && !isConnected[i]) sameLineCities[sameLineCitiesIndex++] = i;
		}
	}
	
	static boolean allConnected() {
		for (int i = 0; i < citiesIndex; ++i) {
			if (!isConnected[i]) {
			//	System.out.println(cities[i][0] + " " + cities[i][1] + " not connected!");
				return false;
			}
		} return true;
	}
	
	static double calcDist(int[] a, int[] b) {
		return Math.sqrt( ( a[0] - b[0] ) * ( a[0] - b[0] ) 
				+ ( a[1] - b[1] ) * ( a[1] - b[1] ) );
	}
	
	static void sort() {
		int[] temp;
		for (int i = 0; i < citiesIndex; ++i) {
			for (int j = i; j < citiesIndex; ++j) {
				if (cities[j][1] < cities[i][1]) {
					temp = cities[i];
					cities[i] = cities[j];
					cities[j] = temp;
				} else if (cities[j][1] == cities[i][1]) {
					if (cities[j][0] < cities[i][0]) {
						temp = cities[i];
						cities[i] = cities[j];
						cities[j] = temp;
					}
				}
			}
		}
	}
	
} // Tsunami

	
