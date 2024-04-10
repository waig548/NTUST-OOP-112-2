#include <fstream>
#include <map>
#include <vector>


int main() {
	std::ifstream ifs("grade.txt");
	std::vector<size_t> counts(6, 0);
	int g;
	while (ifs >> g) {
		counts[g]++;
	}
	ifs.close();
	std::ofstream ofs("grades.Output");
	for (int i = 0; i < counts.size(); i++) {
		ofs << counts[i] << " grade(s) of " << i << std::endl;
	}
	ofs.close();
}