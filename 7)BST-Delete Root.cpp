void DeleteRoot(KVPair* kv) // kv is root
{
  if(kv->left==nullptr&&kv->right==nullptr)
  {
    root=nullptr;
    delete kv;
  }
  if(kv->left!=nullptr&&kv->right==nullptr)
  {
    root=kv->left;
    root->parent=nullptr;
    delete kv;
  }
  if(kv->right!=nullptr&&kv->left==nullptr)
  {
    root=kv->right;
    root->parent=nullptr;
    delete kv;
  }
  if(kv->right!=nullptr&&kv->left!=nullptr)
  {
    KVPair* temp;
    temp = FindSmallest(kv->right);
    kv->CopyKV(temp);
    DeleteNode(temp);
  }
  return;
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
