typedef struct nodo{
int dato;
struct nodo *sgte;
struct nodo *ante;
}lista;
int insertar (lista **i, int d);
void listar (lista *i);
int insertarFin(lista **i, int dato);
int eliminar(lista **i, int dato);
lista *crearLista(int dato);
