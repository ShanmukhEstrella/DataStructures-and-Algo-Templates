KVPair* SearchGet(int k)
{
  return SearchGetHelp(root,k);
}
KVPair* SearchGetHelp(KVPair* treeroot , int k)
{
  if(treeroot==nullptr)
  {
    return nullptr;
  }
  else
  {
    if(k==treeroot->key)
    {
      return treeroot;
    }
    else
    {
      if(k < treeroot->key)
      {
        return SearchGetHelp(treeroot->left,k);
      }
      else if(k > treeroot->key)
      {
        return SearchGetHelp(treeroot->right,k);
      }
      else return nullptr;
    }
  }
}
