#include <iostream>
#include "Functions.h"
#include <windows.h>
#include "MainRandom.h"
#include <algorithm>
#include <vector>
//#include <unordered_map>

//extern char Field[][5];
extern std::vector<std::vector<char>> Field;
extern std::vector<int> empty;
extern std::vector<char> types_of_blocks;
extern int rows, cols;
extern int count_of_block_categories;
extern int max_count_staticblocks;
extern int max_count_staticblocks_columns;

struct StaticColum
{
	int position_of_colum; // Позиция колоны стат.блоков на поле
	int count_staticblocks_in_columns; 
	std::vector<int> Ypositions_staticblocks;
};

void CreateField() {
	
	Field = std::vector<std::vector<char>>(rows, std::vector<char>(cols));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			Field[i][j] = '.';
		}
	}
}

void ShowField() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std:: cout<<Field[i][j]<<' ';
		}
		std::cout << '\n';
	}
}

void ArrangeCategories() {
	std::vector<int> Xpositions = { MyRandom(4, 0, cols-1, count_of_block_categories, empty, empty, true) };
	//Sleep(10);
	std::vector<int> positions_types_of_blocks = { MyRandom(4, 0, count_of_block_categories-1, count_of_block_categories, empty, empty, false) };
	int j = 0;
	for (int i = 0; i < cols; ++i) {
		if (j < count_of_block_categories) {
			if (i == Xpositions[j]) {
				Field[0][i] = types_of_blocks[positions_types_of_blocks[j]];
				++j;
			}
			else {
				Field[0][i] = char(219);
			}
		}
		else {
			Field[0][i] = char(219);
		}
	}
}

void PlacementOfStaticBlocks() {      // Нужно будет переписать для динамического поля
	std::vector<int> static_columns;
	std::vector<int> count_staticblocks_in_columns;
	std::vector<int> Ypositions_staticblocks;
	bool closelocation = false;
	bool from_the_side = false;
	for (int i = 0; i < cols; ++i) {
		if (Field[0][i] == char(219)) {
			static_columns.push_back(i);
		}
	}
	if (static_columns[0] + 1 == static_columns[1]) {
		closelocation = true;
	}
	if (static_columns[0] == 0 || static_columns[1] == 4) {
		from_the_side = true;
	}
	if (closelocation && from_the_side) {
		count_staticblocks_in_columns = MyRandom(1, 0, rows - 2, count_of_block_categories, empty, empty, true);
		count_staticblocks_in_columns.push_back(max_count_staticblocks - count_staticblocks_in_columns[0]);
		if (static_columns[0] == 0) {
			std::sort(count_staticblocks_in_columns.begin(), count_staticblocks_in_columns.end(), std::greater<int>());
		}
		else {
			std::sort(count_staticblocks_in_columns.begin(), count_staticblocks_in_columns.end());
		}
		Ypositions_staticblocks = MyRandom(4, 0, 4, count_staticblocks_in_columns[0], empty, empty, true);
		for (int i = 0; i < Ypositions_staticblocks.size(); ++i) {
			Field[static_columns[0]][Ypositions_staticblocks[i]]= char(219);
		}
		if (count_staticblocks_in_columns[1] != 0) {
			std::vector<int> emptyblocks;
			for (int i = 0; i < 5; ++i) {
				emptyblocks.push_back(i);
			}
			for (auto it = emptyblocks.begin(); it != emptyblocks.end();) {
				if (std::find(Ypositions_staticblocks.begin(), Ypositions_staticblocks.end(), *it) != Ypositions_staticblocks.end()) {
					it = emptyblocks.erase(it);
				}
				else {
					++it;
				}
			}
			Ypositions_staticblocks.clear();
			Ypositions_staticblocks = MyRandom(5, 0, 4, count_staticblocks_in_columns[1], empty, emptyblocks, true);
			for (int i = 0; i < Ypositions_staticblocks.size(); ++i) {
				Field[static_columns[1]][Ypositions_staticblocks[i]] = char(219);
			}
		}
	}
	else if (closelocation) {

	}
	else {

	}
}

void PlacementOfStaticBlocks_v2() {
	std::vector<StaticColum> static_columns; // Колоны со стат.блоками (c 0 по макс. число колон)  (Нужно сделать глобальной)
	//std::vector<int> count_staticblocks_in_columns; // Количество стат.блоков в колоне  
	//std::vector<int> Ypositions_staticblocks; // Позиции стат.блоков в колоне
	for (int i = 0; i < cols; ++i) {
		if (Field[0][i] == char(219)) {
			StaticColum colum;
			colum.position_of_colum = i;
			static_columns.push_back(colum);
		}
	}





	for (int i = 0; i < cols; ++i) { // Заполнение информации для каждой колоны со стат.блоками
		//if (static_columns[i] != 0 || static_columns[i] != cols - 1) { // Если рассматриваемая колона расположена не сбоку
			count_staticblocks_in_columns.push_back(MyRandom(1, 0, rows - 2, count_of_block_categories, empty, empty, true)[0]);
		//}
			max
	}

}

