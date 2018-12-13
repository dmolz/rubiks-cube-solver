#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstring>

typedef std::vector<std::vector<char> > CubeType;

// Function for swapping two colors
// Can't use std::swap to swap between two faces (vectors)
void swap(CubeType& Cube, int old_face, int old_space, int new_face, int new_space) {
	char temp = Cube[old_face][old_space];
	Cube[old_face][old_space] = Cube[new_face][new_space];
	Cube[new_face][new_space] = temp;
}

// Prints the Cube
void print_cube(CubeType& Cube) {
	// White Side
	std::cout << "            -------------" << std::endl;
	std::cout << "            | ";
	std::cout << Cube[0][0] << " | " << Cube[0][1] << " | " << Cube[0][2] << " |" << std::endl;
	std::cout << "            -------------" << std::endl;
	std::cout << "            | ";
	std::cout << Cube[0][7] << " | " << Cube[0][8] << " | " << Cube[0][3] << " |" << std::endl;
	std::cout << "            -------------" << std::endl;
	std::cout << "            | ";
	std::cout << Cube[0][6] << " | " << Cube[0][5] << " | " << Cube[0][4] << " |" << std::endl;

	// First row of G/R/B/O sides
	for (int i = 0; i < 49; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << "| "  << Cube[4][0]
			  << " | " << Cube[4][1]
			  << " | " << Cube[4][2] << " | ";
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << Cube[i][j] << " | ";
		}
	}
	std::cout << std::endl;

	// Second row of G/R/B/O sides
	for (int i = 0; i < 49; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << "| "  << Cube[4][7]
			  << " | " << Cube[4][8]
			  << " | " << Cube[4][3] << " | ";
	for (int i = 1; i < 4; i++) {
		std::cout << Cube[i][7] << " | "
		          << Cube[i][8] << " | "
				  << Cube[i][3] << " | ";

	}
	std::cout << std::endl;

	// Third row of G/R/B/O sides
	for (int i = 0; i < 49; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << "| " << Cube[4][6]
			  << " | "<< Cube[4][5]
			  << " | "<< Cube[4][4] << " | ";
	for (int i = 1; i < 4; i++) {
		std::cout << Cube[i][6] << " | "
		          << Cube[i][5] << " | "
				  << Cube[i][4] << " | ";

	}
	std::cout << std::endl;
	for (int i = 0; i < 49; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	// Yellow side
	std::cout << "            | ";
	std::cout << Cube[5][0] << " | " << Cube[5][1] << " | " << Cube[5][2] << " |" << std::endl;
	std::cout << "            -------------" << std::endl;
	std::cout << "            | ";
	std::cout << Cube[5][7] << " | " << Cube[5][8] << " | " << Cube[5][3] << " |" << std::endl;
	std::cout << "            -------------" << std::endl;
	std::cout << "            | ";
	std::cout << Cube[5][6] << " | " << Cube[5][5] << " | " << Cube[5][4] << " |" << std::endl;
	std::cout << "            -------------" << std::endl;
}

// Finds edge adjacent to given edge in Cube
char find_adj_edge(int i, int j, CubeType& Cube) {
	char current = Cube[i][8];

	/*  			-------------
					| 0 | 1 | 2 |
					-------------
					| 7 | W | 3 |
					-------------
					| 6 | 5 | 4 |
		-------------------------------------------------
		| 0 | 1 | 2 | 0 | 1 | 2 | 0 | 1 | 2 | 0 | 1 | 2 | 
		-------------------------------------------------
		| 7 | G | 3 | 7 | R | 3 | 7 | B | 3 | 7 | O | 3 |
		-------------------------------------------------
		| 6 | 5 | 4 | 6 | 5 | 4 | 6 | 5 | 4 | 6 | 5 | 4 |
		-------------------------------------------------
					| 0 | 1 | 2 |
					-------------
					| 7 | Y | 3 |
					-------------
					| 6 | 5 | 4 |
					-------------
	*/

	if (current == 'w') {
		if 		(j == 1) return Cube[3][1];
		else if (j == 3) return Cube[2][1];
		else if (j == 5) return Cube[1][1];
		else if (j == 7) return Cube[4][1];
	}
	else if (current == 'r') {
		if 		(j == 1) return Cube[0][5];
		else if (j == 3) return Cube[2][7];
		else if (j == 5) return Cube[5][1];
		else if (j == 7) return Cube[4][3];
	}
	else if (current == 'b') {
		if 		(j == 1) return Cube[0][3];
		else if (j == 3) return Cube[3][7];
		else if (j == 5) return Cube[5][3];
		else if (j == 7) return Cube[1][3];
	}
	else if (current == 'o') {
		if 		(j == 1) return Cube[0][1];
		else if (j == 3) return Cube[4][7];
		else if (j == 5) return Cube[5][5];
		else if (j == 7) return Cube[2][3];
	}
	else if (current == 'g') {
		if 		(j == 1) return Cube[0][7];
		else if (j == 3) return Cube[1][7];
		else if (j == 5) return Cube[5][7];
		else if (j == 7) return Cube[3][3];
	}
	else if (current == 'y') {
		if 		(j == 1) return Cube[1][5];
		else if (j == 3) return Cube[2][5];
		else if (j == 5) return Cube[3][5];
		else if (j == 7) return Cube[4][5];
	}

	return current;
}

void insert_corner(int side, CubeType& Cube) {
}

/* Takes in a cube face and the vector of cube faces and
   adjusts the face and layers to rotate clockwise */
void rotate_clockwise(char side, CubeType& Cube, std::vector<std::string>& solution) {
	/*  			-------------
					| 0 | 1 | 2 |
					-------------
					| 7 | W | 3 |
					-------------
					| 6 | 5 | 4 |
		-------------------------------------------------
		| 0 | 1 | 2 | 0 | 1 | 2 | 0 | 1 | 2 | 0 | 1 | 2 | 
		-------------------------------------------------
		| 7 | G | 3 | 7 | R | 3 | 7 | B | 3 | 7 | O | 3 |
		-------------------------------------------------
		| 6 | 5 | 4 | 6 | 5 | 4 | 6 | 5 | 4 | 6 | 5 | 4 |
		-------------------------------------------------
					| 0 | 1 | 2 |
					-------------
					| 7 | Y | 3 |
					-------------
					| 6 | 5 | 4 |
					-------------
	*/

	if (side == 'w') {
		// Rotate face
		swap(Cube,0,0,0,2);
		swap(Cube,0,0,0,4);
		swap(Cube,0,0,0,6);
		swap(Cube,0,1,0,3);
		swap(Cube,0,1,0,5);
		swap(Cube,0,1,0,7);
		// Rotate layer
		swap(Cube,4,0,3,0);
		swap(Cube,4,1,3,1);
		swap(Cube,4,2,3,2);
		swap(Cube,4,0,2,0);
		swap(Cube,4,1,2,1);
		swap(Cube,4,2,2,2);
		swap(Cube,4,0,1,0);
		swap(Cube,4,1,1,1);
		swap(Cube,4,2,1,2);

		// std::cout << "White" << std::endl;
		solution.push_back("White");
	}
	else if (side == 'r') {
		// Rotate face
		swap(Cube,1,0,1,2);
		swap(Cube,1,0,1,4);
		swap(Cube,1,0,1,6);
		swap(Cube,1,1,1,3);
		swap(Cube,1,1,1,5);
		swap(Cube,1,1,1,7);
		// Rotate layer
		swap(Cube,0,6,2,0);
		swap(Cube,0,5,2,7);
		swap(Cube,0,4,2,6);
		swap(Cube,0,6,5,2);
		swap(Cube,0,5,5,1);
		swap(Cube,0,4,5,0);
		swap(Cube,0,6,4,4);
		swap(Cube,0,5,4,3);
		swap(Cube,0,4,4,2);

		// std::cout << "Red" << std::endl;
		solution.push_back("Red");
	}
	else if (side == 'b') {
		// Rotate face
		swap(Cube,2,0,2,2);
		swap(Cube,2,0,2,4);
		swap(Cube,2,0,2,6);
		swap(Cube,2,1,2,3);
		swap(Cube,2,1,2,5);
		swap(Cube,2,1,2,7);
		// Rotate layer
		swap(Cube,0,2,3,6);
		swap(Cube,0,3,3,7);
		swap(Cube,0,4,3,0);
		swap(Cube,0,2,5,2);
		swap(Cube,0,3,5,3);
		swap(Cube,0,4,5,4);
		swap(Cube,0,2,1,2);
		swap(Cube,0,3,1,3);
		swap(Cube,0,4,1,4);

		// std::cout << "Blue" << std::endl;
		solution.push_back("Blue");
	}
	else if (side == 'o') {
		// Rotate face
		swap(Cube,3,0,3,2);
		swap(Cube,3,0,3,4);
		swap(Cube,3,0,3,6);
		swap(Cube,3,1,3,3);
		swap(Cube,3,1,3,5);
		swap(Cube,3,1,3,7);
		// Rotate layer
		swap(Cube,0,0,4,6);
		swap(Cube,0,1,4,7);
		swap(Cube,0,2,4,0);
		swap(Cube,0,0,5,4);
		swap(Cube,0,1,5,5);
		swap(Cube,0,2,5,6);
		swap(Cube,0,0,2,2);
		swap(Cube,0,1,2,3);
		swap(Cube,0,2,2,4);

		// std::cout << "Orange" << std::endl;
		solution.push_back("Orange");
	}
	else if (side == 'g') {
		// Rotate face
		swap(Cube,4,0,4,2);
		swap(Cube,4,0,4,4);
		swap(Cube,4,0,4,6);
		swap(Cube,4,1,4,3);
		swap(Cube,4,1,4,5);
		swap(Cube,4,1,4,7);
		// Rotate layer
		swap(Cube,0,0,1,0);
		swap(Cube,0,7,1,7);
		swap(Cube,0,6,1,6);
		swap(Cube,0,0,5,0);
		swap(Cube,0,7,5,7);
		swap(Cube,0,6,5,6);
		swap(Cube,0,0,3,4);
		swap(Cube,0,7,3,3);
		swap(Cube,0,6,3,2);

		// std::cout << "Green" << std::endl;
		solution.push_back("Green");
	}
	else if (side == 'y') {
		// Rotate face
		swap(Cube,5,0,5,2);
		swap(Cube,5,0,5,4);
		swap(Cube,5,0,5,6);
		swap(Cube,5,1,5,3);
		swap(Cube,5,1,5,5);
		swap(Cube,5,1,5,7);
		// Rotate layer
		swap(Cube,4,6,1,6);
		swap(Cube,4,5,1,5);
		swap(Cube,4,4,1,4);
		swap(Cube,4,6,2,6);
		swap(Cube,4,5,2,5);
		swap(Cube,4,4,2,4);
		swap(Cube,4,6,3,6);
		swap(Cube,4,5,3,5);
		swap(Cube,4,4,3,4);

		// std::cout << "Yellow" << std::endl;
		solution.push_back("Yellow");
	}
}

/* Takes in a cube face and the vector of cube faces and
   adjusts the face and layers to rotate counter-clockwise */
void rotate_counter_clockwise(char side, CubeType& Cube, std::vector<std::string>& solution) {
	if (side == 'w') {
		// Rotate face
		swap(Cube,0,0,0,6);
		swap(Cube,0,0,0,4);
		swap(Cube,0,0,0,2);
		swap(Cube,0,1,0,7);
		swap(Cube,0,1,0,5);
		swap(Cube,0,1,0,3);
		// Rotate layer
		swap(Cube,4,0,1,0);
		swap(Cube,4,1,1,1);
		swap(Cube,4,2,1,2);
		swap(Cube,4,0,2,0);
		swap(Cube,4,1,2,1);
		swap(Cube,4,2,2,2);
		swap(Cube,4,0,3,0);
		swap(Cube,4,1,3,1);
		swap(Cube,4,2,3,2);

		// std::cout << "White Prime" << std::endl;
		solution.push_back("White Prime");
	}
	else if (side == 'r') {
		// Rotate face
		swap(Cube,1,0,1,6);
		swap(Cube,1,0,1,4);
		swap(Cube,1,0,1,2);
		swap(Cube,1,1,1,7);
		swap(Cube,1,1,1,5);
		swap(Cube,1,1,1,3);
		// Rotate layer
		swap(Cube,0,6,4,4);
		swap(Cube,0,5,4,3);
		swap(Cube,0,4,4,2);
		swap(Cube,0,6,5,2);
		swap(Cube,0,5,5,1);
		swap(Cube,0,4,5,0);
		swap(Cube,0,6,2,0);
		swap(Cube,0,5,2,7);
		swap(Cube,0,4,2,6);

		// std::cout << "Red Prime" << std::endl;
		solution.push_back("Red Prime");
	}
	else if (side == 'b') {
		// Rotate face
		swap(Cube,2,0,2,6);
		swap(Cube,2,0,2,4);
		swap(Cube,2,0,2,2);
		swap(Cube,2,1,2,7);
		swap(Cube,2,1,2,5);
		swap(Cube,2,1,2,3);
		// Rotate layer
		swap(Cube,0,2,1,2);
		swap(Cube,0,3,1,3);
		swap(Cube,0,4,1,4);
		swap(Cube,0,2,5,2);
		swap(Cube,0,3,5,3);
		swap(Cube,0,4,5,4);
		swap(Cube,0,2,3,6);
		swap(Cube,0,3,3,7);
		swap(Cube,0,4,3,0);

		// std::cout << "Blue Prime" << std::endl;
		solution.push_back("Blue Prime");
	}
	else if (side == 'o') {
		// Rotate face
		swap(Cube,3,0,3,6);
		swap(Cube,3,0,3,4);
		swap(Cube,3,0,3,2);
		swap(Cube,3,1,3,7);
		swap(Cube,3,1,3,5);
		swap(Cube,3,1,3,3);
		// Rotate layer
		swap(Cube,0,0,2,2);
		swap(Cube,0,1,2,3);
		swap(Cube,0,2,2,4);
		swap(Cube,0,0,5,4);
		swap(Cube,0,1,5,5);
		swap(Cube,0,2,5,6);
		swap(Cube,0,0,4,6);
		swap(Cube,0,1,4,7);
		swap(Cube,0,2,4,0);

		// std::cout << "Orange Prime" << std::endl;
		solution.push_back("Orange Prime");
	}
	else if (side == 'g') {
		// Rotate face
		swap(Cube,4,0,4,6);
		swap(Cube,4,0,4,4);
		swap(Cube,4,0,4,2);
		swap(Cube,4,1,4,7);
		swap(Cube,4,1,4,5);
		swap(Cube,4,1,4,3);
		// Rotate layer
		swap(Cube,0,0,3,4);
		swap(Cube,0,7,3,3);
		swap(Cube,0,6,3,2);
		swap(Cube,0,0,5,0);
		swap(Cube,0,7,5,7);
		swap(Cube,0,6,5,6);
		swap(Cube,0,0,1,0);
		swap(Cube,0,7,1,7);
		swap(Cube,0,6,1,6);
		
		// std::cout << "Green Prime" << std::endl;
		solution.push_back("Green Prime");
	}
	else if (side == 'y') {
		// Rotate face
		swap(Cube,5,0,5,6);
		swap(Cube,5,0,5,4);
		swap(Cube,5,0,5,2);
		swap(Cube,5,1,5,7);
		swap(Cube,5,1,5,5);
		swap(Cube,5,1,5,3);
		// Rotate layer
		swap(Cube,4,6,3,6);
		swap(Cube,4,5,3,5);
		swap(Cube,4,4,3,4);
		swap(Cube,4,6,2,6);
		swap(Cube,4,5,2,5);
		swap(Cube,4,4,2,4);
		swap(Cube,4,6,1,6);
		swap(Cube,4,5,1,5);
		swap(Cube,4,4,1,4);

		// std::cout << "Yellow Prime" << std::endl;
		solution.push_back("Yellow Prime");
	}
}

void undo_clockwise(char side, CubeType& Cube, std::vector<std::string>& solution) {
	rotate_counter_clockwise(side,Cube,solution);
	solution.pop_back();
	solution.pop_back();
}

void undo_counter_clockwise(char side, CubeType& Cube, std::vector<std::string>& solution) {
	rotate_clockwise(side,Cube,solution);
	solution.pop_back();
	solution.pop_back();
}

// Priority for cross is RED->BLUE->ORANGE->GREEN
void solve_white_cross(CubeType& Cube, std::vector<std::string>& solution) {
	
	// First, solve the white and red edge piece
	while (!(Cube[0][5] == 'w' && find_adj_edge(0,5,Cube) == 'r')) {
		// CASE 1:
		//	Edge piece is lined up with red already
		if (Cube[1][3] == 'r' && find_adj_edge(1,3,Cube) == 'w') {
			rotate_counter_clockwise('r',Cube,solution);
		}
		else if ((Cube[1][5] == 'r' && find_adj_edge(1,5,Cube) == 'w') ||
				 (Cube[1][7] == 'r' && find_adj_edge(1,7,Cube) == 'w')) {
			rotate_clockwise('r',Cube,solution);
		}

		// CASE 2:
		//	Edge piece is lined up with white already
		else if (Cube[0][7] == 'w' && find_adj_edge(0,7,Cube) == 'r') {
			rotate_counter_clockwise('w',Cube,solution);
		}
		else if ((Cube[0][3] == 'w' && find_adj_edge(0,3,Cube) == 'r') ||
				 (Cube[0][1] == 'w' && find_adj_edge(0,1,Cube) == 'r')) {
			rotate_clockwise('w',Cube,solution);
		}
		
		// CASE 3:
		//	Edge piece is lined up with yellow on the bottom face
		//	(works into CASE 1)
		else if (Cube[5][3] == 'w' && find_adj_edge(5,3,Cube) == 'r') {
			rotate_counter_clockwise('y',Cube,solution);
		}
		else if (Cube[5][7] == 'w' && find_adj_edge(5,7,Cube) == 'r') {
			rotate_clockwise('y',Cube,solution);
		}
		else if (Cube[5][5] == 'w' && find_adj_edge(5,5,Cube) == 'r') {
			rotate_clockwise('y',Cube,solution);
			rotate_clockwise('y',Cube,solution);
		}

		// CASE 4:
		//	Edge piece is lined up with yellow but oriented wrong
		//	(works into CASE 1)
		else if (Cube[5][3] == 'r' && find_adj_edge(5,3,Cube) == 'w') {
			rotate_clockwise('b',Cube,solution);
		}
		else if (Cube[5][7] == 'r' && find_adj_edge(5,7,Cube) == 'w') {
			rotate_counter_clockwise('g',Cube,solution);
		}
		else if ((Cube[5][5] == 'r' && find_adj_edge(5,5,Cube) == 'w') ||
				 (Cube[5][1] == 'r' && find_adj_edge(5,1,Cube) == 'w')) {
			rotate_clockwise('y',Cube,solution);
		}

		// CASE 5:
		//	Edge piece is lined up with white but oriented wrong
		//	(works into CASE 1)
		else if (Cube[0][7] == 'r' && find_adj_edge(0,7,Cube) == 'w') {
			rotate_clockwise('g',Cube,solution);
		}
		else if (Cube[0][3] == 'r' && find_adj_edge(0,3,Cube) == 'w') {
			rotate_counter_clockwise('b',Cube,solution);
		}
		else if ((Cube[0][5] == 'r' && find_adj_edge(0,5,Cube) == 'w') ||
				 (Cube[0][1] == 'r' && find_adj_edge(0,1,Cube) == 'w')) {
			rotate_clockwise('w',Cube,solution);
		}

		// CASE 6:
		//	Edge piece is in middle layer but not lined up with anything
		else {
			for (int i = 2; i <= 4; i++) {
				if (Cube[i][7] == 'r' && find_adj_edge(i,7,Cube) == 'w') {
					rotate_clockwise(Cube[i][8],Cube,solution);
				}
				else if (Cube[i][3] == 'r' && find_adj_edge(i,3,Cube) == 'w') {
					rotate_counter_clockwise(Cube[i][8],Cube,solution);
				}
			}
		}
	}

	// Next, solve the blue edge piece
	while (!(Cube[0][3] == 'w' && find_adj_edge(0,3,Cube) == 'b')) {
		// CASE 1:
		//	Edge piece is lined up with blue already
		if (Cube[2][3] == 'b' && find_adj_edge(2,3,Cube) == 'w') {
			rotate_counter_clockwise('b',Cube,solution);
		}
		else if (Cube[2][5] == 'b' && find_adj_edge(2,5,Cube) == 'w') {
			rotate_clockwise('b',Cube,solution);
			rotate_clockwise('b',Cube,solution);
		}
		else if (Cube[2][7] == 'b' && find_adj_edge(2,7,Cube) == 'w') {
			rotate_clockwise('b',Cube,solution);
		}

		// CASE 2:
		//	Edge piece is lined up with white already
		//	(works into CASE 3)
		else if (Cube[0][1] == 'w' && find_adj_edge(0,1,Cube) == 'b') {
			rotate_clockwise('o',Cube,solution);
			rotate_clockwise('o',Cube,solution);
		}
		else if (Cube[0][7] == 'w' && find_adj_edge(0,7,Cube) == 'b') {
			rotate_clockwise('g',Cube,solution);
			rotate_clockwise('g',Cube,solution);
		}
		
		// CASE 3: 
		//	Edge piece is lined up with yellow on the bottom face
		//	(works into CASE 1)
		else if ((Cube[5][1] == 'w' && find_adj_edge(5,1,Cube) == 'b') ||
				 (Cube[5][7] == 'w' && find_adj_edge(5,7,Cube) == 'b')) {
			rotate_clockwise('y',Cube,solution);
		}
		else if (Cube[5][5] == 'w' && find_adj_edge(5,5,Cube) == 'b') {
			rotate_counter_clockwise('y',Cube,solution);
		}

		// CASE 4: 
		//	Edge piece is lined up with yellow but oriented wrong
		//	(works into CASE 1)
		else if (Cube[5][5] == 'b' && find_adj_edge(5,5,Cube) == 'w') {
			rotate_clockwise('o',Cube,solution);
		}
		else if ((Cube[5][1] == 'b' && find_adj_edge(5,1,Cube) == 'w') ||
				 (Cube[5][3] == 'b' && find_adj_edge(5,3,Cube) == 'w')) {
			rotate_clockwise('y',Cube,solution);
		}
		else if (Cube[5][7] == 'b' && find_adj_edge(5,7,Cube) == 'w') {
			rotate_counter_clockwise('y',Cube,solution);
		}

		// CASE 5:
		//	Edge piece is lined up with white but oriented wrong
		else if (Cube[0][3] == 'b' && find_adj_edge(0,3,Cube) == 'w') {
			rotate_clockwise('b',Cube,solution);
			rotate_clockwise('b',Cube,solution);
		}
		else if (Cube[0][7] == 'b' && find_adj_edge(0,7,Cube) == 'w') {
			rotate_clockwise('g',Cube,solution);
			rotate_clockwise('g',Cube,solution);
		}
		else if (Cube[0][1] == 'b' && find_adj_edge(0,1,Cube) == 'w') {
			rotate_counter_clockwise('o',Cube,solution);
		}

		// CASE 6:
		//	Edge piece is in middle layer but not lined up with anything
		else if (Cube[2][3] == 'w' && find_adj_edge(2,3,Cube) == 'b') {
				rotate_clockwise('b',Cube,solution);
		}
		else if (Cube[2][7] == 'w' && find_adj_edge(2,7,Cube) == 'b') {
			rotate_counter_clockwise('b',Cube,solution);
		}
		else if (Cube[4][3] == 'w' && find_adj_edge(4,3,Cube) == 'b') {
			rotate_clockwise('g',Cube,solution);
		}
		else if (Cube[4][7] == 'w' && find_adj_edge(4,7,Cube) == 'b') {
			rotate_counter_clockwise('g',Cube,solution);
		}
		else if (Cube[4][3] == 'b' && find_adj_edge(4,3,Cube) == 'w') {
			rotate_counter_clockwise('g',Cube,solution);
		}
		else if (Cube[4][7] == 'b' && find_adj_edge(4,7,Cube) == 'w') {
			rotate_clockwise('g',Cube,solution);
		}
	}

	// Next, solve the orange edge
	while (!(Cube[0][1] == 'w' && find_adj_edge(0,1,Cube) == 'o')) {
		// CASE 1:
		//	Edge piece is lined up with orange already
		if (Cube[3][3] == 'o' && find_adj_edge(3,3,Cube) == 'w') {
			rotate_counter_clockwise('o',Cube,solution);
		}
		else if ((Cube[3][5] == 'o' && find_adj_edge(3,5,Cube) == 'w') ||
				 (Cube[3][7] == 'o' && find_adj_edge(3,7,Cube) == 'w')) {
			rotate_clockwise('o',Cube,solution);
		}

		// CASE 2:
		//	Edge piece is lined up with white already
		//	(works into CASE 3)
		else if (Cube[0][7] == 'w' && find_adj_edge(0,7,Cube) == 'o') {
			rotate_clockwise('g',Cube,solution);
			rotate_clockwise('g',Cube,solution);
		}

		// CASE 3:
		//	Edge piece is lined up with yellow on the bottom face
		else if ((Cube[5][3] == 'w' && find_adj_edge(5,3,Cube) == 'o') ||
				 (Cube[5][1] == 'w' && find_adj_edge(5,1,Cube) == 'o')) {
			rotate_clockwise('y',Cube,solution);
		}
		else if (Cube[5][7] == 'w' && find_adj_edge(5,7,Cube) == 'o') {
			rotate_counter_clockwise('y',Cube,solution);
		}

		// CASE 4:
		//	Edge piece is lined up with yellow but oriented wrong
		else if (Cube[5][5] == 'o' && find_adj_edge(5,5,Cube) == 'w') {
			rotate_clockwise('y',Cube,solution);
		}
		else if ((Cube[5][1] == 'o' && find_adj_edge(5,1,Cube) == 'w') ||
				 (Cube[5][3] == 'o' && find_adj_edge(5,3,Cube) == 'w')) {
			rotate_counter_clockwise('y',Cube,solution);
		}
		else if (Cube[5][7] == 'o' && find_adj_edge(5,7,Cube) == 'w') {
			rotate_clockwise('g',Cube,solution);
		}

		// CASE 5:
		//	Edge piece is lined up with white but oriented wrong
		else if (Cube[0][1] == 'o' && find_adj_edge(0,1,Cube) == 'w') {
			rotate_clockwise('o',Cube,solution);
			rotate_clockwise('o',Cube,solution);
		}
		else if (Cube[0][7] == 'o' && find_adj_edge(0,7,Cube) == 'w') {
			rotate_counter_clockwise('g',Cube,solution);
		}

		// CASE 6:
		//	Edge piece is between blue and red
		else if (Cube[1][3] == 'w' && find_adj_edge(1,3,Cube) == 'o') {
			rotate_clockwise('w',Cube,solution);
			rotate_clockwise('b',Cube,solution);
			rotate_counter_clockwise('w',Cube,solution);
		}
		else if (Cube[1][3] == 'o' && find_adj_edge(1,3,Cube) == 'w') {
			rotate_counter_clockwise('w',Cube,solution);
			rotate_counter_clockwise('r',Cube,solution);
			rotate_clockwise('w',Cube,solution);
		}

		// CASE 7:
		//	Edge piece is in middle layer
		else if (Cube[3][7] == 'w' && find_adj_edge(3,7,Cube) == 'o') {
			rotate_counter_clockwise('o',Cube,solution);
		}
		else if (Cube[3][3] == 'w' && find_adj_edge(3,3,Cube) == 'o') {
			rotate_clockwise('o',Cube,solution);
		}
		else if (Cube[4][3] == 'w' && find_adj_edge(4,3,Cube) == 'o') {
			rotate_clockwise('g',Cube,solution);
		}
		else if (Cube[4][3] == 'o' && find_adj_edge(4,3,Cube) == 'w') {
			rotate_clockwise('g',Cube,solution);
		}
	}

	// Last, solve the green edge
	while (!(Cube[0][7] == 'w' && find_adj_edge(0,7,Cube) == 'g')) {
		// CASE 1:
		//	Edge piece is lined up with green already
		if (Cube[4][3] == 'g' && find_adj_edge(4,3,Cube) == 'w') {
			rotate_counter_clockwise('g',Cube,solution);
		}
		else if ((Cube[4][5] == 'g' && find_adj_edge(4,5,Cube) == 'w') ||
				 (Cube[4][7] == 'g' && find_adj_edge(4,7,Cube) == 'w')) {
			rotate_clockwise('g',Cube,solution);
		}

		// CASE 3:
		//	Edge piece is lined up with yellow on the bottom face
		else if (Cube[5][1] == 'w' && find_adj_edge(5,1,Cube) == 'g') {
			rotate_counter_clockwise('y',Cube,solution);
		}
		else if ((Cube[5][5] == 'w' && find_adj_edge(5,5,Cube) == 'g') ||
				 (Cube[5][3] == 'w' && find_adj_edge(5,3,Cube) == 'g')) {
			rotate_clockwise('y',Cube,solution);
		}

		// CASE 4:
		//	Edge piece is lined up with yellow but oriented wrong
		else if (Cube[5][5] == 'g' && find_adj_edge(5,5,Cube) == 'w') {
			rotate_counter_clockwise('o',Cube,solution);
			rotate_clockwise('g',Cube,solution);
			rotate_clockwise('o',Cube,solution);
		}
		else if (Cube[5][1] == 'g' && find_adj_edge(5,1,Cube) == 'w') {
			rotate_clockwise('r',Cube,solution);
			rotate_counter_clockwise('g',Cube,solution);
			rotate_counter_clockwise('r',Cube,solution);
		}
		else if ((Cube[5][3] == 'g' && find_adj_edge(5,3,Cube) == 'w') ||
				 (Cube[5][7] == 'g' && find_adj_edge(5,7,Cube) == 'w')) {
			rotate_clockwise('y',Cube,solution);
		}

		// CASE 5:
		//	Edge piece is lined up with white but oriented wrong
		else if (Cube[0][7] == 'g' && find_adj_edge(0,7,Cube) == 'w') {
			rotate_counter_clockwise('g',Cube,solution);
			rotate_clockwise('w',Cube,solution);
			rotate_counter_clockwise('o',Cube,solution);
			rotate_counter_clockwise('w',Cube,solution);
		}

		// CASE 6:
		//	Edge piece is between blue and red
		else if (Cube[1][3] == 'w' && find_adj_edge(1,3,Cube) == 'g') {
			rotate_counter_clockwise('w',Cube,solution);
			rotate_counter_clockwise('r',Cube,solution);
			rotate_clockwise('w',Cube,solution);
		}
		else if (Cube[1][3] == 'g' && find_adj_edge(1,3,Cube) == 'w') {
			rotate_counter_clockwise('w',Cube,solution);
			rotate_counter_clockwise('r',Cube,solution);
			rotate_clockwise('w',Cube,solution);
		}

		// CASE 7:
		//	Edge piece is between blue and orange
		else if (Cube[2][3] == 'w' && find_adj_edge(2,3,Cube) == 'g') {
			rotate_clockwise('w',Cube,solution);
			rotate_clockwise('o',Cube,solution);
			rotate_counter_clockwise('w',Cube,solution);
		}
		else if (Cube[2][3] == 'g' && find_adj_edge(2,3,Cube) == 'w') {
			rotate_clockwise('w',Cube,solution);
			rotate_clockwise('w',Cube,solution);
			rotate_counter_clockwise('b',Cube,solution);
			rotate_clockwise('w',Cube,solution);
			rotate_clockwise('w',Cube,solution);
		}

		// CASE 8: 
		//	Edge piece is lined up with green but oriented wrong
		else if (Cube[4][3] == 'w' && find_adj_edge(4,3,Cube) == 'g') {
			rotate_counter_clockwise('w',Cube,solution);
			rotate_clockwise('r',Cube,solution);
			rotate_clockwise('w',Cube,solution);
		}
		else if (Cube[4][7] == 'w' && find_adj_edge(4,7,Cube) == 'g') {
			rotate_clockwise('w',Cube,solution);
			rotate_counter_clockwise('o',Cube,solution);
			rotate_counter_clockwise('w',Cube,solution);
		}
	}
}

void solve_white_cross_recursive(CubeType& Cube, std::vector<CubeType>& solved_cubes, std::vector<std::string>& solution,
	std::vector<std::vector<std::string> >& all_solutions, const std::vector<char>& colors,
	int last_turn, char last_color, int count, int height) {

	bool white_cross_solved = Cube[0][1] == 'w' && Cube[0][3] == 'w' && Cube[0][5] == 'w' && Cube[0][7] == 'w'
						   && Cube[1][1] == 'r' && Cube[2][1] == 'b' && Cube[3][1] == 'o' && Cube[4][1] == 'g';

	if (white_cross_solved) {
		all_solutions.push_back(solution);
	}
	else if (height > 10) {
		return;
	}

	for (int i = 0; i < colors.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (count == 2) continue;

			/* If first try and last turn was not same side and last turn was not CCW */
			if (j == 0 && (last_color != colors[i] && last_turn != 1)) {
				if (last_color == colors[i]) count = 2;
				else count = 1;
			}
		}
	}


}

void solve_first_layer_recursive(CubeType& Cube, std::vector<CubeType>& solved_cubes, std::vector<std::string>& solution,
	std::vector<std::vector<std::string> >& all_solutions, const std::vector<char>& colors,
	int last_turn, char last_color, int count, int height) {
	bool white_side_solved = Cube[0][0] == 'w' && Cube[0][1] == 'w' && Cube[0][2] == 'w' &&
							 Cube[0][3] == 'w' && Cube[0][4] == 'w' && Cube[0][5] == 'w' &&
							 Cube[0][6] == 'w' && Cube[0][7] == 'w';
	bool first_layer_solved = Cube[1][0] == 'r' && Cube[1][1] == 'r' && Cube[1][2] == 'r' &&
							  Cube[2][0] == 'b' && Cube[2][1] == 'b' && Cube[2][2] == 'b' &&
							  Cube[3][0] == 'o' && Cube[3][1] == 'o' && Cube[3][2] == 'o' &&
							  Cube[4][0] == 'g' && Cube[4][1] == 'g' && Cube[4][2] == 'g';
	if (white_side_solved && first_layer_solved) {
		all_solutions.push_back(solution);
		solved_cubes.push_back(Cube);
		return;
	}
	else if (height >= 20) {
		// height = 0;
		return;
	}

	for (int i = 0; i < colors.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (count == 2) continue;

			if (j == 0 && (last_color != colors[i] && last_turn != 1)) {
				if (last_color == colors[i]) count = 2;
				else count = 1;

				height++;
				rotate_clockwise(colors[i],Cube,solution);
				solve_white_cross_recursive(Cube,solved_cubes,solution,all_solutions,colors,j,colors[i],count,height);
				height--;
				undo_clockwise(colors[i],Cube,solution);
				// std::cout << "Move" << std::endl;
			}
			else if (j == 1 && (last_color != colors[i] && last_turn != 0)) {
				if (last_color == colors[i]) count = 2;
				else count = 1;

				height++;
				rotate_counter_clockwise(colors[i],Cube,solution);
				solve_white_cross_recursive(Cube,solved_cubes,solution,all_solutions,colors,j,colors[i],count,height);
				height--;
				undo_counter_clockwise(colors[i],Cube,solution);
				// std::cout << "Move" << std::endl;
			}
		}
	}

	// print_cube(Cube);

	for (int i = 0; i < colors.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (count == 2) continue;

			if (j == 0 && (last_color != colors[i] && last_turn != 1)) {
				if (last_color == colors[i]) count = 2;
				else count = 1;

				height++;
				rotate_clockwise(colors[i],Cube,solution);
				solve_first_layer_recursive(Cube,solved_cubes,solution,all_solutions,colors,j,colors[i],count,height);
				height--;
				undo_clockwise(colors[i],Cube,solution);
				// std::cout << "Move" << std::endl;
			}
			else if (j == 1 && (last_color != colors[i] && last_turn != 0)) {
				if (last_color == colors[i]) count = 2;
				else count = 1;

				height++;
				rotate_counter_clockwise(colors[i],Cube,solution);
				solve_first_layer_recursive(Cube,solved_cubes,solution,all_solutions,colors,j,colors[i],count,height);
				height--;
				undo_counter_clockwise(colors[i],Cube,solution);
				// std::cout << "Move" << std::endl;
			}
		}
	}
}

