class KVPair
{
  private:
  int key;
  string value;
  KVPair* left;
  KVPair* right;
  KVPair* parent;
  public:
  KVPair(int k=-1,string s="")
  {
    key=k;
    value=s;
  }
  friend class BST;
};
class BST
{
  private:
  KVPair* root;
  public:
  BST()
  {
    root=nullptr;
  }
  BST(KVPair* a)
  {
    root=a;
  }
  void BST::Insert(KVPair* kvp)
  {
    if(root==nullptr)
    {
      root=kvp;
      return;
    }
    else
    {
      InsertHelp(root,kvp);
    }
  }
  void InsertHelp(KVPair* treeroot, KVPair* kvp)
  {
    if(kvp->key < treeroot->key)
    {
      if(treeroot->left==nullptr)
      {
        treeroot->left=kvp;
        kvp->parent=treeroot;
        return;
      }
      InsertHelp(treeroot->left,kvp);
    }
    if(kvp->key > treeroot->key)
    {
      if(treeroot->right==nullptr)
      {
        treeroot->right=kvp;
        kvp->parent=treeroot;
        return;
      }
      InsertHelp(treeroot->right,kvp);
    }
    if(kvp->key==treeroot->key)
    {
      return;
    }
  }
};
