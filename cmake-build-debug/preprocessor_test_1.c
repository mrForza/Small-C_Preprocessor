#include <stdio.h>

int main() {
    int side1, side2, side3; // Sides of triangle
    /*
*  Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna
 * sin(x) + 1/2
    * void swap(int *px, int* py) {swapp x and y}
    */
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%d %d %d", &side1, &side2, &side3); // Some comments

    if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
    /* */    printf("The triangle is correct.\n"); // Another comment
    } else {
        printf("The triangle is not correct.\n"); /*
    */}

    return 0;
}
