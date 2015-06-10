#include <iostream> 
#include <iomanip> 
using namespace std;

template <typename T> 
class IList {
public:
	virtual void add(const T& value) = 0;
	virtual void insertAt(int index, const T& value) = 0;
	virtual T getAt(int index) = 0;
	virtual void removeAt(int index) = 0;
	virtual int size() = 0;
	virtual bool empty() = 0;
};

template <typename T> 
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
class ListIterator;

template <typename T> 
class LinkedList : public IList<T> {
	Node<T>* start;
	Node<T>* end;
	int _size;

	void copy(const LinkedList<T>& other);
	void del();
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	virtual ~LinkedList();
	LinkedList<T>& operator=(const LinkedList<T>& other);

	virtual void add(const T& value);
	virtual void insertAt(int index, const T& value);
	virtual T getAt(int index);
	virtual void removeAt(int index);
	virtual int size();
	virtual bool empty();

	ListIterator<T> iterator();

	friend ostream& operator<<<T>(ostream& stream, const LinkedList<T>& l);
};

template <typename T> 
void LinkedList<T>::copy(const LinkedList<T>& other)
{
	Node<T>* p = other.start;


	if ( p )
	{
		start = new Node<T>;
		start->data = p->data;
		start->next = NULL;
		end = start;
		p = p->next;
	}

	while ( p )
	{
		Node<T>* node = new Node<T>;
		node->data = p->data;
		node->next = NULL;
		end->next = node;
		end = node;
		p = p->next;
	}

	_size = other._size;
}

template <typename T> 
void LinkedList<T>::del()
{
	Node<T>* p = start;
	Node<T>* q;

	while ( p )
	{
		q = p;
		p = p->next;
		delete q;
	}

	start = end = NULL;
	_size = 0;
}

template <typename T> 
LinkedList<T>::LinkedList()
{
	start = end = NULL;
	_size = 0;
}

template <typename T> 
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	copy(other);
}

template <typename T> 
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

template <typename T> 
LinkedList<T>::~LinkedList()
{
	del();
}

//Adds an element to the end of the list.
template <typename T> 
void LinkedList<T>::add(const T& value)
{
	Node<T>* node = new Node<T>;
	node->data = value;
	node->next = NULL;

	if (!start) //empty list
	{
		start = node;
	}
	else
	{
		end->next = node;
	}

	end = node;
	++_size;
}

template <typename T> 
void LinkedList<T>::insertAt(int index, const T& value)
{
	Node<T>* node = new Node<T>;
	node->data = value;
	node->next = NULL;

	if (!start) //empty list
	{
		start = end = node;
		++_size;
		return;
	}

	if (index <= 0)
	{
		node->next = start;
		start = node;
		++_size;
		return;
	}

	if (index >= _size)
	{
		add(value);
		return;
	}

	Node<T>* p = start;

	for(int i=0; i < index - 1; ++i)
	{
		p = p->next;
	}

	node->next = p->next;
	p->next = node;
	++_size;
}

template <typename T> 
T LinkedList<T>::getAt(int index)
{
	if (!start)
	{
		exit(1);
	}

	if (index < 0)
	{
		return start->data;
	}

	if (index >= _size)
	{
		return end->data;
	}

	Node<T>* p = start;

	for(int i=0; i < index; ++i)
	{
		p = p->next;
	}

	return p->data;
}

template <typename T> 
void LinkedList<T>::removeAt(int index)
{
	if (index < 0 || index >= _size)
	{
		return;
	}

	if (index == 0)
	{
		Node<T>* p = start;
		start = start->next;
		delete p;
		--_size;
		return;
	}

	Node<T>* p = start;

	for(int i=0; i < index - 1; ++i)
	{
		p = p->next;
	}

	Node<T>* q = p->next;
	p->next = p->next->next;
	delete q;

	if (index == _size - 1)
	{
		end = p;
	}

	--_size;
}

template <typename T> 
int LinkedList<T>::size()
{
	return _size;
}

template <typename T> 
bool LinkedList<T>::empty()
{
	return !start;
}

template <typename T>
ListIterator<T> LinkedList<T>::iterator() {
	return ListIterator<T>(start, end);
}

template <typename T> 
ostream& operator<<(ostream& stream, const LinkedList<T>& l)
{
	Node<T>* p = l.start;
	while ( p )
	{
		cout << p->data << " ";
		p = p->next;
	}

	return stream;
}

template <typename T>
class Iterator {
public:
	virtual ListIterator<T> next() = 0; //��������� ��������� ���� ��������� �������
	virtual T& value() = 0; //����� ���������� �� ��������� �������
	virtual bool hasNext() = 0; //����� ������ ����� ������ ��� ������� �������
};

template <typename T>
class ListIterator : public Iterator<T> {
	Node<T>* _next;
	Node<T>* _prev;
	Node<T>** s;
	Node<T>** e;
public:
	ListIterator(Node<T>* start, Node<T>* end);

	ListIterator<T> next();
	T& value();
	bool hasNext();
};

template <typename T>
ListIterator<T>::ListIterator(Node<T>* start, Node<T>* end)
{
	this->s = &start;
	this->e  = &end;

	this->_next = *s;
	this->_prev = 0;
}

template <typename T>
bool ListIterator<T>::hasNext()
{
	return _next;
}

template <typename T>
ListIterator<T> ListIterator<T>::next()
{
	_prev = _next;
	_next = _next->next;

	return *this;
}

template <typename T>
T& ListIterator<T>::value()
{
	return _next->data;
}
