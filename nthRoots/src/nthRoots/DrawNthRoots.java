/*
 * Author : Johan Oakes
 * Date: 3/29/15
 * 
 * Draw the Nth roots of unity for some give N > 0
 * Use some kind of data structure to store complex numbers (N x 2 array)
 * N x 2 array : (real, imaginary)
 * 
 */


package nthRoots;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.math3.complex.Complex;
import org.apache.commons.math3.exception.NotPositiveException;
import org.apache.commons.math3.exception.util.LocalizedFormats;
import org.apache.commons.math3.util.FastMath;

import nthRoots.StdDraw;

public class DrawNthRoots {
		
	public static void main(String[] args){
		System.out.println("Saaaan!");
		
		int maxRows = 100, maxColumns = 2;
		int i = 0, j = 0;
						
		/*
		for (; i < maxRows ; i++ ) {
			
			// Reinitialize columns to 0;
			j = 0;
			
			for (; j < maxColumns; j++) {
				System.out.print( aryNumbers[i][j] + " ");
			}
			
			System.out.println("");
		}
		*/
		
	}
	
	/**
	 *  Computes the nth roots of this complex number 
	 *  Stores numbers in a ArrayList
	 */
	public List<Complex> nthRoot(int n) throws NotPositiveException {
		
		if (n <= 0 ) {
			throw new NotPositiveException(LocalizedFormats.CANNOT_COMPUTE_NTH_ROOT_FOR_NEGATIVE_N,n);
		}
		
		// Store complex numbers in a List
		final List<Complex> result = new ArrayList<Complex>();

		
		final double nthPhi = ((Complex) result).getArgument() / n;
		final double slice = 2 * FastMath.PI / n;
		final double nthRootOfAbs = FastMath.pow(((Complex) result).abs(), 1.0 / n);
		double innerPart = nthPhi;
		
		for (int i = 0; i < n; i++) {
			final double realPart = nthRootOfAbs * FastMath.cos(innerPart);
			final double imaginaryPart = nthRootOfAbs * FastMath.sin(innerPart);
			result.add(createComplex(realPart, imaginaryPart));
			innerPart += slice;
		}
		
		
		return result;
	}
	
	/* Simple helper method to create a Complex number */
	public Complex createComplex(double realPart, double imaginaryPart){
		return new Complex(realPart,imaginaryPart);
	}
	


}
