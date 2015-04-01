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

import java.util.Scanner;

import org.apache.commons.math3.complex.Complex;

import nthRoots.StdDraw;

public class DrawNthRoots {
		
	public static void main(String[] args){

		System.out.println("Starting Lab 3...");

		// Draw the nth roots of unity
		// drawNthRoots();

		// compute x x y matrix F with N
		// computeFMatrix(8,8,8);

		// System.out.println("");

		// compute F-inverse matrix
		computeFInverse(8,8,8);
		
		// System.exit(0);
	}
	
	/* Method to output the Nth roots given N > 0 */
	public static void drawNthRoots() {
		
		// Draw the Nth roots of unity for N > 0 
		// Here, N is set to 100 to give a good picture of the unit circle
		int N = 500;
		
		StdDraw.setScale(-1.0, 1.0);
		
		if (N <= 0) {
			System.out.println("Cannot compute Nth root of negative N");
		} else {
			for (int i = 0; i < N; i++ ) {
				double x = Math.cos(2.0 * Math.PI * i / N);
				double y = Math.sin(2.0 * Math.PI * i / N);
				
				// Create a new complex number based on the real and imaginary parts
				Complex t = new Complex(x,y);

				// Plot the real and imaginary coordinates
				StdDraw.point(x,y);


				// System.out.println(t);
			}
		}
	}

	/* Computing the Fourier matrix F */
	public static void computeFMatrix(int i, int j, int N) {

		Complex F[][] = new Complex[i][j];

		for (int m = 0; m < i; m++){
			for (int n = 0; n < j; n++) {

				double x = Math.cos(2.0 * Math.PI * (m*n)/N);
				double y = (0.0 - (Math.sin(2.0 * Math.PI * (m*n)/N)));

				Complex t = new Complex(x, y);

				F[m][n] = t;
				System.out.print(F[m][n] + "    ");
			}
			System.out.println("");
		}
	}

	/* Compute the Fourier Matrix F - Inverse */
	public static void computeFInverse(int i, int j, int N) {

		Complex FInverse[][] = new Complex[i][j];

		double oneOverN = 1.0/N;
		// Create a new complex number from  oneOVerN
		Complex z = new Complex(oneOverN, 0.0); // (1/N) + 0i

		for (int m = 0; m < i; m++) {
			for (int n = 0; n < i; n++) {

				double x = Math.cos(2.0 * Math.PI * (m*n)/N);
				double y = Math.sin(2.0 * Math.PI * (m * n) / N);

				Complex t = new Complex(x,y);

				Complex complete = t.multiply(oneOverN);

				FInverse[m][n] = complete;

				System.out.print(FInverse[m][n] + "    ");
			}
			System.out.println("");
		}
	}



}
