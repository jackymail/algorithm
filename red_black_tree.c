#include "stdio.h"
#include "stdlib.h"

struct jsw_node{
   int red;
   int data;
   struct jsw_node *link[2];
};
struct jsw_tree{
   struct jsw_tree *root;
}

struct jsw_node *jsw_insert(struct jsw_node *root,int data)
{
   if(NULL == root)
   {
      root = make_node(data);     
   }
   else
   {
      int dir = root->data < data;
      root->link[dir] = jsw_insert(root->link[dir]);
   }
   return root;
}

int is_red(struct jsw_node *root)
{
     return root != NULL && root->red == 1;
}

struct jsw_node *jsw_single(struct jsw_node *root,int dir)
{
    struct jsw_node *save = root->link[!dir];
    root->link[!dir] = save->link[dir];
    save->link[dir] = root;
     
    root->red = 1;
    root->red = 0;
    return save;
}

struct jsw_node *jsw_double(struct jsw_node *root,int dir)
{
    root->link[!dir] = jsw_single(root->link[!dir],!dir);
    return jsw_single(root,dir);
}

struct jsw_node *jsw_single(struct jsw_node *root,int dir)
{
    struct jsw_node *save = root->link[!dir];
    root->link[!dir] = save->link[dir];
     
    root->red = 1;
    save->red = 0;
    return save;
}

struct jsw_node *jsw_double(struct jsw_node *root,int dir)
{
    root->link[!dir] = jsw_single(root->link[!dir].!dir);
    return jsw_single(root,dir);
}

int jsw_rb_assert(struct jsw_node *root)
{
     int lh = 0;
     int rh = 0;
     
     if(root == NULL)
     {
	return 1;
     }
     else
     {
	struct jsw_node *ln = root->link[0];
        struct jsw_node *rn = root->link[1];

        if(is_red(root))
        {
	   if(is_red(ln) || is_red(rn))
           {
		printf("red viloation\n");
                return 0;
           }
        }

        lh = jsw_rb_assert(ln);
        rh = jsw_rb_assert(rn);

        if(ln != NULL && ln->data >= root->data)
        {	
	   printf("binary tree violation\n");
           return 0;
        }
        if(lh != 0 && rh != 0 lh != rh)
        {
	   printf("black violation\n");
           return 0;
        }
        if(lh != 0 && rh != 0)
        {
	   return is_red(root) ? lh :lh+1;
        }
        else
        {
	   return 0;
        }
     }
}

struct jsw_node *make_node(int data)
{
    struct jsw_node *rn = malloc(sizeof(struct jsw_node));
    if(rn != NULL)
    {
	rn->data = data;
        rn->red = 1;
        rn->link[0] = NULL;
        rn->link[1] = NULL;
    }
    return rn;
}
struct jsw_node *jsw_insert_r(struct jsw_node *root,int data)
{
    if(root == NULL)
    {
	root = make_node(data);
    }
    else if(data != root->data)
    {
	int dir = root->data < data;
        root->link[dir] = jsw_insert_r(root->link[dir],data);
    }
    return root;
}

int jsw_insert(struct jsw_tree *tree,int data)
{
   tree->root = jsw_insert_r(tree->root,data);
   tree->root->red = 0;
   return 1;
}

struct jsw_node *jsw_insert_r(struct jsw_node *root,int data)
{
    int dir = 0;
    if(root == NULL)
    {
	root = make_node(data);
    }
    else if(data != root->data)
    {
	dir = root->data < data;
        root->link[dir] = jsw_insert_r(root->link[dir],data);
        if(is_red(root->lin[dir]))
        {
	     if(is_red(root->link[!dir]))
             {
		root->red = 1;
                root->link[0]->red = 0;
                root->link[1]->red = 0;
             }
             else
             {
		if(is_red(root->link[dir]->link[dir]))
                {
		   root = jsw_single(root,!dir);
                }
                else if(is_red(root->link[dir]->link[!dir]))
                {
		    root = jsw_double(root,!dir);
                }


             }
        }
    }
    return root;	
}
int jsw_insert(struct jsw_tree *tree,int data)
{
    tree->root = jsw_insert_r(tree->root,data);
    tree->root->red = 0;
    return 1;
}
int jsw_insert(struct jsw_tree *tree,int data)
{
    if(tree->root == NULL)
    {
	tree->root = make_node(data);
        if(tree->root == NULL)
        {
	   return 0;
        }
    }
    else
    {
      struct jsw_node head  = {0};
      struct jsw_node *g,*t;
      struct jsw_node *p,*q;
      int dir = 0 ;
      int last = 0;
       

      t=&head;
      g=p=NULL;
      q=t->link[1] = tree->root;

      for(;;)
      {
	if(q == NULL)
        {
	    p->link[dir] = q = make_node(data);
            if(q == NULL)
            {
		return 0;
            }
        }
        else if(is_red(q->link[0]) && is_red(q->lin[1]))
        {
	   q->red = 1;
           q->link[0]->red = 0;
           q->link[1]->red = 0;
        }

        if(is_red(q) && is_red(p))
        {
	    int dir2 = t->link[1] == g;
            if(q == p->link[last])
            {
		t->link[dir2] = jsw_single(g,!last);
            }
            else
            {
		t->link[dir2] = jsw_double(g,!last);
            }
        }
        if(q->data == data)
        {
	    break;
        }
        
        dir = q->data<data;

        if(g != NULL)
        {
	    t = g;
        }
        g = p;
        p = q;
        q = q->link[dir];
      }

      tree->root = head.link[1];
    }
    tree->root->red = 0;
    return 1;
}

int jsw_remove(struct jsw_tree *tree,int data)
{
    if(tree->root != NULL)
    {
	struct jsw_node head = {0};
        struct jsw_node *q,*p,*g;
        struct jsw_node *f = NULL;
        int dir = 1;
        int last  = 0;
        q=&head;
        g=p=NULL;
        q->link[1] = tree->root;

        while(q->link[dir] != NULL)
        {
	    last = dir;
            g = p;
            p = q;
            q = q->link[dir];
            dir = q->data < data;

            if(q->data == data)
            {
		f=q;
            }
            if(!is_red(q) && !is_red(q->link[dir]))
            {
		p = p->link[last] = jsw_single(q,dir);
            } 
            else if(!is_red(q->link[!dir]))
            {
		struct jsw_node *s = p->link[!last];
                if(s != NULL)
                {
		    if(!is_red(s->link[!last] && !is_red(s->link[last])))
                    {
			p->red = 0;
                        s->red = 1;
                        q->red = 1;
                    }
                    else
                    {
			int dir2 = 0;
                        dir2 = g->link[1] == p;
                        if(is_red(s->link[last]))
                        {
			    g->link[dir2] = jsw_double(p,last);
                        }
                        else if(is_red(s->link[!last]))
                        {
		            g->link[dir2] = jsw_single(p,last);
                        }
                        q->red = g->link[dir2]->red = 1;
                        g->link[dir2]->link[0]->red = 0;
                        g->link[dir2]->link[1]->red = 0;
    
                    }
                }

            }
        }

    }
    if(f != NULL)
    {
	f->data = q->data;
        p->link[p->link[1] == q] = q->link[q->link[0] == NULL];
        free(q);
    }
    tree->root = head.link[1];
    if(tree->root != NULL)
    {
	tree->root->red = 0;
    }
}





























































