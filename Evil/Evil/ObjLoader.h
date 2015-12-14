#include <vector>
#include "Matrices.h"

using namespace std;

struct sVertex
{
	float x, y, z;
};

struct sTexCoord
{
	float u, v;
};

struct sMaterial
{	
	char name[256];
	int illum;
	char map_Kd[256];
	float Ns;
	float Ni;
	float d;
	float Ka[3];
	float Kd[3];
	float Ks[3];
	float Tf[3];
	unsigned int texture;

	sMaterial() {
		memset (this, 0, sizeof(sMaterial));
	}
};

struct sFace
{
	int n;

	int v[5];	//vertices
	int vt[5];	//text coords
	int vn[5];	//normals

	sFace() {
		memset (this, 0, sizeof(sFace));
	}
};

struct sPart
{
	char name[256];
	vector<sFace> faces;

	sPart() {
		name[0] = 0;
	}
};

class CObjLoader
{
public:
	CObjLoader ();
	~CObjLoader();

	void loadMaterialsTexture ();
	bool Load (const char *objfile, const char *mtlfile = NULL);
	void Draw (Vector3 center, float scale = 1.f);

private:
	vector<sMaterial> materials;

	vector<sVertex> vertexes;
	vector<sTexCoord> texcoords;
	vector<sVertex> normals;

	vector<sPart> parts;

	bool loadObjects (const char *fileName);
	bool loadMaterials (const char *fileName);

	int findMaterialIndex(char *name);
	bool loadTexture (const char *fileName, unsigned int *texture);

private:	
	char _work_path[_MAX_DIR];
	bool _loaded;
};
