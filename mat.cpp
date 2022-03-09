/**
 * Author: Ofek Rotem
 * Since : 2022-03
 */

#include "mat.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace ariel {
    string mat(int col, int row, char firstSym, char secondSym) {
        if (col %2 == 0 || row%2==0) __throw_invalid_argument("Enter only odd row and column size");
        if (firstSym == secondSym) __throw_invalid_argument("Enter different symbols");
        if (col<=0 || row<=0) __throw_invalid_argument("Enter positive row and column size");
        return "Matala shel 100 lefahot";
    }

}