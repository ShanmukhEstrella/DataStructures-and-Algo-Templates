stack<Elem*> s;
Elem* temp;
if(root==nullptr)
{
  return;
}
else
{
  s.push(root);
  while(!s.empty())
  {
    temp=s.top();
    cout<<temp->data<<endl;
    s.pop();
    if(temp->right!=nullptr)
    {
      s.push(temp->right);
    }
    if(temp->left!=nullptr)
    {
      s.push(temp->left);
    }
  }
}
