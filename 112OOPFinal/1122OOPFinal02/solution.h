/**
 * @brief
 * Please complete the specified functionality within the function as
 * described in the problem.
 *
 * @param n - Indicates how many people there are in total, numbered 1 ~ n.
 * @param k - The step used to determine which person to eliminate ineach
 * round.
 * @return int - The number of the last remaining person
 */

#include <vector>
inline int permutation(int n, int k) {
    std::vector<int> items;
    for (int i = 1; i <= n; i++)
        items.push_back(i);
    
    int idx = k-1;
    while (items.size() > 1)
    {
        items.erase(items.begin() + idx);
        idx += k-1;
        idx %= items.size();
    }

    return items.front();
}