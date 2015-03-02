import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws IOException {
		System.out.println("In main!");
		
		RSA rsa = new RSA(1024, "privKey.txt", "pubKey.txt");
		
		BigInteger publicKey = rsa.e;
		BigInteger N = rsa.N;
		BigInteger privateKey = rsa.d;
		
		System.out.println("Public key: " + publicKey);
		System.out.println("Private key: " + privateKey);
		System.out.println("N: " + N);
		
		// Encrypt and decrypt a message
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		System.out.println("Encrypted message: ");
		String en = sc.nextLine();
		
		BigInteger encrypt = rsa.messageEncrypt(en);
		BigInteger decrypt = rsa.decrypt(encrypt);
		
		// Print out the decrypted message
		System.out.println("Decrypted Message is: " + decrypt + "\n");
		System.out.println("Message turns out to be: " + rsa.messageDecrypt(decrypt));
	}
}
