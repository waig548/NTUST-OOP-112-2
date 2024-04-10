#include <vector>
#include <string>
#include <iostream>

class Vec {
public:
	int x;
	int y;

	Vec() : Vec(0, 0) {}
	Vec(int x, int y) : x(x), y(y) {}

	Vec operator+(const Vec& other) const {
		return Vec(x + other.x, y + other.y);
	}
	bool operator==(const Vec& other) const {
		return x == other.x && y == other.y;
	}

	Vec rotateLeft()const {
		return Vec( y, (-1) * x);
	}
	Vec rotateRight() const {
		return Vec((-1) * y, x);
	}
};



class Maze {
private:
	std::string map;
public:
	const int width;
	const int height;


	Maze(const std::string& map, int width, int height) : map(map), width(width), height(height) {}
	Maze(const std::string& map, int sideLength) : Maze(map, sideLength, sideLength) {}

	bool checkBounds(const Vec& p) {
		if (p.x < 0 || p.x >= width || p.y < 0 || p.y >= height)
			return false;
		return true;
	}
	char getAt(int x, int y) const {
		return map[y * width + x];
	}
	char getAt(const Vec& p) const {
		return getAt(p.x, p.y);
	}
	void setAt(int x, int y, char ch) {
		map[y * width + x] = ch;
	}
	void setAt(const Vec& p, char ch) {
		setAt(p.x, p.y, ch);
	}

	void print() {
		for (int i = 0; i < map.size(); i += width) {
			std::cout << map.substr(i, width) << std::endl;
		}
	}
};



const std::vector<char> pathType{ 'L', 'R' };




int traverseMaze(Maze& maze, int method) {
	int step = 0;
	Vec cur, face(1, 0), left, right, initial;
	for (int i = 0; i < maze.height; i++)
	{
		if (maze.getAt(0, i) == 'X')
			cur = { 0, i };
	}
	initial = cur;
	while (1) {
		left = face.rotateLeft(), right = face.rotateRight();
		if (cur == initial && maze.getAt(cur) != 'X')
			return -1;

		maze.setAt(cur, pathType[method]);

		if (cur.x == maze.width-1)
			return step;

		if (method == 0) {
			Vec next = left;
			while (!(maze.checkBounds(cur + next) && maze.getAt(cur + next) != '#'))
				next =next.rotateRight();
			face = next;
		}
		else if (method == 1) {
			Vec next = right;
			while (!(maze.checkBounds(cur + next) && maze.getAt(cur + next) != '#'))
				next = next.rotateLeft();
			face = next;
		}
		cur = cur + face;
		step++;
	}
}



int main() {
	int method, sideLength;
	std::string content, tmp;
	std::cin >> method >> sideLength;
	for (int i = 0; i < sideLength; i++) {
		std::cin >> tmp;
		content += tmp;
	}
	Maze maze(content, sideLength);
	int result = traverseMaze(maze, method);
	maze.print();
	std::cout << result << std::endl;
}