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
