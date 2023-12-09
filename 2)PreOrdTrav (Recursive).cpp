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
  cout<<E->data<<endl;
  PreOrdTravHelp(E->left);
  PreOrdTravHelp(E->right);
}
