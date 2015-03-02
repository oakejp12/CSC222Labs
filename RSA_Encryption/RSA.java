import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class RSA {

	/* Hold public N and e value */
	public static BigInteger N, e;
	
	/* Hold private key d */
	public static BigInteger d;
	
	
    /* Simple helper function to generate the public and private keys */
	private void genKeys(int n) {
		
		// Prime numbers p and q
		BigInteger p = ModularArithmetic.genPrime(n);
		BigInteger q = ModularArithmetic.genPrime(n);
		
		
		// Generate the public key e
		e = ModularArithmetic.genPrime(n);
		
		
		// N = p*q
		N = p.multiply(q);
		
		// s = (p - 1)(q - 1)
		BigInteger s = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
		
		//  d = Inverse e mod s <-> 1 / e mod s
		d = ModularArithmetic.moddiv(BigInteger.ONE, e, s);
	}
	
	
	
	/* RSA(n)
	 * Generates a public (N,e) and private (N,d) RSA key pair, where N,e,d
	 * are numbers of approx. n bits in length. The private key is stored
	 * as a private field of the class and the public key is printed to std output
	 */
	public RSA (int n) {
		// Generate the keys
		genKeys(n);
	}
	
	/* RSA (n, filename, filename)
	 * Same as RSA(n) but in addition it stores the public and private key pair in file filename
	 */
	public RSA(int n, String pubFilename, String privFilename) throws IOException {
		
		// Generate the keys
		genKeys(n);
		
		
		// Use a try/catch block to catch and examine associated errors
		// Print the private keys to the private file name privFilename
		try {
			PrintWriter sampleFile = new PrintWriter(privFilename, "UTF-8");
			sampleFile.println(N);
			sampleFile.println(d);
			sampleFile.close();
		} catch (FileNotFoundException exc) { // couldn't find file
			exc.printStackTrace();
		}
		
		// Print the public keys to the public file pubFilename
		try {
			PrintWriter sampleFile = new PrintWriter(pubFilename);
			sampleFile.write(N + "\n" + e);
			sampleFile.close();
		} catch (FileNotFoundException exc1) { // couldn't find file
			exc1.printStackTrace();
		}
			
	}
	
	
	/* RSA(filename)
	 * Reads in the private key stored in file filename
	 */
	public RSA(String filename) throws IOException {
		
		File dir = new File(".");
		File sampleFile = new File(dir.getCanonicalPath() + File.separator + filename);
		
		// Handle and errors associated with file opening
		try {
			@SuppressWarnings("resource")
			Scanner scan = new Scanner(sampleFile);
			
			// Read N
			N = scan.nextBigInteger();
			
			// Read d
			d = scan.nextBigInteger();
			
			
			System.out.println("N: "  + N);
			System.out.println("d: " + d);			
			
		} catch (FileNotFoundException exc) {
			exc.printStackTrace();
		}
		
	}
	
	/* c = encrypt (m, N, e)
	 * For a given integer m < N and public key (N,e) return the encrypted message
	 * c = m^e (mod N)
	 * 
	 */
	public BigInteger encrypt(BigInteger m, BigInteger N, BigInteger e) {
		BigInteger c = ModularArithmetic.modexp(m, e, N);
		return c;
	}
	
	/* m = decrypt (c)
	 * For an integer c < N, use the private key to return the decrypted message
	 * m = c^d (mod N)
	 */
	public BigInteger decrypt(BigInteger c) {
		BigInteger m = ModularArithmetic.modexp(c, d, N);
		return m;
	}
	
	/* Decrypt the message using the private key */
	public String messageDecrypt (BigInteger m) {
		String temp = new String(m.toByteArray());
		return temp;
	}
	
	public BigInteger messageEncrypt(String m) {
		BigInteger temp = new BigInteger(m.getBytes());
		return encrypt(temp,N,e);
	}
	
	
}


