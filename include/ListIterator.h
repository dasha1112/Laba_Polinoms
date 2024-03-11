#ifndef _LISTITER_
#define _LISTITER_

#include <iostream>
#include "MyNode.h"
#include "MyList.h"

using namespace std;

/*template <class T>
class TListIterator 
{
protected:
	TNode<T>* curr; //указатель на узел
	TList<T>& list; //указатель на список
public:
	//TListIterator(TList<T>& d, TNode<T>& p);
	TListIterator(const TListIterator <T>& p);
	TListIterator(TListIterator<T>&& p);
	~TListIterator();
	void PushAfter(T* a);
	void PushBefore(T* a);
	T* operator* ();
	TListIterator<T>& operator = (const TListIterator<T>& p);
	TListIterator<T>& operator = (const TListIterator<T>&& p);
	TListIterator<T>& operator ++ ();
	TListIterator<T>& operator -- ();
	bool operator == (const TListIterator<T>& p);
	bool operator != (const TListIterator<T>& p);
};


template<class T>
inline TListIterator<T>::TListIterator(const TListIterator<T>& p)
{
	curr = p.curr;
	list = p.list;
}

template<class T>
inline TListIterator<T>::TListIterator(TListIterator<T>&& p)
{
	curr = p.curr;
	p.curr = nullptr;
	list = p.list;
}

template<class T>
inline TListIterator<T>::~TListIterator()
{
	curr = nullptr;
}

template<class T>
inline void TListIterator<T>::PushAfter(T* a)
{
	TNode<T>* t = new TNode<T>(curr->GetNext(), curr, a);
	curr->GetNext()->GetPrev(t);
	curr->SetNext(t);
	list->count++;
}

template<class T>
inline void TListIterator<T>::PushBefore(T* a)
{
	TNode<T>* t = new TNode<T>(curr, curr.GetPrev(), a);
	curr->GetPrev()->SetNext(t);
	curr->SetPrev(t);
	list->count++;
}

template<class T>
inline T* TListIterator<T>::operator*()
{
	if (curr != nullptr) 
	{
		return curr->GetData();
	}
	else 
	{
		throw "Ошибка";
	}
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator=(const TListIterator<T>& p)
{
	curr = p.curr;
	list = p.list;
	return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator=(const TListIterator<T>&& p)
{
	curr = p.curr;
	list = p.list;
	p.curr = nullptr;
	return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator++()
{
	if (curr != nullptr)
	{
		curr = curr->GetNext();
	}
	else 
	{
		throw "Ошибка";
	}
	return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator--()
{
	if (curr != nullptr && curr->GetPrev() != nullptr) 
	{
		curr = curr->GetPrev();
	}
	else 
	{
		throw "Ошибка";
	}
	return *this;
}

template<class T>
inline bool TListIterator<T>::operator==(const TListIterator<T>& p)
{
	if (curr == p.curr) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline bool TListIterator<T>::operator!=(const TListIterator<T>& p)
{
	if (curr != p.curr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
#endif