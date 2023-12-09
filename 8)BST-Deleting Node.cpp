void DeleteNode(KVPair* kv)
{
  KVPair* temp;
  if(kv==root)
  {
    DeleteRoot(kv);
    return;
  }
  else
  {
    //Leaf node deletion
    if(kv->left==nullptr&&kv->right==nullptr)
    {
      if(kv->parent->left==kv)
      {
        kv->parent->left=nullptr;
      }
      if(kv->parent->right==kv)
      {
        kv->parent->right=nullptr;
      }
      delete kv;
      return;
    }
    //deletion of Node with only left child
    if(kv->left!=nullptr&&kv->right==nullptr)
    {
      if(kv->parent->left==kv)
      {
        DeleteOneChild(kv,kv->left,'L');
      }
      else
      {
        DeleteOneChild(kv,kv->left,'R');
      }
      return;
    }
    //deletion of Node with only right child
    if(kv->right!=nullptr&&kv->left==nullptr)
    {
      if(kv->parent->left==kv)
      {
        DeleteOneChild(kv,kv->right,'L');
      }
      else
      {
        DeleteOneChild(kv,kv->right,'R');
      }
      return;
    }
    //deletion of node with both left and right child
    if(kv->right!=nullptr&&kv->left!=nullptr)
    {
      temp=FindSmallest(kv->right);
      kv->CopyKV(temp);
      DeleteNode(temp);
      return;
    }
  }
}
void CopyKV(KVPair* src)
{
  key=src->key;
  value=src->value;
}
KVPair* FindSmallest(KVPair* kvp)
{
  KVPair* temp=kvp;
  while(temp->left!=nullptr)
  {
    temp=temp->left;
  }
  return temp;
}
void DeleteOneChild(kvpair* kv,kvpair* child , char dir)
{
  KVPair* kvparent=kv->parent;
  if(dir=='L')
  {
    kvparent->left=child;
  }
  else
  {
    kvparent->right=child;
  }
  child->parent=kvparent;
  delete kv;
}
