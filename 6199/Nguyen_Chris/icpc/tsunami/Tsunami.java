package icpc.tsunami;
import static java.lang.System.out;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Tsunami {

	public static void main(String[] args) {
		Scanner sc;
		City[] cities = null;
		int x = 0;
		int y = 0;
		int i = 0;
		
		try {
			sc = new Scanner(new File("resources/Input.txt"));
			while (sc.hasNext()) {
				Scanner sc2 = new Scanner(sc.nextLine());
				while (sc2.hasNext()) {
					try { // determine if line arg is 1. # of cities or 2. (x,y)
						x = sc2.nextInt();
						y = sc2.nextInt();
						cities[i] = new City(x,y);
						++i;
					} catch (Exception e2) {
						if (x == 0) { // end of input
							//for (int j = 0; j < cities.length; ++j) out.println(cities[j].toString());
							sort(cities);
							out.printf("%.2f\n", minimum(cities)); // compute minimum distance
							System.exit(0); 
						} else if (cities == null) {
							cities = new City[x];
							i = 0;
						} else {
							//for (int j = 0; j < cities.length; ++j) out.println(cities[j].toString());
							sort(cities);
							out.printf("%.2f\n", minimum(cities)); // computer minimum distance
							cities = new City[x];
							i = 0;
						} // if
						//out.println(cities.length);
					} // try
				} // while
			} // while
		} catch (Exception e) {
			e.printStackTrace();
		} // try
		
	} // main

	public static double minimum(City[] cities) {
		double answer = 0;
		// 0. sort cities by y values then by x values;
		// 1. assume a city closest to y = 0 has the meteorological tower
		// 2. transmit down-up
		// 3. every city on the same y-line has to transmit to each other
		// 4. 
		for (int i = 0; i < cities.length-1; ++i) {
			answer += dist(cities[i], cities[i+1]);
		} // for
		return answer;
	} // minimum
	
	public static double dist(City c1, City c2) {
		int x1 = Math.abs(c1.x);
		int y1 = Math.abs(c1.y);
		int x2 = Math.abs(c2.x);
		int y2 = Math.abs(c2.y);
		return Math.sqrt(Math.abs((x2-x1)*(x2-x1)) + Math.abs((y2-y1)*(y2-y1)));
	} // distance
	
	public static void sort(City[] cities) {
		for (int i = 0; i < cities.length; ++i) {
			for (int j = 0; j < cities.length; ++j) {
				if (cities[i].compareTo(cities[j]) < 1) {
					City temp = cities[i];
					cities[i] = cities[j];
					cities[j] = temp;
				} // if
			} // for
		} // for
	} // sort
	
} // Tsunami
