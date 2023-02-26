#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;


float a, b, c;
const string strInput = R"(C:\Users\79823\CLionProjects\YP_1\infile.txt)";
const string strOutput = R"(C:\Users\79823\CLionProjects\YP_1\outfile.txt)";


void ReadFile(string str)
{
    ifstream fin (str);
    fin >> a >> b >> c;
}


vector<float> RootFinder (float a, float b, float c)
{
        vector<float> roots;

        float discriminant = b*b - 4*a*c;
        if (discriminant >= 0)
        {
            roots.push_back((- b + sqrt(discriminant)) / (2 * a));
            if (((- b - sqrt(discriminant))/(2 * a)) != (- b + sqrt(discriminant) )/ (2 * a))
                roots.push_back((- b - sqrt(discriminant) )/ (2 * a));
        }

        return roots;

}

void WriteFile(string str, vector<float> roots)
{
    ofstream fout (str);
    if (roots.size() != 0)
        for (auto i : roots)
            fout << roots[i] << " ";
        else fout << "Roots aren`t real!";
}


int main() {
    ReadFile(strInput);
    vector<float> roots = RootFinder(a, b, c);
    WriteFile(strOutput, roots);

}

