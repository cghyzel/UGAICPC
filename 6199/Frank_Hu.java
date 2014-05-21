import java.util.Scanner;

public class Tsunami {
static int cities = 0;
// First array spot = city
// Second array is cartesian point, there are two, the first is X and the
// second is Y.
static int[][] cityCartesians = new int[1000][2];
static int totalCable = 0;
static int totalCitiesOnSamePlane = 0;

public static void takeInput() {
Scanner myScanner = new Scanner(System.in);
String s = myScanner.nextLine();
cities = Integer.parseInt(s);
System.out.println(cities);
for (int city = 0; city < cities; city++) {
for (int cartesianPoint = 0; cartesianPoint < 2; cartesianPoint++) {
cityCartesians[city][cartesianPoint] = myScanner.nextInt();
}
}
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
int x = cityCartesians[city][0];
cityCartesians[city][0] = cityCartesians[k][0];
cityCartesians[k][0] = x;
int y = cityCartesians[city][1];
cityCartesians[city][1] = cityCartesians[k][1];
cityCartesians[k][1] = y;
}

public static void sort() {
for (int city = 0; city < cities; city++) {
for (int k = 0; k < cities; k++) {
if (cityCartesians[city][1] < cityCartesians[k][1]) {
swap(city, k);
}
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
if (distance(city, sameCityY) < currentLeastRopeCity) {
currentLeastRopeCity = sameCityY;
}
}
for (int diffCityY = city; diffCityY > city; diffCityY--) {
if (distance(diffCityY, city) < currentLeastRopeCity) {
currentLeastRopeCity = diffCityY;
}
}

}
}

public static void main(String[] asdf) {
process();
double distance = 0;
System.out.println("cities");
for (int x = 0; x < cities; x++) {
System.out.println(x + " x " + cityCartesians[x][0]);
System.out.println(x + " y " + cityCartesians[x][1]);
}
for (int city = 0; city < cities - 1; city += 1) {
System.out.println(distance(city, city + 1));
distance += distance(city, city + 1);
System.out.println(distance);
}
}

}
