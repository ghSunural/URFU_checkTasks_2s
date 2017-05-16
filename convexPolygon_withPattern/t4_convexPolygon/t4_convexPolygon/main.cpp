#include <iostream>
#include <conio.h>
#include <string>
#include <regex>
#include "TConvexPolygon.h"
#include "AbstractFactory.h"

#include "TCommon.h"

#define ESC 27

using namespace std;

int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "������� � �������� ��������� ��������������\n\n";
	cout << "��� ������ ������� Esc \n";

//	AbstractFactory<TConvexPolygon>& factory = AbstractFactory<TConvexPolygon>::getInstance();


	while (true) {
		try {

			//	int iMaxVerticesCount;
			//	cout << "������� ����������� ��������� ���������� ������ ��������������,\n������� ����������\n";
			//	cin.clear();
			//	cin >> iMaxVerticesCount;
			//	TConvexPolygon* polygon = new TConvexPolygon(iMaxVerticesCount);
			//TConvexPolygon* polygon = factory.create();
			TConvexPolygon* polygon = new TConvexPolygon();

			cout << "������� ��������������� ���������� X � Y\n��� ���������� ������� ���������� 0-� �������\n";
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

			//�������, � �������� �������
		/*	cout << "���-�� ������ " << polygon->getCountVertices() << "\n";
			for (int i = 0; i < polygon->getCountVertices(); i++) {
				polygon->displayVertex(polygon->vertices[i]);
			}
		*/

			cout << "�������: " << polygon->calcArea() << '\n';
			cout << "��������: " << polygon->calcPerimeter() << '\n';
			delete polygon;

		}
		catch (TSpecException& e) {
			cout << "������: " << e.getErrorMessage() << '\n';
			if (_getch() == ESC) {
				break;
			}
			cin.clear();
		}

		cout << "��� ������ ������� Esc" << endl;
		if (_getch() == ESC) {
			break;
		}
	};
	return 0;
}










