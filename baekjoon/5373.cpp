#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum dir{
	UP,
	LEFT,
	FRONT,
	RIGHT,
	BACK,
	DOWN,
};

char cube[6][3][3];

void init_cube() {
	//윗면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[UP][i][j] = 'w';
		}
	}
	
	//왼쪽면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[LEFT][i][j] = 'g';
		}
	}

	//앞면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[FRONT][i][j] = 'r';
		}
	}

	//오른쪽면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[RIGHT][i][j] = 'b';
		}
	}

	//뒷면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[BACK][i][j] = 'o';
		}
	}

	//아랫면
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[DOWN][i][j] = 'y';
		}
	}
}

void turn_cube(string str) {
	char dir1 = str[0];
	char dir2 = str[1];

	switch (dir1) {
	case 'U':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[UP][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][2][2 - i] = tmp1[i][2];
			}
			
			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[RIGHT][0][i];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[LEFT][0][i];
				cube[LEFT][0][i] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][0][i];
				cube[BACK][0][i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][0][i] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[UP][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[LEFT][0][i];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[RIGHT][0][i];
				cube[RIGHT][0][i] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][0][i];
				cube[BACK][0][i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][0][i] = tmp2[i];
			}
		}
		break;

	case 'L':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[LEFT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][2][2 - i] = tmp1[i][2];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][i][0];
				cube[FRONT][i][0] = cube[UP][i][0];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[DOWN][i][0];
				cube[DOWN][i][0] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2 - i][2];
				cube[BACK][2 - i][2] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][0] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[LEFT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][i][0];
				cube[FRONT][i][0] = cube[DOWN][i][0];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[UP][i][0];
				cube[UP][i][0] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2 - i][2];
				cube[BACK][2 - i][2] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][0] = tmp2[i];
			}
		}
		break;

	case 'F':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[FRONT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][2][2 - i] = tmp1[i][2];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[UP][2][i];
				cube[UP][2][i] = cube[LEFT][2 - i][2];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][2 - i][2] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[FRONT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[FRONT][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[UP][2][i];
				cube[UP][2][i] = cube[RIGHT][i][0];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[LEFT][2 - i][2];
				cube[LEFT][2 - i][2] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][0] = tmp2[i];
			}
		}
		break;

	case 'R':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[RIGHT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][2][2 - i] = tmp1[i][2];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[DOWN][i][2];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[UP][i][2];
				cube[UP][i][2] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2 - i][0];
				cube[BACK][2 - i][0] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][2] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[RIGHT][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[UP][i][2];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[DOWN][i][2];
				cube[DOWN][i][2] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2 - i][0];
				cube[BACK][2 - i][0] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[UP][i][2] = tmp2[i];
			}
		}
		break;

	case 'B':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[BACK][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][2][2 - i] = tmp1[i][2];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[UP][0][i];
				cube[UP][0][i] = cube[RIGHT][i][2];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][i][2] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[BACK][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[BACK][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[UP][0][i];
				cube[UP][0][i] = cube[LEFT][2 - i][0]; 
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][2 - i][0] = tmp2[i];
			}
		}
		break;

	case 'D':
		if (dir2 == '+') {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[DOWN][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][2] = tmp1[0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][0] = tmp1[2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][0][2 - i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][2][2 - i] = tmp1[i][2];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[LEFT][2][i];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2][i];
				cube[BACK][2][i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[LEFT][2][i] = tmp2[i];
			}
		}
		else {
			char tmp1[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp1[i][j] = cube[DOWN][i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][0][i] = tmp1[i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][2][i] = tmp1[i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][0] = tmp1[0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[DOWN][i][2] = tmp1[2][2 - i];
			}

			char tmp2[3];
			char tmp3[3];
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[RIGHT][2][i];
			}
			for (int i = 0; i < 3; i++) {
				tmp3[i] = cube[LEFT][2][i];
				cube[LEFT][2][i] = tmp2[i];
			}
			for (int i = 0; i < 3; i++) {
				tmp2[i] = cube[BACK][2][i];
				cube[BACK][2][i] = tmp3[i];
			}
			for (int i = 0; i < 3; i++) {
				cube[RIGHT][2][i] = tmp2[i];
			}
		}
		break;

	}
}

void printUpside() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[UP][i][j];
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int tc;
	cin >> tc;

	while (tc--) {
		init_cube();

		int n;
		cin >> n;
		while (n--) {
			string str;
			cin >> str;
			vector<string> dir_vector;
			string tmp = "";
			for (int i = 0; i < str.length(); i++) {
				if ((i + 1) % 3 == 0) continue;
				
				tmp += str[i];
				if ((i + 2) % 3 == 0) {
					dir_vector.push_back(tmp);
					tmp = "";
				}
			}

			for(int i = 0; i < dir_vector.size(); i++)
				turn_cube(dir_vector[i]);
		}
		printUpside();
	}

}
