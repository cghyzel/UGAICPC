package icpc.tsunami;

public class City implements Comparable<City> {
	protected int x;
	protected int y;
	
	public City(int x, int y) {
		this.x = x;
		this.y = y;
	} // City constructor
	
	public int compareTo(City c) {
		if (this.y > c.y) return 1;
		else if (this.y == c.y) {
			if (this.x > c.x) return 1;
			else if (this.x == c.x) return 0;
			return -1;
		} 
		return -1;
	} // compareTo
	
	public String toString() {
		return "" + x + " " + y;
	} // toString
}
