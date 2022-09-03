/*******************************************************************************
@brief This program will attempt to make a rotating 3D cube in the terminal
*******************************************************************************/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float A, B, C;                  /* Floats that will represent different angles */
float cubeWidth = 10;           /* A float that will determine the width of the cube */
int width = 160;                /* Width of the area the cube will be displayed in */
int height = 44;                /* Height of the area the cube will be displayed in */
float zBuffer[160 * 44];        /* Depth buffer */
char buffer[160 * 44];          /* Buffer for our character allocation */
int backgroundASCIICode = ' ';  /* Fill the background that is not being used with empty spaces */
float incrementSpeed = 0.6;     /* Speed of incrementation */

/******************************************************************************
@brief A function to handle the calculation that represents the X axis
       We obtain this equation from taking the three basic rotation matrixes found here: https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
       And multiplying them by (i j k). We take the result of this matrix multiplication and use it to represent this specific axis 
*******************************************************************************/
float calculateX(int i, int j, int k)
{
    return (j * sin(A) * sin(B) * cos(C)) - (k * cos(A) * sin(B) * cos(C)) +
           (j * cos(A) * sin(C)) + (k * sin(A) * sin(C)) + (i * cos(B) * cos(C));
}

/******************************************************************************
@brief A function to handle the calculation that represents the Y axis
       We obtain this equation from taking the three basic rotation matrixes found here: https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
       And multiplying them by (i j k). We take the result of this matrix multiplication and use it to represent this specific axis 
*******************************************************************************/
float calculateY(int i, int j, int k)
{
    return (j * cos(A) * cos(C)) + (k * sin(A) * cos(C)) - (j * sin(A) * sin(B) * sin(C)
           (k * cos(A) * sin(B) * sin(C)) - (i * cos(B) * sin(C)));
}

/******************************************************************************
@brief A function to handle the calculation that represents the Z axis
       We obtain this equation from taking the three basic rotation matrixes found here: https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
       And multiplying them by (i j k). We take the result of this matrix multiplication and use it to represent this specific axis 
*******************************************************************************/
float calculateZ(int i, int j, int k)
{
    return (k * cos(A) * cos(B)) -(j * sin(A) * cos(B)) + (i * sin(B));
}

int main()
{
    print("\x1b[23");

    while (1)
    {
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);
        for(float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed)
        {
            for(float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed)
            {
                calculateForSurface(cubeX, cubeY, -cubeWidth, '#');
            }
        }
    }

    return 0;
}
