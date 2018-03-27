#include <stdio.h>
#include <math.h>
#define PI 3.14

/*This program calculates, the area of the largest circle that fits inside a rectangle,
the area of the largest square that fits inside the rectangle,
the area of the smallest circle that surrounds the same rectangle, 
the area of the smallest square that surrounds the same rectangle.
*/


double circle_area(double radius) 
/*Calculate the area of the circle*/
{
	double area;
	area=PI*pow(radius,2);
	
	return area;
}

double calc_hipotenus(int side1, int side2)
/*Calculate the hipotenus of the circle*/
{
	double hipotenus;
	hipotenus=sqrt(pow(side1,2)+pow(side2,2)); 
	/*I used the functions of the mat.h library to calculate.*/

	return hipotenus;	
}

double calc_area_of_square(int side)
/*General formule to calculate areo of the square*/
{
	double area;
	area=pow(side,2);
	
	return area;
}

double calc_radius_of_smallest_circle(int side1, int side2)
/*To calculate the radius of the smallest circle, we have to calculate a half of the hipotenus*/
{
	double radius;
	radius=calc_hipotenus(side1,side2)/2;
	
	return radius;
}

double calc_radius_of_largest_circle(int side1,int side2)
/*Radius of the largest circle is the half of the smallest side.*/
{
	double radius,temp;
	if(side1<side2)
	
	{
		radius=side1/2.0;
	}
	else
	{
		radius=side2/2.0;
	}

	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2)
/*We can calculate radius and area easily with the help of the functions we wrote. We just called the radius and area function which suits the problem.*/
{
	double radius, area;
	radius=calc_radius_of_smallest_circle(side1,side2);
	area=circle_area(radius);
	
	return area;
}

double calc_area_of_largest_circle(int side1,int side2)
/*I used the function that i made before again to calculate easily.*/
{
	double radius,area;
	radius=calc_radius_of_largest_circle(side1,side2);
	area=circle_area(radius);
	
	return area;
}

double calc_area_of_smallest_square(int side1,int side2)
/*To calculate areo of the smallest square, first I calculate one side of the square, then i called function to calculate area.*/
{
	double side,area;
	if(side1>side2)
	{
		side=side1;
	}
	else
	{
		side=side2;
	}
	
	area=calc_area_of_square(side);

	return area;
}

double calc_area_of_largest_square(int side1,int side2)
/*I calculate one side of the square then i called function to calculate area.*/
{
	double side,area;
	if(side1<side2)
	{
		side=side1;
	}
	else
	{
		side=side2;
	}
	
	area=calc_area_of_square(side);

	return area;
}

void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square)
/*To display results, I used printf function. This function just prints the results.*/
{	
	printf("The area of the largest circle that fits inside a rectangle:     %15.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside a rectangle:     %15.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:%14.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:%14.2lf\n",smallest_square);
	
	return;
}

void main(void)
{
	double largest_circle,largest_square,smallest_square,smallest_circle;
	/*These variables will hold the area of the circles that matches their names. I will use them to print area of the figures.*/
	int side1,side2;
	
	printf("Enter the first side for rectangle: "); /*I get the numbers from the user.*/
	scanf("%d",&side1);
	printf("Enter the second side for rectangle: ");/*I get the numbers from the user.*/
	scanf("%d",&side2);
	
	largest_circle=calc_area_of_largest_circle(side1,side2); /*This functions assign the true value to these variables.*/
	largest_square=calc_area_of_largest_square(side1,side2);
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	smallest_square=calc_area_of_smallest_square(side1,side2);
	
	display_results(largest_circle, largest_square, smallest_circle, smallest_square); /*I just printed all results.*/
	
	return;
}
