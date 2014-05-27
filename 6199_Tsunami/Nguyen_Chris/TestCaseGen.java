import java.util.Random;

public class TestCaseGen {
    
    public static void main(String[] args) {
	Random rand = new Random();
	int x, y;
	int testCases = rand.nextInt(5)+1; // put in how many test cases you want
	int copy = testCases;
	while (testCases != 0) {
	    int size = rand.nextInt(200) + 1; // put in how many numbers per test case
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
	//System.out.println(copy); // prints num of test cases if you needed to know
    } // main
    
} // City
