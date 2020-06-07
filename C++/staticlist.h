#ifndef STATICLIST_H
#define STATICLIST_H

/* ______________________Documentación general del archivo_____________________

Date: 			11/12/2019
Developer:		Oscar Martinez
Descripción:	Definición de los métodos y atributos de la clase StaticList

____________________________________________________________________________ */

#include <iostream>
#include <exception>

template <class T, long ARRAYSIZE>
class StaticList{
	// _____________Definición de los métodos y atributos privados_____________

    private:
        bool order;
		long last;
		T data[ARRAYSIZE];

		bool isValid(const long &pos); // T(n) = 6
		void swapData(T &a, T &b); // T(n) = 3
		long linearSearch(const T &e); // T(n) = 4n + 3
		long binarySearch(const T &e); // T(n) = 9log_2 (n+1) + 4

		void bubbleSort(); // T(n) = 6n^2 + 20n + 3
		void shellSort(); // T(n) = 12nlog_2(n) + 9log_2(n) - 6(log_2(n))^2
		void insertSort(); // T(n) = 5n^2 + 16n + 2
		void selectSort(); // T(n) = 3n^2 +15n + 2
		void mergeSort(); // T(n) =
		void mergeSort(T *temp, long int leftEdge, long int rightEdge); // T(n) =
		void quickSort(); // T(n) =
		void quickSort(long leftEdge, long  rightEdge); // T(n) =

		class Exception : public std::exception{
			private:
				std::string msg;
			public:
				explicit Exception(const char* message) : msg(message){} // T(n) = 1
				explicit Exception(const std::string& message) : msg(message){} // T(n) = 1
				virtual ~Exception() throw(){}
				virtual const char* what() const throw(){
					return msg.c_str();
				} // T(n) = 2
		};

    // ________________________________________________________________________


    // _____________Definición de los métodos y atributos públicos_____________

    public:

        // _____________________Constructores y destructor_____________________

        StaticList(); // T(n) = 2
		~StaticList();

        // ____________________________________________________________________


        // ________________________Métodos comparables_________________________

        /*StaticList& operator = (const StaticList&);

		bool operator == (const StaticList&) const;
		bool operator != (const StaticList&) const;
		bool operator < (const StaticList&) const;
		bool operator <= (const StaticList&) const;
		bool operator > (const StaticList&) const;
		bool operator >= (const StaticList&) const;*/

        // ____________________________________________________________________


        // ______________________Métodos control de flujo______________________

        /*friend std::ostream& operator << (std::ostream&, StaticList&);
		friend std::istream& operator >> (std::istream&, StaticList&);*/

		// ____________________________________________________________________


		// _________________________Métodos generales__________________________

		bool isEmpty(); // T(n) = 2
		bool isFull(); // T(n) = 3
		bool isOrder(); // T(n) = 6n - 2

		long getFirstPos(); // T(n) = 2
		long getLastPos(); // T(n) = 1
		long getPrevPos(const long &pos); // T(n) = 10
		long getNextPos(const long &pos); // T(n) = 10

		long getSize(); // T(n) = 2
		long getMaxSize(); // T(n) = 1
		void print(); // T(n) = 5n + 2

		bool insert(const long &pos, const T &e); // T(n) = 6n + 20
        bool insertInOrder(const T &e); // T(n) = 7n+13
        bool remove(const long &pos); // T(n) = 12n + 9
        T retrieve(const long& pos); // T(n) = 10
        long index(const T& e);
        /* Si isInOrder && n > 7 T(n) = 9log_2 (n+1) + 8
                            else T(n) = 4n + 7 */
        bool append(const T& e); // T(n) = 15
        T top(); // T(n) = 5
        T pop(); // T(n) = 6n + 2
        bool extend(StaticList<T, ARRAYSIZE> *l);  // T(l.n) = 6n + 11
        bool extendInOrder(StaticList<T, ARRAYSIZE> *l); // T(n) = 9n + 13
        void sort();


		// ____________________________________________________________________

    // ________________________________________________________________________

};

using namespace std;

