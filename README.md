# Rubik's Cube Solver Program
C++ program designed to solve a Rubik's Cube. Input the current state of a cube and get a list of moves to solve the cube from that state.

## How to use:
  1. Start with red side facing forward, white on top, yellow on bottom.
  2. Enter colors in clockwise order, starting in top left of red side.
  3. Make sure white side is inputted with red on bottom.
  4. Make sure yellow is inputted with red on top.

## ASCII Diagrams for Input Orientations:
Example:
```
	TOP	
LEFT	FRONT	RIGHT	BACK
	BOTTOM
```
Red:
```
	W
G	R	B	O
	Y
```
Blue:
```
	W
R	B	O	G
	Y
```
Orange:
```
	W
B	O	G	R
	Y
```
Green:
```
	W
O	G	R	B
```
White:
```
	O
G	W	B	O
	R
```
Yellow:
```
	R
G	Y	B	O
	O
```

### What has been accomplished so far:
  1. Ability to input and store data efficiently
  2. Ability to manipulate the cube via turns
  3. Ability to solve white cross in minimum amount of moves using if statements
  
### What needs to be completed:
  1. Find a recursive algorithm that solves the cube efficiently every time
  
### Next step after cube can be solved efficiently:
  1. Create mobile app
