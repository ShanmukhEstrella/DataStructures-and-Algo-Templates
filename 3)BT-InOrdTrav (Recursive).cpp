void PreOrdTrav()
{
  PreOrdTravHelp(root);
}
void PreOrdTravHelp(Elem* E)
{
  if(E==nullptr)
  {
    return;
  }
  PreOrdTravHelp(E->left);
  cout<<E->data<<endl;
  PreOrdTravHelp(E->right);
}
