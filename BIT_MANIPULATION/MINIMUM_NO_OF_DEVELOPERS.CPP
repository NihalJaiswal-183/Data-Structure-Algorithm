#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
vector<string> vect2;
void solution(int people[], int np, int finalskill, int currskill, int count, int i, vector<string> vect1)
{

    if (finalskill == currskill)
    {
        if (ans >= count)
        {
            ans = count;
            vect2.clear();
            vect2.assign(vect1.begin(), vect1.end());
            return;
        }
        return;
    }
    if (i > np)
    {
        return;
    }
    vect1.push_back(to_string(i));
    solution(people, np, finalskill, currskill | people[i], count + 1, i + 1, vect1);
    vect1.pop_back();
    solution(people, np, finalskill, currskill, count, i + 1, vect1);
}

int main()
{
    int n;
    cin >> n;
    string temp;
    int finalskill = 0;
    unordered_map<string, int> smap;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        smap[temp] = i;
        finalskill = finalskill | 1 << i;
    }

    int np;
    cin >> np;
    int people[np] = {0};
    for (int i = 0; i < np; i++)
    {
        int personSkills;
        cin >> personSkills;
        for (int j = 0; j < personSkills; j++)
        {

            cin >> temp;
            int snum = smap[temp];
            people[i] = people[i] | (1 << snum);
        }
    }
    vector<string> vect1;
    solution(people, np, finalskill, 0, 0, 0, vect1);

    cout << "[";
    for (int i = 0; i < vect2.size(); i++)
    {
        cout << vect2[i];
        if (i != vect2.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}