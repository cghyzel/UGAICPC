
//import Tandems.TandemRepeatFinder;

public class BoyerMoore {
    private final int R; // the radix
    private int[] right; // the bad-character skip array

    private char[] pattern; // store the pattern as a character array
    private String pat; // or as a string
    public static int numbersOfTandsFound = 0;

    // pattern provided as a string
    public BoyerMoore(String pat) {
	this.R = 256;
	this.pat = pat;

	// position of rightmost occurrence of c in the pattern
	right = new int[R];
	for (int c = 0; c < R; c++)
	    right[c] = -1;
	for (int j = 0; j < pat.length(); j++)
	    right[pat.charAt(j)] = j;
    }

    // pattern provided as a character array
    public BoyerMoore(char[] pattern, int R) {
	this.R = R;
	this.pattern = new char[pattern.length];
	for (int j = 0; j < pattern.length; j++)
	    this.pattern[j] = pattern[j];

	// position of rightmost occurrence of c in the pattern
	right = new int[R];
	for (int c = 0; c < R; c++)
	    right[c] = -1;
	for (int j = 0; j < pattern.length; j++)
	    right[pattern[j]] = j;
    }

    // return offset of first match; N if no match
    public int search(String txt) {
	int M = pat.length();
	int N = txt.length();
	int skip;
	for (int i = 0; i <= N - M; i += skip) {
	    skip = 0;
	    for (int j = M - 1; j >= 0; j--) {
		if (pat.charAt(j) != txt.charAt(i + j)) {
		    skip = Math.max(1, j - right[txt.charAt(i + j)]);
		    break;
		}
	    }
	    if (skip == 0) {

		numbersOfTandsFound++;
		return i; // found

	    }
	}
	return N; // not found
    }

    // return offset of first match; N if no match
    public int search(char[] text) {
	int M = pattern.length;
	int N = text.length;
	int skip;
	for (int i = 0; i <= N - M; i += skip) {
	    skip = 0;
	    for (int j = M - 1; j >= 0; j--) {
		if (pattern[j] != text[i + j]) {
		    skip = Math.max(1, j - right[text[i + j]]);
		    break;
		}
	    }
	    if (skip == 0) {

		return i; // found

	    }
	}
	return N; // not found
    }

    // test client
    public static void main(String[] args) {

	TandemRepeatFinder.createDictionary(TandemRepeatFinder.tandem,
					    TandemRepeatFinder.tandem.length() / 2);
	String[] doubledLetters;
	doubledLetters = TandemRepeatFinder.getArrayLetters();
	for (int k = 0; k < TandemRepeatFinder.setOfLetters.size(); k++) {
	    System.out.println(TandemRepeatFinder.setOfLetters.get(k)
			       .toString());
	    String pat = doubledLetters[k];
	    String txt = TandemRepeatFinder.tandem;
	    char[] pattern = pat.toCharArray();
	    char[] text = txt.toCharArray();

	    BoyerMoore boyermoore1 = new BoyerMoore(pat);
	    BoyerMoore boyermoore2 = new BoyerMoore(pattern, 256);
	    int offset1 = boyermoore1.search(txt);
	    int offset2 = boyermoore2.search(text);

	    // print results
	    System.out.println("text:    " + txt);

	    System.out.print("pattern: ");
	    for (int i = 0; i < offset1; i++)
		System.out.print(" ");
	    System.out.println(pat);

	    System.out.print("pattern: ");
	    for (int i = 0; i < offset2; i++)
		System.out.print(" ");
	    System.out.println(pat);

	    System.out.println(numbersOfTandsFound);
	}
    }
}