void solve_white_corners(CubeType& Cube, std::vector<std::string>& solution) {
	// 8 corners
	//	R0 G2 W6
	//	R2 B0 W4
	//	R4 B6 Y2
	//	R6 G4 Y0
	//	O0 B2 W2
	//	O2 G0 W0
	//	O4 G6 Y6
	//	O6 B4 Y4
}

void solve_second_layer(CubeType& Cube, std::vector<std::string>& solution) {

}

void solve_yellow_cross(CubeType& Cube, std::vector<std::string>& solution) {

}

void orient_yellow_cross(CubeType& Cube, std::vector<std::string>& solution) {

}

void solve_yellow_corners(CubeType& Cube, std::vector<std::string>& solution) {

}

void orient_yellow_corners(CubeType& Cube, std::vector<std::string>& solution) {

}


int main() {
	// Initializing face vectors as fully solved cube
	std::vector<char> white(9,'w');
	std::vector<char> red(9,'r');
	std::vector<char> blue(9,'b');
	std::vector<char> orange(9,'o');
	std::vector<char> green(9,'g');
	std::vector<char> yellow(9,'y');

	std::vector<std::string> solution;

	CubeType Cube;
	Cube.push_back(white);		// White = Cube[0]
	Cube.push_back(red);		// Red = Cube[1]
	Cube.push_back(blue);		// Blue = Cube[2]
	Cube.push_back(orange);		// Orange = Cube[3]
	Cube.push_back(green);		// Green = Cube[4]
	Cube.push_back(yellow);		// Yellow = Cube[5]

	std::vector<char> colors;
	colors.push_back('w');
	colors.push_back('r');
	colors.push_back('b');
	colors.push_back('o');
	colors.push_back('g');
	colors.push_back('y');

	std::vector<std::vector<std::string> > all_solutions;
	std::vector<CubeType> solved_cubes;

	// Input:
	// std::cout << "White: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[0][i];
	
	// std::cout << "Red: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[1][i];
	
	// std::cout << "Blue: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[2][i];
	
	// std::cout << "Orange: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[3][i];
	
	// std::cout << "Green: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[4][i];
	
	// std::cout << "Yellow: ";
	for (int i = 0; i < 9; i++)
		std::cin >> Cube[5][i];
	
	print_cube(Cube);

	solve_white_cross_recursive(Cube,solved_cubes,solution,all_solutions,colors,-1,'n',-1,0);

	// std::cout << "Solving white cross..." << std::endl;
	// solve_white_cross(Cube,solution);
	// assert(Cube[0][1] == 'w' && find_adj_edge(0,1,Cube) == 'o');
	// assert(Cube[0][3] == 'w' && find_adj_edge(0,3,Cube) == 'b');
	// assert(Cube[0][5] == 'w' && find_adj_edge(0,5,Cube) == 'r');
	// assert(Cube[0][7] == 'w' && find_adj_edge(0,7,Cube) == 'g');
	// std::cout << "White cross solved!" << std::endl;
	// std::cout << std::endl;

	// std::cout << "Solving white corners..." << std::endl;
	// solve_white_corners(Cube,solution);

	// rotate_clockwise('r',Cube,solution);
	// print_cube(Cube);
	// rotate_clockwise('w',Cube,solution);
	// print_cube(Cube);
	// rotate_clockwise('b',Cube,solution);
	// print_cube(Cube);
	// rotate_clockwise('g',Cube,solution);
	// print_cube(Cube);
	// rotate_clockwise('o',Cube,solution);
	// print_cube(Cube);
	// rotate_clockwise('y',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('y',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('o',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('g',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('b',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('w',Cube,solution);
	// print_cube(Cube);
	// rotate_counter_clockwise('r',Cube,solution);
	// print_cube(Cube);

	print_cube(Cube);
	
	std::cout << "Solutions: " << std::endl;
	std::cout << all_solutions.size() << std::endl;

	return 0;
}

/* STEPS:
	1. Check edge pieces on white side
	2. Search for missing edge pieces in color order (Red, blue, green, orange)
	3. */
