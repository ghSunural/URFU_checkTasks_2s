#include <iostream>
#include <conio.h>
#include <string>
#include <regex>
#include "TConvexPolygon.h"

#include "TCommon.h"

#define ESC 27

using namespace std;

int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ПЛОЩАДЬ И ПЕРИМЕТР ВЫПУКЛОГО МНОГОУГОЛЬНИКА\n\n";
	cout << "Для выхода нажмите Esc \n";

	/*
	TSpecLinkedList<int>* list = new TSpecLinkedList<int>();
	list->addtNode(8);
	list->addtNode(7);
	list->addtNode(3);
	list->addtNode(7);
	list->addtNode(5);
	list->addtNode(6);
	list->addtNode(15);
	list->displayList();
	cout << list->count << "\n";
	cout << "\nКонец\n";
	*/

	while (true) {
		try {

			//	int iMaxVerticesCount;
			//	cout << "Введите максимально возможное количество вершин многоугольника,\nвключая замыкающую\n";
			//	cin.clear();
			//	cin >> iMaxVerticesCount;
			//	TConvexPolygon* polygon = new TConvexPolygon(iMaxVerticesCount);

			TConvexPolygon* polygon = new TConvexPolygon();

			cout << "Вводите последовательно координаты X и Y\nДля завершения введите координаты 0-й вершины\n";
			int No = 0;
			double x;
			double y;

			while (true) {

				cout << "X" << No << " = ";
				cin >> x;
				cout << "Y" << No << " = ";
				cin >> y;

				polygon->addVertex(No, x, y);

				/*
				if ((No) &&
					(x == polygon->vertices[0].x) &&
					(y == polygon->vertices[0].y))
				{
					polygon->vertices[0].axVtoV = polygon->vertices[No].axVtoV;
					polygon->vertices[0].ayVtoV = polygon->vertices[No].ayVtoV;
					break;
				}
				*/
				//Vertex firstVertex = polygon->verticesList->getFirst();
				
				if ((No) &&
					(x == polygon->verticesList->getFirst().x &&
					(y == polygon->verticesList->getFirst().y)))
				{
					
					
					TConvexPolygon::Vertex V = polygon->verticesList->getByKey(No);
					polygon->verticesList->recordDataByKey(V, 0);

					/*polygon->verticesList->getFirst().axVtoV = 
						polygon->verticesList->getByKey(No).axVtoV;


					polygon->verticesList->getByKey(No).ayVtoV =
						polygon->vertices[No].ayVtoV;

					*/

					break;
				}	
				
				No++;
			};

			polygon->verticesList->displayList();

			//Отладка, в продакшн стереть
		/*	cout << "Кол-во вершин " << polygon->getCountVertices() << "\n";
			for (int i = 0; i < polygon->getCountVertices(); i++) {
				polygon->displayVertex(polygon->vertices[i]);
			}
		*/

			cout << "Площадь: " << polygon->calcArea() << '\n';
			cout << "Периметр: " << polygon->calcPerimeter() << '\n';
			delete polygon;

		}
		catch (TSpecException& e) {
			cout << "Ошибка: " << e.getErrorMessage() << '\n';
			if (_getch() == ESC) {
				break;
			}
			cin.clear();
		}

		cout << "Для выхода нажмите Esc" << endl;
		if (_getch() == ESC) {
			break;
		}
	};
	return 0;
}










