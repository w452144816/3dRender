#include "GeometryGenerator.h"




void GeometryGenerator::CreateBox(float width, float height, float depth, MeshData &mesh)
{
	mesh.vertices.clear();
	mesh.indices.clear();

	//一共24个顶点(每面4个)
	mesh.vertices.resize(24);
	//一共36个索引(每面6个)
	mesh.indices.resize(36);

	float halfW = width * 0.5f;
	float halfH = height * 0.5f;
	float halfD = depth * 0.5f;

	//眼睛面向z轴正方向
	//构建顶点
	//前面
    mesh.vertices[0].pos = XVector(-halfW, -halfH, -halfD,1.f);
    mesh.vertices[0].normal = XVector(0.f, 0.f, -1.f);
    mesh.vertices[0].color = XVector(1.f, 0.f, 0.f,1.f);
    mesh.vertices[0].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[1].pos = XVector(-halfW, halfH, -halfD,1.f);
    mesh.vertices[1].normal = XVector(0.f, 0.f, -1.f);
    mesh.vertices[1].color = XVector(0.f, 0.f, 0.f, 1.f);
    mesh.vertices[1].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[2].pos = XVector(halfW, halfH, -halfD, 1.f);
    mesh.vertices[2].normal = XVector(0.f, 0.f, -1.f);
    mesh.vertices[2].color = XVector(1.f, 0.f, 0.f, 1.f);
    mesh.vertices[2].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[3].pos = XVector(halfW, -halfH, -halfD, 1.f);
    mesh.vertices[3].normal = XVector(0.f, 0.f, -1.f);
    mesh.vertices[3].color = XVector(0.f, 1.f, 0.f, 1.f);
    mesh.vertices[3].tex = XFLOAT2(1.f, 1.f);
	//左侧面
    mesh.vertices[4].pos = XVector(-halfW, -halfH, halfD, 1.f);
    mesh.vertices[4].normal = XVector(-1.f, 0.f, 0.f);
    mesh.vertices[4].color = XVector(0.f, 0.f, 1.f, 1.f);
    mesh.vertices[4].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[5].pos = XVector(-halfW, halfH, halfD, 1.f);
    mesh.vertices[5].normal = XVector(-1.f, 0.f, 0.f);
    mesh.vertices[5].color = XVector(1.f, 1.f, 0.f, 1.f);
    mesh.vertices[5].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[6].pos = XVector(-halfW, halfH, -halfD, 1.f);
    mesh.vertices[6].normal = XVector(-1.f, 0.f, 0.f);
    mesh.vertices[6].color = XVector(0.f, 0.f, 0.f, 1.f);
    mesh.vertices[6].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[7].pos = XVector(-halfW, -halfH, -halfD, 1.f);
    mesh.vertices[7].normal = XVector(-1.f, 0.f, 0.f);
    mesh.vertices[7].color = XVector(1.f, 1.f, 1.f, 1.f);
    mesh.vertices[7].tex = XFLOAT2(1.f, 1.f);
	//背面
    mesh.vertices[8].pos = XVector(halfW, -halfH, halfD, 1.f);
    mesh.vertices[8].normal = XVector(0.f, 0.f, 1.f);
    mesh.vertices[8].color = XVector(1.f, 0.f, 1.f, 1.f);
    mesh.vertices[8].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[9].pos = XVector(halfW, halfH, halfD, 1.f);
    mesh.vertices[9].normal = XVector(0.f, 0.f, 1.f);
    mesh.vertices[9].color = XVector(0.f, 1.f, 1.f, 1.f);
    mesh.vertices[9].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[10].pos = XVector(-halfW, halfH, halfD, 1.f);
    mesh.vertices[10].normal = XVector(0.f, 0.f, 1.f);
    mesh.vertices[10].color = XVector(1.f, 1.f, 0.f, 1.f);
    mesh.vertices[10].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[11].pos = XVector(-halfW, -halfH, halfD, 1.f);
    mesh.vertices[11].normal = XVector(0.f, 0.f, 1.f);
    mesh.vertices[11].color = XVector(0.f, 0.f, 1.f, 1.f);
    mesh.vertices[11].tex = XFLOAT2(1.f, 1.f);
	//右侧面
    mesh.vertices[12].pos = XVector(halfW, -halfH, -halfD, 1.f);
    mesh.vertices[12].normal = XVector(1.f, 0.f, 0.f);
    mesh.vertices[12].color = XVector(0.f, 1.f, 0.f, 1.f);
    mesh.vertices[12].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[13].pos = XVector(halfW, halfH, -halfD, 1.f);
    mesh.vertices[13].normal = XVector(1.f, 0.f, 0.f);
    mesh.vertices[13].color = XVector(1.f, 0.f, 0.f, 1.f);
    mesh.vertices[13].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[14].pos = XVector(halfW, halfH, halfD, 1.f);
    mesh.vertices[14].normal = XVector(1.f, 0.f, 0.f);
    mesh.vertices[14].color = XVector(0.f, 1.f, 1.f, 1.f);
    mesh.vertices[14].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[15].pos = XVector(halfW, -halfH, halfD, 1.f);
    mesh.vertices[15].normal = XVector(1.f, 0.f, 0.f);
    mesh.vertices[15].color = XVector(1.f, 0.f, 1.f, 1.f);
    mesh.vertices[15].tex = XFLOAT2(1.f, 1.f);
	//上面
    mesh.vertices[16].pos = XVector(-halfW, halfH, -halfD, 1.f);
    mesh.vertices[16].normal = XVector(0.f, 1.f, 0.f);
    mesh.vertices[16].color = XVector(0.f, 0.f, 0.f, 1.f);
    mesh.vertices[16].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[17].pos = XVector(-halfW, halfH, halfD, 1.f);
    mesh.vertices[17].normal = XVector(0.f, 1.f, 0.f);
    mesh.vertices[17].color = XVector(1.f, 1.f, 0.f, 1.f);
    mesh.vertices[17].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[18].pos = XVector(halfW, halfH, halfD, 1.f);
    mesh.vertices[18].normal = XVector(0.f, 1.f, 0.f);
    mesh.vertices[18].color = XVector(0.f, 1.f, 1.f, 1.f);
    mesh.vertices[18].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[19].pos = XVector(halfW, halfH, -halfD, 1.f);
    mesh.vertices[19].normal = XVector(0.f, 1.f, 0.f);
    mesh.vertices[19].color = XVector(1.f, 0.f, 0.f, 1.f);
    mesh.vertices[19].tex = XFLOAT2(1.f, 1.f);
	//底面
    mesh.vertices[20].pos = XVector(-halfW, -halfH, halfD, 1.f);
    mesh.vertices[20].normal = XVector(0.f, -1.f, 0.f);
    mesh.vertices[20].color = XVector(0.f, 0.f, 1.f, 1.f);
    mesh.vertices[20].tex = XFLOAT2(0.f, 1.f);
    mesh.vertices[21].pos = XVector(-halfW, -halfH, -halfD, 1.f);
    mesh.vertices[21].normal = XVector(0.f, -1.f, 0.f);
    mesh.vertices[21].color = XVector(1.f, 1.f, 1.f, 1.f);
    mesh.vertices[21].tex = XFLOAT2(0.f, 0.f);
    mesh.vertices[22].pos = XVector(halfW, -halfH, -halfD, 1.f);
    mesh.vertices[22].normal = XVector(0.f, -1.f, 0.f);
    mesh.vertices[22].color = XVector(0.f, 1.f, 0.f, 1.f);
    mesh.vertices[22].tex = XFLOAT2(1.f, 0.f);
    mesh.vertices[23].pos = XVector(halfW, -halfH, halfD, 1.f);
    mesh.vertices[23].normal = XVector(0.f, -1.f, 0.f);
    mesh.vertices[23].color = XVector(1.f, 0.f, 1.f, 1.f);
    mesh.vertices[23].tex = XFLOAT2(1.f, 1.f);

	//构建索引
	mesh.indices[0] = 0;
	mesh.indices[1] = 1;
	mesh.indices[2] = 2;
	mesh.indices[3] = 0;
	mesh.indices[4] = 2;
	mesh.indices[5] = 3;

	mesh.indices[6] = 4;
	mesh.indices[7] = 5;
	mesh.indices[8] = 6;
	mesh.indices[9] = 4;
	mesh.indices[10] = 6;
	mesh.indices[11] = 7;

	mesh.indices[12] = 8;
	mesh.indices[13] = 9;
	mesh.indices[14] = 10;
	mesh.indices[15] = 8;
	mesh.indices[16] = 10;
	mesh.indices[17] = 11;

	mesh.indices[18] = 12;
	mesh.indices[19] = 13;
	mesh.indices[20] = 14;
	mesh.indices[21] = 12;
	mesh.indices[22] = 14;
	mesh.indices[23] = 15;

	mesh.indices[24] = 16;
	mesh.indices[25] = 17;
	mesh.indices[26] = 18;
	mesh.indices[27] = 16;
	mesh.indices[28] = 18;
	mesh.indices[29] = 19;

	mesh.indices[30] = 20;
	mesh.indices[31] = 21;
	mesh.indices[32] = 22;
	mesh.indices[33] = 20;
	mesh.indices[34] = 22;
    mesh.indices[35] = 23;
}

void GeometryGenerator::CreateCoordinate(GeometryGenerator::MeshData &mesh)
{
    mesh.vertices.clear();
    mesh.indices.clear();

    //一共24个顶点(每面4个)
    mesh.vertices.resize(24);
    //一共36个索引(每面6个)
    mesh.indices.resize(36);
}


