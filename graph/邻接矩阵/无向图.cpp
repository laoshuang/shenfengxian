#include"stdio.h"
typedef char VertexNameType;
typedef int WeightTypeOrEdgeType;
#define MAXVEX 100
#define INFINITY 9999

typedef struct 
{
	VertexNameType vex[MAXVEX];			//�������飨����������Ϣ�� 
	WeightTypeOrEdgeType edge[MAXVEX][MAXVEX];		//�����飬�ڽӾ��� 
	int VertexNum,EdgeNum;		//�������ͱ��� 
 }Graph;
 
void CreateGraph(Graph *G); 
void Show(Graph *G);

void CreateGraph(Graph *G){
	int i,j,k,weight;
	//�������ͱ��� 
	printf("�����ͼ�Ķ������ͱ���:\n");
	scanf("%d",&G->VertexNum);getchar();scanf("%d",&G->EdgeNum);getchar();
	//�������� 
	for(i=0;i<G->VertexNum;i++){
		printf("�������%d�����������:",i+1);
		scanf("%c",&G->vex[i]);getchar();
	}
	//�ڽӾ��� - ��ʼ�� 
	for(i=0;i<G->VertexNum;i++) {
		for(j=0;j<G->VertexNum;j++){
			if(i==j) G->edge[i][j]=0;
				else  G->edge[i][j]=INFINITY;
		}
	}
	//�ڽӾ��� - �����
	for(i=0;i<G->EdgeNum;i++){
		printf("�������%d���ߵ������ڽӵ���±� �� Ȩֵ:\n",i+1);
		scanf("%d",&j);getchar();scanf("%d",&k);getchar();scanf("%d",&weight);getchar();
		G->edge[j][k]=weight;
		G->edge[k][j]=weight;
	} 
}

void Show(Graph *G){
	int i,j;
	puts("�ڽӾ�������!!!!");
	
	printf("  ");
	for(i=0;i<G->VertexNum;i++)
		printf("%c ",G->vex[i]);
	putchar(10);
		
	for(i=0;i<G->VertexNum;i++) {
		printf("%c ",G->vex[i]);
		for(j=0;j<G->VertexNum;j++){
			if(G->edge[i][j]==9999) printf("# ");
				else printf("%d ",G->edge[i][j]);
		}
		putchar(10);
	}
}


int main()
{
	Graph G;
	CreateGraph(&G);
	Show(&G);
	return 0;
}

