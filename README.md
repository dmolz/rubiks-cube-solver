# rubiks-cube-solver
C++ program designed to solve a Rubik's Cube.

How to use:
  1. Start with red side facing forward, white on top, yellow on bottom.
  2. Enter colors in clockwise order, starting in top left of red side.
  3. Make sure white side is inputted with red on bottom.
  4. Make sure yellow is inputted with red on top.

ASCII Diagrams for Input Orientations:
       TOP
 LEFT FRONT RIGHT BACK
      BOTTOM

        W
RED:  G R B O
        Y
        
        W
BLU:  R B O G
        Y
        
        W
GRN:  O G R B
        Y
        
        W
ORN:  B O G R
        Y
        
        O
WHT:  G W B O
        R
        
        R        
YLW:  G Y B O
        O


What has been accomplished so far:
  1. Ability to input and store data efficiently
  2. Ability to manipulate the cube via turns
  3. Ability to solve white cross in minimum amount of moves using if statements
  
What needs to be completed:
  1. Find a recursive algorithm that solves the cube efficiently every time
  
Next step after cube can be solved efficiently:
  1. Create mobile app
