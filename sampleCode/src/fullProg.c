#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** Creates a new vector of size n
 *
 * Each element of the new vector is initialized to be 0.
 *
 * @param n - the size of the new vector.
 *
 * @return - a new vector of size n or NULL if an error occurs.
 *
 */
double* newVector(size_t n)
{
  double* v = (double*)malloc(sizeof(double)*n);

  if(!v)
    return v;

  size_t i;
  for(i = 0; i < n; i++)
    v[i] = 0;

  return v;
}

/** Creates a new matrix of size nxm.
 *
 * Each element is initialized to be 0.
 *
 * @param n - the row size of the new matrix
 * @param m - the column size of the new matrix;
 *
 * @return - a new nxm matrix or NULL if an error occurs.
 *
 */
double** newMatrix(size_t n, size_t m)
{
  double** A = (double**)malloc(sizeof(double*)*m);

  size_t i;

  for(i = 0; i < n; i++)
  {
    A[i] = newVector(n);

    if(!A[i])
      return NULL;
  }

  return A;
}

/** Frees the memory allocated for a vector
 *
 * This is exactly the same as calling free(...)
 *
 */
void freeVector(double* v)
{
  free(v);
}

/** Frees the memory allocated for a matrix
 *
 */
void freeMatrix(double** M, size_t n)
{
  size_t i;
  for(i = 0; i < n; i++)
    freeVector(M[i]);

  free(M);
}

/** Left multiply a matrix and a vector
 *
 * @param A - the matrix of size nxm
 * @param v - the vector to multiply against the matrix. This vector must be of
 * size m.
 * @param out - the output vector. This vector must be of size n
 * @param n - row size of A
 * @param m - column size of A
 *
 * @return - same as out or NULL if an error occurs.
 *
 */
double* leftMult(double** A, double* v, double* out, size_t n, size_t m)
{
  size_t i,j;

  if(!A || !v || !out || n <=0 || m <= 0)
    return NULL;

  //perform the matrix multiplication
  for(i = 0; i < n; i++)
  {
    out[i] = 0;
    for(j = 0; j < m; j++)
      out[i] += A[j][i]*v[i];
  }

  return out;
}

/** Finds the maximum height of a projectile given the initial velocity
 *
 * This function assumes a zero initial position.
 *
 * @param v0 - the initial velocity vector
 * @param out - the vector to store the result in.
 * @param n - the size of the vector.
 *
 * @return - same as out or NULL if an error occurs.
 *
 */
double* maxHeight(double* v0, const double G, double* out, size_t n)
{
  double** A = newMatrix(n,n);

  if(!A)
    return out;

  A[1][0] = v0[0]/G;
  A[1][1] = v0[1]/(2*G);

  out = leftMult(A,v0,out,n,n);

  freeMatrix(A,n);

  return out;
}

/** Calculate the max distance given the initial velocity.
 *
 * This function assumes a zero initial position.
 *
 * @param v0 - the inital velocity vector
 * @param n - the size of the vector
 *
 * @return - the distance the max projectile will travel. 0 is returned if an
 * error occured.
 *
 */
double maxDistance(double* v0, const double G, size_t n)
{
  if(!v0 || n < 2)
    return 0;

  return (2*v0[0]*v0[1])/G;
}

double* makeInitVel(double magnitude, double angle, double* out)
{
	out[0] = magnitude*cos(angle);
	out[1] = magnitude*sin(angle);

	return out;
}

int main(int argc, char const* argv[])
{
  /** the size of our vectors */
  const size_t N = 2;

  /** the size of gravity */
  const double G = 9.81;

  double initVel[N];
	double maxH[N];

  double d;

  //here

	makeInitVel(1,M_PI/4,initVel);

	d = maxDistance(initVel,G,N);
	maxHeight(initVel,G,maxH,N);

	printf("Max Distance: %f\n",d);
	printf("Max Height:\n");
	printf("  [ %f %f]\n",maxH[0],maxH[1]);

  return 0;
}
