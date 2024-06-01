#include <iostream>
#include <vector>
#include <map>
#include <set>



int main()
{
	int n, m;
	while (std::cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		std::vector<std::pair<char, char>> tPairs;
		std::map<char, std::set<char>> convertTable;
		for (int i = 0; i < n; i++)
		{
			char a, b;
			std::cin >> a >> b;
			tPairs.push_back({ a,b });
		}
		for (auto c = 'a'; c <= 'z'; c++)
			convertTable.emplace(c, std::set<char>{ c });

		for (auto p : tPairs)
		{
			convertTable.try_emplace(p.first);
			convertTable[p.first].insert(p.second);
		}
		while (true)
		{
			bool stable = true;
			for (auto& cp : convertTable)
			{
				int preSize = cp.second.size();
				for (auto c : cp.second)
					for (auto e : convertTable.at(c))
						cp.second.insert(e);
					
				if (cp.second.size() != preSize)
					stable = false;
			}
			if (stable)
				break;
		}

		for (int i = 0; i < m; i++)
		{
			std::string a, b;
			std::cin >> a >> b;
			bool flag = true;
			if (a.size() != b.size())
				flag = false;
			for (int i = 0; i < a.size(); i++)
			{
				if (!convertTable.at(a[i]).count(b[i]))
				{
					flag = false;
					break;
				}
			}
			if (flag)
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		}

	}

	return 0;
}