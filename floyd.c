/*1:调用多次单源最短路径算法。对稀疏图
 *2:floyd算法基本思想，从i 到 j只经过 编号小于等于k的顶点的最短路径。
 *
 *
 */


#include "stdio.h"

bool Floyd(MGraph Graph,WeighType D[][MaxVerxNum],Vertex path[][MaxVertexNum])
{
    Vertex i,j,k;
    
    for(k=0;k<Graph->Nv;k++)
    {
	for(i=0;i<Graph->Nv;i++)
        {
	    for(j=0;j<Graph->Nv;j++)
            {
		if(D[i][k] + D[k][j] < D[i][j])
                {
		    D[i][j] = D[i][k] + D[k][j];
                    if(i==j && D[i][j] < 0)
                    {
			return false;
                    }
                    path[i][j] = k;
                }
            }
        }

    }
   return true;
}
