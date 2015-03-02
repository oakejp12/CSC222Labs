// Java BigInteger and Random Libraries
import java.math.BigInteger;
import java.util.Random;


/**
 * Implement the modular functions for RSA Encryption
 */
public class ModularArithmetic {
	
	
	/* Modular Addition using BigInteger library */
	public static BigInteger modadd(BigInteger a, BigInteger b, BigInteger N) {
		BigInteger c = a.add(b).mod(N);
		return c;
	}
	
	public static BigInteger modmult(BigInteger a, BigInteger b, BigInteger N) {
		return a.mod(N).multiply(b.mod(N)).mod(N);
	}
	
	
	/* z = modexp(a,b,N) where c = a^b (mod N) */
	public static BigInteger modexp(BigInteger a, BigInteger b, BigInteger N) {
		
		BigInteger z = BigInteger.ONE;
		
		a = a.mod(N);
		
		// For faster looping
		int i = 0, k = b.bitLength();
		for (; i < k; i++) {
			
			if (b.testBit(i)) {
				z = z.multiply(a).mod(N);
			}
			
			a = a.multiply(a).mod(N);
		}		
		return z;
	}
	
	/* Modular division function */
	public static BigInteger moddiv(BigInteger a, BigInteger b, BigInteger N) {
		
		// Need to find the inverse of b mod N
		BigInteger bprime = extendedEuclid(b,N)[0];
		BigInteger aprime = a.multiply(bprime);
				
		// We want to return a*x (mod N)
		BigInteger z = aprime.mod(N);
		
		return z;
	}
	
	/* Implement the Extended Euclidean Algorithm */
	public static BigInteger [] extendedEuclid(BigInteger a, BigInteger N) {
		
		// b=0 ? return (1,0,a)
		if (N.compareTo(BigInteger.ZERO) == 0)
			return new BigInteger [] {BigInteger.ONE, BigInteger.ZERO, a};
		
		// Since n is bigger
		BigInteger [] c = extendedEuclid(N, a.mod(N));
		
		
		// xprime - floor(a/N)*yprime
		BigInteger temp = (a.divide(N)).multiply(c[1]);
		BigInteger hold = c[0].add(temp.negate());
		
		// return the array yprime, xprime-floor(a/b)yprime, d
		return new BigInteger [] {c[1], hold, c[2]};
	}
	
	
	/* Fermats Little Theorem test - Need to test against Carmichael Numbers */
	public static boolean isPrime(BigInteger N, int k) {
		
		// Hold value of -1
		BigInteger hold = new BigInteger("-1");
		
		
		
		Random rand = new Random();
		int i = 0;
		for (; i < k; i++) {
			
			BigInteger lim = N.add(hold);
			
			BigInteger z;
			
			
			// Generate a random integer of N-1 length
			do {
				z = new BigInteger(lim.bitLength(), rand);
			} while (z.compareTo(lim) >= 0);
			
			
			// Assert that c is not 0 
			if (z.mod(N).equals(BigInteger.ZERO)) 
				z.add(BigInteger.ONE);
			
			BigInteger exponent = ModularArithmetic.modexp(z, N.subtract(BigInteger.ONE), N);
			
			
			if (!exponent.equals(BigInteger.ONE)) return false;
		}
		
		return true;
	}
	
	
	/* Generate a random prime */
	public static BigInteger genPrime(final int n) {
		
		if (n==0)
			return BigInteger.ONE;
		
		
		BigInteger smallNBits = new BigInteger("2");
		
		int i = 1;
		BigInteger temp = new BigInteger("2");
		for (; i < n - 1; i++) 
			smallNBits = smallNBits.multiply(temp);
		
		BigInteger pnum = null;
		Random rand = new Random();
		
		while (true) {
			pnum = new BigInteger(n,rand);
			
			if (pnum.compareTo(smallNBits) >= 0 && isPrime(pnum, n))
				return pnum;
			
		}
		
	}
	
	
}

	

