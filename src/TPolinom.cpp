#include "TPolinom.h"

TPolinom::TPolinom():TList <TMonom>::TList()
{
}

TPolinom::TPolinom(const TPolinom& p):TList<TMonom>::TList(p)
{
}

TPolinom::~TPolinom()
{
  Clear();
}

TPolinom TPolinom::operator+(TPolinom& p)
{
  TPolinom res;
  TNode<TMonom>* i = begin;
  TNode<TMonom>* j = p.begin;
  while (i != end || j != end) // Проходимся по двум полиномам 
  {
    if (i->GetData() == j->GetData()) // Если мономы равны
    {
      TMonom m(i->GetData()->GetC()+j->GetData()->GetC(), i->GetData()->GetDegrees()); // Складываем коэффиценты
      res.PushEnd(&m);
      ++i;
      ++j;
    }
    else if (i->GetData() > j->GetData()) 
    {
      res.PushEnd(i->GetData());
      ++i;
    }
    else 
    {
      res.PushEnd(j->GetData());
      ++j;
    }
  }
  return res;
}

TPolinom TPolinom::operator-(TPolinom& p)
{
  TPolinom res;
  TNode<TMonom>* i = begin;
  TNode<TMonom>* j = p.begin;
  while (i != end || j != end) // Проходимся по двум полиномам 
  {
    if (i->GetData() == j->GetData()) // Если мономы равны
    {
      TMonom m(i->GetData()->GetC() - j->GetData()->GetC(), i->GetData()->GetDegrees()); // Вычитаем коэффиценты
      res.PushEnd(&m);
      ++i;
      ++j;
    }
    else if (i->GetData() > j->GetData())
    {
      res.PushEnd(i->GetData());
      ++i;
    }
    else
    {
      res.PushEnd(j->GetData());
      ++j;
    }
  }
  return res;
}

TPolinom TPolinom::operator*(TPolinom& p)
{
  TPolinom res;
  TNode<TMonom>* i = begin;
  TMonom m;
  double k = m.GetC();
  TVector<double> d = m.GetDegrees();
  while (i != nullptr) 
  { 
    TPolinom temp;
    TNode<TMonom>* j = p.begin;
    while (j != nullptr) 
    {
      k = i->GetData()->GetC() * j->GetData()->GetC();
      d = i->GetData()->GetDegrees() * j->GetData()->GetDegrees();
      m.SetC(k);
      m.SetDegrees(d);
      temp.PushEnd(&m);
      j = j->GetNext();
    }
    res = res + temp;
    i = i->GetNext();
  }
  return res;
}

TPolinom& TPolinom::operator=(TPolinom& p)
{
  if (this == &p) { return *this; }
  if (this != &p) 
  {
    this->Clear(); // Очищаем текущий список мономов  
    TNode<TMonom>* temp = p.GetBegin();// Копируем мономы из списка p в текущий объект
    while (temp != nullptr) {
      TMonom *monom = temp->GetData();
      this->PushEnd(monom); // Добавляем скопированный моном в конец списка текущего объекта
      temp = temp->GetNext();
    }
  }
  return *this;
}

TPolinom TPolinom::operator+=(TMonom& m)
{
  TNode<TMonom>* temp = new TNode<TMonom>(&m);
  if (IsEmpty()) {
    begin = end = temp;
  }
  else {
    end->SetNext(temp);
    temp->SetPrev(end);
    end = temp;
  }
  count++;
  return *this;
}

TPolinom TPolinom::operator-=(TMonom m)
{
  TNode<TMonom>* temp = new TNode<TMonom>(&m);
  if (IsEmpty()) {
    begin = end = temp;
  }
  else {
    end->SetNext(temp);
    temp->SetPrev(end);
    end = temp;
  }
  count++;
  return *this;
}

TPolinom TPolinom::operator*=(TMonom m)
{
  TNode<TMonom>* current = begin;
  double k = m.GetC();
  TVector<double> d = m.GetDegrees();
  while (current != nullptr) {
    current->GetData()->GetC() * k;
    current->GetData()->GetDegrees()* d;
    current = current->GetNext();
  }
  return *this;
}

bool TPolinom::operator==(const TPolinom& p)
{
  if (count != p.count) 
  {
    return false;
  }
  TNode<TMonom>* i = begin;
  TNode<TMonom>* j = p.begin;
  while (i != end || j != end) 
  {
    if (i->GetData()->GetC()!=j->GetData()->GetC() ||
      i->GetData()->GetDegrees() != j->GetData()->GetDegrees()) 
    {
      return false;
    }
  }
  return true;
}

bool TPolinom::operator!=(const TPolinom& p)
{
  if (count != p.count)
  {
    return true;
  }
  TNode<TMonom>* i = begin;
  TNode<TMonom>* j = p.begin;
  while (i != end || j != end)
  {
    if (i->GetData()->GetC() != j->GetData()->GetC() ||
      i->GetData()->GetDegrees() != j->GetData()->GetDegrees())
    {
      return true;
    }
  }
  return false;
}

int TPolinom::GetCount()
{
  return this->count;
}

ostream& operator<<(ostream& out, const TPolinom& polinom)
{
  TNode<TMonom>* temp = polinom.GetBegin();
  while (temp != nullptr) {
    out << temp->GetData() << " ";
    temp = temp->GetNext();
  }
  return out;
}

istream& operator>>(istream& in, TPolinom& polinom)
{
  return in;
}
