#include"stdio.h"
typedef char VertexNameType;
typedef int WeightTypeOrEdgeType;
#define MAXVEX 100
#define INFINITY 9999

typedef struct 		//图节点
{
	VertexNameType vex[MAXVEX];			//顶点数组（包括顶点信息） 
	WeightTypeOrEdgeType edge[MAXVEX][MAXVEX];		//边数组，邻接矩阵 
	int VertexNum,EdgeNum;		//顶点数和边数 
 }Graph;
 
void CreateGraph(Graph *G); 
void Show(Graph *G);

void CreateGraph(Graph *G){
	int i,j,k,weight;
	//顶点数和边数 
	printf("输入此图的顶点数和边数:\n");
	scanf("%d",&G->VertexNum);getchar();scanf("%d",&G->EdgeNum);getchar();
	//顶点数组 
	for(i=0;i<G->VertexNum;i++){
		printf("请输入第%d个顶点的名称:",i+1);
		scanf("%c",&G->vex[i]);getchar();
	}
	//邻接矩阵 - 初始化 
	for(i=0;i<G->VertexNum;i++) {
		for(j=0;j<G->VertexNum;j++){
			if(i==j) G->edge[i][j]=0;
				else  G->edge[i][j]=INFINITY;
		}
	}
	//邻接矩阵 - 保存边
	for(i=0;i<G->EdgeNum;i++){
		printf("请输入第%d条边的两个邻接点的下标 和 权值:\n",i+1);
		scanf("%d",&j);getchar();scanf("%d",&k);getchar();scanf("%d",&weight);getchar();
		G->edge[j][k]=weight;
		G->edge[k][j]=weight;
	} 
}

void Show(Graph *G){
	int i,j;
	puts("邻接矩阵如下!!!!");
	
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
