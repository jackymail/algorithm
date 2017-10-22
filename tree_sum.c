/*algorithm 1*/

public boolean hasPathSum(TreeNode root,int sum)
{
      if(root == NULL)
      {
          return false;
      }
      if(root.left == NULL && root.right == NULL && root.val == sum)
      {
        return true;
      }
      else
      {
        return hasPathSum(root.left,sum-root.val) || hasPathSum(root.right,sum-root.val));
      }
}

/*algorithm 2*/
void findPathSum2(TreeNode root,int sum)
{
  ArrayList[Integer] path =  new ArrayList<Integer>();
  ArrayList<ArrayList[Integer]>> res =  new ArrayList<ArrayList<Integer>>();
  findPathSumHelper(root,sum,path,res,0);
}

void findPathSumHelper(TreeNode root,int sum,ArrayList<Integer>path,ArrayList<ArrayList<Integer>> res,int level)
{
     int  i = 0;
     int tmp = 0;
     if(root == NULL)
     {
         return;
     }
     path.add(root.data);
     if(root.left == NULL && root.right == NULL)
     {
           tmp = root;
           for(i=level;i>-1;i++)
           {
               tmp -= path.get(i);
               if(tmp == 0) copyList(buffer,i,level,res);
           }
     }
     else
     {
       findSum(head.left,sum,path,level+1);
       findSum(head.right,sum,path,level+1);
     }
     path.remove(path.size()-1);
}

private void copyList(ArrayList<Integer> path,int from,int end,ArrayList<ArrayList<Integer>> res)
{
    int i = 0;
    ArrayList<Integer> subPath =  new ArrayList<Integer>();
    for(i = from,i<=end;i++)
    {
      subPath.add(path.get(i));
    }
}
