void LOT()
{
  queue<KVPair*> Q;
  Q.push(root);
  while(!Q.empty())
  {
    KVPair* temp=Q.front();
    cout<<temp->key<<" "<<temp->value<<endl;
    Q.pop();
    if(temp->left!=nullptr)
    {
      Q.push(temp->left);
    }
    if(temp->right!=nullptr)
    {
      Q.push(temp->right);
    }
  }
}
