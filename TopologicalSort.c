status topological_sort(ALGraph G)
{
   FindDegree(G,indegree); //求个顶点的入度。
   InitStack(S);
   for(i=0;i<G->vernum;++i)
   {
	if(indegree[i] == 0)
        {
	   Push(S,i);
        }
   }
   count = 0;
   while(!stackempty(S))
   {
	Pop(S,i);
        printf(i,G.vertexces[i].data);
        ++count;
        for(p=G->vertexces[i].firsttarc;p;p=p->nextrc)
        {
	     k = p->adjvx;
             if(!(--indegree[k]))
             {
		PUSH(S,k);
             }
         }
   }
   if(count<G.vernum)
   {
	return ERROR;
   }
   return OK;




}
