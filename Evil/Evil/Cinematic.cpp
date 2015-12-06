#include "Cinematic.h"
#include "GS.h"


Cinematic::Cinematic(){
}

Cinematic::~Cinematic(){}

bool Cinematic::readFile(const char* fileName) {
	ifstream in(fileName);

	while(!in.eof())
	{
		cineCoordinate v;
		in >> v.x >> v.z >> v.lookx >> v.looky >> v.lookz;
		vertexes.push_back(v);
	}
	in.close();

	return true;
}

bool Cinematic::Load(const char *cineFile)
{
	_splitpath(cineFile, NULL, _work_path, NULL, NULL);

	if (cineFile && *cineFile) {
		readFile(cineFile);
	}
	return true;
}

void Cinematic::returnVertexes(int i) {
	posX = vertexes.at(i).x;
	posZ = vertexes.at(i).z;
	lookx = vertexes.at(i).lookx;
	looky = vertexes.at(i).looky;
	lookz = vertexes.at(i).lookz;
	
	
	
}

int Cinematic::returnVectorSize() {
	return vertexes.size();
}

float Cinematic::getposX() {
	return posX;
}

float Cinematic::getposZ() {
	return posZ;
}
float Cinematic::getlookx()
{
	return lookx;
}
float Cinematic::getlooky()
{
	return looky;
}
float Cinematic::getlookz()
{
	return lookz;
}