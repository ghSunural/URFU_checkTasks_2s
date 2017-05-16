#pragma once

#include <iostream>
#include <string>

#include "TSpecLinkedList.h"
#include "TSpecException.h"
#include "TPolygon.h"
#include "TCommon.h"

using namespace std;

// À¿—— ¬€œ” À€… ÃÕŒ√Œ”√ŒÀ‹Õ» 

//: TPolygon
class TConvexPolygon  {

private:

	int countVertices_;
	bool isExists_();
	bool isConvex_();
	bool isClosed_();
	void validationData_();

public:

	struct Vertex {
		int No;
		double x;
		double y;
		double axNtoV;
		double ayNtoV;
		double axVtoV;
		double ayVtoV;

	};

	friend ostream& operator<<(ostream& os, const Vertex& V) {

		os << "No=" << V.No <<
			" X=" << V.x << " Y=" << V.y <<
			" axNtoV= " << V.axNtoV << " ayNtoV= " << V.ayNtoV <<
			" axVtoV= " << V.axVtoV << " ayVtoV= " << V.ayVtoV;

		return os;
	}

	double calcVectorProductNtoV(Vertex, Vertex);
	double calcVectorProductVtoV(Vertex, Vertex);

	//TConvexPolygon(int maxVerticesCount);
	TConvexPolygon();

	//Vertex* vertices;
	TSpecLinkedList<Vertex>* verticesList;

	void addVertex(int, double, double);
	//void addVertex(double, double); //to list
	int getCountVertices();
	double calcArea();
	double calcPerimeter();

	~TConvexPolygon();
};
