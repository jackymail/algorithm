int Isomorphic( Tree T1, Tree T2 )
{
  int ret1 = 0;
  int ret2 = 0;
  
  if(NULL == T1 && NULL  == T2)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
  
  if(T1 != T2)
  {
    return 0;
  }
  
  if(T1->Left != T2->Left && T1->Right != T2->Right && T1->Left != T2->Right
  && T1->Right != T2->Left)
  {
     return 0;
  }
  if((T1->Left == T2->Left && T1->Right != T2->Right) || (T1->Right == T2->Right &&
  T1->Left != T2->Left))
  {
    return 0;
  }
 
  if(T1->Left == T2->Left && T1->Right == T2->Right)
  {
    ret1 = Isomorphic(T1->Left,T2->Left);
    ret2 = Isomorphic(T2->Right,T2->Right);
    if(ret1 ==1 && ret2 ==1)
    {
       return 1;
    }
    else
    {
       return 0;
    }
  }
  
  if(T1->Left == T2->Right && T1->Right == T2->Left)
  {
    ret1 = Isomorphic(T1->Left,T2->Right);
    ret2 = Isomorphic(T1->Right,T2->Left);
    if(ret1 == 1 && ret2 == 1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}
