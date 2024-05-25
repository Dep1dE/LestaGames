#include <iostream>
#include <windows.h>
#include "Functions.h"
#include "MainRandom.h"
#include <vector>



std::vector<std::vector<char>> Field;  // Поле
std::vector<int> empty; // Вектор(для проверки)
std::vector<char> types_of_blocks = {'R','G','B'}; //Виды блоков
int rows=6, cols=5;  // Количество строк и столбцов
int count_of_block_categories = 3; // Количество видов блоков;
int max_count_staticblocks = 6; // Максимальное количество статических блоков
int max_count_staticblocks_columns = 2; // Максимальное число колонн со статическими блоками


//std::vector<std::vector<char>> Field = {
//    {char(219), char(219), '.', '.', '.'},
//    {'.', '.', '.', '.', '.'},
//    {'.', '.', '.', '.', '.'},
//    {'.', '.', '.', '.', '.'},
//    {'.', '.', '.', '.', '.'},
//    {'.', '.', '.', '.', '.'}
//};

int main()
{
    //setlocale(LC_ALL, "Russian");
    for (int i = 0; i < 1; ++i) {
        CreateField();
        ArrangeCategories();
        //PlacementOfStaticBlocks();
        ShowField();
        std::cout << '\n';
        Sleep(1000);
    }
    /*for (int i = 0; i < 100; ++i) {
        std::vector<int> main_arr = { 1, 2, 3, 4, 5 };
        std::vector<int> exception = { 1, 2, 3, 4, 6, 9};
        std::vector<int> arr = { MyRandom(5, 5, 10, 4, main_arr, exception, false) };
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << ' ';
            Sleep(500);
        }
    }*/
	return 0;
}