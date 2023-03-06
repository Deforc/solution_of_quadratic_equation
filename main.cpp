#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;


const string strInput = "..\\infile.txt";
const string strOutput = "..\\outfile.txt";


array<float, 3> ReadFile(const string& str)
{
    array<float, 3> coef{0,0, 0};
    ifstream fin (str);
    for(auto &i : coef)
        fin >> i;
    fin.close();
    return coef;

}


vector<float> RootFinder (const array<float, 3>& coefs)
{
        vector<float> roots;

        float discriminant = coefs[1]*coefs[1] - 4*coefs[0]*coefs[2];
        if (discriminant >= 0)
        {
            roots.push_back((- coefs[1] + sqrt(discriminant)) / (2 * coefs[0]));
            if (((- coefs[1] - sqrt(discriminant))/(2 * coefs[0])) != (- coefs[1] + sqrt(discriminant) )/ (2 * coefs[0]))
                roots.push_back((- coefs[1] - sqrt(discriminant) )/ (2 * coefs[0]));
        }

        return roots;

}

void WriteFile(const string& str, const vector<float>& roots)
{
    ofstream fout (str);
    if (!roots.empty())
        for (auto &i : roots)
            fout << i << " ";
    else fout << "Roots aren`t real!";
    fout.close();
}


int main() {
    array<float, 3> coefs = ReadFile(strInput);
    vector<float> roots = RootFinder(coefs);
    WriteFile(strOutput, roots);

}

