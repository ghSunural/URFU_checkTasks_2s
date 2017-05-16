#pragma once
#include <iostream>
#include "TShape.h"
#include "TSpecLinkedList.h"
#include "TSpecException.h"
#include "TCommon.h"

class TPolygon : TShape {
protected:

	int countVertices_;
	bool isExists_();
	bool isClosed_();	

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

	

	//TConvexPolygon(int maxVerticesCount);
	TPolygon();


	TSpecLinkedList<Vertex>* verticesList;

	void addVertex(int, double, double);	
	int getCountVertices();

	~TPolygon();
};