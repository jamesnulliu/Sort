#include "../header/Chain.h"

int main() {
	Chain<int> line;
	line.insert(1);
	line.insert(2);
	line.insert(5);
	line.insert(2);
	line.insert(0);
	line.binSort(6);
}