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
		
		// Draw the nth roots of unity
		drawNthRoots();
		
		
		return;
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
				
				System.out.println(t);	
			}
		}
	}
}
