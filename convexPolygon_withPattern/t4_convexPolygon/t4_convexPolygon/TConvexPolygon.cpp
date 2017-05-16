#include "TConvexPolygon.h"

//ИМПЛЕМЕНТАЦИЯ КЛАССА ВЫПУКЛЫЙ МНОГОУГОЛЬНИК
//--------------------------------------------------------------
/*TConvexPolygon::TConvexPolygon(int maxVerticesCount) {

	try {
		if (maxVerticesCount < 4) {
			throw TSpecException("");
		}
		vertices = new Vertex[maxVerticesCount];
		countVertices_ = 0;
		cout << "Объект Многоугольник создан \n";
	}

	catch (...) {
		throw TSpecException("Неверные данные \n");
	}


}*/
//--------------------------------------------------------------
TConvexPolygon::TConvexPolygon() {

	verticesList = new TSpecLinkedList<Vertex>;

}
//--------------------------------------------------------------
TConvexPolygon::~TConvexPolygon() {
	cout << "Объект Многоугольник уничтожен \n";
}
//--------------------------------------------------------------
//векторное произведение
double TConvexPolygon::calcVectorProductNtoV(Vertex a, Vertex b) {

	double VectorProduct =
		(a.axNtoV * b.ayNtoV - b.axNtoV * a.ayNtoV);

	return VectorProduct;
}
//--------------------------------------------------------------
//векторное произведение
double TConvexPolygon::calcVectorProductVtoV(Vertex a, Vertex b) {

	double VectorProduct =
		(a.axVtoV * b.ayVtoV - b.axVtoV * a.ayVtoV);

	return VectorProduct;
}
//--------------------------------------------------------------
//проверка существования
bool TConvexPolygon::isExists_() {
	if (countVertices_ > 3) {

		return true;
	}

	return false;
}
//--------------------------------------------------------------
//проверка выпуклости
bool TConvexPolygon::isConvex_() {

	TCommon::Sign currentSign;
	TCommon::Sign tempSign = TCommon::null;

	for (int i = 0; i < countVertices_ - 1; i++) {

		//currentSign = TCommon::getNumberSign(calcVectorProductVtoV(vertices[i], vertices[i + 1]));
		currentSign = TCommon::getNumberSign(
			calcVectorProductVtoV(verticesList->getByKey(i), verticesList->getByKey(i + 1)));


		if (tempSign == TCommon::null && currentSign != TCommon::null) {
			tempSign = currentSign;
		}

		if (currentSign != TCommon::null && currentSign != tempSign) {

			return false;
		}
	}

	return true;
}
//--------------------------------------------------------------
//проверка замкнутости
bool TConvexPolygon::isClosed_() {

	//if ((vertices[0].x == vertices[countVertices_ - 1].x)
	//	&& (vertices[0].y == vertices[countVertices_ - 1].y)) {

		if ((verticesList->getFirst().x == verticesList->getByKey(countVertices_ - 1).x)
			&& (verticesList->getFirst().y == verticesList->getByKey(countVertices_ - 1).y)) {
		

		return true;
	}

	return false;
}
//--------------------------------------------------------------
//комплексная валидация входных данных
void TConvexPolygon::validationData_() {
	if (!isExists_()) {
		throw
			TSpecException("Многоугольника не существует \n");
	}

	else if (!isConvex_()) {
		throw
			TSpecException("Многоугольник не выпуклый \n");
	}

	else if (!isClosed_()) {
		throw
			TSpecException("Многоугольник не замкнут \n");
	}
}
//--------------------------------------------------------------
//добавить вершину
void TConvexPolygon::addVertex(int No, double x, double y) {

	Vertex vertex;

	vertex.No = No;
	vertex.x = x;
	vertex.y = y;
		

	if (No) {
		vertex.axNtoV = x - verticesList->getByKey(0).x;
		vertex.ayNtoV = y - verticesList->getByKey(0).y;
		vertex.axVtoV = x - verticesList->getByKey(No - 1).x;
		vertex.ayVtoV = y - verticesList->getByKey(No - 1).y;
	}
	else {
		vertex.axVtoV = 0;
		vertex.ayVtoV = 0;
	}

	verticesList->addLast(vertex);

	/*
		vertices[No].No = No;
		vertices[No].x = x;
		vertices[No].y = y;

		vertices[No].axNtoV = x - vertices[0].x;
		vertices[No].ayNtoV = y - vertices[0].y;

		if (No) {
			vertices[No].axVtoV = x - vertices[No - 1].x;
			vertices[No].ayVtoV = y - vertices[No - 1].y;
		}
		else {
			vertices[No].axVtoV = 0;
			vertices[No].ayVtoV = 0;
		}
		*/
	countVertices_++;

}
//--------------------------------------------------------------
//количество вершин
int TConvexPolygon::getCountVertices() {

	return countVertices_;
}
//--------------------------------------------------------------
//вычислить площадь
double TConvexPolygon::calcArea() {

	validationData_();

	double area = 0;
	/*
	for (int i = 1; i < countVertices_ - 1; i++) {
		area += 0.5 * (calcVectorProductNtoV(vertices[i], vertices[i + 1]));
	}
	*/
	for (int i = 1; i < countVertices_ - 1; i++) {
		area += 0.5 * (calcVectorProductNtoV(verticesList->getByKey(i), 
			verticesList->getByKey(i + 1)));
	}

	return abs(area);
}
//--------------------------------------------------------------
//вычислить периметр
double TConvexPolygon::calcPerimeter() {

	validationData_();

	double perimeter = 0;
	/*
	for (int i = 1; i < countVertices_; i++) {
		perimeter +=
			sqrt(
				pow(vertices[i].axVtoV, 2) +
				pow(vertices[i].ayVtoV, 2)
			);
	}
	*/

	for (int i = 1; i < countVertices_; i++) {
		perimeter +=
			sqrt(
				pow(verticesList->getByKey(i).axVtoV, 2) +
				pow(verticesList->getByKey(i).ayVtoV, 2)
			);
	}

	return perimeter;
}



