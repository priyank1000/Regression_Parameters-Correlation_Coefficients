/***********************************************************/
/* Program Assignment: 2					           */
/* Name: Priyank Joshi						      */               
/* Date: 20/04/2015						           */                             
/* Description: The program will calculate the regression parameters and correlation coefficients of 'n' sets of data	*/
/***********************************************************/

#include <stdio.h>
#define xK 386	/* Constant is defined here, that will be used through out the program without changing its value */

int main(void)

{
	int i;
	int n;

	/* declaring arrays x (first column), y (second column), z (third column) and a (fourth column) in a one-dimensional array that can contain upto 100 elements */ 
 
	double x[100], y[100], z[100], a[100], d = 1.0, d2 = 1.0, d3 = 1.0, d4 = 1.0, sum1 = 0.0, sum2 = 0.0, sum3 = 0.0, sum4 = 0.0, sum5 = 0.0, sum6 = 0.0, sum7 = 0.0, sum8 = 0.0, sum9 = 0.0, sum10 = 0.0, sum11 = 0.0, sum12 = 0.0, sum13 = 0.0, sum14 = 0.0, sum15 = 0.0, sum16 = 0.0, sum17 = 0.0, sum18 = 0.0, sum19 = 0.0, sum20 = 0.0, mean1, mean2, mean3, mean4, mean5, mean6, mean7, mean8, xx, xx2, aa2, aa4, yy, yy3, zz3, zz4, xy, xa2, zy3, za4, b1, b12, b13, b14, b0, b02, b03, b04, Rxy, Rxy2, Rxy3, Rxy4, h = 0.0, h2 = 0.0, h3 = 0.0, h4 = 0.0, rSquared, rSquared2, rSquared3, rSquared4, denom, denom2, denom3, denom4, equationY, equationY2, equationY3, equationY4;	/* variables are declared above, and some variables are initialised */


	/* Using a file pointer, that will let the program keep track of the file data.txt being accessed */

	FILE *fptr1;
	printf("Enter the number of elements = ");
	scanf("%d",&n);

	/* fopen and fscanf function simply opens and reads the file which returns a file pointer. In addition a FOR loop is introduced to run a number of iterations until the last element has been read and calculated */
	fptr1 = fopen("data.txt","r");
	for (i = 0; i < n; i++)
	{
		fscanf(fptr1,"%lf %lf %lf %lf", &x[i], &y[i], &z[i], &a[i]);
	}
	fclose(fptr1);

	/* fopen and fscanf function simply opens and reads the file which returns a file pointer. In addition a FOR loop is introduced to run a number of iterations until the last element has been read and calculated */

	/* Test case 1 */
	/* The program calculates the regression parameters and correlation coefficients between estimated proxy size and actual actual added and modified size */

	for (i = 0; i < n; i++)
	{
		sum1 = sum1 + x[i]; 	/* As the elements in column one keep iterating until the last value/element, the sum of x column is calculated */
	}
		mean1 = (sum1 / n); 	/* Once the iteration is completed, the mean of x column is calculated using the sum derived from above */

	for (i = 0; i < n; i++)
	{
		sum2 = sum2 + y[i];	/* As the elements in column two keep iterating until the last value/element, the sum of y column is calculated */
	}
		mean2 = (sum2 / n);	/* Once the iteration is completed, the mean of y column is calculated using the sum derived from above */
		
	/* As elements in the x column and y column keep iterating, calculates the product of elements in x times elements in y (x[i] * y[i]) and then calculates the summation of the elements derived. It also calculates the product of elements in x times elements in x (x[i] * x[i]) and then calculates the summation of the elements derived. Lastly, it calculates the product of elements in y times elements in y (y[i] * y[i]) and then calculates the summation of the elements derived  */
	for (i = 0; i < n; i++)
	{
		xy = x[i] * y[i];
		sum3 = sum3 + xy;
		xx = x[i] * x[i];
		sum4 = sum4 + xx;
		yy = y[i] * y[i];
		sum5 = sum5 + yy;
		
	}

	/* The regression parameter B1 is calculated by using a formula. SUbstituion method is used, since the above summations and mean values had been calculated */
	b1 = (sum3 - (10.0*mean1*mean2)) / (sum4 - (10.0*mean1*mean1)); 
	
	/* The regression parameter B0 is then calculated using a formula, and substituing the value of B1, mean of x and y into the formula */
	b0 = mean2 - (b1*mean1); 

	/* The linear regression is calculated using equation formula, and substituting the values of regression parameters B0 and B1 while xK = 386 (constant) */
	equationY = b0 + (b1*xK); 

	denom = (10*(sum4) - (sum1*sum1)) * (10*(sum5) - (sum2*sum2));  

		/* while loop is introduced, so that repetition can occur and therefore setting b >= 0.01 so that we can not get a negative value when square rooting in the denomenator. square rooting a negative value will show an error in java, hence it can only be possible when dealing with complex numbers */ 
		while (d >= 0.01)
		{
			d = denom - (h * h);
			h = h + 0.05;	
		}

	/* Denomenator has been calculated above and also applying while loop was implemented mentioned above, using the denomenator, correlation coefficient Rx,y is calculated using a formula. Furthermore, square of r (r^2) is also calculated.   */
	Rxy = (10*(sum3)-(sum1)*(sum2))/h;
	rSquared = Rxy * Rxy; 

	/* Test case 2 */
	/* The same procedure of calculation as used in Test case 1 is implemeneted in this case. However, in this case, the program calculates the regression parameters and correlation coefficients between plan added and modified size and actual development time */


	for (i = 0; i < n; i++)
	{
		sum6 = sum6 + x[i]; 	
	}
		mean3 = (sum6 / n);
		

	for (i = 0; i < n; i++)
	{
		xa2 = x[i] * a[i];
		sum7 = sum7 + xa2;
		xx2 = x[i] * x[i];
		sum8 = sum8 + xx2;
		aa2 = a[i] * a[i];
		sum9 = sum9 + aa2;
		
	}

	for (i = 0; i < n; i++)
	{
		sum10 = sum10 + a[i];
	}
		mean4 = (sum10 / n);

	b12 = (sum7 - (10.0*mean3*mean4)) / (sum8 - (10.0*mean3*mean3));
	b02 = mean4 - (b12*mean3);
	equationY2 = b02 + (b12*xK);

	denom2 = (10*(sum8) - (sum6*sum6)) * (10*(sum9) - (sum10*sum10));  

		while (d2 >= 0.01)
		{
			d2 = denom2 - (h2 * h2);
			h2 = h2 + 0.05;	
		}

	Rxy2 = (10*(sum7)-(sum6)*(sum10))/h2;
	rSquared2 = Rxy2 * Rxy2; 

	/* Test case 3 */
	/* The same procedure of calculation as used in Test case 1 is implemeneted in this case. However, in this case, the program calculates the regression parameters and correlation coefficients between plan added and modified size and actual development time */

	for (i = 0; i < n; i++)
	{
		sum11 = sum11 + z[i];	
	}
		mean5 = (sum11 / n);
		
	for (i = 0; i < n; i++)
	{
		zy3 = z[i] * y[i];
		sum12 = sum12 + zy3;
		zz3 = z[i] * z[i];
		sum13 = sum13 + zz3;
		yy3 = y[i] * y[i];
		sum14 = sum14 + yy3;
		
	}

	for (i = 0; i < n; i++)
	{
		sum15 = sum15 + y[i];
	}
		mean6 = (sum15 / n);

	b13 = (sum12 - (10.0*mean5*mean6)) / (sum13 - (10.0*mean5*mean5));
	b03 = mean6 - (b13*mean5);
	equationY3 = b03 + (b13*xK);

	denom3 = (10*(sum13) - (sum11*sum11)) * (10*(sum14) - (sum15*sum15));  

		while (d3 >= 0.01)
		{
			d3 = denom3 - (h3 * h3);
			h3 = h3 + 0.05;	
		}

	Rxy3 = (10*(sum12)-(sum11)*(sum15))/h3;
	rSquared3 = Rxy3 * Rxy3;

	/* Test case 4 */
	/* The same procedure of calculation as used in Test case 1 is implemeneted in this case. However, in this case, the program calculates the regression parameters and correlation coefficients between plan added and modified size and actual development time */


	for (i = 0; i < n; i++)
	{
		sum16 = sum16 + z[i];	
	}
		mean7 = (sum16 / n);
		
	for (i = 0; i < n; i++)
	{
		za4 = z[i] * a[i];
		sum17 = sum17 + za4;
		zz4 = z[i] * z[i];
		sum18 = sum18 + zz4;
		aa4 = a[i] * a[i];
		sum19 = sum19 + aa4;
		
	}

	for (i = 0; i < n; i++)
	{
		sum20 = sum20 + a[i];
	}
		mean8 = (sum20 / n);

	b14 = (sum17 - (10.0*mean7*mean8)) / (sum18 - (10.0*mean7*mean7));
	b04 = mean8 - (b14*mean7);
	equationY4 = b04 + (b14*xK);

	denom4 = (10*(sum18) - (sum16*sum16)) * (10*(sum19) - (sum20*sum20));  

		while (d4 >= 0.01)
		{
			d4 = denom4 - (h4 * h4);
			h4 = h4 + 0.05;	
		}

	Rxy4 = (10*(sum17)-(sum16)*(sum20))/h4;
	rSquared4 = Rxy4 * Rxy4;  
	
	/* Printf statements are used in order to output the results to the user. The purpose of %lf is to display a real number, hence its data type is double */
	printf("Test 1: B0 = %lf  B1 = %lf  Rxy = %lf  r^2 = %lf  y = %lf\n", b0, b1, Rxy, rSquared, equationY);

	printf("Test 2: B0 = %lf  B1 = %lf  Rxy = %lf  r^2 = %lf  y = %lf\n", b02, b12, Rxy2, rSquared2, equationY2);
	
	printf("Test 3: B0 = %lf  B1 = %lf  Rxy = %lf  r^2 = %lf  y = %lf\n", b03, b13, Rxy3, rSquared3, equationY3);

	printf("Test 4: B0 = %lf  B1 = %lf  Rxy = %lf  r^2 = %lf  y = %lf\n", b04, b14, Rxy4, rSquared4, equationY4);

	return 0;
}
		




	
	
	



