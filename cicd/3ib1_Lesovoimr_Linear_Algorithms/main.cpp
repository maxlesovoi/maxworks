#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int kingX, kingY;
    int rookX, rookY;
    int bishopX, bishopY;

    cout << "Введите координаты короля: ";
    cin >> kingX >> kingY;

    cout << "Введите координаты ладьи: ";
    cin >> rookX >> rookY;
    cout << "Введите координаты слона: ";
    cin >> bishopX >> bishopY;

    if ((kingX == rookX && bishopX == kingX) && ((bishopY < rookY && bishopY > kingY) || (bishopY > rookY && bishopY < kingY))){
        cout << "Ладья перекрыта" << endl;
    }
    else if((abs(rookX - bishopX) == abs(rookY - bishopY) && (abs(kingX - bishopX) == abs(kingY - bishopY))) && ((rookX < bishopX && rookX > kingX) || (rookX > bishopX && rookX < kingX))){
        cout << "Слон перекрыт" << endl;
    }
    else if((kingX == rookX || kingY == rookY) && (abs(kingX - bishopX) == abs(kingY - bishopY))) {
        cout << "Атакуют обе фигуры" << endl;
    }
    else if (kingX == rookX || kingY == rookY) {
        cout << "Атакует ладья" << endl;
    }
    else if (abs(kingX - bishopX) == abs(kingY - bishopY)) {
        cout << "Атакует слон" << endl;
    }
    else {
        cout << "Атаки нет" << endl;
    }
    return 0;
}
