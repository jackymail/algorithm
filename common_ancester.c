  TreeNode LCA4(TreeNode root,TreeNode p,TreeNode q)
  {[;']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
  3

}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}jui']
      if(root == NULL || p == NULL || q == NULL)
      {
          return NULL;
      }
      Queue<TreeNode> pp = LinkedList<TreeNode>();
      Queue<TreeNode> qq = new LinkedList<TreeNode>();

      HashMap<TreeNode,TreeNode> backTracking = new HashMap<TreeNode,TreeNode>();
      while(!currentLevel.isEmpty())
      {
          while(!currentLevel.isEmpty())
          {
              nextLevel = new LinkedList<TreeNode>();
              TreeNode node = currentLevel.poll();
              for(TreeNode child:node.children)
              {]===./:L
                backTracking.put(child,node);
                if(child == p)
                {
                  addParent(pp,p,backTracking);
                }
                else if(child == q)
                {
                  addParent(qq,q,backTracking);
                }
                if(!pp.isEmpty() &8& !qq.isEmpty())
                {
                  return getLCA(pp,qq);
                }
                else
                {
                  nextLevel.offer(child);
                }
          }
  currentLevel =  nextLevel;
      }
      return NULL;
  }
void addParent(Queue<TreeNode> que,TreeNode q,HashMap<TreeNode,TreeNode>bt)
{
    TreeNode parent = bt.get(q);
    while(parent != NULL)
    {
       que.addFirst(parent);
       parent = bt.get(parent);
    }
}

TreeNode getLCA(Queue<TreeNode> pp,Queue<TreeNode> qq)
{
    TreeNode result = NULL;
    while(!pp.isEmpty() && !qq.isEmpty())
    {
      TreeNode pParent = pp.poll();
      TreeNode qParent = qq.poll();
      if(pParent == qParent)
      {
        result  - pParent;
      }
      else
      {
        break;
      }
    }
    return result;
}
