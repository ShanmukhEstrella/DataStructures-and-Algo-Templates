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
  PreOrdTravHelp(E->right);
  cout<<E->data<<endl;
}
