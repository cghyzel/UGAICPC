import java.util.Random;

public class City implements Comparable<City> {
	
	protected int x;
	protected int y;
	
	public City(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public int compareTo(City c) {
		if (this.y > c.y) return 1;
		else if (this.y == c.y) {
			if (this.x > c.x) return 1;
			else if (this.x == c.x) return 0;
			return -1;
		}
		return -1;
	}
	
	public String toString() {
		return x + " " + y;
	}

	public static void main(String[] args) {
		Random rand = new Random();
		
		int x, y;
		int testCases = rand.nextInt(5)+1;
		int copy = testCases;
		while (testCases != 0) {
			int size = rand.nextInt(200) + 1;
			System.out.println(size);
			for (int i = 0; i < size; i++) {
				if (rand.nextInt(2) % 2 == 0) {
					x = rand.nextInt(1001);
					if (rand.nextInt(2) % 2 == 0) y = rand.nextInt(1001);
					else y = -1 * rand.nextInt(1001);
				} else {
					x = -1 * rand.nextInt(1001);
					if (rand.nextInt(2) % 2 == 0) y = rand.nextInt(1001);
					else y = -1 * rand.nextInt(1001);
				}
				System.out.println(x + "\t" + y);
			} // for
			testCases--;
		} // while
		System.out.println("0");
		//System.out.println(copy);
	} // main
	
} // City
