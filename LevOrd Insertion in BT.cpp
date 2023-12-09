class Elem
{
  private:
  int data;
  Elem* parent;
  Elem* left;
  Elem* right;
  public:
  Elem()
  {
    data=-1;
    parent=left=right=nullptr;
  }
  Elem(int d)
  {
    data=d;
    parent=left=right=nullptr;
  }
  friend class BT;
};
class BT
{
  private:
  Elem* root;
  public:
  BT()
  {
    root=nullptr;
  }
  BT(Elem* a)
  {
    root=a;
  }
  void InsertNodeLevelOrder(Elem*);
};
void BT::InsertNodeLevelOrder(Elem* E)
{
  if(root==nullptr)
  {
    root=E;
    return ;
  }
  queue<Elem*> NodeQ;
  NodeQ.push(root);
  while(!NodeQ.empty())
  {
    Elem* temp=NodeQ.front();
    NodeQ.pop();
    if(temp->left!=nullptr)
    {
      NodeQ.push(temp->left);
    }
    else
    {
      temp->left=E;
      E->parent=temp;
      return;
    }
    if(temp->right!=nullptr)
    {
      NodeQ.push(temp->right);
    }
    else
    {
      temp->right=E;
      E->parent=temp;
      return;
    }
  }
}
