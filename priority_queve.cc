#include <bits/stdc++.h>
#define psi pair<string, int>
using namespace std;
// Campritor doing the Campairison
// psi custom datatype
class myComparator
{
public:
    bool operator()(const psi &p1, const psi &p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};
int main()
{
    // psi -> datatype to be stored
    // vector <psi> -> container
    // myComparator -> Doing Comparions deciding order of pririty queue
    priority_queue<psi, vector<psi>, myComparator> pq;
    pq.push({"adfdfd", 2});
    pq.push({"vafdafd", 2});
    pq.push({"dfa", 3});
    pq.push({"abd", 1});
    while (pq.size() != 0)
    {
        cout << pq.top().second << " " << pq.top().first << "\n";
        pq.pop();
    }
    /*Output : -
                    3 dfa
                    2 adfdfd
                    2 vafdafd
                    1 abd
    */
    return 0;
}
