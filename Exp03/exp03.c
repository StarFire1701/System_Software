#include <stdio.h> 

// Enrollment no. 220140107001

// Simple Macro 
#define PI 3.14159 

// Nested Macro 
#define SQUARE(x) ((x) * (x)) 
#define CUBE(x) (SQUARE(x) * (x)) 

// Macro with Argument 
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

// Macro as Inline Function 
#define SUM(a, b) ((a) + (b)) 

int main() { 
    // Simple Macro 
    float radius = 5.0; 
    float area = PI * radius * radius; 
    printf("Area of circle: %.2f\n", area); 

    // Nested Macro 
    int num = 3; 
    printf("Cube of %d is %d\n", num, CUBE(num)); 

    // Macro with Argument 
    int x = 10, y = 20; 
    printf("Maximum is %d\n", MAX(x, y)); 

    // Macro as Inline Function 
    int result = SUM(5, 10); 
    printf("Sum is %d\n", result); 

    return 0; 
}
