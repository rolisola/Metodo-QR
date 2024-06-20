import numpy as np, math # Para operações básicas com vetores e matrizes

def norma_vetor(vetor):
    soma_quadrados = 0.0
  
    # Calcula a soma dos quadrados dos elementos do vetor
    for elemento in vetor:
        soma_quadrados += elemento ** 2
    
    # Retorna a raiz quadrada da soma dos quadrados
    norma = math.sqrt(soma_quadrados)
    
    return norma

def gram_schmidt(matriz):
    """
    Realiza a decomposição QR de uma matriz matriz usando o processo de Gram-Schmidt.

    Args:
    - matriz: Matriz quadrada (numpy array)

    Returns:
    - Q: Matriz ortogonal (numpy array)
    - R: Matriz triangular superior (numpy array)
    """

    tam_matriz = matriz.shape[0]
    Q = np.zeros_like(matriz, dtype=float)
    R = np.zeros_like(matriz, dtype=float)

    for j in range(tam_matriz):
        vetor = matriz[:, j]

        print(f"vetor: {j+1}", vetor)

        for i in range(j):
            R[i, j] = np.dot(Q[:, i], matriz[:, j])
            vetor -= R[i, j] * Q[:, i]
        R[j, j] = norma_vetor(vetor)
        Q[:, j] = vetor / R[j, j]
    
    return Q, R

def householder(A):
    m, n = A.shape
    R = A.copy()
    Q = np.eye(m)

    for j in range(n):
        # Aplicando a reflexão de Householder para zerar os elementos abaixo da diagonal em R
        x = R[j:m, j]
        norma_x = norma_vetor(x)
        if R[j, j] > 0:
            v1 = -norma_x
        else:
            v1 = norma_x
        v = np.zeros_like(x)
        v[0] = v1
        v = v + x
        v = v / norma_vetor(v)
        R[j:m, j:n] -= 2 * np.outer(v, np.dot(v.T, R[j:m, j:n]))
        Q[j:m, :] -= 2 * np.outer(v, np.dot(v.T, Q[j:m, :]))

    return Q.T, R

def givens(A):
    m, n = A.shape
    Q = np.eye(m)
    R = A.copy()

    for j in range(n):
        for i in range(m-1, j, -1):
            if R[i, j] != 0:
                # Calcular os parâmetros da rotação de Givens
                r = np.sqrt(R[j, j]**2 + R[i, j]**2)
                c = R[j, j] / r
                s = -R[i, j] / r

                # Aplicar a rotação de Givens à direita de R
                G = np.identity(m)
                G[[j, i], [j, i]] = c
                G[j, i] = s
                G[i, j] = -s
                R = np.dot(G, R)

                # Acumular a matriz Q
                Q = np.dot(Q, G.T)

    return Q, R

def metodo_qr(matriz_inicial, max_iteracoes=100, erro=1e-8):
    """
    Aplica o método QR iterativo para encontrar autovalores de uma matriz matriz_inicial.

    Args:
    - matriz_inicial: Matriz quadrada (numpy array)
    - max_iteracoes: Número máximo de iterações (opcional)

    Returns:
    - autovalores: Lista de autovalores aproximados
    """

    A_k = matriz_inicial.copy()
    tam_matriz = matriz_inicial.shape[0]
    autovalores = []

    for k in range(max_iteracoes):
        Q, R = gram_schmidt(A_k)

        print(f"Matriz Q_{k+1}:")
        print(Q)
        print(f"Matriz R_{k+1}:")
        print(R)

        A_k = np.dot(R, Q) # Multiplicação RxQ
        print(f"Matriz A_{k+1}:")
        print(A_k)

        # Extração dos autovalores da diagonal de A_k
        autovalores_k = [A_k[i, i] for i in range(tam_matriz)]
        autovalores.append(autovalores_k)

        # Critério de parada (todos os elementos abaixo da diagonal principal são menores que o Erro)
        criterio_parada = True
        for i in range(1, tam_matriz):
            for j in range(i):
                if abs(A_k[i][j]) >= erro:
                    criterio_parada = False
                    break
            if not criterio_parada:
                break

        if criterio_parada:
            break

    return autovalores

# Exemplo de uso:
if __name__ == "__main__":
    # Definindo uma matriz de exemplo
    matriz_inicial = np.array([
        [2, 3, 0],
        [0, 4, 0],
        [2, -3, 1]
    ], dtype=float)

    # Aplicando o método QR para encontrar os autovalores
    autovalores = metodo_qr(matriz_inicial,3)

    print("Autovalores aproximados:")
    for i, autovalor in enumerate(autovalores[-1]):
        print(f"lambda_{i+1} =", autovalor)
