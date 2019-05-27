const int MAX_LOTES_COMPRA = 30;
const int MAX_INI_COMPRADORES = 3;

// Estructura de un comprador
typedef struct {
    long long int numero;
    float total;
} tComprador;

// Tipo puntero a comprador
typedef tComprador *tPunteroComprador;

// Lista: array dinámico y contador
typedef struct {
    tPunteroComprador compradores;
    int contador;
    int tamanyo;
} tListaComprador;


// Inicializa una lista de compradores
void inicializa(tListaComprador &lista);

// Aumenta el tamaño de una lista de compradores
void aumentar(tListaComprador &lista);

// Inserta un nuevo comprador en la lista de compradores
void insertar(tListaComprador &lista, long long int comprador, float precio);

// Busca un comprador en la lista de compradores
bool buscar(const tListaComprador &lista, long long int comprador, int &pos);

// Muestra la información de una lista de compradores
void mostrar(const tListaComprador &lista);

// Libera la memoria dinámica utilizada
void libera(tListaComprador &lista);