// ___________________Implementación de los métodos privados___________________

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::isValid(const long &pos){
    /* Descripción: Recibe por parámetro una posición del arreglo, sí la
    posición es válida, retorna true, si no es válida retorna false,
    una posición es valida solo si existe un elemento en esa posición */
    return pos >= 0 && pos <= last && pos < ARRAYSIZE;
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::swapData(T &a, T &b){
    /* Descripción: Realiza un intercambio entre variables, a = b y b = a */
	T aux(a);
	a = b;
	b = aux;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::linearSearch(const T &e){
    /* Descripción: Busca el elemento "e" en el arreglo, de forma lineal, sí lo
    encuentra, retorna la posición, sí no lo encuentra retorna -1 */
    for(long i(0); i<=last; i++)
        if(data[i] == e)
            return i;
    return -1;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::binarySearch(const T &e){
    /* Descripción: Busca el elemento "e" en el arreglo, de forma binaria, sí
    lo encuentra, retorna la posición, sí no lo encentra retorna -1 */
    long first (0);
    long last(this->last);
    long half;

    while (first <= last){
		half = (last + first) / 2;
      	if (data[half] == e)
 			return half;
      	else if (data[half] > e)
   			last = half - 1;
 		else
   			first = half + 1;
    }

    return -1;
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::bubbleSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */

    if(order)
        return;

    for(int i(last); i>0; i--)
        for(int j=0; j<i; j++)
            if(data[j] > data[j+1])
                swapData(data[j], data[j+1]);
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::shellSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */

	for(long i(last/2); i>0; i/=2)
		for(long j(0); j <= last-i; j++)
			if(data[j] > data[j+i])
				swapData(data[j], data[j+i]);
}
template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::insertSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */
    for(long i(1); i<=last; i++){
        T aux(data[i]);

        long j(i);
        for(;j > 0 && aux < data[j-1]; j--)
            data[j] = data[j-1];

        if(i != j )
            data[j] = aux;
    }
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::selectSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */
	for(long i(0); i<last; i++){
		long m(i);
		for(long j(i+1); j<=last; j++)
			if(data[j] < data[m])
				m = j;

		if(i != m)
			swapData(data[i], data[m]);
	}
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::mergeSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */
	T temp[ARRAYSIZE];
	mergeSort(temp, getFirstPos(), getLastPos());
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::mergeSort(T *temp, long leftEdge, long rightEdge){
    /* Descripción: Ordena el arreglo de menor a mayor */
	if(leftEdge >= rightEdge)
		return;

	long m((leftEdge + rightEdge) / 2);

	mergeSort(temp, leftEdge, m);
	mergeSort(temp, m+1, rightEdge);

	for(long z(leftEdge); z<=rightEdge; z++)
		temp[z]=data[z];

	long i(leftEdge), j(m+1), x(leftEdge);

	while(i <= m and j <= rightEdge){
		while(i<= m and temp[i] <= temp[j])
			data[x++]=temp[i++];

		if(i <= m)
			while(j <= rightEdge and temp[j] <= temp[i])
				data[x++] = temp[j++];
	}

	while(i <= m)
		data[x++] = temp[i++];

	while(j <= rightEdge)
		data[x++] = temp[j++];
}


template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::quickSort(){
    /* Descripción: Ordena el arreglo de menor a mayor */
	quickSort(getFirstPos(), getLastPos());
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::quickSort(long leftEdge, long  rightEdge){
    /* Descripción: Ordena el arreglo de menor a mayor */
	if(leftEdge >= rightEdge)
		return;

	long i(leftEdge), j(rightEdge);

	while(i < j){
		while(i < j && data[i] <= data[rightEdge])
			i++;

		while(i < j && data[j] >= data[rightEdge])
			j--;

		if(i != j)
			swapData(data[i], data[j]);
	}

	if (i != rightEdge)
		swapData(data[i], data[rightEdge]);

	quickSort(leftEdge, i-1);
	quickSort(i+1, rightEdge);
}

// ____________________________________________________________________________


// ___________________Implementación de los métodos públicos___________________
// _________________________Constructores y destructor_________________________

template<class T, long ARRAYSIZE>
StaticList<T, ARRAYSIZE>::StaticList(): order(true), last(-1){}

template<class T, long ARRAYSIZE>
StaticList<T, ARRAYSIZE>::~StaticList(){}

// ____________________________________________________________________________


// ____________________________Métodos comparables_____________________________

/*Name& Name::operator = (const Name& c){
	attribute = c.attribute;

	return *this;
}


bool Name::operator == (const Name& c) const{
	return attribute == c.attribute;
}

bool Name::operator != (const Name& c) const{
	return attribute != c.attribute;
}

bool Name::operator < (const Name& c) const{
	return attribute < c.attribute;
}

bool Name::operator <= (const Name& c) const{
	return attribute <= c.attribute;
}

bool Name::operator > (const Name& c) const{
	return attribute > c.attribute;
}

bool Name::operator >= (const Name& c) const{
	return attribute >= c.attribute;
}*/

// ____________________________________________________________________________


// __________________________Métodos control de flujo__________________________

/*ostream& Name::operator << (ostream& o, Name& c){
	o << c.attribute;

	return o;
}

istream& Name::operator >> (istream& i, Name& c){
	string str;

	getline(i, str);
	c.attribute = str.c_str();
	//cin.ignore();
	//getline(i, n.attribute2);

	return i;
}*/

// ____________________________________________________________________________


// _____________________________Métodos generales______________________________

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::isEmpty(){
    /* Descripción: Revisa si el arreglo no contiene elementos, si no contiene
    retorna true, si contiene uno o más elementos retorna false */
	return last == -1;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::isFull(){
    /* Descripción: Revisa si el arreglo está lleno, si esta lleno, retorna
    true, si no lo esta, retorta false */
	return ARRAYSIZE - 1 == last;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::isOrder(){
    /* Descripción: Retorna true si la lista se encuentra ordedana, de lo
    contrario retorna false */

    if(order)
        return order;
    for(long i(0); i<last; i++)
        if(data[i] > data[i+1])
            return false;

    order = true;
    return order;
}


template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getFirstPos(){
    /* Descripción: Retorna la primer posición del arreglo */
    return last == -1 ? -1 : 0;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getLastPos(){
    /* Descripción: Retorna la última posición del arrelgo */
    return last;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getPrevPos(const long &pos){
    /* Descripción: Devuelve una posición anterior a la pasada por parámetro
    sí la posición no es valida, retorna -1 */
    return isValid(pos - 1) ? pos - 1 : -1;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getNextPos(const long &pos){
    /* Descripción: Devuelve una posición siguiente a la pasada por parámetro
    si la posición no es valida, retorna -1 */
    return isValid(pos + 1) ? pos + 1 : -1;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getSize(){
    /* Decripción: Retorna el número de elementos en el arreglo */
    return last + 1;
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::getMaxSize(){
    /* Decripción: Retorna el número máximo de elementos en el arreglo */
    return ARRAYSIZE;
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::print(){
    /* Descripción: Imprime los elementos del arreglo en consola */
    for(long i(0); i<=last; i++)
        cout << data[i] << endl;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::insert(const long &pos, const T &e){
    /* Descripción: verifica si la lista esta llena, si lo esta no inserta el
    elemento y retorna false. inserta el elemento e pasado por párametro en
    el arregloen la posición pos, para poder insertar recorre todos los
    elementos a la derecha si la posición no es válida, retorna false, si es
    válida retorna true. También evaluá sí el arreglo sigue estando ordenado */
    if(isFull())
        return false;

    last++;
    if(!isValid(pos)){
        last--;
        return false;
    }

    for(long i(last); i>pos; i--)
        data[i] = data[i-1];

    data[pos] = e;

    // Cambia el estatus, de ordenado
    // Evaluá si se encuentra ordenado y hay más de 1 elemento en el arreglo
    if(order && last > 0){
        if(0 == pos){ // Caso I: Se inserta al principio
            if(e > data[1])
                order = false;
        }
        else if(pos == last){ // Caso II: Se inserta al final
            if(data[pos-1] > e)
                order = false;
        }
        // Caso III: Se inserta al en medio
        else if(data[pos-1] > e || e > data[pos+1])
            order = false;
    }

    return true;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::insertInOrder(const T &e){
    /* Descripción: Inserta el elemento pasado por parámetro en orden, sí el
    arreglo esta lleno, no se inserta y retorna false, sí el arreglo no esta
    ordenado no se inserta y retorna false */
    if(!order || isFull())
        return false;

    long i;
    for(i=last++; data[i]>e; i--)
        data[i+1] = data[i];

    data[i+1] = e;

    return true;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::remove(const long &pos){
    /* Descripción: Elimina un elemento del arreglo, de la posición pos, sí
    la posición no es válida, retorna false, de lo contrario retorna true.
    También comprueba si quedo ordenado el arreglo */

    if(!isValid(pos))
        return false;

    for(long i(pos); i<last; i++)
        data[i] = data[i+1];

    last--;
    isOrder();
    return true;
}

template<class T, long ARRAYSIZE>
T StaticList<T, ARRAYSIZE>::retrieve(const long &pos){
    /* Descripción: Verifica sí la posición "pos" es válida, sí no lo es
    lanza una excepción, si es válida retorna el elemento en esa posición */

    if(!isValid(pos))
		throw Exception("Invalid position");
	return data[pos];
}

template<class T, long ARRAYSIZE>
long StaticList<T, ARRAYSIZE>::index(const T &e){
    /* Descripción: Busca el elemento "e" en el arreglo, si el arreglo esta
    ordenado y existen más de 7 elementos utiliza busqueda binaria, de lo
    contrario utiliza busqueda lineal, sí lo encuentra, retorna la posición
    sí no lo encuentra retorna -1 */

    if(order && 6 < last)
        return binarySearch(e);

    return linearSearch(e);
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::append(const T &e){
    /* Descripción: Agrega un elemento al final del arreglo, verifica sí el
    arreglo permanece ordenado, si ya no hay espacio en el arreglo retorna
    false, de lo contrario retorna true */

    if(data[last] > e)
        order = false;

    if(!isValid(++last)){
        last--;
        return false;
    }

    data[last] = e;

    return true;
}

template<class T, long ARRAYSIZE>
T StaticList<T, ARRAYSIZE>::top(){
    /* Descripción: Retorna el último elemento, siempre y cuando no este vácio
    el arreglo */

    if(isEmpty())
        throw Exception("The list is empty");

    return data[last];
}

template<class T, long ARRAYSIZE>
T StaticList<T, ARRAYSIZE>::pop(){
    /* Descripción: Retorna y elimina el último elemento, siempre y cuando no
    este vácio el arreglo */

    if(isEmpty())
        throw Exception("The list is empty");

    last--;
    isOrder();

    return data[last+1];
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::extend(StaticList<T, ARRAYSIZE> *l){
    /* Descripción: Une dos listas, si no hay espacio suficiente, retona false
    de lo contrario retorna true, verifica si el arreglo sique ordendado */

    if(last + l->last + 2 > ARRAYSIZE)
        return false;

    if(!l->order || l->data[0] < data[last])
        order = false;

    for(long i(0); i<=l->last; i++)
        data[++last] = l->data[i];

    return true;
}

template<class T, long ARRAYSIZE>
bool StaticList<T, ARRAYSIZE>::extendInOrder(StaticList<T, ARRAYSIZE> *l){
    /* Descripción: Une dos listas ordenadas y se mantiene el orden, si no hay
    espacio suficiente o las listas no estan ordenadas, retona false de lo
    contrario retorna true, verifica si el arreglo sique ordendado */

    long max_new(last + l->last + 1);

    if(max_new + 1 > ARRAYSIZE)
        return false;

    if(!(l->order && order))
        return false;

    long l_last(l->last);
    long this_last(last);

    for(long i(max_new); l_last>=0; i--)
        if(data[this_last] > l->data[l_last])
            data[i] = data[this_last--];
        else
            data[i] = l->data[l_last--];

    last = max_new;
    return true;
}

template<class T, long ARRAYSIZE>
void StaticList<T, ARRAYSIZE>::sort(){
    /* Descripción: Revisa si el arreglo esta ordenado, sí no lo está lo
    ordena de menor a mayor */
    if(!order){
        quickSort();
        order = true;
    }
}

// ____________________________________________________________________________

// ____________________________________________________________________________

#endif // STATICLIST_H

