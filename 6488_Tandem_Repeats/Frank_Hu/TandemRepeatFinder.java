
import java.util.ArrayList;
import java.util.Scanner;

public class TandemRepeatFinder {

	static Scanner myScanner = new Scanner(System.in);
	public static String tandem = myScanner.nextLine();
	public static ArrayList<Suffix> setOfLetters = new ArrayList<Suffix>();

	public static boolean setOfLettersIsSame(String s) {
		for (int i = 0; i < setOfLetters.size(); i++) {
			if (s.equals(setOfLetters.get(i).toString())) {
				return true;
			}
		}
		return false;
	}

	public static ArrayList<Suffix> createDictionary(String s, int n) {

		if (n != s.length() && n < s.length()) {
			for (int i = n - s.length() / 2; i < n - 1; i++) {
				String o = s.substring(i, n);
				if (!setOfLettersIsSame(o))
					setOfLetters.add(new Suffix(o));
			}
		} else {

			return setOfLetters;
		}
		setOfLetters.add(new Suffix(s.substring(n - s.length() / 2,
				1 + (n - s.length() / 2))));
		return createDictionary(s, n + 1);
	}

	public static String[] getArrayLetters() {
		String[] doubledLetters = new String[setOfLetters.size()];
		for (int i = 0; i < doubledLetters.length; i++) {

			doubledLetters[i] = setOfLetters.get(i).toString();
			doubledLetters[i] += setOfLetters.get(i).toString();
		}
		return doubledLetters;
	}

	public static void main(String[] args0) {
		createDictionary(tandem, tandem.length() / 2);
		String[] letters = getArrayLetters();
		System.out.println(letters.length);
		for (int i = 0; i < letters.length; i++) {
			System.out.println(letters[i].toString());
		}

	}
}

class Suffix implements Comparable<Suffix> {
	private final String text;

	Suffix(String text) {
		this.text = text;
	}

	public String toString() {
		return text;
	}

	@Override
	public int compareTo(Suffix arg0) {
		// TODO Auto-generated method stub
		return 0;
	}
}
